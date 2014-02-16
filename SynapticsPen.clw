; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSizer
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SynapticsPen.h"

ClassCount=4
Class1=CSynapticsPenApp
Class2=CSynapticsPenDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_SYNAPTICSPEN_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CSizer
Resource4=IDD_SIZER

[CLS:CSynapticsPenApp]
Type=0
HeaderFile=SynapticsPen.h
ImplementationFile=SynapticsPen.cpp
Filter=N

[CLS:CSynapticsPenDlg]
Type=0
HeaderFile=SynapticsPenDlg.h
ImplementationFile=SynapticsPenDlg.cpp
Filter=D
LastObject=CSynapticsPenDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SynapticsPenDlg.h
ImplementationFile=SynapticsPenDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_TXTABOUT,edit,1352730628

[DLG:IDD_SYNAPTICSPEN_DIALOG]
Type=1
Class=CSynapticsPenDlg
ControlCount=6
Control1=IDC_TXTPOS,edit,1350568064
Control2=IDC_PRESSURELOG,static,1342177287
Control3=IDC_BTNSWITCH,button,1342246915
Control4=IDC_BTNSIZER,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_CHKTOUCH,button,1342177283

[DLG:IDD_SIZER]
Type=1
Class=CSizer
ControlCount=1
Control1=IDC_BTNFINISHED,button,1342242817

[CLS:CSizer]
Type=0
HeaderFile=Sizer.h
ImplementationFile=Sizer.cpp
BaseClass=CDialog
Filter=D
LastObject=CSizer
VirtualFilter=dWC

