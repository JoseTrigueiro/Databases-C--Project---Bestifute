#pragma once


// CAgentLoginDia dialog

class CAgentLoginDia : public CDialogEx
{
	DECLARE_DYNAMIC(CAgentLoginDia)

public:
	CAgentLoginDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAgentLoginDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AGENTDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLogin();
	CString AgentUsername;
	CString AgentPassword;
};
