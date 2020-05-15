#include "Plex.h"
#include<fstream>

#include<vector>

Plex::Plex(TLine * tmp) {
	start = new TLine(*tmp);
}

void dfsCopy(TBase* start, TBase* x) {
	if (x->GetType() == _Point) {
		start = new TPoint(*((TPoint*)(x)));
	}
	else if (x->GetType() == _Line) {
		start = new TLine(*((TLine*)(x)));
		if (((TLine*)(x))->GetLeft()) {
			dfsCopy(((TLine*)(start))->GetLeft(), ((TLine*)(x))->GetLeft());
		}
		if (((TLine*)(x))->GetRight()) {
			dfsCopy(((TLine*)(start))->GetRight(), ((TLine*)(x))->GetRight());
		}
	}
}

Plex::Plex(const Plex & tmp) {
	dfsCopy(start, tmp.start);
}

Plex & Plex::operator=(const Plex & tmp) {
	if (this == &tmp) return *this;
	if (start) delete start;
	dfsCopy(start, tmp.start);
	return *this;
}

void Plex::InsertLine(TLine * le, TLine * ri) {
	if (le->GetLeft()->GetName() == ri->GetLeft()->GetName()) {
		ri->SetLeft(le->GetLeft());
		le->SetLeft(ri);
	}
	else {
		ri->SetLeft(le->GetRight());
		le->SetRight(ri);
	}
}

void Plex::addLine(TLine * tm) {
	TLine* tmp = new TLine(*tm);
	std::fstream err;
	err.open("Errors.txt", std::ios::out);
	if (start == nullptr) {
		start = tmp;
		return;
	}
	TLine* le = SearchLineWithPoint(tmp->GetLeft()->GetName());
	TLine* ri = SearchLineWithPoint(tmp->GetRight()->GetName());
	if (le && !ri) {
		InsertLine(le, tmp);
	} else if (!le && ri) {
		tmp->Inverse();
		InsertLine(ri, tmp);
	} else if (le && ri) {
		err << "HERE\n";
		err << "LINK: ";
		err << le->to_string() << ' ' << tmp->to_string() << '\n';
		err << ri->to_string() << '\n';
		InsertLine(le, tmp);
		if (ri->GetLeft()->GetName() == tmp->GetLeft()->GetName()) {
			ri->GetLeft()->IncRating();
			//delete tmp->GetRight();
			err << "!" << '\n';
			tmp->SetRight(ri->GetLeft());
			tmp->GetRight()->IncRating();
		} else {
			//delete tmp->GetRight();
			//err << "!!" << '\n';
			//ri->GetRight()->IncRating();
			//tmp->SetRight(ri->GetRight());
			tmp->GetRight()->IncRating();
		}

	}
	err.close();
}

TLine* dfsSearchLine(TBase* x, int &find, const std::string & name) {
	if (x->GetType() == _Point) {
		if (x->GetName() == name) {
			find = 1;
			return nullptr;
		}
	}
	else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetLeft(), find, name);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
		if (((TLine*)(x))->GetRight()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetRight(), find, name);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
	}
	return nullptr;
}

TLine* dfsSearchLine(TBase* x, int &find, int X, int Y) {
	if (x->GetType() == _Point) {
		if (((TPoint*)(x))->GetX() == X && ((TPoint*)(x))->GetY() == Y) {
			find = 1;
			return nullptr;
		}
	}
	else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetLeft(), find, X, Y);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
		if (((TLine*)(x))->GetRight()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetRight(), find, X, Y);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
	}
	return nullptr;
}

TLine * Plex::SearchLineWithPoint(const std::string & name) {
	int find = 0;
	TLine* ans = dfsSearchLine(start, find, name);
	if (find) return ans;
	return nullptr;
}

TLine * Plex::SearchLineWithPoint(int x, int y) {
	int find = 0;
	TLine* ans = dfsSearchLine(start, find, x, y);
	if (find) return ans;
	return nullptr;
}

TPoint* dfsSearchPoint(TBase* x, bool &find, const std::string & name) {
	if (x->GetType() == _Point) {
		if (x->GetName() == name) {
			find = 1;
			return ((TPoint*)(x));
		}
	} else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetLeft(), find, name);
			if (find) return res;
		}
		if (((TLine*)(x))->GetRight()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetRight(), find, name);
			if (find) return res;
		}
	}
	return nullptr;
}

TPoint* dfsSearchPoint(TBase* x, bool &find, int X, int Y) {
	if (x->GetType() == _Point) {
		if (((TPoint*)(x))->GetX() == X && ((TPoint*)(x))->GetY() == Y) {
			find = 1;
			return ((TPoint*)(x));
		}
	}
	else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetLeft(), find, X, Y);
			if (find) return res;
		}
		if (((TLine*)(x))->GetRight()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetRight(), find, X, Y);
			if (find) return res;
		}
	}
	return nullptr;
}

TPoint * Plex::SearchPoint(const std::string & name) {
	bool find = 0;
	TPoint* ans = dfsSearchPoint(start, find, name);
	if (find) return ans;
	return nullptr;
}

TPoint * Plex::SearchPoint(int x, int y) {
	bool find = 0;
	TPoint* ans = dfsSearchPoint(start, find, x, y);
	if (find) return ans;
	return nullptr;
}

void Plex::Move(int dx, int dy) {
	if (start == nullptr) return;
	if (start->GetType() == _Point) {
		((TPoint*)start)->MovePoint(dx, dy);
		return;
	}
	((TLine*)start)->MovePoint(dx, dy);
}

void Plex::Draw(System::Drawing::Graphics ^ g) {
	if (start == nullptr) return;
	if (start->GetType() == _Point) {
		((TPoint*)start)->Draw(g);
		return;
	}
	((TLine*)start)->Draw(g);
}

bool Plex::Empty() const {
	return (start ? true : false);
}

void increase_width(std::vector<std::string> & ans, int x) {
	std::string qwe(x, ' ');
	for (auto i : ans) {
		i = qwe + i;
	}
}

void dfsForSaveGraph(TBase* x, int width, int depth, std::vector<std::string> &ans) {
	if (x == nullptr) return;
	if (x->GetType() == _Point) {
		std::string convert = ((TPoint*)(x))->to_string();
		for (int i = 0; i < convert.size(); i++) {
			//if (width + i < 0) increase_width(ans, width + i);
			ans[depth][width + i] = convert[i];
		}
		return;
	}
	if (((TLine*)(x))->GetLeft() != nullptr) {
		//out << "GO LEFT\n";
		dfsForSaveGraph(((TLine*)(x))->GetLeft(), width - (15 - depth) * 5, depth + 4, ans);
		//out << "OUT LEFT\n";
	}
	if (((TLine*)(x))->GetRight() != nullptr) {
		//out << "GO RIGHT\n";
		dfsForSaveGraph(((TLine*)(x))->GetRight(), width + (15 - depth) * 5, depth + 4, ans);
		//out << "OUT RIGHT\n";
	}
	//out << ((TLine*)(x))->to_string() << '\n';
	std::string convert = ((TLine*)x)->to_string();
	for (int i = 0; i < convert.size(); i++) {
		ans[depth][width + i] = convert[i];
	}
}

void Plex::saveGraph() {
	std::vector<std::string> ans(10000, std::string(10000, ' '));
	dfsForSaveGraph(start, 500, 0, ans);
	std::fstream out;
	out.open("outputGraph.txt", std::ios::out);
	for (auto i : ans) {
		out << i << '\n';
	}
	out.close();
}

void dfsForSaveFile(TBase* x, std::fstream & out) {
	if (x == nullptr) return;
	if (x->GetType() == _Point) {
		std::string convert = ((TPoint*)(x))->to_string();
		out << convert << '\n';
		return;
	}
	if (((TLine*)(x))->GetLeft() != nullptr) {
		out << "GO LEFT\n";
		dfsForSaveFile(((TLine*)(x))->GetLeft(), out);
		out << "OUT LEFT\n";
	}
	if (((TLine*)(x))->GetRight() != nullptr) {
		out << "GO RIGHT\n";
		dfsForSaveFile(((TLine*)(x))->GetRight(), out);
		out << "OUT RIGHT\n";
	}
	out << ((TLine*)(x))->to_string() << '\n';
}

void Plex::saveFile() {
	std::fstream out;
	out.open("outputFile.txt", std::ios::out);
	dfsForSaveFile(start, out);
	out.close();
}
