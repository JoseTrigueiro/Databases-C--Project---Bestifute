#pragma once
#include <vector>
using namespace std;

// ReqstPlayers dialog

class ReqstPlayers : public CDialogEx
{
	DECLARE_DYNAMIC(ReqstPlayers)

public:
	ReqstPlayers(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ReqstPlayers();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REQSTPLAYERS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog();
	CString welc_message;
	CString n_req;
	afx_msg void OnBnClickedButtonseereq();
	CListCtrl requests;
	vector<LVITEM> reqs_vector;
	CString n_reqs_str;
};


