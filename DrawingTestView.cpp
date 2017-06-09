
// DrawingTestView.cpp : CDrawingTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DrawingTest.h"
#endif

#include "DrawingTestDoc.h"
#include "DrawingTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingTestView

IMPLEMENT_DYNCREATE(CDrawingTestView, CView)

BEGIN_MESSAGE_MAP(CDrawingTestView, CView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_COLOR_BLACK, &CDrawingTestView::OnColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, &CDrawingTestView::OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, &CDrawingTestView::OnColorGreen)
	ON_COMMAND(ID_COLOR_RED, &CDrawingTestView::OnColorRed)
END_MESSAGE_MAP()

// CDrawingTestView ����/����

CDrawingTestView::CDrawingTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CDrawingTestView::~CDrawingTestView()
{
}

BOOL CDrawingTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawingTestView ����

void CDrawingTestView::OnDraw(CDC* pDC)
{
	CDrawingTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	auto plines = pDoc->GetAllLines();
	for (auto line : *plines)
	{
		DrawLine(line.first, line.second);
	}

}


// CDrawingTestView ���

#ifdef _DEBUG
void CDrawingTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawingTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawingTestDoc* CDrawingTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingTestDoc)));
	return (CDrawingTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingTestView ��Ϣ�������


void CDrawingTestView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	m_bDraw = FALSE;

	CView::OnRButtonUp(nFlags, point);
}


void CDrawingTestView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptOrigin  = point;            //����ǰ��갴�µ�λ����m_ptOrigin��¼
	m_bDraw = TRUE;                        //����갴�±�־��ΪTURE

	CView::OnRButtonDown(nFlags, point);
}


void CDrawingTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_bDraw == TRUE)
	{
		///������
		//CDC *pDC = GetDC();                      //��ȡһ��CDC������ָ��
		//pDC->MoveTo(m_ptOrigin);
		//pDC->LineTo(point);
		//ReleaseDC(pDC);
		DrawLine(m_ptOrigin, point);

		// save the line to the document class
		CDrawingTestDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		pDoc->AddLine(m_ptOrigin, point);

		m_ptOrigin = point;       //���յ���Ϊ��һ�λ��ߵ���㡣��������������ѭ����ֱ����굯������ѭ���������ߡ�
	}

	CView::OnMouseMove(nFlags, point);
}


void CDrawingTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CDC *pDC = GetDC();                      //��ȡһ��CDC������ָ��
	//pDC->MoveTo(m_ptOrigin);
	//pDC->LineTo(point);
	//ReleaseDC(pDC);
	DrawLine(m_ptOrigin, point);

	// save the line to the document class
	CDrawingTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->AddLine(m_ptOrigin, point);

	CView::OnLButtonUp(nFlags, point);
}


void CDrawingTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptOrigin = point;            //����ǰ��갴�µ�λ����m_ptOrigin��¼

	CView::OnLButtonDown(nFlags, point);
}

void CDrawingTestView::DrawLine(CPoint a, CPoint b)
{
	CPen pen(PS_SOLID, 1, m_color);        //����һ���ʣ�CPen���װ�˸�������صĲ�����
											//�����ͣ��ߴ֣���ɫ��
	CClientDC dc(this);                                                //����һ��DC
	CPen *pOldPen = dc.SelectObject(&pen);           //����ѡ���豸��������
	dc.MoveTo(a);
	dc.LineTo(b);
	dc.SelectObject(pOldPen);
}

void CDrawingTestView::OnColorBlack()
{
	// TODO: �ڴ���������������
	m_color = RGB(0, 0, 0);
}


void CDrawingTestView::OnColorBlue()
{
	// TODO: �ڴ���������������
	m_color = RGB(0, 0, 255);
}


void CDrawingTestView::OnColorGreen()
{
	// TODO: �ڴ���������������
	m_color = RGB(0, 255, 0);
}


void CDrawingTestView::OnColorRed()
{
	// TODO: �ڴ���������������
	m_color = RGB(255, 0, 0);
}
