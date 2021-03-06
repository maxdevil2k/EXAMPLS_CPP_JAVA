
// OlympicEmblemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OlympicEmblem.h"
#include "OlympicEmblemDlg.h"
#include "afxdialogex.h"

#include <time.h>

using namespace std;



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COlympicEmblemDlg dialog



COlympicEmblemDlg::COlympicEmblemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_OLYMPICEMBLEM_DIALOG, pParent)
{
	srand((unsigned)time(NULL)); // генератор випадкових чисел
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COlympicEmblemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COlympicEmblemDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// COlympicEmblemDlg message handlers

BOOL COlympicEmblemDlg::OnInitDialog()
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

void COlympicEmblemDlg::OnPaint()
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

		hNew = CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Times New Roman Cyr");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO

		int minX = rc.left;
		int maxX = rc.right;
		int minY = rc.top;
		int maxY = rc.bottom;

		int d, cb, cq, cr;

		for (k = 0; k < 50; k++)
		{
			cr = rand() % 255;
			cq = rand() % 255;
			cb = rand() % 255;
			cf = RGB(cr, cq, cb);
			hPenOxy = CreatePen(PS_SOLID, rand() % 14, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);

			x1 = minX + rand() % (maxX - minX + 1);
			y1 = minY + rand() % (maxY - minY + 1);
			x2 = minX + rand() % (maxX - minX + 1);
			y2 = minY + rand() % (maxY - minY + 1);

			dc.Rectangle(x1, y1, x2, y2); // випадкові прямокутники

			cr = rand() % 255;
			cq = rand() % 255;
			cb = rand() % 255;
			cf = RGB(cr, cq, cb);
			hPenOxy = CreatePen(PS_SOLID, rand() % 14, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);

			x1 = minX + rand() % (maxX - minX + 1);
			y1 = minY + rand() % (maxY - minY + 1);
			x2 = minX + rand() % (maxX - minX + 1);
			y2 = minY + rand() % (maxY - minY + 1);

			// випадкові зафарбовані прямокутники
			dc.FillSolidRect(x1 + 5, y1 + 5, x2 - 5, y2 - 5, cf);
			
			cr = rand() % 255;
			cq = rand() % 255;
			cb = rand() % 255;
			cf = RGB(cr, cq, cb);
			hPenOxy = CreatePen(PS_SOLID, rand() % 14, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);

			x1 = minX + rand() % (maxX - minX + 1);
			y1 = minY + rand() % (maxY - minY + 1);
			x2 = minX + rand() % (maxX - minX + 1);
			y2 = minY + rand() % (maxY - minY + 1);

			dc.Ellipse(x1, y1, x2, y2); // випадкові еліпси
			
			cr = rand() % 255;
			cq = rand() % 255;
			cb = rand() % 255;
			cf = RGB(cr, cq, cb);
			hPenOxy = CreatePen(PS_SOLID, rand() % 14, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);

			x1 = minX + rand() % (maxX - minX + 1);
			y1 = minY + rand() % (maxY - minY + 1);
			d = rand() % 50;
			
			// випадкові кола
			Circl(x1, y1, d, rand() % 12, cf);

			Sleep(5);

		}



		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);
		hold = (HFONT)SelectObject(dc, hbk);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COlympicEmblemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



afx_msg void COlympicEmblemDlg::Circl(int X, int Y, int D, int WDT, COLORREF CF)
{
	CClientDC dc(this);

	hPenOxy = CreatePen(PS_SOLID, WDT, CF);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	double xf, yf, f;
	f = 0;

	dc.MoveTo(X + D / 2, Y);

	do
	{
		xf = D / 2 * cos(f);
		yf = D / 2 * sin(f);
		//dc.SetPixel(xf+X, yf+Y, cf);
		dc.LineTo(xf + X, yf + Y);
		f += 0.9;
	} while (f <= 360);
}