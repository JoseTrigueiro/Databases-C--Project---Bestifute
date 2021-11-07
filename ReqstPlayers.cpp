// ReqstPlayers.cpp : implementation file
//

#include "pch.h"
#include "V2.h"
#include "Flags.h"
#include "ReqstPlayers.h"
#include "afxdialogex.h"
#include <vector>
#include "myconnectorclassDB.h"

using namespace std;

// ReqstPlayers dialog

IMPLEMENT_DYNAMIC(ReqstPlayers, CDialogEx)

ReqstPlayers::ReqstPlayers(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REQSTPLAYERS, pParent)
	, welc_message(_T("Welcome ")+ScoutName+_T("."))

	, n_req(_T(""))
{
	
}

ReqstPlayers::~ReqstPlayers()
{
}

void ReqstPlayers::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WELCOME, welc_message);
	DDX_Text(pDX, IDC_NREQ, n_req);
	DDX_Control(pDX, IDC_LISTREQ, requests);
}

BOOL ReqstPlayers::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(TRUE);
	myconnectorclassDB reqs;
	reqs.connect();
	reqs_vector = reqs.getrequests(ScoutName);
	int n_reqs = (reqs_vector.size())/3;
	n_reqs_str.Format(_T("%d"), n_reqs);
	n_req=(_T("You have ") + n_reqs_str + _T(" request(s)!"));
	requests.InsertColumn(0,L"Coach Name",LVCFMT_LEFT,150);
	requests.InsertColumn(1, L"Position", LVCFMT_LEFT, 50);
	requests.InsertColumn(2, L"Performance Requirements", LVCFMT_LEFT, 550);

	UpdateData(FALSE);


	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);		// Set small icon

	return TRUE;
}

BEGIN_MESSAGE_MAP(ReqstPlayers, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONSEEREQ, &ReqstPlayers::OnBnClickedButtonseereq)
END_MESSAGE_MAP()


// ReqstPlayers message handlers


void ReqstPlayers::OnBnClickedButtonseereq()
{
	UpdateData(TRUE);
	

	requests.DeleteAllItems();

	bool  first_item = TRUE;
	for (unsigned int i = 0; i < reqs_vector.size(); i++)
	{
		if (first_item)
		{
			requests.InsertItem(&reqs_vector[i]);

		}

		else
		{
			requests.SetItem(&reqs_vector[i]);
		}
		if (i < reqs_vector.size() - 1)
		{
			if (reqs_vector[i + 1].iSubItem > 0)
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
