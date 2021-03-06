
// MyProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyProgram.h"
#include "MyProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyProgramDlg dialog



CMyProgramDlg::CMyProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MYPROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC1, mpic1);
	DDX_Control(pDX, IDC_PIC2, mpic2);
	DDX_Control(pDX, IDC_PIC3, mpic3);
	DDX_Control(pDX, IDC_PIC4, mpic4);

	p = 1;

}

BEGIN_MESSAGE_MAP(CMyProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMyProgramDlg message handlers

BOOL CMyProgramDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyProgramDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyProgramDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CClientDC dc(this);
	GetClientRect(&rc);
	
	w1.left = rc.left;
	w1.right = rc.right-200;
	w1.top = rc.top;
	w1.bottom = rc.bottom-200;
	
	w2.left = rc.left+200;
	w2.right = rc.right;
	w2.top = rc.top;
	w2.bottom = rc.bottom - 200;

	w3.left = rc.left + 200;
	w3.right = rc.right;
	w3.top = rc.top+200;
	w3.bottom = rc.bottom;

	w4.left = rc.left;
	w4.right = rc.right-200;
	w4.top = rc.top + 200;
	w4.bottom = rc.bottom;

	if (PtInRect(&w1, point))
	{
		p = 1;
	}
	if (PtInRect(&w2, point))
	{
		p = 2;
	}
	if (PtInRect(&w3, point))
	{
		p = 3;
	}
	if (PtInRect(&w4, point))
	{
		p = 4;
	}

	pic1.LoadBitmapW(IDB_BITMAP1);
	pic2.LoadBitmapW(IDB_BITMAP2);
	pic3.LoadBitmapW(IDB_BITMAP3);
	pic4.LoadBitmapW(IDB_BITMAP4);

	
	switch (p)
	{
	case 1:
	{
		mpic1.SetBitmap(pic1);
		mpic2.SetBitmap(pic2);
		mpic3.SetBitmap(pic3);
		mpic4.SetBitmap(pic4);
	} break;
	case 2:
	{
		mpic1.SetBitmap(pic2);
		mpic2.SetBitmap(pic1);
		mpic3.SetBitmap(pic3);
		mpic4.SetBitmap(pic4);
	} break;
	case 3:
	{
		mpic1.SetBitmap(pic2);
		mpic2.SetBitmap(pic3);
		mpic3.SetBitmap(pic1);
		mpic4.SetBitmap(pic4);
	} break;
	case 4:
	{
		mpic1.SetBitmap(pic2);
		mpic2.SetBitmap(pic3);
		mpic3.SetBitmap(pic4);
		mpic4.SetBitmap(pic1);
	} break;

	}
	//dc.FillSolidRect(&w4, RGB(255, 255, 255));


	pic1.DeleteObject();
	pic2.DeleteObject();
	pic3.DeleteObject();
	pic4.DeleteObject();

	CDialog::OnLButtonDown(nFlags, point);
}
