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
		
		self.Img_Connected = wx.StaticBitmap( self, wx.ID_ANY, wx.Bitmap( u"img/disconnected.png", wx.BITMAP_TYPE_ANY ), wx.DefaultPosition, wx.Size( -1,-1 ), 0 )
		gSizer4.Add( self.Img_Connected, 0, wx.ALL, 5 )
		
		
		gSizer1.Add( gSizer4, 1, 0, 5 )
		
		self.PlotFrame = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		gSizer1.Add( self.PlotFrame, 1, wx.EXPAND |wx.ALL, 5 )
		
		gSizer5 = wx.GridSizer( 4, 4, 0, 0 )
		
		self.m_staticText4 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText4.Wrap( -1 )
		gSizer5.Add( self.m_staticText4, 0, wx.ALL, 5 )
		
		self.m_staticText5 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText5.Wrap( -1 )
		gSizer5.Add( self.m_staticText5, 0, wx.ALL, 5 )
		
		self.m_staticText6 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText6.Wrap( -1 )
		gSizer5.Add( self.m_staticText6, 0, wx.ALL, 5 )
		
		self.m_staticText7 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText7.Wrap( -1 )
		gSizer5.Add( self.m_staticText7, 0, wx.ALL, 5 )
		
		self.m_staticText8 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText8.Wrap( -1 )
		gSizer5.Add( self.m_staticText8, 0, wx.ALL, 5 )
		
		self.m_staticText9 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText9.Wrap( -1 )
		gSizer5.Add( self.m_staticText9, 0, wx.ALL, 5 )
		
		self.m_staticText10 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText10.Wrap( -1 )
		gSizer5.Add( self.m_staticText10, 0, wx.ALL, 5 )
		
		self.m_staticText11 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText11.Wrap( -1 )
		gSizer5.Add( self.m_staticText11, 0, wx.ALL, 5 )
		
		self.m_staticText12 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText12.Wrap( -1 )
		gSizer5.Add( self.m_staticText12, 0, wx.ALL, 5 )
		
		self.m_staticText13 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText13.Wrap( -1 )
		gSizer5.Add( self.m_staticText13, 0, wx.ALL, 5 )
		
		self.m_staticText14 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText14.Wrap( -1 )
		gSizer5.Add( self.m_staticText14, 0, wx.ALL, 5 )
		
		self.m_staticText15 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText15.Wrap( -1 )
		gSizer5.Add( self.m_staticText15, 0, wx.ALL, 5 )
		
		self.m_staticText16 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText16.Wrap( -1 )
		gSizer5.Add( self.m_staticText16, 0, wx.ALL, 5 )
		
		self.m_staticText17 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText17.Wrap( -1 )
		gSizer5.Add( self.m_staticText17, 0, wx.ALL, 5 )
		
		self.m_staticText18 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText18.Wrap( -1 )
		gSizer5.Add( self.m_staticText18, 0, wx.ALL, 5 )
		
		self.m_staticText19 = wx.StaticText( self, wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText19.Wrap( -1 )
		gSizer5.Add( self.m_staticText19, 0, wx.ALL, 5 )
		
		
		gSizer1.Add( gSizer5, 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( gSizer1 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.Bttn_Scan.Bind( wx.EVT_BUTTON, self.OnScanBttnClicked )
		self.Bttn_ConnectDisconnect.Bind( wx.EVT_BUTTON, self.OnConnectBttnClicked )
		self.PlotFrame.Bind( wx.EVT_MOTION, self.OnPlotMouseover )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnScanBttnClicked( self, event ):
		event.Skip()
	
	def OnConnectBttnClicked( self, event ):
		event.Skip()
	
	def OnPlotMouseover( self, event ):
		event.Skip()
	

