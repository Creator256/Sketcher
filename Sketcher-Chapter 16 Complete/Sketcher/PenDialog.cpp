// PenDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Sketcher.h"
#include "PenDialog.h"
#include "afxdialogex.h"


// CPenDialog dialog

IMPLEMENT_DYNAMIC(CPenDialog, CDialogEx)

CPenDialog::CPenDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PENWIDTH_DLG, pParent), m_PenWidth{}
{

}

CPenDialog::~CPenDialog()
{
}

void CPenDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPenDialog, CDialogEx)
	ON_BN_CLICKED(IDC_PENWITDH0, &CPenDialog::OnPenwitdh0)
	ON_BN_CLICKED(IDC_PENWITDH1, &CPenDialog::OnPenwitdh1)
	ON_BN_CLICKED(IDC_PENWITDH2, &CPenDialog::OnPenwitdh2)
	ON_BN_CLICKED(IDC_PENWITDH3, &CPenDialog::OnPenwitdh3)
	ON_BN_CLICKED(IDC_PENWITDH4, &CPenDialog::OnPenwitdh4)
	ON_BN_CLICKED(IDC_PENWITDH6, &CPenDialog::OnPenwitdh6)
END_MESSAGE_MAP()


// CPenDialog message handlers


BOOL CPenDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	switch (m_PenWidth) {
	case 1:
		CheckDlgButton(IDC_PENWITDH1, BST_CHECKED);
		break;
	case 2:
		CheckDlgButton(IDC_PENWITDH2, BST_CHECKED);
		break;
	case 3:
		CheckDlgButton(IDC_PENWITDH3, BST_CHECKED);
		break;
	case 4:
		CheckDlgButton(IDC_PENWITDH4, BST_CHECKED);
		break;
	case 5:
		//THIS IS PEN WIDTH 5 BECAUSE VS IS STUPID AND WOULDNT LET ME SET IT TO 5
		CheckDlgButton(IDC_PENWITDH6, BST_CHECKED);
		break;
	default:
		CheckDlgButton(IDC_PENWITDH0, BST_CHECKED);	
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPenDialog::OnPenwitdh0()
{
	m_PenWidth = 0;
}


void CPenDialog::OnPenwitdh1()
{
	m_PenWidth = 1;
}


void CPenDialog::OnPenwitdh2()
{
	m_PenWidth = 2;
}


void CPenDialog::OnPenwitdh3()
{
	m_PenWidth = 3;
}


void CPenDialog::OnPenwitdh4()
{
	m_PenWidth = 4;
}

//AGAIN, ITS 6 because VS is stupid
void CPenDialog::OnPenwitdh6()
{
	m_PenWidth = 5;
}
