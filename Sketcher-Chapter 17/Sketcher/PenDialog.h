#pragma once


// CPenDialog dialog

class CPenDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPenDialog)

public:
	CPenDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPenDialog();

// Dialog Data
enum {IDD = IDD_PENWIDTH_DLG};

//VAR
int m_PenWidth;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPenwitdh0();
	afx_msg void OnPenwitdh1();
	afx_msg void OnPenwitdh2();
	afx_msg void OnPenwitdh3();
	afx_msg void OnPenwitdh4();
	afx_msg void OnPenwitdh6();
};
