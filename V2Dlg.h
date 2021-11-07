
// V2Dlg.h : header file
//

#pragma once


// CV2Dlg dialog
class CV2Dlg : public CDialogEx
{
// Construction
public:
	CV2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_V2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCoachbutton();
	afx_msg void OnBnClickedSportdbutton();
	afx_msg void OnBnClickedScoutbutton();
	afx_msg void OnBnClickedAgentbutton();
};
