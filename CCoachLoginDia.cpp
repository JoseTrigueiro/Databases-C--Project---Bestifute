// CCoachLoginDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CCoachLoginDia.h"
#include "CCoachMenuDia.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "myconnectorclassDB.h"
#include <vector>

CString CoachName;

// CCoachLoginDia dialog

IMPLEMENT_DYNAMIC(CCoachLoginDia, CDialogEx)

CCoachLoginDia::CCoachLoginDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COACHLOGDIALOG, pParent)
	, CoachUsername(_T(""))
	, CoachPassword(_T(""))
{

}

CCoachLoginDia::~CCoachLoginDia()
{
}

void CCoachLoginDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, CoachUsername);
	DDX_Text(pDX, IDC_PASSWORD, CoachPassword);
}


BEGIN_MESSAGE_MAP(CCoachLoginDia, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN, &CCoachLoginDia::OnBnClickedLogin)
END_MESSAGE_MAP()


// CCoachMenuDia message handlers

BOOL CCoachLoginDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCoachLoginDia::OnBnClickedLogin() //Log in
{
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	CString logintype;
	logintype = "coach";

	UpdateData(TRUE);
	std::vector<CString> InputedData;
	InputedData = MyConnection.CheckLogin(logintype, CoachUsername);
	UpdateData(FALSE);

	//Check if coach exists in database


	if (!InputedData.empty())
	{
		if (CoachPassword == InputedData[1])
		{
			CoachName = CoachUsername;
			SportDName = _T("");
			ScoutName = _T("");
			AgentName = _T("");
			EndDialog(0);

			CCoachMenuDia CoachMenu;
			CoachMenu.DoModal();
		}
		else
		{
			AfxMessageBox(_T("Wrong password (make sure CAPS LOCK is off)"));

			UpdateData(TRUE);
			CoachPassword.Format(_T(""));
			UpdateData(FALSE);
		}
	}
	else
	{
		AfxMessageBox(_T("Coach not found in the system"));
	}
}
