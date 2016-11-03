# -*- coding: utf-8 -*- 

###########################################################################
## Python code generated with wxFormBuilder (version Jun 17 2015)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import wx
import wx.xrc

###########################################################################
## Class MainFrame
###########################################################################

class MainFrame ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = wx.EmptyString, pos = wx.DefaultPosition, size = wx.Size( 1000,500 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL, name = u"Pacemaker Interface" )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		gSizer1 = wx.GridSizer( 3, 1, 0, 0 )
		
		gSizer4 = wx.GridSizer( 0, 2, 0, 0 )
		
		gSizer3 = wx.GridSizer( 0, 3, 0, 0 )
		
		SerialDropdownChoices = []
		self.SerialDropdown = wx.Choice( self, wx.ID_ANY, wx.DefaultPosition, wx.Size( 200,-1 ), SerialDropdownChoices, 0 )
		self.SerialDropdown.SetSelection( 0 )
		gSizer3.Add( self.SerialDropdown, 0, wx.ALL, 5 )
		
		self.Bttn_Scan = wx.Button( self, wx.ID_ANY, u"Scan Ports", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer3.Add( self.Bttn_Scan, 0, wx.ALL, 5 )
		
		self.Bttn_ConnectDisconnect = wx.Button( self, wx.ID_ANY, u"Connect", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer3.Add( self.Bttn_ConnectDisconnect, 0, wx.ALL, 5 )
		
		
		gSizer4.Add( gSizer3, 1, 0, 5 )
		
		self.Img_Connected = wx.StaticBitmap( self, wx.ID_ANY, wx.NullBitmap, wx.DefaultPosition, wx.Size( -1,-1 ), 0 )
		gSizer4.Add( self.Img_Connected, 0, wx.ALL, 5 )
		
		
		gSizer1.Add( gSizer4, 1, 0, 5 )
		
		self.PlotFrame = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		self.PlotFrame.SetForegroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_WINDOW ) )
		self.PlotFrame.SetBackgroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_WINDOW ) )
		
		gSizer1.Add( self.PlotFrame, 1, wx.ALL|wx.EXPAND, 5 )
		
		gSizer5 = wx.GridSizer( 4, 4, 0, 0 )
		
		gSizer51 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText171 = wx.StaticText( self, wx.ID_ANY, u"Wait Time", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText171.Wrap( -1 )
		gSizer51.Add( self.m_staticText171, 0, wx.ALL, 5 )
		
		self.ParamWait = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer51.Add( self.ParamWait, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer51, 1, wx.EXPAND, 5 )
		
		gSizer511 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1711 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1711.Wrap( -1 )
		gSizer511.Add( self.m_staticText1711, 0, wx.ALL, 5 )
		
		self.m_spinCtrl11 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer511.Add( self.m_spinCtrl11, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer511, 1, wx.EXPAND, 5 )
		
		gSizer512 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1712 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1712.Wrap( -1 )
		gSizer512.Add( self.m_staticText1712, 0, wx.ALL, 5 )
		
		self.m_spinCtrl12 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer512.Add( self.m_spinCtrl12, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer512, 1, wx.EXPAND, 5 )
		
		gSizer513 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1713 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1713.Wrap( -1 )
		gSizer513.Add( self.m_staticText1713, 0, wx.ALL, 5 )
		
		self.m_spinCtrl13 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer513.Add( self.m_spinCtrl13, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer513, 1, wx.EXPAND, 5 )
		
		gSizer514 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1714 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1714.Wrap( -1 )
		gSizer514.Add( self.m_staticText1714, 0, wx.ALL, 5 )
		
		self.m_spinCtrl14 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer514.Add( self.m_spinCtrl14, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer514, 1, wx.EXPAND, 5 )
		
		gSizer515 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1715 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1715.Wrap( -1 )
		gSizer515.Add( self.m_staticText1715, 0, wx.ALL, 5 )
		
		self.m_spinCtrl15 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer515.Add( self.m_spinCtrl15, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer515, 1, wx.EXPAND, 5 )
		
		gSizer516 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1716 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1716.Wrap( -1 )
		gSizer516.Add( self.m_staticText1716, 0, wx.ALL, 5 )
		
		self.m_spinCtrl16 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer516.Add( self.m_spinCtrl16, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer516, 1, wx.EXPAND, 5 )
		
		gSizer517 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1717 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1717.Wrap( -1 )
		gSizer517.Add( self.m_staticText1717, 0, wx.ALL, 5 )
		
		self.m_spinCtrl17 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer517.Add( self.m_spinCtrl17, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer517, 1, wx.EXPAND, 5 )
		
		gSizer518 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1718 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1718.Wrap( -1 )
		gSizer518.Add( self.m_staticText1718, 0, wx.ALL, 5 )
		
		self.m_spinCtrl18 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer518.Add( self.m_spinCtrl18, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer518, 1, wx.EXPAND, 5 )
		
		gSizer519 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_staticText1719 = wx.StaticText( self, wx.ID_ANY, u"Parameter", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1719.Wrap( -1 )
		gSizer519.Add( self.m_staticText1719, 0, wx.ALL, 5 )
		
		self.m_spinCtrl19 = wx.SpinCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.SP_ARROW_KEYS, 0, 10, 0 )
		gSizer519.Add( self.m_spinCtrl19, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer5.Add( gSizer519, 1, wx.EXPAND, 5 )
		
		self.Btn_LoadParams = wx.Button( self, wx.ID_ANY, u"Load onto Device", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.Btn_LoadParams, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		gSizer1.Add( gSizer5, 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( gSizer1 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.Bind( wx.EVT_CLOSE, self.OnWindowClose )
		self.Bttn_Scan.Bind( wx.EVT_BUTTON, self.OnScanBttnClicked )
		self.Bttn_ConnectDisconnect.Bind( wx.EVT_BUTTON, self.OnConnectBttnClicked )
		self.Btn_LoadParams.Bind( wx.EVT_BUTTON, self.OnLoadBttnClicked )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnWindowClose( self, event ):
		event.Skip()
	
	def OnScanBttnClicked( self, event ):
		event.Skip()
	
	def OnConnectBttnClicked( self, event ):
		event.Skip()
	
	def OnLoadBttnClicked( self, event ):
		event.Skip()
	

