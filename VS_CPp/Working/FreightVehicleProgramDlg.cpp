
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
	CDialog::DoDataExchange(pDX);

	SetWindowTextW(L"Автомобіль для вантажних перевезень");
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
		hPenOxy = CreatePen(PS_SOLID, 12, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		x1 = w.left = rc.left + 275;
		x2 = w.right = rc.right - 120;
		y1 = w.top = rc.top + 70;
		y2 = w.bottom = rc.bottom - 225;

		//FreightVehicle(x1, y1, x2, y2);

        dc.Rectangle(&w);

		w.left = x1 - 170;
		w.top = y1 + 247;
		w.right = x2 - 40;
		w.bottom = y2 + 51;

		dc.Rectangle(&w);

		
		dc.MoveTo(x1 - 110, y1 + 60);
		dc.LineTo(x2 - 425, y1 + 60);
		dc.LineTo(x2 - 425, y2 - 80);
		dc.LineTo(x1 - 150, y2 - 80);
		dc.LineTo(x1 - 110, y1 + 60);
		
		dc.MoveTo(x1 - 135, y1 + 35);
		dc.LineTo(x2 - 400, y1 + 35);
		dc.LineTo(x2 - 400, y2);
		
		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 24, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		dc.MoveTo(x2 - 418, y2);
		dc.LineTo(x1 - 160, y2);
		
		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 12, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		
		dc.MoveTo(x1 - 170, y2+10);
		dc.LineTo(x1 - 170, y2 - 120);
		dc.LineTo(x1 - 135, y1 + 35);
		
		int r1 = 110;
		x = x2 - 200;
		y = y2;

		dc.Ellipse(x, y, x + r1, y + r1);

		int r2 = 100;
		x = x2 - 220;
		y = y2 - 20;

		dc.Ellipse(x + r2 / 2, y + r2 / 2, x + r2, y + r2);

		r1 = 110;
		x = x1 - 121;
		y = y2;

		dc.Ellipse(x, y, x + r1, y + r1);

		r2 = 100;
		x = x1 - 141;
		y = y2 - 20;

		dc.Ellipse(x + r2 / 2, y + r2 / 2, x + r2, y + r2);

		//Kolco(x2 - 200, y2, 110, 100);
		//Kolco(x1 - 121, y2, 110, 100);


		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);

		CDialog::OnPaint();

	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

afx_msg void CProgramDlg::FreightVehicle(int xf, int yf, int xs, int ys)
{
	CClientDC dc(this);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 12, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	w.left = xf;
	w.right = xs;
	w.top = yf;
	w.bottom = ys;

	dc.Rectangle(&w);

	w.left = xf - 170;
	w.top = yf + 247;
	w.right = xs - 40;
	w.bottom = ys + 51;

	dc.Rectangle(&w);


	dc.MoveTo(xf - 110, yf + 60);
	dc.LineTo(xs - 425, yf + 60);
	dc.LineTo(xs - 425, ys - 80);
	dc.LineTo(xf - 150, ys - 80);
	dc.LineTo(xf - 110, yf + 60);

	dc.MoveTo(xf - 135, yf + 35);
	dc.LineTo(xs - 400, yf + 35);
	dc.LineTo(xs - 400, ys);

	cf = RGB(255, 255, 255);
	hPenOxy = CreatePen(PS_SOLID, 24, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);
	dc.MoveTo(xs - 418, ys);
	dc.LineTo(xf - 160, ys);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 12, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	dc.MoveTo(xf - 170, ys + 10);
	dc.LineTo(xf - 170, ys - 120);
	dc.LineTo(xf - 135, yf + 35);

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);

}


afx_msg void CProgramDlg::Kolco(int xc, int yc, int rc1, int rc2)
{
	CClientDC dc(this);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 12, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	dc.Ellipse(xc, yc, xc + rc1, yc + rc1);
	dc.Ellipse(xc-20 + rc2 / 2, yc-20 + rc2 / 2, xc-20 + rc2, yc-20 + rc2);

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
}