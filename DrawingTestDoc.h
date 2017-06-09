
// DrawingTestDoc.h : CDrawingTestDoc ��Ľӿ�
//


#pragma once
#include <vector>
#include <utility>


class CDrawingTestDoc : public CDocument
{
protected: // �������л�����
	CDrawingTestDoc();
	DECLARE_DYNCREATE(CDrawingTestDoc)

// ����
public:
	void AddLine(CPoint, CPoint);
	const std::vector<std::pair<CPoint, CPoint>> *GetAllLines() const { return &m_lines; }
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDrawingTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	std::vector<std::pair<CPoint, CPoint>> m_lines;

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
