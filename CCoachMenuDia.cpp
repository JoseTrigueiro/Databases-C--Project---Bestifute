// CCoachMenuDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CCoachMenuDia.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "SearchPlayer.h"
#include "REQUEST.h"


// CCoachMenuDia dialog

IMPLEMENT_DYNAMIC(CCoachMenuDia, CDialogEx)

CCoachMenuDia::CCoachMenuDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COACHMENUDIALOG, pParent)
	, wm_output(_T(""))
{

}

CCoachMenuDia::~CCoachMenuDia()
{
}

void CCoachMenuDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WELCOMEMESSAGE, wm_output);
}

// CCoachMenuDia message handlers

BOOL CCoachMenuDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateData(TRUE);
	wm_output = CString("Welcome ") + CoachName;
	UpdateData(FALSE);

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


BEGIN_MESSAGE_MAP(CCoachMenuDia, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCoachMenuDia::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCoachMenuDia::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCoachMenuDia message handlers


void CCoachMenuDia::OnBnClickedButton1()
{
	SearchPlayer SearchPlayerWindow;
	SearchPlayerWindow.DoModal();
}


void CCoachMenuDia::OnBnClickedButton2()
{
	REQUEST RequestWindow;
	RequestWindow.DoModal();
}
