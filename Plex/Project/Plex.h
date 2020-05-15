#pragma once

#include"TLine.h"
#include"TBase.h"
#include"TLine.h"

class Plex {
private:
	TBase* start;
public:
	Plex(TLine* tmp = nullptr);
	Plex(const Plex & tmp);
	Plex &operator=(const Plex & tmp);
	~Plex() {
		delete start;
	}
	void InsertLine(TLine* le, TLine* ri);
	void addLine(TLine* tm);

	TLine* SearchLineWithPoint(const std::string & name);
	TLine* SearchLineWithPoint(int x, int y);

	TPoint* SearchPoint(const std::string & name);
	TPoint* SearchPoint(int x, int y);

	void Move(int dx, int dy);
	void Draw(System::Drawing::Graphics^ g);
	bool Empty()const;
	void saveGraph();
	void saveFile();
};

