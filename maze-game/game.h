#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define back Color(96,58,18)	// 미로 색 정의

using namespace std;
using namespace sf;

class mazeGame {
private:
	RenderWindow window;
	//Color back;
public:
	mazeGame();	// 생성자

	void Intro();	// 인트로 (게임 시작, 게임룰, 랭킹)
	void GameSet();	// 게임 준비
	void GameStart();	//게임 시작
	void Rank();
};