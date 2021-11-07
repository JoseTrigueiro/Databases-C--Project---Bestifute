// CAgentLoginDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CAgentLoginDia.h"
#include "CAgentMenuDia.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"
#include <vector>
#include "Flags.h"

CString AgentName;

// CAgentLoginDia dialog

IMPLEMENT_DYNAMIC(CAgentLoginDia, CDialogEx)

CAgentLoginDia::CAgentLoginDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AGENTDIALOG, pParent)
	, AgentUsername(_T(""))
	, AgentPassword(_T(""))
{

}

CAgentLoginDia::~CAgentLoginDia()
{
}

void CAgentLoginDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, AgentUsername);
	DDX_Text(pDX, IDC_PASSWORD, AgentPassword);
}


// CCoachMenuDia message handlers

BOOL CAgentLoginDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


BEGIN_MESSAGE_MAP(CAgentLoginDia, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN, &CAgentLoginDia::OnBnClickedLogin)
END_MESSAGE_MAP()


// CAgentLoginDia message handlers


void CAgentLoginDia::OnBnClickedLogin()
{
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	CString logintype;
	logintype = "agent";

	UpdateData(TRUE);
	std::vector<CString> InputedData;
	InputedData = MyConnection.CheckLogin(logintype, AgentUsername);
	UpdateData(FALSE);

	if (!InputedData.empty())
	{
		if (AgentPassword == InputedData[1])
		{
			AgentName = AgentUsername;
			SportDName = _T("");
			ScoutName = _T("");
			CoachName = _T("");


			EndDialog(0);

			CAgentMenuDia AgentMenu;
			AgentMenu.DoModal();
		}
		else
		{
			AfxMessageBox(_T("Wrong password (make sure CAPS LOCK is off)"));

			UpdateData(TRUE);
			AgentPassword.Format(_T(""));
			UpdateData(FALSE);
		}
	}
	else
	{
		AfxMessageBox(_T("Agent not found in the system"));
	}
}
