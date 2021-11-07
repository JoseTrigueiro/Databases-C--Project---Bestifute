#pragma once


// CCoachMenuDia dialog

class CCoachMenuDia : public CDialogEx
{
	DECLARE_DYNAMIC(CCoachMenuDia)

public:
	CCoachMenuDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCoachMenuDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COACHMENUDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString wm_output;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
