#include "TBase.h"

std::string TBase::GetType() const {
	if (Figure == _Point) {
		return "Point";
	}
	if (Figure == _Line) {
		return "Line";
	}
	if (Figure == _Rectangle) {
		return "Rectangle";
	}
	return "Curve";
}

bool TBase::GetVisability() const {
	return Visible;
}

int TBase::GetWidth() const {
	return Width;
}

int TBase::GetRating() const {
	return Rating;
}

std::string TBase::GetName() const {
	return Name;
}

int TBase::GetColor() const {
	return Color;
}

void TBase::SetColor(int _c) {
	Color = _c;
}

void TBase::SetWidth(int _width) {
	Width = _width;
}

void TBase::SetVisability(bool _vis) {
	Visible = _vis;
}
