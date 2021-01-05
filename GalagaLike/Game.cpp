#include "Game.h"

Game::Game() :
	m_Initialized(false),
	m_Score(0),
	m_eDirection(EDIRECTION::UNDEFINED),
	m_GameRunning(false)
{}

void Game::SetMyPlane(const GridElem GElem) {
	m_MyPlane = GElem;
}

void Game::InitializeGame() {

	m_Enemies.clear();
	const int iMiddle = (GRIDSIZE - 1) / 2;
	const int iBottom = (GRIDSIZE - 5);
	const GridElem MyBeginPoint(iMiddle, iBottom, true);
	SetMyPlane(MyBeginPoint);

	m_Score = 0;
	m_GameRunning = false;
	m_Initialized = true;

}