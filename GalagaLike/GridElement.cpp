#include "GridElement.h"


GridElem::GridElem() :
	GridElem(0, 0, false)
{}


GridElem::GridElem(const int x, const int y, const bool state) :
	mX(x% GRIDSIZE),
	mY(y% GRIDSIZE),
	mAlive(state)
{}



bool GridElem::operator==(const GridElem& GECompare) const noexcept {
	return (mX == GECompare.mX) && (mY == GECompare.mY);
}


void GridElem::AddX(const int x) noexcept {
	mX = (mX + x + GRIDSIZE) % GRIDSIZE;
}

void GridElem::AddY(const int y) noexcept {
	mY = (mY + y + GRIDSIZE) % GRIDSIZE;
}