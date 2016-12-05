
// SketcherView.h : interface of the CSketcherView class
//

#pragma once
#include "atltypes.h"
#include <memory>
#include "Element.h"

class CSketcherView : public CScrollView
{
protected: // create from serialization only
	CSketcherView();
	DECLARE_DYNCREATE(CSketcherView)

// Attributes
public:
	CSketcherDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	std::shared_ptr<CElement> CreateElement() const;


// Implementation
public:
	virtual ~CSketcherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	// First point recorded for an element
	CPoint m_FirstPoint;
	CPoint m_SecondPoint;
	std::shared_ptr<CElement> m_pTempElement;
	std::shared_ptr<CElement> m_pSelected;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	bool m_MoveMode{ false };
	CPoint m_CursorPos;
	CPoint m_FirstPos;
	void MoveElement(CClientDC& aDC, const CPoint& point);
public:
	virtual void OnInitialUpdate();
	void OnElementDelete();
	void OnElementMove();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);


	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnElementSendtoback();
};

#ifndef _DEBUG  // debug version in SketcherView.cpp
inline CSketcherDoc* CSketcherView::GetDocument() const
   { return reinterpret_cast<CSketcherDoc*>(m_pDocument); }
#endif

