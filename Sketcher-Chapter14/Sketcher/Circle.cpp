#include "stdafx.h"
#include "Circle.h"
#include <cmath>


CCircle::CCircle()
{
}

CCircle::CCircle(const CPoint& start, const CPoint& end, COLORREF color) : CElement{ start, color } 
{
	long radius{ static_cast<long> (sqrt(static_cast<double>((end.x - start.x)*(end.x - start.x) +(end.y - start.y)*(end.y - start.y)))) };
	if (radius < 1L) 
	// Define left-top and right-bottom points of rectangle for MM_TEXT mode
	// Define the enclosing rectangle
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);
}

void CCircle::Draw(CDC* pDC)
{
	// Create a pen for this object and initialize it
	CPen aPen;
	CreatePen(aPen);

	CPen* pOldPen{ pDC->SelectObject(&aPen) };  // Select the pen

												// Select a null brush
	CBrush* pOldBrush{ dynamic_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH)) };

	// Now draw the circle
	pDC->Ellipse(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);

	pDC->SelectObject(pOldPen);                // Restore the old pen
	pDC->SelectObject(pOldBrush);
}

CCircle::~CCircle()
{
}