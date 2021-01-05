#pragma once
#include<utility>
#include "Game.h"

class GridElem {
public:
	GridElem();
	GridElem(const int x, const int y, const bool state);

	bool operator==(const GridElem& GECompare) const noexcept;

	IntPair GetXY() const { return std::make_pair(mX, mY); }

	void AddX(const int x) noexcept;
	void AddY(const int y) noexcept;


private:
	int mX;
	int mY;
	bool mAlive;
};