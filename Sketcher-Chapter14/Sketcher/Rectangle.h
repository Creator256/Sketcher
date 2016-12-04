#pragma once
#include "Element.h"
class CRectangle :
	public CElement
{
public:
	virtual void Draw(CDC* pDC) override;
	CRectangle(const CPoint& start, const CPoint& end, COLORREF color);
	virtual ~CRectangle();

protected:
	CPoint m_BottomRight;
	CRectangle();
};

