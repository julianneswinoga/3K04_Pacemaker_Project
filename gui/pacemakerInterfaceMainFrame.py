import wx
import pacemakerInterface
import wx.lib.plot as plot

import numpy

from serialHelper import *

def rotate(list, n):
		return list[-n:] + list[:-n]
		
def scale_bitmap(bitmap, width, height):
	image = bitmap.ConvertToImage()
	image = image.Scale(width, height, wx.IMAGE_QUALITY_HIGH)
	result = wx.Bitmap(image)
	return result

class pacemakerInterfaceMainFrame(pacemakerInterface.MainFrame):
	def __init__(self, parent):
		pacemakerInterface.MainFrame.__init__(self, parent)
		
		self.plotLength = 100
		self.plotPoints = [0]*self.plotLength
		
		self.THING = 0.0
		
		sizer = self.GetSizer()
		self.canvas = plot.PlotCanvas(self)
		self.canvas.SetXSpec('none')
		self.canvas.SetYSpec('auto')
		sizer.Replace(self.PlotFrame, self.canvas)
		self.Layout()
		
		self.serialPortsAvailable = []
		self.SerialInterface = None
		
		self.StaticBitmapDisconnected = scale_bitmap(wx.Bitmap('img/disconnected.png', wx.BITMAP_TYPE_ANY), 50, 50)
		self.StaticBitmapConnected = scale_bitmap(wx.Bitmap('img/connected.png', wx.BITMAP_TYPE_ANY), 50, 50)
		self.Img_Connected.SetBitmap(self.StaticBitmapDisconnected)
		
		self.timer = wx.Timer(self, 100)
		self.Bind(wx.EVT_TIMER, self.OnTimer)
		self.timer.Start(10)
	
	def OnTimer(self, event):
		if (self.SerialInterface != None and self.SerialInterface.is_open):
			if self.SerialInterface.inWaiting() == 0:
				return
			buf = ''
			data = self.SerialInterface.read()
			while (data != '\n'):
				buf += data
				data = self.SerialInterface.read()
			try:
				data = float(buf)
			except(ValueError):
				print 'Error converting', buf
				data = -1
		else:
			return
		self.AddPoint(data)
		self.THING += 0.1
		self.UpdateGraph()
	
	def AddPoint(self, y):
		self.plotPoints = rotate(self.plotPoints, -1)
		self.plotPoints[-1] = y
	
	def UpdateGraph(self):
		pts = [[c, self.plotPoints[c]] for c in range(len(self.plotPoints))]
		line = plot.PolyLine(pts, colour='green', legend='2', width=1)
		self.canvas.Draw(plot.PlotGraphics([line]))
		
	def OnScanBttnClicked(self, event):
		for i in self.serialPortsAvailable:
			self.SerialDropdown.Delete(0)
		
		self.serialPortsAvailable = serial_ports()
		print 'Serial ports scanned: ' + ', \n'.join(self.serialPortsAvailable) + '\n'
		
		for port in self.serialPortsAvailable:
			self.SerialDropdown.Append(port)
	
	def OnConnectBttnClicked(self, event):
		if (self.SerialInterface == None or not self.SerialInterface.is_open): # Connect to a device
			activeText = self.SerialDropdown.GetStringSelection()
			if (activeText == ''):
				return
			print 'Connecting to ' + activeText + '\n'
			
			self.SerialInterface = open_port(activeText, baud = 9600, timeout = 3)
			if (self.SerialInterface.is_open):
				self.Bttn_ConnectDisconnect.SetLabel('Disconnect')
				self.Img_Connected.SetBitmap(self.StaticBitmapConnected)
			else:
				print 'Serial connection to ' + activeText + ' failed!'
		elif (self.SerialInterface != None and self.SerialInterface.is_open): # Disconnect from a device
			self.SerialInterface.close()
			if (not self.SerialInterface.is_open):
				self.Bttn_ConnectDisconnect.SetLabel('Connect')
				self.Img_Connected.SetBitmap(self.StaticBitmapDisconnected)
			else:
				print 'Failed to disconnect from serial device!'
				
	def OnLoadBttnClicked(self, event):
		if (self.SerialInterface == None or not self.SerialInterface.is_open):
			return
		
		byteStream = []
		
		byteStream.append(bytes([self.choice_FnCode.GetSelection()])) # FnCode
		
		byteStream.append(bytes([self.choice_pacingState.GetSelection()])) # pacingState
		byteStream.append(bytes([self.choice_pacingMode.GetSelection()])) # pacingMode
		byteStream.append(bytes([self.choice_hysteresis.GetSelection()])) # hysteresis
		byteStream.append(bytes([self.spinctrl_hysteresisInterval.GetValue()])) # hysteresisInterval
		byteStream.append(bytes([self.spinctrl_vPaceAmp.GetValue()])) # vPaceAmp
		byteStream.append(bytes([self.spinctrl_vPaceWidth_10x.GetValue()])) # vPaceWidth_10x
		byteStream.append(bytes([self.spinctrl_VRP.GetValue()])) # VRP
		
		byteStream.append(bytes([0])); # checksum
		
		byteStream.append("\0"); # null ending byte
		
		self.SerialInterface.write(bytes(byteStream))
		self.SerialInterface.flush()
		
	def OnWindowClose(self, event):
		self.timer.Stop()
		self.Destroy()

if (__name__ == '__main__'):
	app = wx.App(False) 
	frame = pacemakerInterfaceMainFrame(None) 
	frame.Show(True)
	
	app.MainLoop() 