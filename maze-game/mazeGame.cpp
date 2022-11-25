#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	int x = 0, y = 0;

	Clock clock;	//경과 시간을 측정할 수 있는 Clock 객체 선언
	Clock ai_timer;
	float interval = 0, delay1 = 4.0;
	int count = 0;

	const Time ai_time = seconds(0.5f);

	cout << "게임 시작" << endl;

	// 텍스쳐, 스프라이트
	Texture Tbackground, Tstart, Trule, Trank;
	Sprite background, start, rule, rankBtn;

	Texture rankScreen, ruleScreen, mapScreen;
	Sprite rank_screen, rule_screen, map_screen;



	// 이미지 파일 읽기
	Tbackground.loadFromFile("images/bg.png");
	Tstart.loadFromFile("images/startBtn.png");
	Trule.loadFromFile("images/ruleBtn.png");
	Trank.loadFromFile("images/rankBtn.png");
	rankScreen.loadFromFile("images/rankScreen.png");
	ruleScreen.loadFromFile("images/ruleScreen.png");
	mapScreen.loadFromFile("images/mapScreen.png");

	// Sprite 세팅
	background.setTexture(Tbackground);

	start.setTexture(Tstart);
	start.setPosition(100, 600);

	rule.setTexture(Trule);
	rule.setPosition(550, 590);

	rankBtn.setTexture(Trank);
	rankBtn.setPosition(1000, 600);

	rank_screen.setTexture(rankScreen);
	rule_screen.setTexture(ruleScreen);
	map_screen.setTexture(mapScreen);
	map_screen.setPosition(0, 0);

	// 화면 크기, 캡션 이름 설정
	RenderWindow app(VideoMode(1500, 900), "MazeGame");
	app.setFramerateLimit(60);	//프레임 비율 설정

	// 초당 60 프레임 설정
	app.setFramerateLimit(60);

	// SFML 메인 루프 - 윈도우 닫힐때까지 반복

	while (app.isOpen())
	{
		// 초단위로 경과시간을 구함
		/*float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		interval += time;*/

		Event event;
		// 이벤트 처리
		while (app.pollEvent(event)) {


			// 프로그램 종료 이벤트 처리
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "게임 종료" << endl;
			}

			// 마우스 버튼 눌림 이벤트
			if (event.type == Event::MouseButtonPressed)
			{
				switch (event.key.code)
				{
				case Mouse::Left:
				{
					Vector2i pos = Mouse::getPosition(app);

					if (pos.x >= 155 && pos.x <= 500 && pos.y >= 614 && pos.y <= 720) {
						cout << "게임 시작버튼 눌림" << endl;
						//app.clear();
						app.draw(map_screen);
					}
					else if (pos.x >= 576 && pos.x <= 946 && pos.y >= 628 && pos.y <= 728) {
						cout << "게임 방법버튼 눌림" << endl;
						//app.clear();
						app.draw(rule_screen);
					}
					else if (pos.x >= 1027 && pos.x <= 1401 && pos.y >= 630 && pos.y <= 732) {
						cout << "게임 랭킹버튼 눌림" << endl;
						//app.clear();
						app.draw(rank_screen);
					}
					else {
						app.draw(background);
						app.draw(start);
						app.draw(rule);
						app.draw(rankBtn);
					}
				}
				}

			}
		}

		// 프레임 스크린에 출력
		app.display();

	}
	return 0;
}