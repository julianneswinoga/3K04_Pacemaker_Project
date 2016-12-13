import wx
import pacemakerInterface
import wxmplot

import numpy, struct, binascii, threading, time, csv

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
		
		self.plotLength = 1000
		self.plotPointsX = []
		self.plotPointsY = []
		self.relativeX = []
		self.pointsToAdd = []
		self.axisOverscale = 0.2 # 20%
		
		sizer = self.GetSizer()
		self.canvas = wxmplot.PlotPanel(self)
		sizer.Replace(self.PlotFrame, self.canvas)
		self.Layout()
		self.canvas.plot(numpy.array([0]), numpy.array([0]), ymin=-5, ymax=10, axes_style='bottom', size=(800, 500))
		self.canvas.axesmargins = (10, 10, 10, 10)
		
		self.annotationMax = None
		self.annotationMin = None
		
		self.serialPortsAvailable = []
		self.SerialInterface = None
		self.streamingData = False
		self.runSerialThread = True
		self.serialThreadExit = False
		
		self.simulating = False
		self.simulatedData = []
		self.simulatedDataPosition = 0
		with open('simulatedECG.csv', 'rb') as csvfile:
			csvReader = csv.reader(csvfile, delimiter=' ', quotechar='|')
			for row in csvReader:
				self.simulatedData.append(float(row[0]))
		
		self.StaticBitmapDisconnected = scale_bitmap(wx.Bitmap('img/disconnected.png', wx.BITMAP_TYPE_ANY), 50, 50)
		self.StaticBitmapConnected = scale_bitmap(wx.Bitmap('img/connected.png', wx.BITMAP_TYPE_ANY), 50, 50)
		self.Img_Connected.SetBitmap(self.StaticBitmapDisconnected)
		
		self.timer = wx.Timer()
		self.timer.Bind(wx.EVT_TIMER, self.OnGraphUpdateTimer)
		self.timer.Start(100)
		self.limitTimer = wx.Timer()
		self.limitTimer.Bind(wx.EVT_TIMER, self.OnLimitUpdateTimer)
		self.limitTimer.Start(100)
	
	@threaded
	def serialFunction(self):
		while (self.runSerialThread):
			if (self.simulating):
				self.pointsToAdd.append([time.time(), self.simulatedData[self.simulatedDataPosition] + numpy.random.normal(scale=0.01)])
				if (self.simulatedDataPosition < len(self.simulatedData) - 1):
					self.simulatedDataPosition += 1
				else:
					self.simulatedDataPosition = 0
				time.sleep(0.001)
				#for i in range(1000000):
				#	pass
			else:
				if (self.SerialInterface != None and self.SerialInterface.is_open and self.SerialInterface.in_waiting >= 0):				
					buf = ''
					try:
						data = self.SerialInterface.read()
					except:
						pass
					while (data != "\n" and self.runSerialThread):
						buf += data
						try:
							data = self.SerialInterface.read()
						except:
							pass
					
					try:
						point = struct.unpack('f', buf)[0]
						self.pointsToAdd.append([time.time(), point])
					except:
						print buf
		self.serialThreadExit = True
	
	def OnLimitUpdateTimer(self, event):
		if (len(self.relativeX) > 0 and len(self.plotPointsY) > 0):
			self.canvas.set_xylims((self.relativeX[0], self.relativeX[-1] + 0.1, min(self.plotPointsY)-((max(self.plotPointsY)-min(self.plotPointsY))*self.axisOverscale), max(self.plotPointsY)+((max(self.plotPointsY)-min(self.plotPointsY))*self.axisOverscale)))
	
	def OnGraphUpdateTimer(self, event):
		if (self.SerialInterface != None and self.SerialInterface.is_open):
			self.gauge_bufferSize.SetValue(self.SerialInterface.in_waiting)
	
		while(len(self.pointsToAdd) > 0):
			time, y = self.pointsToAdd.pop(0)
			self.AddPoint(time, y)
		self.UpdateGraph()
	
	def AddPoint(self, time, y):
		if (len(self.plotPointsX) >= self.plotLength):
			self.plotPointsX = rotate(self.plotPointsX, -1)
			self.plotPointsX[-1] = time
			
			self.plotPointsY = rotate(self.plotPointsY, -1)
			self.plotPointsY[-1] = y
		else:
			self.plotPointsX.append(time)
			self.plotPointsY.append(y)
	
	def UpdateGraph(self):
		if (len(self.plotPointsX) > 0 and len(self.plotPointsY) > 0):
			currTime = time.time()
			for i, x in enumerate(self.plotPointsX):
				if (i > len(self.relativeX)-1):
					self.relativeX.append(x - currTime)
				else:
					self.relativeX[i] = x - currTime
			
			minPosition, minValue = min(enumerate(self.plotPointsY), key=lambda p: p[1])
			maxPosition, maxValue = max(enumerate(self.plotPointsY), key=lambda p: p[1])
			self.annotationMax = self.addMarker(self.annotationMax, self.relativeX[maxPosition], maxValue, 'Max', 'red')
			self.annotationMin = self.addMarker(self.annotationMin, self.relativeX[minPosition], minValue, 'Min', 'black')
			
			self.canvas.update_line(0, numpy.array(self.relativeX), numpy.array(self.plotPointsY), draw=True)
	
	def addMarker(self, marker, x, y, text, color):
		if (marker != None):
			self.canvas.axes.texts.remove(marker)
		return self.canvas.axes.annotate(text, xy=(x, y), xytext=(x+1, y), arrowprops=dict(facecolor=color, shrink=0.05))
	
	def OnScanBttnClicked(self, event):
		for i in self.serialPortsAvailable:
			self.SerialDropdown.Delete(0)
		
		self.serialPortsAvailable = serial_ports()
		print 'Serial ports scanned: ' + ', \n'.join(self.serialPortsAvailable) + '\n'
		
		for port in self.serialPortsAvailable:
			self.SerialDropdown.Append(port)
		self.SerialDropdown.SetSelection(0)
	
	def OnBttnStartStopStreamClicked(self, event):
		if (self.SerialInterface == None or not self.SerialInterface.is_open):
			if (self.checkBox_simulateData.GetValue()):
				if (self.simulating):
					self.Bttn_StartStopStream.SetLabel('Start Streaming')
					self.simulating = False
				else:
					self.Bttn_StartStopStream.SetLabel('Stop Streaming')
					self.simulating = True
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
			self.connectSerial()
		elif (self.SerialInterface != None and self.SerialInterface.is_open): # Disconnect from a device
			self.disconnectSerial()
			
	def connectSerial(self):
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
	
	def disconnectSerial(self):
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
	
	def OnSimulateDataChecked(self, event):
		if (self.checkBox_simulateData.GetValue()):
			if (self.SerialInterface != None and self.SerialInterface.is_open): # If we're connected, we need to disconnect
				self.disconnectSerial()
				
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
		self.limitTimer.Stop()
		self.Destroy()

if (__name__ == '__main__'):
	app = wx.App(False) 
	frame = pacemakerInterfaceMainFrame(None) 
	serialHandle = frame.serialFunction()
	frame.Show(True)
	
	app.MainLoop() 
	