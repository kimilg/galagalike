#pragma once
#include <utility>
#include <vector>
#include "GridElement.h"

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
	void SetMyPlane(const GridElem GElem);

private:
	std::vector<GridElem>	 m_Enemies;
	GridElem				 m_MyPlane;
	bool					 m_Initialized;
	int						 m_Score;
	EDIRECTION				 m_eDirection;
	bool					 m_GameRunning;
};