
// V2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Flags.h"
#include "V2.h"
#include "V2Dlg.h"
#include "afxdialogex.h"
#include "CCoachLoginDia.h"
#include "CSportDLoginDia.h"
#include "CScoutLoginDia.h"
#include "CAgentLoginDia.h"
#include "SearchPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL ScoutMode;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CV2Dlg dialog



CV2Dlg::CV2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_V2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CV2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CV2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COACHBUTTON, &CV2Dlg::OnBnClickedCoachbutton)
	ON_BN_CLICKED(IDC_SPORTDBUTTON, &CV2Dlg::OnBnClickedSportdbutton)
	ON_BN_CLICKED(IDC_SCOUTBUTTON, &CV2Dlg::OnBnClickedScoutbutton)
	ON_BN_CLICKED(IDC_AGENTBUTTON, &CV2Dlg::OnBnClickedAgentbutton)
END_MESSAGE_MAP()


// CV2Dlg message handlers

BOOL CV2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CV2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CV2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CV2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CV2Dlg::OnBnClickedCoachbutton() //Coach Login
{
	CCoachLoginDia CoachLoginDialog;
	CoachLoginDialog.DoModal();
}


void CV2Dlg::OnBnClickedSportdbutton()
{
	CSportDLoginDia SportDLoginDialog;
	SportDLoginDialog.DoModal();
}


void CV2Dlg::OnBnClickedScoutbutton()
{
	ScoutMode = TRUE;

	CScoutLoginDia ScoutLoginDialog;
	ScoutLoginDialog.DoModal();
}


void CV2Dlg::OnBnClickedAgentbutton()
{
	ScoutMode = FALSE;

	CAgentLoginDia AgentLoginDialog;
	AgentLoginDialog.DoModal();
}
