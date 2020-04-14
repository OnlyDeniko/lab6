#pragma once

#include<string>

enum TypeFigure { _Point, _Line, _Rectangle, _Curve };

class TBase {
protected:
	TypeFigure Figure;
	std::string Name;
	bool Visible;
	int Color;
	int R;
	int Width;
	int Rating;
public:
	TBase(TypeFigure _type = _Point, std::string _name = "", bool _visible = true,
			int _color = 100, int _r = 1, int _width = 100, int _rating = 1) :
				Figure(_type), Name(_name), Visible(_visible), Color(_color), R(_r), 
					Width(_width), Rating(_rating) {};
	~TBase() {};
	std::string GetType() const;
	bool GetVisability() const;
	int GetWidth() const;
	int GetRating() const;
	std::string GetName() const;
	int GetColor() const;
	void SetColor(int _c);
	void SetWidth(int _width);
	void SetVisability(bool _vis);
	virtual void IncRating() = 0;
	virtual void Draw(System::Drawing::Graphics^ g) = 0;
	virtual bool IsFigure(int _x, int _y) = 0;
	virtual std::string to_string() = 0;
};

