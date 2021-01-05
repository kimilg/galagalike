#pragma once
#include "GridElement.h"
#include <vector>

constexpr int GRIDSIZE = 50;
typedef std::pair<int, int> IntPair;
class GridElem;

class Game {
public:
	enum class EDIRECTION {
		UNDEFINED = -1,
		RIGHT,
		LEFT
	};
	Game();

	void InitializeGame();
	void Play();
	void SetDirection(const EDIRECTION eDirection);
	void SetMySpaceShip(GridElem GElem);
	void GenerateMissile(Game& ActiveGame);
	bool IsPlaying() const noexcept {
		return m_GameRunning && !m_Paused && !m_GameOver;
	}
	void MoveDirection(const EDIRECTION eDirection);
	void TogglePause(const bool ForcedPause);

private:
	std::vector<GridElem>	 m_Enemies;
	std::vector<GridElem>	 m_Missiles;
	GridElem*				 m_SpaceShip;
	bool					 m_Initialized;
	int						 m_Score;
	EDIRECTION				 m_eDirection;
	bool					 m_GameRunning;
	bool					 m_Paused;
	bool					 m_GameOver;
};