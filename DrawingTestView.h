
// DrawingTestView.h : CDrawingTestView ��Ľӿ�
//

#pragma once


class CDrawingTestView : public CView
{
protected: // �������л�����
	CDrawingTestView();
	DECLARE_DYNCREATE(CDrawingTestView)

// ����
public:
	CDrawingTestDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CDrawingTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint m_ptOrigin;      //������¼��갴��ʱ�ĵ�          
	BOOL m_bDraw;           //��갴�µı�־�������ж���굯������û��
	// CPoint m_ptOld;         //������¼�����ƶ�·��
	COLORREF m_color;

	void DrawLine(CPoint, CPoint);

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // DrawingTestView.cpp �еĵ��԰汾
inline CDrawingTestDoc* CDrawingTestView::GetDocument() const
   { return reinterpret_cast<CDrawingTestDoc*>(m_pDocument); }
#endif

