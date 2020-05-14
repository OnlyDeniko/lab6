#pragma once

#include"TBase.h"
#include"TPoint.h"

class TLine : public TBase {
protected:
	TBase *left;
	TBase *right;
public:
	TLine(TPoint *_left, TPoint *_right) : TBase(_Line, _left->GetName() + ' ' + _right->GetName(), 7) {
		left = _left;
		right = _right;
	}
	TLine(const TLine & tmp);
	
	TLine &operator= (const TLine & tmp);
	~TLine() {
		delete left;
		delete right;
	}
	void SetLeft(TPoint* tmp);
	void SetRight(TPoint* tmp);
	TBase* GetLeft() const;
	TBase* GetRight() const;
	void Inverse();
	void Draw(System::Drawing::Graphics^ g) override;
	void IncRating() override;
	bool IsFigure(int _x, int _y) override;
	std::string to_string() override;
};

