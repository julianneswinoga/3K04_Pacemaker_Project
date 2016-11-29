import wx
import pacemakerInterface
import wx.lib.plot as plot

import numpy, struct, binascii, threading

from serialHelper import *

def rotate(list, n):
		return list[-n:] + list[:-n]
		
def scale_bitmap(bitmap, width, height):
	image = bitmap.ConvertToImage()
	image = image.Scale(width, height, wx.IMAGE_QUALITY_HIGH)
	result = wx.Bitmap(image)
	return result


def threaded(fn):
	def wrapper(*args, **kwargs):
		thread = threading.Thread(target=fn, args=args, kwargs=kwargs)
		thread.start()
		return thread
	return wrapper
	
	
class pacemakerInterfaceMainFrame(pacemakerInterface.MainFrame):
	def __init__(self, parent):
		pacemakerInterface.MainFrame.__init__(self, parent)
		
		self.plotLength = 600
		self.plotPoints = [0]*self.plotLength
		self.pointsToAdd = []
		
		sizer = self.GetSizer()
		self.canvas = plot.PlotCanvas(self)
		self.canvas.SetXSpec('none')
		self.canvas.SetYSpec('auto')
		sizer.Replace(self.PlotFrame, self.canvas)
		self.Layout()
		
		self.serialPortsAvailable = []
		self.SerialInterface = None
		self.streamingData = False
		self.runSerialThread = True
		self.serialThreadExit = False
		
		self.StaticBitmapDisconnected = scale_bitmap(wx.Bitmap('img/disconnected.png', wx.BITMAP_TYPE_ANY), 50, 50)
		self.StaticBitmapConnected = scale_bitmap(wx.Bitmap('img/connected.png', wx.BITMAP_TYPE_ANY), 50, 50)
		self.Img_Connected.SetBitmap(self.StaticBitmapDisconnected)
		
		self.timer = wx.Timer(self, 100) # 100 is the timer ID
		self.Bind(wx.EVT_TIMER, self.OnGraphUpdateTimer)
		self.timer.Start(20)
	
	@threaded
	def serialFunction(self):
		while (self.runSerialThread):
			if (self.SerialInterface != None and self.SerialInterface.is_open and self.SerialInterface.in_waiting >= 0):				
				buf = ''
				try:
					data = self.SerialInterface.read()
				except:
					continue
				while (data != "\n" and self.runSerialThread):
					buf += data
					try:
						data = self.SerialInterface.read()
					except:
						continue
				
				try:
					point = struct.unpack('f', buf)[0]
					self.pointsToAdd.append(point)
				except:
					print buf
		self.serialThreadExit = True
	
	def OnGraphUpdateTimer(self, event):
		if (self.SerialInterface != None and self.SerialInterface.is_open and self.SerialInterface.in_waiting >= 1000):
			print 'Overload:', self.SerialInterface.in_waiting
	
		while(len(self.pointsToAdd) > 0):
			self.AddPoint(self.pointsToAdd.pop())
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
	
	def OnBttnStartStopStreamClicked(self, event):
		if (self.SerialInterface == None or not self.SerialInterface.is_open):
			return
		if (self.streamingData):
			self.SerialInterface.write(struct.pack('B', 3))
			self.Bttn_StartStopStream.SetLabel('Start Streaming')
			self.streamingData = False
		else:
			self.SerialInterface.write(struct.pack('B', 2))
			self.Bttn_StartStopStream.SetLabel('Stop Streaming')
			self.streamingData = True
		
	
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
				
				self.SerialInterface.write(struct.pack('B', 4)) # send connect signal
				self.SerialInterface.flush()
				
				self.SerialInterface.write(struct.pack('B', 0))
				self.SerialInterface.write('123456789\nbbbbbbbbbbb\ncccccc\n')
				self.SerialInterface.flush()
				
				
			else:
				print 'Serial connection to ' + activeText + ' failed!'
		elif (self.SerialInterface != None and self.SerialInterface.is_open): # Disconnect from a device
			self.SerialInterface.write(struct.pack('B', 5)) # send disconnect signal
			self.SerialInterface.flush()
		
			self.SerialInterface.close()
			if (not self.SerialInterface.is_open):
				self.Bttn_ConnectDisconnect.SetLabel('Connect')
				self.Img_Connected.SetBitmap(self.StaticBitmapDisconnected)
				self.streamingData = False
				self.Bttn_StartStopStream.SetLabel('Start Streaming')
			else:
				print 'Failed to disconnect from serial device!'
				
	def OnLoadBttnClicked(self, event):
		if (self.SerialInterface == None or not self.SerialInterface.is_open):
			return
		
		dataStream = []
		byteStream = ''
		
		self.SerialInterface.write(struct.pack('B', 1))
		
		dataStream.append(['B', self.choice_pacingState.GetSelection()]) # pacingState
		dataStream.append(['B', self.choice_pacingMode.GetSelection()]) # pacingMode
		dataStream.append(['B', self.choice_hysteresis.GetSelection()]) # hysteresis
		
		dataStream.append(['H', self.spinctrl_hysteresisInterval.GetValue()]) # hysteresisInterval
		dataStream.append(['<f', self.spinctrl_vPaceAmp.GetValue()]) # vPaceAmp
		dataStream.append(['H', self.spinctrl_vPaceWidth_10x.GetValue()]) # vPaceWidth_10x
		dataStream.append(['H', self.spinctrl_VRP.GetValue()]) # VRP
		dataStream.append(['B', self.spinctrl_BaseHeartRate.GetValue()]) # Base heart rate
		dataStream.append(['B', self.spinctrl_MaxHeartRate.GetValue()]) # Max heart rate
		
		dataStream.append(['B', 0]); # checksum
		
		for i in dataStream:
			byteStream += struct.pack(i[0], i[1])
		
		print self.SerialInterface.write(byteStream), ':', repr(byteStream)
		for b in byteStream[6:10]:
			print bin(int(binascii.hexlify(b), 16))
		self.SerialInterface.flush()
		
	def OnWindowClose(self, event):
		self.runSerialThread = False
		print 'Waiting for serial thread to die'
		while (not self.serialThreadExit):
			pass
		self.timer.Stop()
		self.Destroy()

if (__name__ == '__main__'):
	app = wx.App(False) 
	frame = pacemakerInterfaceMainFrame(None) 
	serialHandle = frame.serialFunction()
	frame.Show(True)
	
	app.MainLoop() 
	