
// DrawingTestView.h : CDrawingTestView 类的接口
//

#pragma once


class CDrawingTestView : public CView
{
protected: // 仅从序列化创建
	CDrawingTestView();
	DECLARE_DYNCREATE(CDrawingTestView)

// 特性
public:
	CDrawingTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CDrawingTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint m_ptOrigin;      //用来记录鼠标按下时的点          
	BOOL m_bDraw;           //鼠标按下的标志，用来判断鼠标弹起来了没有
	// CPoint m_ptOld;         //用来记录鼠标的移动路劲
	COLORREF m_color;

	void DrawLine(CPoint, CPoint);

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColorBlack();
	afx_msg void OnColorBlue();
	afx_msg void OnColorGreen();
	afx_msg void OnColorRed();
};

#ifndef _DEBUG  // DrawingTestView.cpp 中的调试版本
inline CDrawingTestDoc* CDrawingTestView::GetDocument() const
   { return reinterpret_cast<CDrawingTestDoc*>(m_pDocument); }
#endif

