#include "stdafx.h"
#include "Circle.h"
#include <cmath>

IMPLEMENT_SERIAL(CCircle, CElement, VERSION_NUMBER)
CCircle::CCircle()
{
}

CCircle::CCircle(const CPoint& start, const CPoint& end, COLORREF color, int penWidth) : CElement{ start, color, penWidth } 
{
	long radius{ static_cast<long> (sqrt(static_cast<double>((end.x - start.x)*(end.x - start.x) +(end.y - start.y)*(end.y - start.y)))) };
	if (radius < 1L) 		radius = 1L; // Circle radius must be >= 1
	// Define left-top and right-bottom points of rectangle for MM_TEXT mode	m_StartPoint = CPoint{ start.x - radius, start.y - radius };	m_BottomRight = CPoint{ start.x + radius, start.y + radius };
	// Define the enclosing rectangle	m_EnclosingRect = CRect{ m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y };
	int width{ penWidth == 0 ? 1 : penWidth };
	m_EnclosingRect.InflateRect(width, width);
}

void CCircle::Draw(CDC* pDC, std::shared_ptr<CElement> pElement)
{
	// Create a pen for this object and initialize it	// Create a pen for this object and initialize it
	CPen aPen;
	CreatePen(aPen, pElement);

	CPen* pOldPen{ pDC->SelectObject(&aPen) };  // Select the pen

												// Select a null brush
	CBrush* pOldBrush{ dynamic_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH)) };

	// Now draw the circle
	pDC->Ellipse(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);

	pDC->SelectObject(pOldPen);                // Restore the old pen
	pDC->SelectObject(pOldBrush);
}

void CCircle::Move(const CSize& aSize) {
	m_StartPoint += aSize;
	m_BottomRight += aSize;
	m_EnclosingRect += aSize;
}

void CCircle::Serialize(CArchive& ar)
{
	CElement::Serialize(ar); // Call the base class function
	if (ar.IsStoring())
	{ // Writing to the file
		ar << m_BottomRight; // Bottom-right point for the circle
	}
	else
	{ // Reading from the file
		ar >> m_BottomRight;
	}
}

CCircle::~CCircle()
{
}
