#include "stdafx.h"
#include "Curve.h"
#include <algorithm>
IMPLEMENT_SERIAL(CCurve, CElement, VERSION_NUMBER)
CCurve::CCurve()
{
}

CCurve::CCurve(const CPoint& first, const CPoint& second, COLORREF color, int penWidth) : CElement{ first, color, penWidth } {
	m_Points.push_back(second);
	m_EnclosingRect = CRect{(std::min)(first.x, second.x), (std::min)(first.y, second.y),(std::max)(first.x, second.x), (std::max)(first.y, second.y) };
	int width{ penWidth == 0 ? 1 : penWidth };
	m_EnclosingRect.InflateRect(width, width);
}

void CCurve::Draw(CDC* pDC, std::shared_ptr<CElement> pElement) {
	CPen aPen;
	CreatePen(aPen, pElement);

	CPen* pOldPen{ pDC->SelectObject(&aPen) };
	pDC->MoveTo(m_StartPoint);
	for (const auto& point : m_Points) {
		pDC->LineTo(point);
	}

	pDC->SelectObject(pOldPen);
}

void CCurve::AddSegment(const CPoint& point) {

	m_Points.push_back(point);
	int width{ m_PenWidth == 0 ? 1 : m_PenWidth };
	m_EnclosingRect.DeflateRect(width, width);
	m_EnclosingRect = CRect{ (std::min)(point.x, m_EnclosingRect.left),(std::min)(point.y, m_EnclosingRect.top), (std::max)(point.x, m_EnclosingRect.right),(std::max)(point.y, m_EnclosingRect.bottom) };

	m_EnclosingRect.InflateRect(width, width);

}

void CCurve::Move(const CSize& aSize) {
	m_EnclosingRect += aSize;
	m_StartPoint += aSize;
	for (auto& p : m_Points) {
		p += aSize;
	}
}

void CCurve::Serialize(CArchive& ar)
{
	CElement::Serialize(ar); // Call the base class function
							 // Serialize the vector of points
	if (ar.IsStoring())
	{
		ar << m_Points.size(); // Store the point count
							   // Now store the points
		for(const auto& Point : m_Points)
		ar << Point;
	}
	else
	{
		size_t nPoints{}; // Stores number of points
		ar >> nPoints; // Retrieve the number of points
					   // Now retrieve the points
		CPoint point;
		for (size_t i{}; i < nPoints; ++i)
		{
			ar >> point;
			m_Points.push_back(point);
		}
	}
}

CCurve::~CCurve()
{
}
