#pragma once


// CScoutDia dialog

class CScoutLoginDia : public CDialogEx
{
	DECLARE_DYNAMIC(CScoutLoginDia)

public:
	CScoutLoginDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CScoutLoginDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCOUTLOGDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString ScoutUsername;
	CString ScoutPassword;
	afx_msg void OnBnClickedLogin();
};
