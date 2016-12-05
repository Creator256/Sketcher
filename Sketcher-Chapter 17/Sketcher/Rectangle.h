#pragma once
#include "Element.h"
static const UINT VERSION_NUMBER{ 1001 };
class CRectangle :
	public CElement
{
	DECLARE_SERIAL(CRectangle)
public:
	virtual void Draw(CDC* pDC, std::shared_ptr<CElement> pElement = nullptr) override;
	virtual void Move(const CSize& aSize) override;
	virtual void Serialize(CArchive& ar) override;
	CRectangle(const CPoint& start, const CPoint& end, COLORREF color, int penWidth);
	virtual ~CRectangle();

protected:
	CPoint m_BottomRight;
	CRectangle();
};

