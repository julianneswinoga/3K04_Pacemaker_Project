# -*- coding: utf-8 -*- 

###########################################################################
## Python code generated with wxFormBuilder (version Jun 17 2015)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import wx
import wx.xrc
import wx.grid

###########################################################################
## Class MainFrame
###########################################################################

class MainFrame ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Pacemaker Interface", pos = wx.DefaultPosition, size = wx.Size( 1500,600 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL, name = u"Pacemaker Interface" )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		gSizer1 = wx.GridSizer( 4, 1, 0, 0 )
		
		gSizer4 = wx.GridSizer( 1, 7, 0, 0 )
		
		SerialDropdownChoices = []
		self.SerialDropdown = wx.Choice( self, wx.ID_ANY, wx.DefaultPosition, wx.Size( -1,-1 ), SerialDropdownChoices, 0 )
		self.SerialDropdown.SetSelection( 0 )
		gSizer4.Add( self.SerialDropdown, 0, wx.ALIGN_TOP|wx.ALL|wx.ALIGN_CENTER_HORIZONTAL, 5 )
		
		self.Bttn_Scan = wx.Button( self, wx.ID_ANY, u"Scan Ports", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer4.Add( self.Bttn_Scan, 0, wx.ALL, 5 )
		
		self.Bttn_ConnectDisconnect = wx.Button( self, wx.ID_ANY, u"Connect", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer4.Add( self.Bttn_ConnectDisconnect, 0, wx.ALIGN_LEFT|wx.ALL, 5 )
		
		self.Img_Connected = wx.StaticBitmap( self, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.Size( -1,-1 ), 0 )
		gSizer4.Add( self.Img_Connected, 0, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL, 5 )
		
		self.Bttn_StartStopStream = wx.Button( self, wx.ID_ANY, u"Start Streaming", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer4.Add( self.Bttn_StartStopStream, 0, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL, 5 )
		
		self.checkBox_simulateData = wx.CheckBox( self, wx.ID_ANY, u"Simulate Data", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer4.Add( self.checkBox_simulateData, 0, wx.ALL, 5 )
		
		self.gauge_bufferSize = wx.Gauge( self, wx.ID_ANY, 4096, wx.DefaultPosition, wx.Size( -1,-1 ), wx.GA_HORIZONTAL )
		self.gauge_bufferSize.SetValue( 0 ) 
		self.gauge_bufferSize.SetMaxSize( wx.Size( -1,50 ) )
		
		gSizer4.Add( self.gauge_bufferSize, 0, wx.ALL|wx.ALIGN_RIGHT, 5 )
		
		
		gSizer1.Add( gSizer4, 0, wx.ALIGN_CENTER_HORIZONTAL|wx.EXPAND|wx.ALL, 5 )
		
		self.PlotFrame = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.Size( -1,-1 ), wx.TAB_TRAVERSAL )
		self.PlotFrame.SetForegroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_WINDOW ) )
		self.PlotFrame.SetBackgroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_WINDOW ) )
		
		gSizer1.Add( self.PlotFrame, 0, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		gSizer5 = wx.GridSizer( 3, 4, 0, 0 )
		
		gSizer511 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1711 = wx.StaticText( self, wx.ID_ANY, u"Pacing State", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1711.Wrap( -1 )
		gSizer511.Add( self.m_staticText1711, 0, wx.ALL, 5 )
		
		choice_pacingStateChoices = [ u"PERMANENT", u"TEMPORARY", u"PACE_NOW", u"MAGNET", u"POWER_ON_RESET" ]
		self.choice_pacingState = wx.Choice( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, choice_pacingStateChoices, 0 )
		self.choice_pacingState.SetSelection( 0 )
		gSizer511.Add( self.choice_pacingState, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer511, 1, wx.EXPAND, 5 )
		
		gSizer512 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1712 = wx.StaticText( self, wx.ID_ANY, u"Pacing Mode", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1712.Wrap( -1 )
		gSizer512.Add( self.m_staticText1712, 0, wx.ALL, 5 )
		
		choice_pacingModeChoices = [ u"OFF", u" AAT", u" VVT", u" AOO", u" AAI", u"VOO", u"VVI", u"VDD", u"DOO", u"DDI", u"DDD", u"AOOR", u"AAIR", u"VOOR", u"VVIR", u"VDDR", u"DOOR", u"DDIR", u"DDDR" ]
		self.choice_pacingMode = wx.Choice( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, choice_pacingModeChoices, 0 )
		self.choice_pacingMode.SetSelection( 5 )
		gSizer512.Add( self.choice_pacingMode, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer512, 1, wx.EXPAND, 5 )
		
		gSizer513 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1713 = wx.StaticText( self, wx.ID_ANY, u"Hysteresis", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1713.Wrap( -1 )
		gSizer513.Add( self.m_staticText1713, 0, wx.ALL, 5 )
		
		choice_hysteresisChoices = [ u"No", u"Yes" ]
		self.choice_hysteresis = wx.Choice( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, choice_hysteresisChoices, 0 )
		self.choice_hysteresis.SetSelection( 0 )
		gSizer513.Add( self.choice_hysteresis, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer513, 1, wx.EXPAND, 5 )
		
		gSizer514 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1714 = wx.StaticText( self, wx.ID_ANY, u"Hysteresis Interval", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1714.Wrap( -1 )
		gSizer514.Add( self.m_staticText1714, 0, wx.ALL, 5 )
		
		self.spinctrl_hysteresisInterval = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10000, 0 )
		gSizer514.Add( self.spinctrl_hysteresisInterval, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer514, 1, wx.EXPAND, 5 )
		
		gSizer515 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1715 = wx.StaticText( self, wx.ID_ANY, u"Pacing Amplitude", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1715.Wrap( -1 )
		gSizer515.Add( self.m_staticText1715, 0, wx.ALL, 5 )
		
		self.spinctrl_vPaceAmp = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, -10, 10, 0 )
		gSizer515.Add( self.spinctrl_vPaceAmp, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer515, 1, wx.EXPAND, 5 )
		
		gSizer516 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1716 = wx.StaticText( self, wx.ID_ANY, u"Pace Width", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1716.Wrap( -1 )
		gSizer516.Add( self.m_staticText1716, 0, wx.ALL, 5 )
		
		self.spinctrl_vPaceWidth_10x = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 1000, 0 )
		gSizer516.Add( self.spinctrl_vPaceWidth_10x, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer516, 1, wx.EXPAND, 5 )
		
		gSizer517 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1717 = wx.StaticText( self, wx.ID_ANY, u"VRP", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1717.Wrap( -1 )
		gSizer517.Add( self.m_staticText1717, 0, wx.ALL, 5 )
		
		self.spinctrl_VRP = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer517.Add( self.spinctrl_VRP, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer517, 1, wx.EXPAND, 5 )
		
		gSizer518 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1718 = wx.StaticText( self, wx.ID_ANY, u"Base Heart Rate", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1718.Wrap( -1 )
		gSizer518.Add( self.m_staticText1718, 0, wx.ALL, 5 )
		
		self.spinctrl_BaseHeartRate = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 50, 90, 0 )
		gSizer518.Add( self.spinctrl_BaseHeartRate, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer518, 1, wx.EXPAND, 5 )
		
		gSizer519 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1719 = wx.StaticText( self, wx.ID_ANY, u"Max Heart Rate", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1719.Wrap( -1 )
		gSizer519.Add( self.m_staticText1719, 0, wx.ALL, 5 )
		
		self.spinctrl_MaxHeartRate = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 110, 175, 0 )
		gSizer519.Add( self.spinctrl_MaxHeartRate, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer519, 1, wx.EXPAND, 5 )
		
		self.m_staticText10 = wx.StaticText( self, wx.ID_ANY, u" ", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText10.Wrap( -1 )
		gSizer5.Add( self.m_staticText10, 0, wx.ALL, 5 )
		
		self.m_staticText11 = wx.StaticText( self, wx.ID_ANY, u" ", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText11.Wrap( -1 )
		gSizer5.Add( self.m_staticText11, 0, wx.ALL, 5 )
		
		self.Btn_LoadParams = wx.Button( self, wx.ID_ANY, u"Load onto Device", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.Btn_LoadParams, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer1.Add( gSizer5, 1, wx.ALIGN_CENTER_HORIZONTAL, 5 )
		
		self.m_scrolledWindow2 = wx.ScrolledWindow( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.HSCROLL|wx.VSCROLL )
		self.m_scrolledWindow2.SetScrollRate( 5, 5 )
		gSizer16 = wx.GridSizer( 1, 2, 0, 0 )
		
		self.grid_params = wx.grid.Grid( self.m_scrolledWindow2, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, 0 )
		
		# Grid
		self.grid_params.CreateGrid( 1, 2 )
		self.grid_params.EnableEditing( False )
		self.grid_params.EnableGridLines( True )
		self.grid_params.EnableDragGridSize( False )
		self.grid_params.SetMargins( 0, 0 )
		
		# Columns
		self.grid_params.SetColSize( 0, 10 )
		self.grid_params.SetColSize( 1, 10 )
		self.grid_params.EnableDragColMove( False )
		self.grid_params.EnableDragColSize( True )
		self.grid_params.SetColLabelSize( 30 )
		self.grid_params.SetColLabelValue( 0, u"Parameter" )
		self.grid_params.SetColLabelValue( 1, u"Value" )
		self.grid_params.SetColLabelAlignment( wx.ALIGN_CENTRE, wx.ALIGN_CENTRE )
		
		# Rows
		self.grid_params.AutoSizeRows()
		self.grid_params.EnableDragRowSize( True )
		self.grid_params.SetRowLabelSize( 0 )
		self.grid_params.SetRowLabelAlignment( wx.ALIGN_CENTRE, wx.ALIGN_CENTRE )
		
		# Label Appearance
		
		# Cell Defaults
		self.grid_params.SetDefaultCellAlignment( wx.ALIGN_LEFT, wx.ALIGN_TOP )
		gSizer16.Add( self.grid_params, 0, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL, 5 )
		
		self.Bttn_ReadParams = wx.Button( self.m_scrolledWindow2, wx.ID_ANY, u"Read Parameters from Pacemaker", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer16.Add( self.Bttn_ReadParams, 0, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		self.m_scrolledWindow2.SetSizer( gSizer16 )
		self.m_scrolledWindow2.Layout()
		gSizer16.Fit( self.m_scrolledWindow2 )
		gSizer1.Add( self.m_scrolledWindow2, 1, wx.EXPAND |wx.ALL, 5 )
		
		
		self.SetSizer( gSizer1 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.Bind( wx.EVT_CLOSE, self.OnWindowClose )
		self.Bttn_Scan.Bind( wx.EVT_BUTTON, self.OnScanBttnClicked )
		self.Bttn_ConnectDisconnect.Bind( wx.EVT_BUTTON, self.OnConnectBttnClicked )
		self.Bttn_StartStopStream.Bind( wx.EVT_BUTTON, self.OnBttnStartStopStreamClicked )
		self.checkBox_simulateData.Bind( wx.EVT_CHECKBOX, self.OnSimulateDataChecked )
		self.Btn_LoadParams.Bind( wx.EVT_BUTTON, self.OnLoadBttnClicked )
		self.Bttn_ReadParams.Bind( wx.EVT_BUTTON, self.OnBttnReadParamsClicked )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnWindowClose( self, event ):
		event.Skip()
	
	def OnScanBttnClicked( self, event ):
		event.Skip()
	
	def OnConnectBttnClicked( self, event ):
		event.Skip()
	
	def OnBttnStartStopStreamClicked( self, event ):
		event.Skip()
	
	def OnSimulateDataChecked( self, event ):
		event.Skip()
	
	def OnLoadBttnClicked( self, event ):
		event.Skip()
	
	def OnBttnReadParamsClicked( self, event ):
		event.Skip()
	

