// CAgentMenuDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CAgentMenuDia.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "CEditPlayer.h"
#include "AddNewPlayerDia.h"

// CAgentMenuDia dialog

IMPLEMENT_DYNAMIC(CAgentMenuDia, CDialogEx)

CAgentMenuDia::CAgentMenuDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AGENTMENUDIALOG, pParent)
	, wm_output(_T(""))
{

}

CAgentMenuDia::~CAgentMenuDia()
{
}

void CAgentMenuDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WELCOMEMESSAGE, wm_output);
}


// CCoachMenuDia message handlers

BOOL CAgentMenuDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateData(TRUE);
	wm_output = CString("Welcome ") + AgentName;
	UpdateData(FALSE);

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


BEGIN_MESSAGE_MAP(CAgentMenuDia, CDialogEx)
	ON_BN_CLICKED(IDC_CREATEP, &CAgentMenuDia::OnBnClickedCreatep)
	ON_BN_CLICKED(IDC_BUTTON2, &CAgentMenuDia::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAgentMenuDia message handlers


void CAgentMenuDia::OnBnClickedCreatep()
{
	AddNewPlayerDia CreatePlayerDia;
	CreatePlayerDia.DoModal();
}


void CAgentMenuDia::OnBnClickedButton2()
{
	CEditPlayer EditPlayerDia;
	EditPlayerDia.DoModal();
}
