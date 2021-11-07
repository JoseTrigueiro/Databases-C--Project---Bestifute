#pragma once


// CCoachLoginDia dialog

class CCoachLoginDia : public CDialogEx
{
	DECLARE_DYNAMIC(CCoachLoginDia)

public:
	CCoachLoginDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCoachLoginDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COACHLOGDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString CoachUsername;
	CString CoachPassword;
	afx_msg void OnBnClickedLogin();
};
