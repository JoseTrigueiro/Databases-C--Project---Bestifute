// CRefdPlayers.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "CRefdPlayers.h"
#include "afxdialogex.h"
#include "Flags.h"
#include "myconnectorclassDB.h"
#include <vector>
#include "CPlayer_Info_Table.h"

using namespace std;

// CRefdPlayers dialog

IMPLEMENT_DYNAMIC(CRefdPlayers, CDialogEx)

CRefdPlayers::CRefdPlayers(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REFDPLAYERS, pParent)
	, m_welcomemessage(_T(""))
{

}
CRefdPlayers::~CRefdPlayers()
{
}

void CRefdPlayers::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_welcomemessage);
	DDX_Control(pDX, IDC_LIST1, m_refd_player_list);
}

BOOL CRefdPlayers::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// TODO: Add extra initialization here
	UpdateData(TRUE);

	myconnectorclassDB get_Coach;
	get_Coach.connect();
	CString manager_name = get_Coach.getcoachname(SportDName);//QUERY
	m_welcomemessage = _T("Hello ") + SportDName + _T(", here are the players recommended by coach ") + manager_name;
	m_refd_player_list.InsertColumn(0, L"Player Name", LVCFMT_LEFT, 200);
	m_refd_player_list.InsertColumn(1, L"Club", LVCFMT_LEFT, 200);
	m_refd_player_list.InsertColumn(2, L"Agent Name", LVCFMT_LEFT, 200);
	m_refd_player_list.InsertColumn(3, L"Transfer Fee (M€)", LVCFMT_LEFT, 150);
	m_refd_player_list.InsertColumn(4, L"Demanded Wage (k€/week)", LVCFMT_LEFT, 150);

	myconnectorclassDB MyConnection;
	MyConnection.connect();
	vector<LVITEM> search_results = MyConnection.getRefdPlayer(SportDName);

	m_refd_player_list.DeleteAllItems();
	RefName_vec.clear();
	bool  first_item = TRUE;
	for (unsigned int i = 0; i < search_results.size(); i++)
	{
		if (first_item)
		{
			m_refd_player_list.InsertItem(&search_results[i]);
			RefName_vec.push_back(search_results[i].pszText);

		}
		else
		{
			m_refd_player_list.SetItem(&search_results[i]);
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


	UpdateData(FALSE);

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control


}



BEGIN_MESSAGE_MAP(CRefdPlayers, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CRefdPlayers::OnNMDblclkList1)
END_MESSAGE_MAP()


// CRefdPlayers message handlers


void CRefdPlayers::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	DWORD dwPos = ::GetMessagePos();
	CPoint point((int)LOWORD(dwPos), (int)HIWORD(dwPos));
	m_refd_player_list.ScreenToClient(&point);

	int nIndex;
	if ((nIndex = m_refd_player_list.HitTest(point)) != -1) {
		// If you are in this if block, that means an item on the list
		//   was chosen and nIndex is the index of the selected item
		//   from the list.

		CPlayer_Info_Table Ref_Player_Info_Window;
		Ref_Player_Info_Window.m_PlayerName = RefName_vec[nIndex];
		Ref_Player_Info_Window.DoModal();
		return;
	}
	*pResult = 0;
}
