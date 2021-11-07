// REQUEST.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "REQUEST.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"
#include "Flags.h"
#include <vector>


// REQUEST dialog

IMPLEMENT_DYNAMIC(REQUEST, CDialogEx)

REQUEST::REQUEST(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REQUEST, pParent)
	, p_req(_T(""))
	, position(_T(""))
{
	
}

REQUEST::~REQUEST()
{
}

void REQUEST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, scoutselected);
	DDX_Text(pDX, IDC_PREQ, p_req);
	DDX_Text(pDX, IDC_POS, position);
}

BOOL REQUEST::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(TRUE);
	int index;
	myconnectorclassDB ScoutVec;
	ScoutVec.connect();
	vector<CString> scout_vector = ScoutVec.getscoutvector();
	for (unsigned int i = 0; i < scout_vector.size(); i++)
	{
		scoutselected.AddString(scout_vector[i]);
	}
	UpdateData(FALSE);


	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;
}


BEGIN_MESSAGE_MAP(REQUEST, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &REQUEST::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &REQUEST::OnBnClickedButton1)
END_MESSAGE_MAP()


// REQUEST message handlers


void REQUEST::OnCbnSelchangeCombo1()
{
	int index;
	index = scoutselected.GetCurSel();
	scoutselected.GetLBText(index, scout_name);
	GetDlgItem(IDC_PREQ)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATICref)->EnableWindow(TRUE); 
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATICpos)->EnableWindow(TRUE);
	GetDlgItem(IDC_POS)->EnableWindow(TRUE);
}


void REQUEST::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CoachName;
	myconnectorclassDB NewRep;
	NewRep.connect();
	NewRep.newrequest(position, CoachName, scout_name, p_req);
	UpdateData(FALSE);
	CString message;
	message = _T(" Your request has been sent to ") + scout_name + _T(".");
	MessageBox(message, L"Notification", MB_ICONASTERISK);
}
