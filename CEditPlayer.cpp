// CEditPlayer.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CEditPlayer.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "myconnectorclassDB.h"
#include <vector>

BOOL GKmode;
// CEditPlayer dialog

IMPLEMENT_DYNAMIC(CEditPlayer, CDialogEx)

CEditPlayer::CEditPlayer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDITPLAYER, pParent)
	, np_name(_T(""))
	, ep_club(_T(""))
	, ep_bdmonth(0)
	, ep_bdyear(0)
	, ep_country(_T(""))
	, ep_position(_T(""))
	, ep_height(0)
	, ep_bdday(0)
	, ep_weight(0)
	, ep_ic(0)
	, ep_preffootselected(2)
	, ep_newcontractlength(1)
	, ep_cedyear(2100)
	, ep_cedmonth(12)
	, ep_cedday(31)
	, ep_desiredwage(1)
	, ep_currentwage(0)
	, ep_agentfee(0)
	, ep_signingfee(0)
	, ep_transferfee(0)
	, ep_handling(0)
	, ep_reflexes(0)
	, ep_passing(0)
	, ep_shoot(0)
	, ep_dribbling(0)
	, ep_positioning(0)
	, ep_speed(0)
	, ep_stamina(0)
	, ep_strength(0)
	, ep_tackling(0)
	, ep_leadership(0)
{

}

CEditPlayer::~CEditPlayer()
{
}

void CEditPlayer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PNAME, np_name);
	DDX_Text(pDX, IDC_PCLUB, ep_club);
	DDX_Text(pDX, IDC_PBDM, ep_bdmonth);
	DDX_Text(pDX, IDC_PBDY, ep_bdyear);
	DDX_Text(pDX, IDC_PCOUNTRY, ep_country);
	DDX_Text(pDX, IDC_PPOSITION, ep_position);
	DDX_Text(pDX, IDC_PHEIGHT, ep_height);
	DDX_Text(pDX, IDC_PDBD1, ep_bdday);
	DDX_Text(pDX, IDC_PWEIGHT, ep_weight);
	DDX_Text(pDX, IDC_PIC, ep_ic);
	DDX_Radio(pDX, IDC_PFOOTR, ep_preffootselected);
	DDX_Text(pDX, IDC_EFNCL, ep_newcontractlength);
	DDX_Text(pDX, IDC_EFCDY, ep_cedyear);
	DDX_Text(pDX, IDC_EFCDM, ep_cedmonth);
	DDX_Text(pDX, IDC_EFCDD, ep_cedday);
	DDX_Text(pDX, IDC_EFNW, ep_desiredwage);
	DDX_Text(pDX, IDC_EFCW, ep_currentwage);
	DDX_Text(pDX, IDC_EFAF, ep_agentfee);
	DDX_Text(pDX, IDC_EFSF, ep_signingfee);
	DDX_Text(pDX, IDC_EFTF, ep_transferfee);
	DDX_Text(pDX, IDC_EPHAND, ep_handling);
	DDX_Text(pDX, IDC_EPREF, ep_reflexes);
	DDX_Text(pDX, IDC_EPPASS, ep_passing);
	DDX_Text(pDX, IDC_EPSHOOT, ep_shoot);
	DDX_Text(pDX, IDC_EPDRIB, ep_dribbling);
	DDX_Text(pDX, IDC_EPPOS, ep_positioning);
	DDX_Text(pDX, IDC_EPSPD, ep_speed);
	DDX_Text(pDX, IDC_EPSTAM, ep_stamina);
	DDX_Text(pDX, IDC_EPSTGH, ep_strength);
	DDX_Text(pDX, IDC_EPTACK, ep_tackling);
	DDX_Text(pDX, IDC_EPLEAD, ep_leadership);
}


BEGIN_MESSAGE_MAP(CEditPlayer, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH, &CEditPlayer::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_CONFIRMDATA, &CEditPlayer::OnBnClickedConfirmdata)
END_MESSAGE_MAP()


// CCoachMenuDia message handlers

BOOL CEditPlayer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CEditPlayer::OnBnClickedSearch()
{
	UpdateData(TRUE);

	if (!np_name.IsEmpty() && np_name.GetLength() < 51)
	{
		myconnectorclassDB VerifyPlayer; //Player name
		VerifyPlayer.connect();

		CString existingplayer;
		existingplayer = VerifyPlayer.CheckPlayerBC(np_name);

		if (existingplayer.IsEmpty())
		{
			AfxMessageBox(_T("Player does not exist in the database")); // Check if player with the same name already exists in data base
		}
		else
		{
			myconnectorclassDB ScoutInfo; //Scout info
			ScoutInfo.connect();

			std::vector<CString> PlayerScoutInfo;
			PlayerScoutInfo = ScoutInfo.getPlayerScoutBC(existingplayer);

			myconnectorclassDB AgentInfo; //Agent info
			AgentInfo.connect();

			std::vector<CString> PlayerAgentInfo;
			PlayerAgentInfo = AgentInfo.getAgentInfoBC(existingplayer);

			// Authorization garanted to players without agent/scout or if the latter match with logged user
			BOOL AuthorizedMode;

			if (PlayerScoutInfo.empty() && ScoutMode) //Attribute new player logged scout
			{
				AuthorizedMode = TRUE;

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
			else if (!PlayerScoutInfo.empty() && ScoutMode)
			{
				if (PlayerScoutInfo[0] == ScoutName) //Scout matches player scout
					AuthorizedMode = TRUE;
				else
					AuthorizedMode = FALSE;
			}
			else if (PlayerAgentInfo.empty() && !ScoutMode) //Attribute new player logged agent
			{
				AuthorizedMode = TRUE;

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
			else
			{
				if (PlayerAgentInfo[0] == AgentName) //Agent matches player agent
					AuthorizedMode = TRUE;
				else
					AuthorizedMode = FALSE;
			}

			if (!AuthorizedMode)
			{
				if (ScoutMode)
					AfxMessageBox(_T("Only allowed to edit players scouted by you"));
				else
					AfxMessageBox(_T("Only allowed to edit your clients"));
			}
			else
			{
				//Get personal info, scouting report and financial info
				myconnectorclassDB PlayerBio;
				PlayerBio.connect();

				std::vector<CString> PlayerPersonalInfo;
				PlayerPersonalInfo = PlayerBio.getPersnalInfoBC(existingplayer);

				myconnectorclassDB PlayerScoutingReport;
				PlayerScoutingReport.connect();

				std::vector<CString> ScoutingReport;
				ScoutingReport = PlayerScoutingReport.getSCInfoBC(existingplayer);

				myconnectorclassDB PlayerFinancialInfo;
				PlayerFinancialInfo.connect();

				std::vector<CString> FinancialInfo;
				FinancialInfo = PlayerFinancialInfo.getFinInfoBC(existingplayer);

				//Update player info;
				ep_position = PlayerPersonalInfo[0];
				ep_club = PlayerPersonalInfo[1];
				ep_country = PlayerPersonalInfo[4];
				ep_height = _ttoi(PlayerPersonalInfo[5]);
				ep_weight = _ttoi(PlayerPersonalInfo[6]);
				ep_ic = _ttoi(PlayerPersonalInfo[7]);

				CString ep_bddate = PlayerPersonalInfo[2];
				ep_bdyear = _ttoi(ep_bddate.Left(4));
				ep_bdmonth = _ttoi(ep_bddate.Mid(5, 2));
				ep_bdday = _ttoi(ep_bddate.Mid(8, 2));

				CString ep_playerpreffoot = PlayerPersonalInfo[3];
				if (ep_playerpreffoot == "R")
					ep_preffootselected = 2;
				else if (ep_playerpreffoot == "B")
					ep_preffootselected = 1;
				else
					ep_preffootselected = 0;

				if (!PlayerScoutInfo.empty())
				{
					ep_handling = _ttoi(ScoutingReport[0]);
					ep_reflexes = _ttoi(ScoutingReport[1]);
					ep_shoot = _ttoi(ScoutingReport[2]);
					ep_passing = _ttoi(ScoutingReport[3]);
					ep_tackling = _ttoi(ScoutingReport[4]);
					ep_dribbling = _ttoi(ScoutingReport[5]);
					ep_leadership = _ttoi(ScoutingReport[6]);
					ep_positioning = _ttoi(ScoutingReport[7]);
					ep_strength = _ttoi(ScoutingReport[8]);
					ep_stamina = _ttoi(ScoutingReport[9]);
					ep_speed = _ttoi(ScoutingReport[10]);

					//Set goalkeeper
					if (ep_position == "GK")
						GKmode = TRUE; //Player is goalie
					else
						GKmode = FALSE; //Player is a field player
				}

				if (!PlayerAgentInfo.empty())
				{
					ep_transferfee = _ttof(FinancialInfo[0]);
					ep_signingfee = _ttof(FinancialInfo[1]);
					ep_currentwage = _ttof(FinancialInfo[2]);
					ep_desiredwage = _ttof(FinancialInfo[4]);
					ep_newcontractlength = _ttof(FinancialInfo[5]);
					ep_agentfee = _ttof(PlayerAgentInfo[4]);


					CString ep_contractexpiringday; // Check if date is valid
					ep_contractexpiringday = FinancialInfo[3];

					ep_cedyear = _ttoi(ep_contractexpiringday.Left(4));
					ep_cedmonth = _ttoi(ep_contractexpiringday.Mid(5, 2));
					ep_cedday = _ttoi(ep_contractexpiringday.Mid(8, 2));
				}

				//Turn on the disabled buttons
				GetDlgItem(IDC_PNAME)->EnableWindow(FALSE);
				GetDlgItem(IDC_SEARCH)->EnableWindow(FALSE);
				GetDlgItem(IDC_PDBD1)->EnableWindow(TRUE);
				GetDlgItem(IDC_PBDM)->EnableWindow(TRUE);
				GetDlgItem(IDC_PBDY)->EnableWindow(TRUE);
				GetDlgItem(IDC_PCLUB)->EnableWindow(TRUE);
				GetDlgItem(IDC_PCOUNTRY)->EnableWindow(TRUE);
				GetDlgItem(IDC_PPOSITION)->EnableWindow(TRUE);
				GetDlgItem(IDC_PHEIGHT)->EnableWindow(TRUE);
				GetDlgItem(IDC_PWEIGHT)->EnableWindow(TRUE);
				GetDlgItem(IDC_PIC)->EnableWindow(TRUE);
				GetDlgItem(IDC_PFOOTB)->EnableWindow(TRUE);
				GetDlgItem(IDC_PFOOTL)->EnableWindow(TRUE);
				GetDlgItem(IDC_PFOOTR)->EnableWindow(TRUE);
				GetDlgItem(IDC_CONFIRMDATA)->EnableWindow(TRUE);

				if (ScoutMode)
				{
					GetDlgItem(IDC_EPPASS)->EnableWindow(TRUE);
					GetDlgItem(IDC_EPLEAD)->EnableWindow(TRUE);

					if (GKmode)
					{
						GetDlgItem(IDC_EPHAND)->EnableWindow(TRUE);
						GetDlgItem(IDC_EPREF)->EnableWindow(TRUE);
					}
					else
					{
						GetDlgItem(IDC_EPSHOOT)->EnableWindow(TRUE);
						GetDlgItem(IDC_EPDRIB)->EnableWindow(TRUE);
						GetDlgItem(IDC_EPPOS)->EnableWindow(TRUE);
						GetDlgItem(IDC_EPSPD)->EnableWindow(TRUE);
						GetDlgItem(IDC_EPSTAM)->EnableWindow(TRUE);
						GetDlgItem(IDC_EPSTGH)->EnableWindow(TRUE);
						GetDlgItem(IDC_EPTACK)->EnableWindow(TRUE);
					}
				}
				else
				{
					GetDlgItem(IDC_EFCDD)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFCDM)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFCDY)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFNCL)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFCW)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFNW)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFTF)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFSF)->EnableWindow(TRUE);
					GetDlgItem(IDC_EFAF)->EnableWindow(TRUE);
				}
			}
		}
	}
	else if (np_name.GetLength() > 51)
		AfxMessageBox(_T("Names with more than 50 characters aren't allowed"));

	UpdateData(FALSE);
}


void CEditPlayer::OnBnClickedConfirmdata()
{
	UpdateData(TRUE);
	UpdateData(FALSE);

	if (ep_country.IsEmpty() || ep_club.IsEmpty() || ep_position.IsEmpty())
		AfxMessageBox(_T("Please fill all options"));
	else if (ep_country.GetLength() > 50 || ep_club.GetLength() > 50)
		AfxMessageBox(_T("Countries/clubs with more than 50 characters aren't allowed"));
	else if (ep_position.GetLength() > 5)
		AfxMessageBox(_T("Positions with more than 5 characters aren't allowed"));
	else
	{
		if (!(1 <= ep_bdday && ep_bdday <= 31 && 1 <= ep_bdmonth && ep_bdmonth <= 12 && 1950 <= ep_bdyear && ep_bdyear <= 2100))
			AfxMessageBox(_T("Please insert a valid date"));
		else
		{
			//Format date
			CString ep_csbdyear;
			CString ep_csbdmonth;
			CString ep_csbdday;

			ep_csbdyear.Format(_T("%d"), ep_bdyear);

			if (ep_bdmonth < 10)
				ep_csbdmonth.Format(_T("0%d"), ep_bdmonth);
			else
				ep_csbdmonth.Format(_T("%d"), ep_bdmonth);

			if (ep_bdday < 10)
				ep_csbdday.Format(_T("0%d"), ep_bdday);
			else
				ep_csbdday.Format(_T("%d"), ep_bdday);

			CString ep_bd = ep_csbdyear + _T("-") + ep_csbdmonth + _T("-") + ep_csbdday;

			BOOL legal;
			legal = PlayerLegal(ep_bdday, ep_bdmonth, ep_bdyear);

			if (!legal)
				AfxMessageBox(_T("Player must be at least 16 to be featured in the database"));
			else if (!(100 <= ep_height && ep_height <= 250 && 30 <= ep_weight && ep_weight <= 160))
				AfxMessageBox(_T("Please insert a valid height/weight"));
			else
			{
				CString ep_csheight;
				CString ep_csweight;
				CString ep_csic;

				ep_csheight.Format(_T("%d"), ep_height);
				ep_csweight.Format(_T("%d"), ep_weight);
				ep_csic.Format(_T("%d"), ep_ic);

				CString ep_preffoot;
				switch (ep_preffootselected)
				{
				case 0:
					ep_preffoot.Format(_T("L"));
					break;
				case 1:
					ep_preffoot.Format(_T("B"));
					break;
				case 2:
					ep_preffoot.Format(_T("R"));
					break;
				}

				if (!(1 <= ep_cedday && ep_cedday <= 31 && 1 <= ep_cedmonth && ep_cedmonth <= 12 && 1950 <= ep_cedyear && ep_cedyear <= 2100))
					AfxMessageBox(_T("Please insert a valid date"));
				else
				{
					//Format contract date
					CString ep_cscedyear;
					CString ep_cscedmonth;
					CString ep_cscedday;

					ep_cscedyear.Format(_T("%d"), ep_cedyear);

					if (ep_cedmonth < 10)
						ep_cscedmonth.Format(_T("0%d"), ep_cedmonth);
					else
						ep_cscedmonth.Format(_T("%d"), ep_cedmonth);

					if (ep_cedday < 10)
						ep_cscedday.Format(_T("0%d"), ep_cedday);
					else
						ep_cscedday.Format(_T("%d"), ep_cedday);

					CString ep_ced = ep_cscedyear + _T("-") + ep_cscedmonth + _T("-") + ep_cscedday;

					BOOL ContractUp;
					ContractUp = IsContractUp(ep_cedday, ep_cedmonth, ep_cedyear);

					if (!(ep_reflexes >= 0 && ep_reflexes <= 10 && ep_handling >= 0 && ep_handling <= 10 && ep_passing >= 0 && ep_passing <= 10 && ep_shoot >= 0 && ep_shoot <= 10 && ep_dribbling >= 0 && ep_dribbling <= 10 && ep_positioning >= 0 && ep_positioning <= 10 && ep_speed >= 0 && ep_speed <= 10 && ep_strength >= 0 && ep_strength <= 10 && ep_stamina >= 0 && ep_stamina <= 10 && ep_tackling >= 0 && ep_tackling <= 10 && ep_leadership >= 0 && ep_leadership <= 10))
					{
						AfxMessageBox(_T("Please insert integer values between 0 and 10"));
					}
					else if (ContractUp)
						AfxMessageBox(_T("Contract has expired"));
					else if (!(ep_agentfee >= 0 && ep_signingfee >= 0 && ep_transferfee >= 0 && ep_currentwage >= 0 && ep_desiredwage > 0 && ep_newcontractlength > 0))
					{
						AfxMessageBox(_T("All values for the financial info must be positive (fees and current wage can be null)"));
					}
					else
					{
						//Update player bio
						myconnectorclassDB AddPlayer;
						AddPlayer.connect();

						AddPlayer.EditPersonalInfo(np_name, ep_position, ep_club, ep_bd, ep_preffoot, ep_country, ep_csheight, ep_csweight, ep_csic);


						if (ScoutMode)
						{
							//Convert ints to cstring
							CString ep_cshandling;
							ep_cshandling.Format(_T("%d"), ep_handling);
							CString ep_csreflexes;
							ep_csreflexes.Format(_T("%d"), ep_reflexes);
							CString ep_csshoot;
							ep_csshoot.Format(_T("%d"), ep_shoot);
							CString ep_cspassing;
							ep_cspassing.Format(_T("%d"), ep_passing);
							CString ep_cstackling;
							ep_cstackling.Format(_T("%d"), ep_tackling);
							CString ep_csdribbling;
							ep_csdribbling.Format(_T("%d"), ep_dribbling);
							CString ep_csleadership;
							ep_csleadership.Format(_T("%d"), ep_leadership);
							CString ep_cspositioning;
							ep_cspositioning.Format(_T("%d"), ep_positioning);
							CString ep_csstrength;
							ep_csstrength.Format(_T("%d"), ep_strength);
							CString ep_csstamina;
							ep_csstamina.Format(_T("%d"), ep_stamina);
							CString ep_csspeed;
							ep_csspeed.Format(_T("%d"), ep_speed);

							myconnectorclassDB GetLastReportID;
							GetLastReportID.connect();

							CString CSReportID;
							CSReportID = GetLastReportID.GetPlayerScoutReportBC(np_name);

							myconnectorclassDB EditScoutingReport;
							EditScoutingReport.connect();

							EditScoutingReport.EditScoutingReport(CSReportID, ep_cshandling, ep_csreflexes, ep_csshoot, ep_cspassing, ep_cstackling, ep_csdribbling, ep_csleadership, ep_cspositioning, ep_csstrength, ep_csstamina, ep_csspeed);
						}
						else
						{
							//Convert floats to cstring
							CString ep_cstransferfee;
							ep_cstransferfee.Format(_T("%.0f"), ep_transferfee);
							CString ep_cscurrentwage;
							ep_cscurrentwage.Format(_T("%.0f"), ep_currentwage);
							CString ep_csdemandedwage;
							ep_csdemandedwage.Format(_T("%.0f"), ep_desiredwage);
							CString ep_csnewcontractlength;
							ep_csnewcontractlength.Format(_T("%.0f"), ep_newcontractlength);
							CString ep_cssigningfee;
							ep_cssigningfee.Format(_T("%.0f"), ep_signingfee);
							CString ep_csagentfee;
							ep_csagentfee.Format(_T("%.0f"), ep_agentfee);

							myconnectorclassDB GetLastContractID;
							GetLastContractID.connect();

							CString CSContractID;
							CSContractID = GetLastContractID.GetPlayerContractBC(np_name);

							myconnectorclassDB EditFinancialInfo;
							EditFinancialInfo.connect();

							EditFinancialInfo.EditFinancialInfo(CSContractID, ep_ced, ep_cstransferfee, ep_cscurrentwage, ep_csdemandedwage, ep_csnewcontractlength, ep_cssigningfee, ep_csagentfee);
						}


						//Update financial info

						EndDialog(0);
					}
				}
			}
		}
	}
}


BOOL CEditPlayer::PlayerLegal(int bday, int bmonth, int byear)
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

BOOL CEditPlayer::IsContractUp(int bday, int bmonth, int byear)
{
	struct tm tm;
	time_t now = time(0);
	localtime_s(&tm, &now);

	int todayyear = tm.tm_year + 1900;
	BOOL ContractUp;

	if (todayyear > byear)
		ContractUp = TRUE;
	else if (todayyear == byear)
	{
		if ((tm.tm_mon + 1) > bmonth)
			ContractUp = TRUE;
		else if ((tm.tm_mon + 1) == bmonth)
		{
			if (tm.tm_mday > bday)
				ContractUp = TRUE;
			else
				ContractUp = FALSE;
		}
		else
			ContractUp = FALSE;
	}
	else
		ContractUp = FALSE;

	return ContractUp;
}