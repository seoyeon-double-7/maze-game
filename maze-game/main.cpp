#include "StateManager.h"
#include "MenuState.h"
#include "SFML/Audio.hpp"

using namespace edy;
using namespace core;
using namespace state;
using namespace sf;

int main()
{
	// state �Ŵ��� ȣ��
	StateManager app;

	// ��Ʈ��(�޴�) ȭ�� ����
	app.pushTop(new MenuState);

	// ���� ���(���������� ���� �ݺ�)
	Music music;
	music.openFromFile("music/backMusic.wav");
	music.play();
	music.setLoop(true);


	// ���� ���� ���� �ֻ�ܿ� �ִ� Run �Լ��� ����!
	app.gameRun();
}