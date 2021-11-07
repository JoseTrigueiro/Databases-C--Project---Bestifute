// AddNewPlayerDia.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "AddNewPlayerDia.h"
#include "Flags.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"
#include <stdio.h>
#include <time.h>


// AddNewPlayerDia dialog

IMPLEMENT_DYNAMIC(AddNewPlayerDia, CDialogEx)

AddNewPlayerDia::AddNewPlayerDia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDNEWPLAYER, pParent)
	, np_name(_T(""))
	, np_bdday(1)
	, np_bdmonth(1)
	, np_bdyear(1950)
	, np_country(_T(""))
	, np_club(_T(""))
	, np_position(_T(""))
	, np_weight(0)
	, np_height(0)
	, np_preffootselected(2)
	, np_ic(0)
{

}

AddNewPlayerDia::~AddNewPlayerDia()
{
}

void AddNewPlayerDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PNAME, np_name);
	DDX_Text(pDX, IDC_PDBD, np_bdday);
	DDX_Text(pDX, IDC_PBDM, np_bdmonth);
	DDX_Text(pDX, IDC_PBDY, np_bdyear);
	DDX_Text(pDX, IDC_PCOUNTRY, np_country);
	DDX_Text(pDX, IDC_PCLUB, np_club);
	DDX_Text(pDX, IDC_PPOSITION, np_position);
	DDX_Text(pDX, IDC_PHEIGHT, np_height);
	DDX_Text(pDX, IDC_PWEIGHT, np_weight);
	DDX_Radio(pDX, IDC_PFOOTR, np_preffootselected);
	DDX_Text(pDX, IDC_PIC, np_ic);
}


// CCoachMenuDia message handlers

BOOL AddNewPlayerDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


BEGIN_MESSAGE_MAP(AddNewPlayerDia, CDialogEx)
	ON_BN_CLICKED(IDC_CONFIRMDATA, &AddNewPlayerDia::OnBnClickedConfirmdata)

END_MESSAGE_MAP()


// AddNewPlayerDia message handlers

void AddNewPlayerDia::OnBnClickedConfirmdata()
{

	UpdateData(TRUE);
	UpdateData(FALSE);

	if (np_name.IsEmpty() || np_country.IsEmpty() || np_club.IsEmpty() || np_position.IsEmpty())
		AfxMessageBox(_T("Please fill all options"));
	else if (np_name.GetLength() > 50 || np_country.GetLength() > 50 || np_club.GetLength() > 50)
		AfxMessageBox(_T("Names/countries/clubs with more than 50 characters aren't allowed"));
	else if (np_position.GetLength() > 5)
		AfxMessageBox(_T("Positions with more than 5 characters aren't allowed"));
	else
	{
		myconnectorclassDB VerifyPlayer;
		VerifyPlayer.connect();

		UpdateData(TRUE);
		CString existingplayer;
		existingplayer = VerifyPlayer.CheckPlayerBC(np_name);
		UpdateData(FALSE);

		if (!existingplayer.IsEmpty())
		{
			AfxMessageBox(_T("Player already exists in the database")); // Check if player with the same name already exists in data base
		}
		else if (!(1 <= np_bdday && np_bdday <= 31 && 1 <= np_bdmonth && np_bdmonth <= 12 && 1950 <= np_bdyear && np_bdyear <= 2100))
			AfxMessageBox(_T("Please insert a valid date"));
		else
		{
			CString np_csbdyear;
			CString np_csbdmonth;
			CString np_csbdday;

			np_csbdyear.Format(_T("%d"), np_bdyear);

			if (np_bdmonth < 10)
				np_csbdmonth.Format(_T("0%d"), np_bdmonth);
			else
				np_csbdmonth.Format(_T("%d"), np_bdmonth);

			if (np_bdday < 10)
				np_csbdday.Format(_T("0%d"), np_bdday);
			else
				np_csbdday.Format(_T("%d"), np_bdday);

			CString np_bd = np_csbdyear + _T("-") + np_csbdmonth + _T("-") + np_csbdday;

			BOOL legal;
			legal = PlayerLegal(np_bdday, np_bdmonth, np_bdyear);

			if (!legal)
				AfxMessageBox(_T("Player must be at least 16 to be featured in the database"));
			else if (!(100 <= np_height && np_height <= 250 && 30 <= np_weight && np_weight <= 160))
				AfxMessageBox(_T("Please insert a valid height/weight"));
			else
			{
				CString np_csheight;
				CString np_csweight;
				CString np_csic;

				np_csheight.Format(_T("%d"), np_height);
				np_csweight.Format(_T("%d"), np_weight);
				np_csic.Format(_T("%d"), np_ic);

				CString np_preffoot;
				switch (np_preffootselected)
				{
				case 0:
					np_preffoot.Format(_T("L"));
					break;
				case 1:
					np_preffoot.Format(_T("B"));
					break;
				case 2:
					np_preffoot.Format(_T("R"));
					break;
				}

				myconnectorclassDB AddPlayer;
				AddPlayer.connect();

				AddPlayer.createplayerBC(np_name, np_position, np_club, np_bd, np_preffoot, np_country, np_csheight, np_csweight, np_csic);

				if (ScoutMode)
				{
					myconnectorclassDB GetLastReportID;
					GetLastReportID.connect();

					CString CSReportID;
					CSReportID = GetLastReportID.GetLastScoutReportBC();

					int ReportID = _ttoi(CSReportID);

					CSReportID.Format(_T("%d"), ++ReportID);

					myconnectorclassDB CreateReport;
					CreateReport.connect();

					CreateReport.AddScoutReportBC(ScoutName, CSReportID, np_name);
				}
				else
				{
					myconnectorclassDB GetLastContractID;
					GetLastContractID.connect();

					CString CSContractID;
					CSContractID = GetLastContractID.GetLastContractBC();

					int ContractID = _ttoi(CSContractID);

					CSContractID.Format(_T("%d"), ++ContractID);

					myconnectorclassDB CreateContract;
					CreateContract.connect();

					CreateContract.AddNewContractBC(AgentName, CSContractID, np_name);
				}

				EndDialog(0);
			}
		}
	}
}


BOOL AddNewPlayerDia::PlayerLegal(int bday, int bmonth, int byear)
{
	struct tm tm;
	time_t now = time(0);
	localtime_s(&tm, &now);

	int playerage = tm.tm_year + 1900 - byear;
	BOOL legal;

	if (playerage < 16)
		legal = FALSE;
	else if (playerage == 16)
	{
		if ((tm.tm_mon + 1) < bmonth)
			legal = FALSE;
		else if ((tm.tm_mon + 1) == bmonth)
		{
			if (tm.tm_mday < bday)
				legal = FALSE;
			else
				legal = TRUE;
		}
		else
			legal = TRUE;
	}
	else
		legal = TRUE;

	return legal;
}
