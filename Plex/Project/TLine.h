#pragma once

#include"TBase.h"
#include"TPoint.h"

class TLine : public TBase {
protected:
	TPoint *left;
	TPoint *right;
public:
	TLine(TPoint *_left, TPoint *_right, std::string _name, bool _vis = true, 
		int _color = 0, int _r = 5, int _width = 4, int _rating = 1) :
		TBase(_Line, _name, _vis, _color, _r, _width, _rating), left(_left), right(_right){};
	~TLine() {
		delete left;
		delete right;
	}
	void SetLeft(TPoint* tmp);
	void SetRight(TPoint* tmp);
	TPoint* GetLeft() const;
	TPoint* GetRight() const;
	void Inverse();
	void Draw(System::Drawing::Graphics^ g) override;
	void IncRating() override;
	bool IsFigure(int _x, int _y) override;
	std::string to_string() override;
};

