// SynapticsPen.h : main header file for the SYNAPTICSPEN application
//

#if !defined(AFX_SYNAPTICSPEN_H__43FEBEFD_E968_4705_A18D_99B2609E0457__INCLUDED_)
#define AFX_SYNAPTICSPEN_H__43FEBEFD_E968_4705_A18D_99B2609E0457__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "SynapticsPenDlg.h"	


/////////////////////////////////////////////////////////////////////////////
// CSynapticsPenApp:
// See SynapticsPen.cpp for the implementation of this class
//

class CSynapticsPenApp : public CWinApp, public _ISynDeviceEvents
{
public:
	CSynapticsPenApp();
	CSynapticsPenDlg *dlg;

	HRESULT STDMETHODCALLTYPE OnSynDevicePacket(long lSequence); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSynapticsPenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSynapticsPenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYNAPTICSPEN_H__43FEBEFD_E968_4705_A18D_99B2609E0457__INCLUDED_)
