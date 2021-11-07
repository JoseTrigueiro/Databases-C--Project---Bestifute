// CPlayer_Info_Table.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "framework.h"
#include "CPlayer_Info_Table.h"
#include "Flags.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector> 
#include "myconnectorclassDB.h"


// CPlayer_Info_Table dialog

IMPLEMENT_DYNAMIC(CPlayer_Info_Table, CDialogEx)

CPlayer_Info_Table::CPlayer_Info_Table(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Player_Info_Table, pParent)
	, goalkeeper_rating(0)
	, technical_rating(0)
	, mental_rating(0)
	, player_name(_T(""))
	, physical_rating(0)
{

}


BOOL CPlayer_Info_Table::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: Add extra initialization here
	CString player_name_in;
	vector<CString> sc_report;
	vector<CString> agent_info;
	vector<CString> financial_info;
	vector<CString> biol_info;
	//player_name_in = _T("Cristiano Ronaldo");
	player_name_in = m_PlayerName;

	player_name = player_name_in + _T("'s Information");
	myconnectorclassDB PlayerStats;
	PlayerStats.connect();
	goalkeeper_rating = PlayerStats.Checkgoalkeeper_rating(player_name_in);
	PlayerStats.connect();
	technical_rating = PlayerStats.Checktechnical_rating(player_name_in);
	PlayerStats.connect();
	mental_rating = PlayerStats.Checkmental_rating(player_name_in);
	PlayerStats.connect();
	physical_rating = PlayerStats.Checkphysical_rating(player_name_in);

	//SC info
	PlayerStats.connect();
	sc_report = PlayerStats.getSCInfo(player_name_in);
	//GK rating
	gk_rating.InsertColumn(0, L"1", LVCFMT_LEFT, 150);
	gk_rating.InsertColumn(1, L"1", LVCFMT_LEFT, 30);
	gk_rating.InsertItem(0, L"Handling");
	gk_rating.SetItemText(0, 1, sc_report[0]);
	gk_rating.InsertItem(1, L"Reflexes");
	gk_rating.SetItemText(1, 1, sc_report[1]);
	tch_rating.InsertColumn(0, L"1", LVCFMT_LEFT, 150);
	tch_rating.InsertColumn(1, L"1", LVCFMT_LEFT, 30);
	tch_rating.InsertItem(0, L"Shooting");
	tch_rating.SetItemText(0, 1, sc_report[2]);
	tch_rating.InsertItem(1, L"Dribbling");
	tch_rating.SetItemText(1, 1, sc_report[5]);
	tch_rating.InsertItem(1, L"Passing");
	tch_rating.SetItemText(1, 1, sc_report[3]);
	tch_rating.InsertItem(1, L"Tackling");
	tch_rating.SetItemText(1, 1, sc_report[4]);
	ment_rating.InsertColumn(0, L"1", LVCFMT_LEFT, 150);
	ment_rating.InsertColumn(1, L"1", LVCFMT_LEFT, 30);
	ment_rating.InsertItem(0, L"Leadership");
	ment_rating.SetItemText(0, 1, sc_report[6]);
	ment_rating.InsertItem(1, L"Positioning");
	ment_rating.SetItemText(1, 1, sc_report[7]);
	ment_rating.InsertItem(1, L"Stamina");
	ment_rating.SetItemText(1, 1, sc_report[9]);
	phys_rating.InsertColumn(0, L"1", LVCFMT_LEFT, 150);
	phys_rating.InsertColumn(1, L"1", LVCFMT_LEFT, 30);
	phys_rating.InsertItem(0, L"Strength");
	phys_rating.SetItemText(0, 1, sc_report[8]);
	phys_rating.InsertItem(1, L"Speed");
	phys_rating.SetItemText(1, 1, sc_report[10]);


	PlayerStats.connect();
	//finacial info
	financial_info = PlayerStats.getFinancialInfo(player_name_in);
	fin_info.InsertColumn(0, L"Transfer fee (M€)", LVCFMT_LEFT, 100);
	fin_info.InsertColumn(1, L"Signing fee (M€)", LVCFMT_LEFT, 100);
	fin_info.InsertColumn(2, L"Current Wage (k€/week)", LVCFMT_LEFT, 150);
	fin_info.InsertColumn(3, L"Contract Expiry date (year)", LVCFMT_LEFT, 150);
	fin_info.InsertColumn(4, L"Demanded Wage (k€/week)", LVCFMT_LEFT, 150);
	fin_info.InsertColumn(5, L"Demanded Contract Length (year)", LVCFMT_LEFT, 200);
	fin_info.InsertItem(0, financial_info[0]);
	fin_info.SetItemText(0, 1, financial_info[1]);
	fin_info.SetItemText(0, 2, financial_info[2]);
	fin_info.SetItemText(0, 3, financial_info[3]);
	fin_info.SetItemText(0, 4, financial_info[4]);
	fin_info.SetItemText(0, 5, financial_info[5]);

	PlayerStats.connect();
	agent_info = PlayerStats.getAgentInfo(player_name_in);
	ag_info.InsertColumn(0, L"Agent Name", LVCFMT_LEFT, 100);
	ag_info.InsertColumn(1, L"Phone number", LVCFMT_LEFT, 100);
	ag_info.InsertColumn(2, L"email", LVCFMT_LEFT, 120);
	ag_info.InsertColumn(3, L"Company", LVCFMT_LEFT, 100);
	ag_info.InsertColumn(4, L"Agent Fee (M€)", LVCFMT_LEFT, 100);
	ag_info.InsertItem(0, agent_info[0]);
	ag_info.SetItemText(0, 1, agent_info[1]);
	ag_info.SetItemText(0, 2, agent_info[2]);
	ag_info.SetItemText(0, 3, agent_info[3]);
	ag_info.SetItemText(0, 4, agent_info[4]);

	PlayerStats.connect();
	biol_info = PlayerStats.getBioInfo(player_name_in);
	bio_info.InsertColumn(0, L"Position", LVCFMT_LEFT, 100);
	bio_info.InsertColumn(1, L"Club", LVCFMT_LEFT, 100);
	bio_info.InsertColumn(2, L"Birth date", LVCFMT_LEFT, 100);
	bio_info.InsertColumn(3, L"Dominant Foot", LVCFMT_LEFT, 100);
	bio_info.InsertColumn(4, L"Country", LVCFMT_LEFT, 100);
	bio_info.InsertColumn(5, L"Height", LVCFMT_LEFT, 50);
	bio_info.InsertColumn(6, L"Weight", LVCFMT_LEFT, 50);
	bio_info.InsertColumn(7, L"International Caps", LVCFMT_LEFT, 150);
	bio_info.InsertItem(0, biol_info[0]);
	bio_info.SetItemText(0, 1, biol_info[1]);
	bio_info.SetItemText(0, 2, biol_info[2]);
	bio_info.SetItemText(0, 3, biol_info[3]);
	bio_info.SetItemText(0, 4, biol_info[4]);
	bio_info.SetItemText(0, 5, biol_info[5]);
	bio_info.SetItemText(0, 6, biol_info[6]);
	bio_info.SetItemText(0, 7, biol_info[7]);

	UpdateData(FALSE);

	if (SportDName != "")
	{
		GetDlgItem(IDC_BUTTONRefered)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTONRefered)->ShowWindow(SW_HIDE);
	}

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

CPlayer_Info_Table::~CPlayer_Info_Table()
{
}

void CPlayer_Info_Table::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2goalkeeper_rating, goalkeeper_rating);
	DDX_Text(pDX, IDC_EDIT1technical_rating, technical_rating);
	DDX_Text(pDX, IDC_EDIT2mental_rating, mental_rating);
	DDX_Control(pDX, IDC_LIST2goalkeeper_rating, gk_rating);
	DDX_Control(pDX, IDC_LIST3tch_rating, tch_rating);
	DDX_Control(pDX, IDC_LIST4mental_rating, ment_rating);
	DDX_Control(pDX, IDC_LIST1bio_info, bio_info);
	DDX_Control(pDX, IDC_LIST1agent_info, ag_info);
	DDX_Control(pDX, IDC_LIST2_financial_info, fin_info);
	DDX_Text(pDX, IDC_EDIT1player_name, player_name);
	DDX_Text(pDX, IDC_EDIT5, physical_rating);
	DDX_Control(pDX, IDC_LIST5, phys_rating);
}


BEGIN_MESSAGE_MAP(CPlayer_Info_Table, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONRefered, &CPlayer_Info_Table::OnBnClickedButtonrefered)
END_MESSAGE_MAP()


// CPlayer_Info_Table message handlers


void CPlayer_Info_Table::OnBnClickedButtonrefered()
{
	myconnectorclassDB ReferPL;
	CString sd_name;
	ReferPL.connect();
	sd_name=ReferPL.getsdname(CoachName);
	ReferPL.connect();
	ReferPL.referplayer(CoachName, sd_name, m_PlayerName);
	UpdateData(TRUE);
	CString message;
	message = m_PlayerName + _T(" will be refered to ") + sd_name + _T(" as a Transfer Target!");
	MessageBox(message, L"Notification", MB_ICONASTERISK);

}
