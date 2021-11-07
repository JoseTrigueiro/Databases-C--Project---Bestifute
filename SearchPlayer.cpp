// SearchPlayer.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "V2.h"
#include "SearchPlayer.h"
#include "afxdialogex.h"
#include "Flags.h"
#include <vector>
#include <iostream>
#include <string>
#include "myconnectorclassDB.h"
#include "CPlayer_Info_Table.h"

using namespace std;


// SearchPlayer dialog

IMPLEMENT_DYNAMIC(SearchPlayer, CDialogEx)

SearchPlayer::SearchPlayer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCHPLAYER, pParent)
	, player_name_search(_T(""))
	, v_check1(FALSE)
	, v_check2(FALSE)
	, player_name_search2(_T(""))
	, v_check3(FALSE)
	, player_name_search3(_T(""))
	, v_check4(FALSE)
	, player_name_search4(_T(""))
	, v_check5(FALSE)
	, player_name_search5(_T(""))
	, v_check6(FALSE)
	, player_name_search6(_T(""))
	, v_check7(FALSE)
	, player_name_search7(_T(""))
	, v_check8(FALSE)
	, player_name_search8(_T(""))
	, v_check9(FALSE)
	, player_name_search9(_T(""))
	, v_check10(FALSE)
	, player_name_search10(_T(""))
	, v_check11(FALSE)
	, v_check12(FALSE)
	, v_check13(FALSE)
	, v_check14(FALSE)
	, v_check15(FALSE)
	, v_check16(FALSE)
	, v_check17(FALSE)
	, v_check18(FALSE)
	, player_name_search11(_T(""))
	, player_name_search12(_T(""))
	, player_name_search13(_T(""))
	, player_name_search14(_T(""))
	, player_name_search15(_T(""))
	, player_name_search16(_T(""))
	, player_name_search17(_T(""))
	, player_name_search18(_T(""))
{

}

BOOL SearchPlayer::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// TODO: Add extra initialization here

	// Ask Mfc to create/insert a column
	m_PlayerList.InsertColumn(
		0,              // Rank/order of item 
		L"Player Name",          // Caption for this header 
		LVCFMT_LEFT,    // Relative position of items under header 
		150);           // Width of items under header
	m_PlayerList.InsertColumn(1, L"Club", LVCFMT_LEFT, 150);
	m_PlayerList.InsertColumn(2, L"Agent Name", LVCFMT_LEFT, 150);
	m_PlayerList.InsertColumn(3, L"Transfer Fee", LVCFMT_LEFT, 100);
	m_PlayerList.InsertColumn(4, L"Demanded Wage", LVCFMT_LEFT, 100);


	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

SearchPlayer::~SearchPlayer()
{
}

void SearchPlayer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search, player_name_search);
	DDX_Control(pDX, IDC_PlayerList, m_PlayerList);
	DDX_Check(pDX, IDC_CHECK1, v_check1);
	DDX_Check(pDX, IDC_CHECK2, v_check2);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search2, player_name_search2);
	DDX_Check(pDX, IDC_CHECK3, v_check3);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search3, player_name_search3);
	DDX_Check(pDX, IDC_CHECK4, v_check4);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search4, player_name_search4);
	DDX_Check(pDX, IDC_CHECK5, v_check5);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search5, player_name_search5);
	DDX_Check(pDX, IDC_CHECK6, v_check6);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search6, player_name_search6);
	DDX_Check(pDX, IDC_CHECK7, v_check7);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search7, player_name_search7);
	DDX_Check(pDX, IDC_CHECK8, v_check8);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search8, player_name_search8);
	DDX_Check(pDX, IDC_CHECK9, v_check9);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search9, player_name_search9);
	DDX_Check(pDX, IDC_CHECK10, v_check10);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search10, player_name_search10);
	DDX_Check(pDX, IDC_CHECK11, v_check11);
	DDX_Check(pDX, IDC_CHECK12, v_check12);
	DDX_Check(pDX, IDC_CHECK13, v_check13);
	DDX_Check(pDX, IDC_CHECK14, v_check14);
	DDX_Check(pDX, IDC_CHECK15, v_check15);
	DDX_Check(pDX, IDC_CHECK16, v_check16);
	DDX_Check(pDX, IDC_CHECK17, v_check17);
	DDX_Check(pDX, IDC_CHECK18, v_check18);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search11, player_name_search11);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search12, player_name_search12);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search13, player_name_search13);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search14, player_name_search14);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search15, player_name_search15);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search16, player_name_search16);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search17, player_name_search17);
	DDX_Text(pDX, IDC_EDIT_Player_Name_Search18, player_name_search18);
}


BEGIN_MESSAGE_MAP(SearchPlayer, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_players, &SearchPlayer::OnBnClickedButtonplayers)
	ON_NOTIFY(NM_DBLCLK, IDC_PlayerList, &SearchPlayer::OnNMDblclkPlayerlist)
	ON_BN_CLICKED(IDC_CHECK1, &SearchPlayer::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &SearchPlayer::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &SearchPlayer::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &SearchPlayer::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &SearchPlayer::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &SearchPlayer::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &SearchPlayer::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &SearchPlayer::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &SearchPlayer::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &SearchPlayer::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &SearchPlayer::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &SearchPlayer::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &SearchPlayer::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &SearchPlayer::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &SearchPlayer::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &SearchPlayer::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK17, &SearchPlayer::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK18, &SearchPlayer::OnBnClickedCheck18)
END_MESSAGE_MAP()


// SearchPlayer message handlers


void SearchPlayer::OnBnClickedButtonplayers()
{
	myconnectorclassDB MyConnection;
	// MyConnection.connect(); 
	
	// player_age = MyConnection.CheckAge(player_name_search);

	CString sentence;
	CString init_query;
	
	init_query = _T("SELECT player_name,club, agent_name,transfer_fee,demanded_wage FROM i WHERE 1 ");
	sentence = init_query;
	UpdateData(TRUE);
	if (v_check1)
	{
		sentence += (_T("AND i.player_name='") + player_name_search + _T("' "));
	}
	if (v_check2)
	{
		sentence += (_T("AND i.transfer_fee<='") + player_name_search2 + _T("' "));
	}
	if (v_check3)
	{
		sentence += (_T("AND i.demanded_wage<='") + player_name_search3 + _T("' "));
	}
	if (v_check4)
	{
		sentence += (_T("AND (i.transfer_fee + i.signing_fee + i.agent_fee)<='") + player_name_search4 + _T("' "));
	}
	if (v_check5)
	{
		sentence += (_T("AND i.position ='") + player_name_search5 + _T("' "));
	}
	if (v_check6)
	{
		
		sentence += (_T("AND i.dominant_foot = '") + player_name_search6 + _T("' "));
	}
	if (v_check7)
	{

		sentence += (_T("AND i.handling >= '") + player_name_search7 + _T("' "));
	}
	if (v_check8)
	{

		sentence += (_T("AND i.reflexes >= '") + player_name_search8 + _T("' "));
	}	
	if (v_check9)
	{

		sentence += (_T("AND i.shooting >= '") + player_name_search9 + _T("' "));
	}	
	if (v_check10)
	{

		sentence += (_T("AND i.passing >= '") + player_name_search10 + _T("' "));
	}
	if (v_check11)
	{

		sentence += (_T("AND i.tackling >= '") + player_name_search11 + _T("' "));
	}
	if (v_check12)
	{

		sentence += (_T("AND i.dribbling >= '") + player_name_search12 + _T("' "));
	}
	if (v_check13)
	{

		sentence += (_T("AND i.leadership >= '") + player_name_search13 + _T("' "));
	}
	if (v_check14)
	{

		sentence += (_T("AND i.positioning >= '") + player_name_search14 + _T("' "));
	}
	if (v_check15)
	{

		sentence += (_T("AND i.strength >= '") + player_name_search15 + _T("' "));
	}
	if (v_check16)
	{

		sentence += (_T("AND i.stamina >= '") + player_name_search16 + _T("' "));
	}
	if (v_check17)
	{

		sentence += (_T("AND i.speed >= '") + player_name_search17 + _T("' "));
	}
	if (v_check18)
	{

		sentence += (_T("AND TIMESTAMPDIFF(YEAR,i.birth_date,CURDATE()) <= '") + player_name_search18 + _T("' "));
	}

	int sentencelen = sentence.GetLength();
	if (sentencelen < 256)
	{
		MyConnection.connect();
		vector<LVITEM> search_results = MyConnection.getPlayerInfo(sentence);

		m_PlayerList.DeleteAllItems();
		PlayerName_vec.clear();
		bool  first_item = TRUE;
		for (unsigned int i = 0; i < search_results.size(); i++)
		{
			if (first_item)
			{
				m_PlayerList.InsertItem(&search_results[i]);
				PlayerName_vec.push_back(search_results[i].pszText);

			}
			/*else if(search_results[i].iSubItem == 2)
			{
				PlayerName_vec.push_back(search_results[i].pszText);
			}*/

			else
			{
				m_PlayerList.SetItem(&search_results[i]);
			}
			if (i < search_results.size() - 1)
			{
				if (search_results[i + 1].iSubItem > 0)
				{
					first_item = FALSE;
				}
				else
				{
					first_item = TRUE;
				}
			}
		}
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox(_T("Query Length must be lower than 256 characters!\r\nPlease reduce the number of restrictions."));
	}
	MyConnection.connect();
	MyConnection.dropi();
}




void SearchPlayer::OnNMDblclkPlayerlist(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	DWORD dwPos = ::GetMessagePos();
	CPoint point((int)LOWORD(dwPos), (int)HIWORD(dwPos));
	m_PlayerList.ScreenToClient(&point);

	int nIndex;
	if ((nIndex = m_PlayerList.HitTest(point)) != -1) {
		// If you are in this if block, that means an item on the list
		//   was chosen and nIndex is the index of the selected item
		//   from the list.

		CPlayer_Info_Table Player_Info_Window;
		Player_Info_Window.m_PlayerName = PlayerName_vec[nIndex];
		Player_Info_Window.DoModal();
		return;
	}
	*pResult = 0;
}


void SearchPlayer::OnBnClickedCheck1()
{
	UpdateData(TRUE);
	if (v_check1 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search)->EnableWindow(true);
	}
	else {
		GetDlgItem(IDC_EDIT_Player_Name_Search)->EnableWindow(false);
		player_name_search = _T("");
	}
	UpdateData(FALSE);
}



void SearchPlayer::OnBnClickedCheck2()
{
	UpdateData(TRUE);
	if (v_check2 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search2)->EnableWindow(true);
	}
	else {
		GetDlgItem(IDC_EDIT_Player_Name_Search2)->EnableWindow(false);
		player_name_search2 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck3()
{
	UpdateData(TRUE);
	if (v_check3 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search3)->EnableWindow(true);
	}
	else {
		GetDlgItem(IDC_EDIT_Player_Name_Search3)->EnableWindow(false);
		player_name_search3 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck4()
{
	UpdateData(TRUE);
	if (v_check4 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search4)->EnableWindow(true);
	}
	else {

		GetDlgItem(IDC_EDIT_Player_Name_Search4)->EnableWindow(false);
		player_name_search4 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck5()
{
	UpdateData(TRUE);
	if (v_check5 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search5)->EnableWindow(true);
	}
	else 
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search5)->EnableWindow(false);
		player_name_search5 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck6()
{
	UpdateData(TRUE);
	if (v_check6 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search6)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search6)->EnableWindow(false);
		player_name_search6 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck7()
{
	UpdateData(TRUE);
	if (v_check7 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search7)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search7)->EnableWindow(false);
		player_name_search7 = _T("");
	}
	UpdateData(FALSE);
}




void SearchPlayer::OnBnClickedCheck8()
{
	UpdateData(TRUE);
	if (v_check8 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search8)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search8)->EnableWindow(false);
		player_name_search8 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck9()
{
	UpdateData(TRUE);
	if (v_check9 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search9)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search9)->EnableWindow(false);
		player_name_search9 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck10()
{
	UpdateData(TRUE);
	if (v_check10 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search10)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search10)->EnableWindow(false);
		player_name_search10 = _T("");
	}
	UpdateData(FALSE);
}



void SearchPlayer::OnBnClickedCheck11()
{
	UpdateData(TRUE);
	if (v_check11 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search11)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search11)->EnableWindow(false);
		player_name_search11 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck12()
{
	UpdateData(TRUE);
	if (v_check12 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search12)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search12)->EnableWindow(false);
		player_name_search12 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck13()
{
	UpdateData(TRUE);
	if (v_check13 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search13)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search13)->EnableWindow(false);
		player_name_search13 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck14()
{
	UpdateData(TRUE);
	if (v_check14 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search14)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search14)->EnableWindow(false);
		player_name_search14 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck15()
{
	UpdateData(TRUE);
	if (v_check15 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search15)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search15)->EnableWindow(false);
		player_name_search15 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck16()
{
	UpdateData(TRUE);
	if (v_check16 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search16)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search16)->EnableWindow(false);
		player_name_search16 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck17()
{
	UpdateData(TRUE);
	if (v_check17 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search17)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search17)->EnableWindow(false);
		player_name_search17 = _T("");
	}
	UpdateData(FALSE);
}


void SearchPlayer::OnBnClickedCheck18()
{
	UpdateData(TRUE);
	if (v_check18 == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search18)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_Player_Name_Search18)->EnableWindow(false);
		player_name_search18 = _T("");
	}
	UpdateData(FALSE);
}
