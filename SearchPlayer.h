#pragma once
#include <vector>

using namespace std;

// SearchPlayer dialog

class SearchPlayer : public CDialogEx
{
	DECLARE_DYNAMIC(SearchPlayer)

public:
	SearchPlayer(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SearchPlayer();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCHPLAYER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString player_name_search;
	CListCtrl m_PlayerList;
	vector<CString> PlayerName_vec;
	//void OnNMDblclkPlayerlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonplayers();
	afx_msg void OnNMDblclkPlayerlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedCheck1();
	BOOL v_check1;
	BOOL v_check2;
	afx_msg void OnBnClickedCheck2();
	CString player_name_search2;
	BOOL v_check3;
	afx_msg void OnBnClickedCheck3();
	CString player_name_search3;
	BOOL v_check4;
	CString player_name_search4;
	afx_msg void OnBnClickedCheck4();
	BOOL v_check5;
	afx_msg void OnBnClickedCheck5();
	CString player_name_search5;
	BOOL v_check6;
	CString player_name_search6;
	afx_msg void OnBnClickedCheck6();
	BOOL v_check7;
	CString player_name_search7;
	afx_msg void OnBnClickedCheck7();
	BOOL v_check8;
	CString player_name_search8;
	afx_msg void OnBnClickedCheck8();
	BOOL v_check9;
	CString player_name_search9;
	afx_msg void OnBnClickedCheck9();
	BOOL v_check10;
	CString player_name_search10;
	afx_msg void OnBnClickedCheck10();
	BOOL v_check11;
	BOOL v_check12;
	BOOL v_check13;
	BOOL v_check14;
	BOOL v_check15;
	BOOL v_check16;
	BOOL v_check17;
	BOOL v_check18;
	CString player_name_search11;
	CString player_name_search12;
	CString player_name_search13;
	CString player_name_search14;
	CString player_name_search15;
	CString player_name_search16;
	CString player_name_search17;
	CString player_name_search18;
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck16();
	afx_msg void OnBnClickedCheck17();
	afx_msg void OnBnClickedCheck18();
};
