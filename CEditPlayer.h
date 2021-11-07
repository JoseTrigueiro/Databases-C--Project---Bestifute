#pragma once


// CEditPlayer dialog

class CEditPlayer : public CDialogEx
{
	DECLARE_DYNAMIC(CEditPlayer)

public:
	CEditPlayer(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEditPlayer();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITPLAYER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString np_name;
	afx_msg void OnBnClickedSearch();
	CString ep_club;
	int ep_bdmonth;
	int ep_bdyear;
	CString ep_country;
	CString ep_position;
	int ep_height;
	int ep_bdday;
	int ep_weight;
	int ep_ic;
	int ep_preffootselected;
	float ep_newcontractlength;
	int ep_cedyear;
	int ep_cedmonth;
	int ep_cedday;
	float ep_desiredwage;
	float ep_currentwage;
	float ep_agentfee;
	float ep_signingfee;
	float ep_transferfee;
	int ep_handling;
	int ep_reflexes;
	int ep_passing;
	int ep_shoot;
	int ep_dribbling;
	int ep_positioning;
	int ep_speed;
	int ep_stamina;
	int ep_strength;
	int ep_tackling;
	int ep_leadership;
	afx_msg void OnBnClickedConfirmdata();
	BOOL PlayerLegal(int bday, int bmonth, int byear);
	BOOL IsContractUp(int bday, int bmonth, int byear);
};
