#include "StateManager.h"
#include "MenuState.h"
#include "SFML/Audio.hpp"

using namespace edy;
using namespace core;
using namespace state;
using namespace sf;

int main()
{
	// state 매니저 호출
	StateManager app;

	// 인트로(메뉴) 화면 설정
	app.pushTop(new MenuState);

	// 음악 재생(끝날때까지 무한 반복)
	Music music;
	music.openFromFile("music/backMusic.wav");
	music.play();
	music.setLoop(true);


	// 현재 스택 가장 최상단에 있는 Run 함수를 실행!
	app.gameRun();
}