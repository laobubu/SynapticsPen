// SynapticsPenDlg.h : header file
//

#if !defined(AFX_SYNAPTICSPENDLG_H__BBC709B2_19B8_413B_AA3B_2DAAAF95CFCE__INCLUDED_)
#define AFX_SYNAPTICSPENDLG_H__BBC709B2_19B8_413B_AA3B_2DAAAF95CFCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Sizer.h"

/////////////////////////////////////////////////////////////////////////////
// CSynapticsPenDlg dialog

class CSynapticsPenDlg : public CDialog
{
// Construction
public:
	~CSynapticsPenDlg();
	void updatePosition(SynPacket *p);
	CSynapticsPenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSynapticsPenDlg)
	enum { IDD = IDD_SYNAPTICSPEN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSynapticsPenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	CSizer sizer;
	bool isRunning;
protected:
	HICON m_hIcon;
	
	//压力统计图
	CDC MemDC; //首先定义一个显示设备对象  
	CBitmap MemBitmap;//定义一个位图对象 
	CRect MemRect;

	// Generated message map functions
	//{{AFX_MSG(CSynapticsPenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnsizer();
	afx_msg void OnBtnswitch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYNAPTICSPENDLG_H__BBC709B2_19B8_413B_AA3B_2DAAAF95CFCE__INCLUDED_)
