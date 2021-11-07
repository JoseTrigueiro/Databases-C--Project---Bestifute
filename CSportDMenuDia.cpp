// CSportDMenuDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CSportDMenuDia.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "SearchPlayer.h"
#include "CRefdPlayers.h"


// CSportDMenuDia dialog

IMPLEMENT_DYNAMIC(CSportDMenuDia, CDialogEx)

CSportDMenuDia::CSportDMenuDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPORTDMENUDIALOG, pParent)
	, wm_output(_T(""))
{

}

CSportDMenuDia::~CSportDMenuDia()
{
}

void CSportDMenuDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WELCOMEMESSAGE, wm_output);
}

// CSportDMenuDia message handlers

BOOL CSportDMenuDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateData(TRUE);
	wm_output = CString("Welcome ") + SportDName;
	UpdateData(FALSE);

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


BEGIN_MESSAGE_MAP(CSportDMenuDia, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSportDMenuDia::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSportDMenuDia::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSportDMenuDia message handlers


void CSportDMenuDia::OnBnClickedButton1()
{
	SearchPlayer SearchPlayerWindow;
	SearchPlayerWindow.DoModal();
}


void CSportDMenuDia::OnBnClickedButton2()
{
	CRefdPlayers RefdPlayers;
	RefdPlayers.DoModal();
}
