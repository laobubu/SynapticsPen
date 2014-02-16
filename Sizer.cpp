// Sizer.cpp : implementation file
//

#include "stdafx.h"
#include "SynapticsPen.h"
#include "Sizer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSizer dialog


CSizer::CSizer(CWnd* pParent /*=NULL*/)
	: CDialog(CSizer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSizer)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	rect.left = 100;
	rect.top = 100;
	rect.right = 400;
	rect.bottom = 400;
}


void CSizer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSizer)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSizer, CDialog)
	//{{AFX_MSG_MAP(CSizer)
	ON_BN_CLICKED(IDC_BTNFINISHED, OnBtnfinished)
	ON_WM_LBUTTONDOWN()
	ON_WM_CANCELMODE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSizer message handlers

void CSizer::OnBtnfinished() 
{
	GetWindowRect(&rect);
	this->EndDialog(1);
}

void CSizer::OnLButtonDown(UINT nFlags, CPoint point) 
{
	ReleaseCapture();
	SendMessage(WM_SYSCOMMAND, SC_MOVE + HTCAPTION,0);
	//CDialog::OnLButtonDown(nFlags, point);
}

BOOL CSizer::OnInitDialog()
{
	BOOL rtn = CDialog::OnInitDialog();
	
	HICON m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CString m_title;
	m_title.LoadString(IDS_SIZER_TITLE);
	this->SetIcon(m_hIcon,TRUE);
	this->SetWindowText(m_title);
	SetWindowPos(&wndTopMost,rect.left,rect.top,rect.Width(),rect.Height(),0);
	
	//transparent
	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,GetWindowLong(this-> GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
	//MessageBox("DoDataExchange");
	HMODULE hUser32 = GetModuleHandle("user32.dll");
	if (hUser32) {
		typedef BOOL (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD);
		MYFUNC SetLayeredWindowAttributes = NULL;
		SetLayeredWindowAttributes = (MYFUNC)GetProcAddress(hUser32, "SetLayeredWindowAttributes");
		SetLayeredWindowAttributes(GetSafeHwnd(), 0, 150, LWA_ALPHA);
		FreeLibrary(hUser32);
	}
	return rtn;
}

void CSizer::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CPen p(PS_SOLID,3,RGB(0,0,0));
	dc.SelectObject(p);
	dc.MoveTo(0,0);
	CRect r;
	GetWindowRect(r);
	dc.LineTo(-pRegion.Width() * r.Height() / pRegion.Height(),r.Height());
	dc.LineTo(r.Width(),-pRegion.Height() * r.Width() / pRegion.Width());
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
