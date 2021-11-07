#pragma once


// CPlayer_Info_Table dialog

class CPlayer_Info_Table : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayer_Info_Table)

public:
	CPlayer_Info_Table(CWnd* pParent = nullptr);   // standard constructor
	CString m_PlayerName;
	virtual ~CPlayer_Info_Table();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Player_Info_Table };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float goalkeeper_rating;
	float technical_rating;
	float mental_rating;
	CListCtrl gk_rating;
	CListCtrl tch_rating;
	CListCtrl ment_rating;
	CListCtrl bio_info;
	CListCtrl ag_info;
	CListCtrl fin_info;
	BOOL OnInitDialog();
	CString player_name;
	float physical_rating;
	CListCtrl phys_rating;
	afx_msg void OnBnClickedButtonrefered();
};
