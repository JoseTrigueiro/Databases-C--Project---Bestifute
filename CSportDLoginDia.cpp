// CSportDLoginDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CSportDLoginDia.h"
#include "CSportDMenuDia.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "myconnectorclassDB.h"
#include <vector>

CString SportDName;

// CSportDLoginDia dialog

IMPLEMENT_DYNAMIC(CSportDLoginDia, CDialogEx)

CSportDLoginDia::CSportDLoginDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPORTDLOGDIALOG, pParent)
	, SportDUsername(_T(""))
	, SportDPassword(_T(""))
{

}

CSportDLoginDia::~CSportDLoginDia()
{
}

void CSportDLoginDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, SportDUsername);
	DDX_Text(pDX, IDC_PASSWORD, SportDPassword);
}


BEGIN_MESSAGE_MAP(CSportDLoginDia, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN, &CSportDLoginDia::OnBnClickedLogin)
END_MESSAGE_MAP()


// CSportDLoginDia message handlers

BOOL CSportDLoginDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSportDLoginDia::OnBnClickedLogin()
{
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	CString logintype;
	logintype = "sd";

	UpdateData(TRUE);
	std::vector<CString> InputedData;
	InputedData = MyConnection.CheckLogin(logintype, SportDUsername);
	UpdateData(FALSE);

	//Check if sporting director exists in database

	if (!InputedData.empty())
	{
		if (SportDPassword == InputedData[1])
		{
			//AfxMessageBox(_T("ZÉ!"));
			
			//Set a flag with user ID
			SportDName = SportDUsername;
			CoachName = _T("");
			ScoutName = _T("");
			AgentName = _T("");

			EndDialog(0);

			CSportDMenuDia SportDMenu;
			SportDMenu.DoModal();
		}
		else
		{
			AfxMessageBox(_T("Wrong password (make sure CAPS LOCK is off)"));

			UpdateData(TRUE);
			SportDPassword.Format(_T(""));
			UpdateData(FALSE);
		}
	}
	else
	{
		AfxMessageBox(_T("Sporting Director not found in the system"));
	}
}
