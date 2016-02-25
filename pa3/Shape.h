#pragma once
#include <wx/dc.h>

// Abstract base class for all Shapes
class Shape
{
public:
	Shape(const wxPoint& start);
	// Tests whether the provided point intersects
	// with this shape
	bool Intersects(const wxPoint& point) const;
	// Update shape with new provided point
	virtual void Update(const wxPoint& newPoint);
	// Finalize the shape -- when the user has finished drawing the shape
	virtual void Finalize();
	// Returns the top left/bottom right points of the shape
	void GetBounds(wxPoint& topLeft, wxPoint& botRight) const;
	// Draw the shape
	virtual void Draw(wxDC& dc) const = 0;
	virtual ~Shape() { }

	void SetPen(const wxPen& pen) { mPen = pen; }
	void SetBrush(const wxBrush& brush) { mBrush = brush; }

	wxPen GetPen() const { return mPen; }
	wxBrush GetBrush() const { return mBrush; }

	void DrawSelection(wxDC& dc);

	void SetSelected(const bool selected) { mSelected = selected; };

	bool IsSelected() const { return mSelected; }

	void Move(const wxPoint moveLoc) { mOffSet+= moveLoc - mStartPoint; }
	wxPoint GetOffSets() const { return mOffSet; }


protected:
	// Starting point of shape
	wxPoint mStartPoint;
	// Ending point of shape
	wxPoint mEndPoint;
	// Top left point of shape
	wxPoint mTopLeft;
	// Bottom right point of shape
	wxPoint mBotRight;

	wxBrush mBrush;
	
	wxPen mPen; 

	wxPoint mOffSet; 

	bool mSelected; 
};
