#pragma once


// CScoutMenuDia dialog

class CScoutMenuDia : public CDialogEx
{
	DECLARE_DYNAMIC(CScoutMenuDia)

public:
	CScoutMenuDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CScoutMenuDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCOUTMENUDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString wm_output;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
