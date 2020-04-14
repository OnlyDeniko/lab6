#include "TLine.h"

void TLine::SetLeft(TPoint * tmp) {
	left = tmp;
}

void TLine::SetRight(TPoint * tmp) {
	right = tmp;
}

TPoint * TLine::GetLeft() const {
	return left;
}

TPoint * TLine::GetRight() const {
	return right;
}

void TLine::Inverse() {
	TPoint* tmp = left;
	left = right;
	right = tmp;
	std::string newName;
	int index = Name.find(' ');
	newName += Name.substr(0, index);
	newName += ' ';
	newName += Name.substr(index + 1, Name.size());
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
	pen->Width = Width;
	g->DrawLine(pen, left->GetX() + left->GetWidth() / 2, left->GetY() + left->GetWidth() / 2, right->GetX() + right->GetWidth() / 2, right->GetY() + right->GetWidth() / 2);
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
