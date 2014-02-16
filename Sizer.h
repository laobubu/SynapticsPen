#if !defined(AFX_SIZER_H__88DDB5CA_6FC8_4620_8FC5_26411722E5EA__INCLUDED_)
#define AFX_SIZER_H__88DDB5CA_6FC8_4620_8FC5_26411722E5EA__INCLUDED_

#pragma once

#define LWA_COLORKEY 0x00000001
#define WS_EX_LAYERED 0x00080000
#define LWA_ALPHA 2

/////////////////////////////////////////////////////////////////////////////
// CSizer dialog

class CSizer : public CDialog
{
// Construction
public:

	CRect rect;
	BOOL OnInitDialog();
	CSizer(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSizer)
	enum { IDD = IDD_SIZER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSizer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:

	// Generated message map functions
	//{{AFX_MSG(CSizer)
	afx_msg void OnBtnfinished();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIZER_H__88DDB5CA_6FC8_4620_8FC5_26411722E5EA__INCLUDED_)
