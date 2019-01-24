
// ProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramDlg dialog



CProgramDlg::CProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramDlg message handlers

BOOL CProgramDlg::OnInitDialog()
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

void CProgramDlg::OnPaint()
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
		
		CClientDC dc(this);
		GetClientRect(&rc);

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 4, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);

		cx = RH / 2;
		cy = RW / 2;

		dx = cx / 8;
		dy = cy / 6;

		x1 = w.left = cx;
		y1 = w.top = cy - 4*dy;
		x2 = w.right = cx;
		y2 = w.bottom = cy+4*dy;

		CorpusSpaceShip(x1, y1, x2, y2, dx, dy);


		// корпус ракеты
		/*
		dc.MoveTo(x1, y1);
		dc.LineTo(x1 + dx, y1 + 2.5*dy);
		dc.LineTo(x1 + dx, y1 + 8*dy);
		dc.LineTo(x2, y2);
		dc.MoveTo(x1, y1);
		dc.LineTo(x1 - dx, y1 + 2.5*dy);
		dc.LineTo(x1 - dx, y1 + 8 * dy);
		dc.LineTo(x2, y2);
		*/


		/*
		int r1, r2;

		r1 = 110;
		r2 = 100;

		x = x1 - 2.1*dx;
		y = y2;
		dc.Ellipse(x, y, x + r1, y + r1);

		x = x1 - 2.5*dx;
		y = y2 - dy*0.45;
		dc.Ellipse(x + r2 / 2, y + r2 / 2, x + r2, y + r2);

		x = x2 - 4.1*dx;
		y = y2;
		dc.Ellipse(x, y, x + r1, y + r1);

		x = x2 - 4.5*dx;
		y = y2 - dy * 0.45;
		dc.Ellipse(x + r2 / 2, y + r2 / 2, x + r2, y + r2);
		*/



		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProgramDlg::CorpusSpaceShip(int X1, int Y1, int X2, int Y2, int DX, int DY)
{
	CClientDC dc(this);
	GetClientRect(&rc);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 4, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);


	dx = DX;
	dy = DY;

	x1 = X1;
	y1 = Y1;
	x2 = X2;
	y2 = Y2;

	// корпус ракеты
	dc.MoveTo(x1, y1);
	dc.LineTo(x1 + dx, y1 + 2.5*dy);
	dc.LineTo(x1 + dx, y1 + 8 * dy);
	dc.LineTo(x2, y2);
	dc.MoveTo(x1, y1);
	dc.LineTo(x1 - dx, y1 + 2.5*dy);
	dc.LineTo(x1 - dx, y1 + 8 * dy);
	dc.LineTo(x2, y2);

}
