import wx
import pacemakerInterface
import wx.lib.plot as plot

import binascii

import numpy, struct

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
		
		self.plotLength = 200
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
		if (self.SerialInterface == None or not self.SerialInterface.is_open):
			return
		
		if (self.SerialInterface.in_waiting == 0):
			return
		
		#print self.SerialInterface.in_waiting
		
		buf = ''
		data = self.SerialInterface.read()
		while (data != "\n"):
			buf += data
			data = self.SerialInterface.read()
		
		#print buf
		
		#return
		
		try:
			thinger = float(buf)
		except:
			return
		
		self.AddPoint(thinger)
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
			
			self.SerialInterface = open_port(activeText, baud = 57600, timeout = 3)
			if (self.SerialInterface.is_open):
				self.Bttn_ConnectDisconnect.SetLabel('Disconnect')
				self.Img_Connected.SetBitmap(self.StaticBitmapConnected)
				
				
				self.SerialInterface.write('123456789\nbbbbbbbbbbb\ncccccc\n')
				self.SerialInterface.flush()
				
				
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
		
		dataStream = []
		byteStream = ''
		
		dataStream.append(['B', self.choice_FnCode.GetSelection()]) # FnCode
		
		dataStream.append(['B', self.choice_pacingState.GetSelection()]) # pacingState
		dataStream.append(['B', self.choice_pacingMode.GetSelection()]) # pacingMode
		dataStream.append(['B', self.choice_hysteresis.GetSelection()]) # hysteresis
		
		dataStream.append(['H', self.spinctrl_hysteresisInterval.GetValue()]) # hysteresisInterval
		dataStream.append(['<f', self.spinctrl_vPaceAmp.GetValue()]) # vPaceAmp
		dataStream.append(['H', self.spinctrl_vPaceWidth_10x.GetValue()]) # vPaceWidth_10x
		dataStream.append(['H', self.spinctrl_VRP.GetValue()]) # VRP
		
		dataStream.append(['B', 0]); # checksum
		
		for i in dataStream:
			byteStream += struct.pack(i[0], i[1])
		
		print self.SerialInterface.write(byteStream), ':', repr(byteStream)
		for b in byteStream[6:10]:
			print bin(int(binascii.hexlify(b), 16))
		self.SerialInterface.flush()
		
	def OnWindowClose(self, event):
		self.timer.Stop()
		self.Destroy()

if (__name__ == '__main__'):
	app = wx.App(False) 
	frame = pacemakerInterfaceMainFrame(None) 
	frame.Show(True)
	
	app.MainLoop() 
	