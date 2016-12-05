#include "stdafx.h"
#include "Line.h"
IMPLEMENT_SERIAL(CLine, CElement, VERSION_NUMBER)

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

void CLine::Serialize(CArchive& ar)
{
	CElement::Serialize(ar); // Call the base class function
	if (ar.IsStoring())
	{ // Writing to the file
		ar << m_EndPoint; // The end point
	}
	else
	{ // Reading from the file
		ar >> m_EndPoint; // The end point
	}
}

CLine::~CLine()
{
}
