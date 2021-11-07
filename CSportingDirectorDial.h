#pragma once


// CSportingDirectorDial dialog

class CSportingDirectorDial : public CDialogEx
{
	DECLARE_DYNAMIC(CSportingDirectorDial)

public:
	CSportingDirectorDial(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSportingDirectorDial();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPORTDLOGDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
