// CScoutDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CScoutLoginDia.h"
#include "CScoutMenuDia.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "myconnectorclassDB.h"
#include <vector>

CString ScoutName;

// CScoutDia dialog

IMPLEMENT_DYNAMIC(CScoutLoginDia, CDialogEx)

CScoutLoginDia::CScoutLoginDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCOUTLOGDIALOG, pParent)
	, ScoutUsername(_T(""))
	, ScoutPassword(_T(""))
{

}

CScoutLoginDia::~CScoutLoginDia()
{
}

void CScoutLoginDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, ScoutUsername);
	DDX_Text(pDX, IDC_PASSWORD, ScoutPassword);
}


BEGIN_MESSAGE_MAP(CScoutLoginDia, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN, &CScoutLoginDia::OnBnClickedLogin)
END_MESSAGE_MAP()


// CScoutDia message handlers

BOOL CScoutLoginDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CScoutLoginDia::OnBnClickedLogin()
{
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	CString logintype;
	logintype = "scout";

	UpdateData(TRUE);
	std::vector<CString> InputedData;
	InputedData = MyConnection.CheckLogin(logintype, ScoutUsername);
	UpdateData(FALSE);

	if (!InputedData.empty())
	{
		if (ScoutPassword == InputedData[1])
		{
			//AfxMessageBox(_T("Login Sucsessful!"));

			//Set a flag with user ID
			ScoutName = ScoutUsername;
			CoachName = _T("");
			SportDName = _T("");
			AgentName = _T("");

			EndDialog(0);

			CScoutMenuDia ScoutMenu;
			ScoutMenu.DoModal();
		}
		else
		{
			AfxMessageBox(_T("Wrong password (make sure CAPS LOCK is off)"));

			UpdateData(TRUE);
			ScoutPassword.Format(_T(""));
			UpdateData(FALSE);
		}
	}
	else
	{
		AfxMessageBox(_T("Scout not found in the system"));
	}
}
