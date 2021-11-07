#pragma once


// CSportDMenuDia dialog

class CSportDMenuDia : public CDialogEx
{
	DECLARE_DYNAMIC(CSportDMenuDia)

public:
	CSportDMenuDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSportDMenuDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPORTDMENUDIALOG };
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
