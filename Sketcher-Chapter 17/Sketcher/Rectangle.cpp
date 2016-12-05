#include "stdafx.h"
#include "Rectangle.h"
#include <algorithm>
IMPLEMENT_SERIAL(CRectangle, CElement, VERSION_NUMBER)
CRectangle::CRectangle()
{
}

CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF color, int penWidth) : CElement{ start, color, penWidth } {

	m_StartPoint = CPoint{ (std::min)(start.x, end.x),(std::min)(start.y, end.y) };
	m_BottomRight = CPoint{ (std::max)(start.x, end.x), (std::max)(start.y, end.y) };
	// Ensure width and height between the points is at least 2
	if ((m_BottomRight.x - m_StartPoint.x) < 2)
		m_BottomRight.x = m_StartPoint.x + 2;
	if ((m_BottomRight.y - m_StartPoint.y) < 2)
		m_BottomRight.y = m_StartPoint.y + 2;
	// Define the enclosing rectangle
	m_EnclosingRect = CRect{ m_StartPoint, m_BottomRight };
	int width{ penWidth == 0 ? 1 : penWidth };
	m_EnclosingRect.InflateRect(width, width);
}

void CRectangle::Draw(CDC* pDC, std::shared_ptr<CElement> pElement) {

	CPen aPen;
	CreatePen(aPen, pElement);

	CPen* pOldPen{ pDC->SelectObject(&aPen) };
	CBrush* pOldBrush{ dynamic_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH)) };

	pDC->Rectangle(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

}

void CRectangle::Move(const CSize& aSize) {
	m_StartPoint += aSize;
	m_BottomRight += aSize;
	m_EnclosingRect += aSize;
}

void CRectangle::Serialize(CArchive& ar)
{
	CElement::Serialize(ar); // Call the base class function
	if (ar.IsStoring())
	{ // Writing to the file
		ar << m_BottomRight; // Bottom-right point for the rectangle
	}
	else
	{ // Reading from the file
		ar >> m_BottomRight;
	}
}

CRectangle::~CRectangle()
{
}
