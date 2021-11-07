#pragma once


// REQUEST dialog

class REQUEST : public CDialogEx
{
	DECLARE_DYNAMIC(REQUEST)

public:
	REQUEST(CWnd* pParent = nullptr);   // standard constructor
	CString scout_name;
	virtual ~REQUEST();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REQUEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox scoutselected;
	CString p_req;
	
	afx_msg void OnBnClickedButton1();
	CString position;
};
