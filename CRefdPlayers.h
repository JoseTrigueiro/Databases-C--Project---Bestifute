#pragma once
#include <vector>
using namespace std;

// CRefdPlayers dialog

class CRefdPlayers : public CDialogEx
{
	DECLARE_DYNAMIC(CRefdPlayers)

public:
	CRefdPlayers(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRefdPlayers();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REFDPLAYERS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString m_welcomemessage;
	CListCtrl m_refd_player_list;
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	vector<CString> RefName_vec;

};
