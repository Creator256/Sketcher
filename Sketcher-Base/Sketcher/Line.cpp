#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
}

CLine::CLine(const CPoint& start, const CPoint& end, COLORREF color, int penWidth) : CElement{ start, color, penWidth }, m_EndPoint{ end } {

	m_EnclosingRect = CRect{ start, end };
	m_EnclosingRect.NormalizeRect();
	int width{ penWidth == 0 ? 1 : penWidth };
	m_EnclosingRect.InflateRect(width, width);
	
}

void CLine::Draw(CDC* pDC,std::shared_ptr<CElement> pElement) {
	CPen aPen;
	CreatePen(aPen, pElement);

	CPen* pOldPen{ pDC->SelectObject(&aPen) };
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);

	pDC->SelectObject(pOldPen);

}

void CLine::Move(const CSize& aSize) {
	m_StartPoint += aSize;
	m_EndPoint += aSize;
	m_EnclosingRect += aSize;
}

CLine::~CLine()
{
}
