#pragma once

// CElement command target

class CElement : public CObject
{

protected:
	CPoint m_StartPoint;
	int m_PenWidth;
	COLORREF m_Color;
	CRect m_EnclosingRect;

public:
	virtual ~CElement();
	virtual void Draw(CDC* pDC) {}

	const CRect& GetEnclosingRect() const {
		return m_EnclosingRect;
	}

protected:
	CElement();
	CElement(const CPoint& start, COLORREF color, int penWidth = 1);
protected:
	void CreatePen(CPen& aPen) {
		if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color)) {
			AfxMessageBox(_T("Pen creation failed."), MB_OK);
			AfxAbort();
		}
	}
};


