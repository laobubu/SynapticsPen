// SynapticsPen.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SynapticsPen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSynapticsPenApp

BEGIN_MESSAGE_MAP(CSynapticsPenApp, CWinApp)
	//{{AFX_MSG_MAP(CSynapticsPenApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSynapticsPenApp construction

CSynapticsPenApp::CSynapticsPenApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSynapticsPenApp object

CSynapticsPenApp theApp;

/////////////////////////////
// Console

#ifdef _DEBUG
#include   <io.h>
#include   <fcntl.h>
#include   <io.h>
#include   <fcntl.h>
void OpenConsole()
{
	AllocConsole();
	HANDLE handle   =   GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt   =   _open_osfhandle((long)handle,_O_TEXT);
	FILE   *   hf   =   _fdopen(   hCrt,   "w"   );
	*stdout   =   *hf;
}
#endif


/////////////////////////////////////////////////////////////////////////////
// CSynapticsPenApp initialization

BOOL CSynapticsPenApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
#ifdef _DEBUG
	OpenConsole();
#endif
	HRESULT hRes = CoInitialize(0);
    if (hRes && hRes != S_FALSE)
      return false; // Error other than already initialized on thread.
	long lHandle = -1;
	if (CoCreateInstance(_uuidof(SynAPI), 0, 
		CLSCTX_INPROC_SERVER, _uuidof(ISynAPI), (void **) &pAPI) ||
		pAPI->Initialize() ||
	    pAPI->FindDevice(SE_ConnectionAny, SE_DeviceTouchPad, &lHandle) || 
	    pAPI->CreateDevice(lHandle, &pDev))
	{
		AfxMessageBox(IDS_CANNOT_LOADAPI,16);
		return false; // Couldn't initialize properly.
	}

	pDev->SetSynchronousNotification(this);
	
    pDev->GetProperty(SP_XLoSensor, &pRegion.left);
    pDev->GetProperty(SP_XHiSensor, &pRegion.right);
    pDev->GetProperty(SP_YLoSensor, &pRegion.bottom);
    pDev->GetProperty(SP_YHiSensor, &pRegion.top);


	dlg = new CSynapticsPenDlg();
	m_pMainWnd = dlg;
	int nResponse = dlg->DoModal();
	//if (nResponse == IDOK);
	
	//pDev->SetProperty(SP_DisableState, 0);
	pDev->Unacquire();

	CoUninitialize();
	return FALSE;
}

HRESULT STDMETHODCALLTYPE CSynapticsPenApp::OnSynDevicePacket(long lSequence) {
    pDev->LoadPacket(m_Packet);
	dlg->updatePosition(&m_Packet);

	//printf("p %d\n",m_Packet.ZRaw());

	/*
    PacketData sPacket(&m_Packet);

    m_Undrawn.Add(sPacket);
    InvalidateGraphArea();*/

    return 0;
}