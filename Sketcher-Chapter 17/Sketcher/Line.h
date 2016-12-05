#pragma once
#include "Element.h"
static const UINT VERSION_NUMBER{ 1001 };
class CLine :
	public CElement
{
	DECLARE_SERIAL(CLine)
public:
	virtual ~CLine();
	virtual void Draw(CDC* pDC, std::shared_ptr<CElement> pElement = nullptr) override; // Function to display a line
	virtual void Serialize(CArchive& ar) override;																			// Constructor for a line object
	CLine(const CPoint& start, const CPoint& end, COLORREF aColor, int penWidth);
	virtual void Move(const CSize& aSize) override;                                   // Function to move an element
protected:
	CPoint m_EndPoint;                                                                // End point of line

protected:
	CLine();                                                                          // Default constructor should not be used
};


