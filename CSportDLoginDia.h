#pragma once


// CSportDLoginDia dialog

class CSportDLoginDia : public CDialogEx
{
	DECLARE_DYNAMIC(CSportDLoginDia)

public:
	CSportDLoginDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSportDLoginDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPORTDLOGDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString SportDUsername;
	CString SportDPassword;
	afx_msg void OnBnClickedLogin();
};
