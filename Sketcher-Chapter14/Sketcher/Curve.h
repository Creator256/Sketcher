#pragma once
#include "Element.h"
#include <vector>
class CCurve :
	public CElement
{
public:
	virtual ~CCurve();
	virtual void Draw(CDC* pDC) override;

	CCurve(const CPoint& first, const CPoint& second, COLORREF color);
	void AddSegment(const CPoint& point);

protected:
	std::vector<CPoint> m_Points;
	CCurve();

};

