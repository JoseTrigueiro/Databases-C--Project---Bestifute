#pragma once


// CAgentMenuDia dialog

class CAgentMenuDia : public CDialogEx
{
	DECLARE_DYNAMIC(CAgentMenuDia)

public:
	CAgentMenuDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAgentMenuDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AGENTMENUDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString wm_output;
	afx_msg void OnBnClickedCreatep();
	afx_msg void OnBnClickedButton2();
};
