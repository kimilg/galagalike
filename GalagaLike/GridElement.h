#pragma once
#include "Game.h"
#include <utility>

typedef std::pair<int, int> IntPair;

class GridElem {
public:
	GridElem();
	GridElem(const int x, const int y, const bool state);

	bool operator==(const GridElem& GECompare) const noexcept;

	IntPair GetXY() const { return std::make_pair(mX, mY); }

	void AddX(const int x) noexcept;
	void AddY(const int y) noexcept;

	void SetActive(const bool bAlive) noexcept { mAlive = true; }
	bool GetActive() const noexcept { return mAlive; }

private:
	int mX;
	int mY;
	bool mAlive;
};