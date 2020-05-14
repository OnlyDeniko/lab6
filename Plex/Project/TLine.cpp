#include "TLine.h"

TLine::TLine(const TLine & tmp) : TBase(_Line, tmp.left->GetName() + ' ' + tmp.right->GetName(), 7) {
	left = tmp.left;
	right = tmp.right;
	Figure = tmp.Figure;
	Name = tmp.Name;
	Visible = tmp.Visible;
	Color = tmp.Color;
	R = tmp.R;
	Width = tmp.Width;
	Rating = tmp.Rating;
}

TLine & TLine::operator=(const TLine & tmp) {
	if (this == &tmp) return *this;
	if (left) delete left;
	if (right) delete right;
	left = tmp.left;
	right = tmp.right;
	Figure = tmp.Figure;
	Name = tmp.Name;
	Visible = tmp.Visible;
	Color = tmp.Color;
	R = tmp.R;
	Width = tmp.Width;
	Rating = tmp.Rating;
	return *this;
}

void TLine::SetLeft(TPoint * tmp) {
	left = tmp;
}

void TLine::SetRight(TPoint * tmp) {
	right = tmp;
}

TBase * TLine::GetLeft() const {
	return left;
}

TBase * TLine::GetRight() const {
	return right;
}

void TLine::Inverse() {
	TBase* tmp = left;
	left = right;
	right = tmp;
	std::string newName;
	int index = Name.find(' ');
	newName += Name.substr(index + 1, Name.size());
	newName += ' ';
	newName += Name.substr(0, index);
	Name = newName;
}

void TLine::Draw(System::Drawing::Graphics ^ g) {
	if (!Visible) return;
	int red, green, blue;
	int tmp = Color;
	blue = tmp % 256;
	tmp /= 256;
	green = tmp % 256;
	tmp /= 256;
	red = tmp;
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(
		System::Drawing::Color::FromArgb(255, red, green, blue));
	pen->Width = R;
	g->DrawLine(pen, ((TPoint*)left)->GetX() + ((TPoint*)left)->GetWidth() / 2, ((TPoint*)left)->GetY() + ((TPoint*)left)->GetWidth() / 2, 
		((TPoint*)right)->GetX() + ((TPoint*)right)->GetWidth() / 2, ((TPoint*)right)->GetY() + ((TPoint*)right)->GetWidth() / 2);
}

void TLine::IncRating() {
	Rating++;
}

bool TLine::IsFigure(int _x, int _y) {
	if (left->IsFigure(_x, _y) || right->IsFigure(_x, _y)) return true;
	//пока не знаю
}

std::string TLine::to_string() {
	std::string ans;
	ans += left->to_string();
	ans += ' ';
	ans += right->to_string();
	return ans;
}
