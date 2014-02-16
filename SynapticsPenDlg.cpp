// SynapticsPenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SynapticsPen.h"
#include "SynapticsPenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CString msg;
	msg.LoadString(IDS_ABOUT);
	msg.Replace("\n","\r\n");
	((CEdit*)GetDlgItem(IDC_TXTABOUT))->SetWindowText(msg);
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSynapticsPenDlg dialog

CSynapticsPenDlg::CSynapticsPenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSynapticsPenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSynapticsPenDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	isRunning = false;
}

void CSynapticsPenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSynapticsPenDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSynapticsPenDlg, CDialog)
	//{{AFX_MSG_MAP(CSynapticsPenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNSIZER, OnBtnsizer)
	ON_BN_CLICKED(IDC_BTNSWITCH, OnBtnswitch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSynapticsPenDlg message handlers

BOOL CSynapticsPenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CWnd* pWnd = GetDlgItem(IDC_PRESSURELOG);
	pWnd->GetClientRect(&MemRect);
  
	CDC *pDC = this->GetDC();
	MemDC.CreateCompatibleDC(pDC);
	MemBitmap.CreateCompatibleBitmap(pDC,MemRect.Width(),MemRect.Height());
	MemDC.SelectObject(MemBitmap);
	MemDC.FillSolidRect(0,0,MemRect.Width(),MemRect.Height(),RGB(0,0,0));

	SetWindowPos(&wndTopMost,0,0,0,0,3);
	
	printf("rect : %d,%d,%d,%d",sizer.rect.left,sizer.rect.top,sizer.rect.Width(),sizer.rect.Height());
	printf("\ntouch: %d,%d,%d,%d",pRegion.left,pRegion.top,pRegion.right,pRegion.bottom);
	printf("\ntouch: %d x %d",pRegion.Width(),pRegion.Height());
	sizer.rect.right = sizer.rect.left + ((-pRegion.Width()) * sizer.rect.Height() / pRegion.Height());

	OnBtnsizer();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSynapticsPenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSynapticsPenDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		
		CClientDC pDC(this);
		pDC.BitBlt(0,0,MemRect.Width(),MemRect.Height(),&MemDC,0,0,SRCCOPY); 
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSynapticsPenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSynapticsPenDlg::OnBtnsizer() 
{
	sizer.DoModal();
}

void CSynapticsPenDlg::OnBtnswitch() 
{
	isRunning =	IsDlgButtonChecked(IDC_BTNSWITCH)==TRUE;
	if (isRunning) 
		pDev->Acquire(0);
	else
		pDev->Unacquire();
}

void CSynapticsPenDlg::updatePosition(SynPacket *p)
{
	static bool leftDown;
	CEdit  *t = (CEdit *)GetDlgItem(IDC_TXTPOS);
	if (!t) return;
	CString cc;
	cc.Format("%u\t%u\t%u",p->XRaw(),p->YRaw(),p->ZRaw());
	t->SetWindowText(cc);

	/*
	MemDC.BitBlt(0,0,MemRect.Width()-2,MemRect.Height(),&MemDC,2,0,SRCCOPY);
	MemDC.FillSolidRect(MemRect.Width()-2,0,2,MemRect.Height(),RGB(0,0,0));

	CPen cp(PS_SOLID,2,RGB(0,255,255));
	MemDC.SelectObject(cp);

	MemDC.MoveTo(MemRect.Width(),p->ZRaw());
	MemDC.LineTo(MemRect.Width(),p->ZRaw()+1);

	CClientDC pDC(this);
	pDC.BitBlt(0,0,MemRect.Width(),MemRect.Height(),&MemDC,0,0,SRCCOPY); 

	InvalidateRect(&MemRect);
	*/
	if (isRunning) {
		if (p->ZRaw()) {
			int x,y;
			x = (p->XRaw() - pRegion.left) * sizer.rect.Width() / pRegion.Width() + sizer.rect.left;
			y = (p->YRaw() - pRegion.top) * sizer.rect.Height() / pRegion.Height() + sizer.rect.top;
			SetCursorPos(x,y);
		}
		
		long k = p->ButtonState();
		bool ll = (k & SF_ButtonLeft)==SF_ButtonLeft;
		if (IsDlgButtonChecked(IDC_CHKTOUCH)) {
			ll |= p->ZRaw()>15;
		}

		if (ll) {
			if (!leftDown) {
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				leftDown = true;
			}
		} else {
			if (leftDown) {
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				leftDown = false;
			}
		}
	}
}

CSynapticsPenDlg::~CSynapticsPenDlg()
{
	MemBitmap.DeleteObject();  
	MemDC.DeleteDC();
}
