#pragma once
#include "Element.h"
class CRectangle :
	public CElement
{
public:
	virtual void Draw(CDC* pDC, std::shared_ptr<CElement> pElement = nullptr) override;
	virtual void Move(const CSize& aSize) override;

	CRectangle(const CPoint& start, const CPoint& end, COLORREF color);
	virtual ~CRectangle();

protected:
	CPoint m_BottomRight;
	CRectangle();
};

