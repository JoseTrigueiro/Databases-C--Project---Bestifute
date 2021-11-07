#pragma once


// AddNewPlayerDia dialog

class AddNewPlayerDia : public CDialogEx
{
	DECLARE_DYNAMIC(AddNewPlayerDia)

public:
	AddNewPlayerDia(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddNewPlayerDia();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNEWPLAYER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString np_name;
	int np_bdday;
	int np_bdmonth;
	int np_bdyear;
	CString np_country;
	CString np_club;
	CString np_position;
	int np_weight;
	int np_height;
	int np_preffootselected;
	afx_msg void OnBnClickedConfirmdata();
	int np_ic;
	BOOL PlayerLegal(int bday, int bmonth, int byear);
};
