#include "TPoint.h"

TPoint::TPoint(const TPoint & Copy) {
	X = Copy.X;
	Y = Copy.Y;
	Figure = Copy.Figure;
	Name = Copy.Name;
	Visible = Copy.Visible;
	Color = Copy.Color;
	R = Copy.R;
	Width = Copy.Width;
	Rating = Copy.Rating;
}

TPoint & TPoint::operator=(const TPoint & Copy) {
	if (this == &Copy) return *this;
	X = Copy.X;
	Y = Copy.Y;
	Figure = Copy.Figure;
	Name = Copy.Name;
	Visible = Copy.Visible;
	Color = Copy.Color;
	R = Copy.R;
	Width = Copy.Width;
	Rating = Copy.Rating;
	return *this;
}

int TPoint::GetX() const {
	return X;
}

int TPoint::GetY() const {
	return Y;
}

void TPoint::MovePoint(int dx, int dy) {
	X += dx;
	Y += dy;
}

void TPoint::Draw(System::Drawing::Graphics ^ g) {
	if (Visible == false) return;
	int red, green, blue;
	int tmp = Color;
	blue = tmp % 256;
	tmp /= 256;
	green = tmp % 256;
	tmp /= 256;
	red = tmp;
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(
		System::Drawing::Color::FromArgb(255, red, green, blue));
	g->FillEllipse(brush, X, Y, Width, Width);
}

void TPoint::DecRating() {
	if (Rating > 0) Rating--;
}

void TPoint::IncRating() {
	Rating++;
}

bool TPoint::IsFigure(int _x, int _y) {
	auto sqr = [](int x) ->long long {
		return (long long)x * x;
	};
	if (sqr(_x - X) + sqr(_y - Y) <= sqr(R)) return 1;
	return 0;
}

std::string TPoint::to_string() {
	std::string ans;
	ans += "X = " + std::to_string(X);
	ans += "Y = " + std::to_string(Y);
	return ans;
}
