// CScoutMenuDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CScoutMenuDia.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "AddNewPlayerDia.h"
#include "CEditPlayer.h"
#include "ReqstPlayers.h"


// CScoutMenuDia dialog

IMPLEMENT_DYNAMIC(CScoutMenuDia, CDialogEx)

CScoutMenuDia::CScoutMenuDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCOUTMENUDIALOG, pParent)
	, wm_output(_T(""))
{

}

CScoutMenuDia::~CScoutMenuDia()
{
}

void CScoutMenuDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WELCOMEMESSAGE, wm_output);
}

// CScoutMenuDia message handlers

BOOL CScoutMenuDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateData(TRUE);
	wm_output = CString("Welcome ") + ScoutName;
	UpdateData(FALSE);

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}



BEGIN_MESSAGE_MAP(CScoutMenuDia, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CScoutMenuDia::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CScoutMenuDia::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CScoutMenuDia::OnBnClickedButton2)
END_MESSAGE_MAP()


// CScoutMenuDia message handlers


void CScoutMenuDia::OnBnClickedButton1()
{
	AddNewPlayerDia NewPlayerWindow;
	NewPlayerWindow.DoModal();

}




void CScoutMenuDia::OnBnClickedButton3()
{
	ReqstPlayers REQS;
	REQS.DoModal();
}


void CScoutMenuDia::OnBnClickedButton2()
{
	CEditPlayer EditPlayer;
	EditPlayer.DoModal();
}
