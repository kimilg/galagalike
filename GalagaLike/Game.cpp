#include "Game.h"
#include <tuple>
#include <utility>

Game::Game() :
	m_Initialized(false),
	m_Score(0),
	m_eDirection(EDIRECTION::UNDEFINED),
	m_GameRunning(false),
	m_GameOver(false),
	m_Paused(false),
	m_SpaceShip(0)
{}

void Game::SetMySpaceShip(GridElem GElem) {
	m_SpaceShip = &GElem;
}
void Game::MoveDirection(const Game::EDIRECTION eDirection) {
	switch (eDirection) {
	case Game::EDIRECTION::LEFT:
		m_SpaceShip->AddX(-5);
		break;
	case Game::EDIRECTION::RIGHT:
		m_SpaceShip->AddX(5);
		break;
	}
}

//first start move, game begin.
void Game::SetDirection(const Game::EDIRECTION eDirection) {
	m_GameRunning = true;
	m_Paused = false;

}

void Game::TogglePause(const bool ForcedPause) {
	if (ForcedPause) {
		m_Paused = true;
	}
	else {
		m_Paused = !m_Paused;
	}
}

void Game::InitializeGame() {

	m_Enemies.clear();
	const int iMiddle = (GRIDSIZE - 1) / 2;
	const int iBottom = (GRIDSIZE - 5);
	const GridElem MyBeginPoint(iMiddle, iBottom, true);
	SetMySpaceShip(MyBeginPoint);

	m_Score = 0;
	m_GameRunning = false;
	m_Initialized = true;

}

void Game::GenerateMissile(Game& ActiveGame) {
	if (ActiveGame.IsPlaying()) {
		if (ActiveGame.m_Missiles.size() <= 1) {
			int x, y;
			std::tie(x, y) = m_SpaceShip->GetXY();
			const int mX = x;
			const int mY = y - 5;
			GridElem nGE(mX, mY, true);
			ActiveGame.m_Missiles.push_back(nGE);
		}
	}
}


