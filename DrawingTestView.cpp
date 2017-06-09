
// DrawingTestView.cpp : CDrawingTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CDrawingTestView 构造/析构

CDrawingTestView::CDrawingTestView()
{
	// TODO: 在此处添加构造代码

}

CDrawingTestView::~CDrawingTestView()
{
}

BOOL CDrawingTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawingTestView 绘制

void CDrawingTestView::OnDraw(CDC* pDC)
{
	CDrawingTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	auto plines = pDoc->GetAllLines();
	for (auto line : *plines)
	{
		DrawLine(line.first, line.second);
	}

}


// CDrawingTestView 诊断

#ifdef _DEBUG
void CDrawingTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawingTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawingTestDoc* CDrawingTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingTestDoc)));
	return (CDrawingTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingTestView 消息处理程序


void CDrawingTestView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	m_bDraw = FALSE;

	CView::OnRButtonUp(nFlags, point);
}


void CDrawingTestView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin  = point;            //将当前鼠标按下的位置用m_ptOrigin记录
	m_bDraw = TRUE;                        //将鼠标按下标志置为TURE

	CView::OnRButtonDown(nFlags, point);
}


void CDrawingTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_bDraw == TRUE)
	{
		///画曲线
		//CDC *pDC = GetDC();                      //获取一个CDC类对象的指针
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

		m_ptOrigin = point;       //将终点设为下一次画线的起点。。。。这样不断循环，直到鼠标弹起，跳出循环结束画线。
	}

	CView::OnMouseMove(nFlags, point);
}


void CDrawingTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CDC *pDC = GetDC();                      //获取一个CDC类对象的指针
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin = point;            //将当前鼠标按下的位置用m_ptOrigin记录

	CView::OnLButtonDown(nFlags, point);
}

void CDrawingTestView::DrawLine(CPoint a, CPoint b)
{
	CPen pen(PS_SOLID, 1, m_color);        //创建一个笔（CPen类封装了跟画笔相关的操作）
											//（线型，线粗，线色）
	CClientDC dc(this);                                                //创建一个DC
	CPen *pOldPen = dc.SelectObject(&pen);           //将笔选到设备描述表中
	dc.MoveTo(a);
	dc.LineTo(b);
	dc.SelectObject(pOldPen);
}

void CDrawingTestView::OnColorBlack()
{
	// TODO: 在此添加命令处理程序代码
	m_color = RGB(0, 0, 0);
}


void CDrawingTestView::OnColorBlue()
{
	// TODO: 在此添加命令处理程序代码
	m_color = RGB(0, 0, 255);
}


void CDrawingTestView::OnColorGreen()
{
	// TODO: 在此添加命令处理程序代码
	m_color = RGB(0, 255, 0);
}


void CDrawingTestView::OnColorRed()
{
	// TODO: 在此添加命令处理程序代码
	m_color = RGB(255, 0, 0);
}
