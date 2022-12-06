#include "game.h"


mazeGame::mazeGame() {

    // 화면 크기 설정해주기
    window.create(VideoMode(600, 600), "maze Game");

    // 플레이어 세팅
    player = Vector2i(13, 13);
    playerTex.loadFromFile("images/player.png");
    playerSprite.setTexture(playerTex);
    playerSprite.setPosition(player.x * 40.f, player.y * 40.f);

    // 도착지 세팅
    door = Vector2i(1, 13);
    doorTex.loadFromFile("images/star.png");
    doorSprite.setTexture(doorTex);
    doorSprite.setPosition(door.x * 40.f, player.y * 40.f);

    // 적 세팅
    opponent = Vector2i(1, 1);
    opponentTex.loadFromFile("images/enemy.png");
    opponentSprite.setTexture(opponentTex);
    opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);



}

void mazeGame::Intro()
{
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

    while (window.isOpen()) {
        Event event;
        //이벤트 처리

        while (window.pollEvent(event)) {


            // 프로그램 종료 이벤트 처리
            if (event.type == Event::EventType::Closed)
            {
                window.close();
                cout << "게임 종료" << endl;
            }

            // 마우스 버튼 눌림 이벤트
            if (event.type == Event::MouseButtonPressed)
            {
                switch (event.key.code)
                {
                case Mouse::Left:
                {
                    Vector2i pos = Mouse::getPosition(window);

                    if (pos.x >= 155 && pos.x <= 500 && pos.y >= 614 && pos.y <= 720) {
                        cout << "게임 시작버튼 눌림" << endl;
                        //app.clear(Color::Black);
                        window.draw(map_screen);
                    }
                    else if (pos.x >= 576 && pos.x <= 946 && pos.y >= 628 && pos.y <= 728) {
                        cout << "게임 방법버튼 눌림" << endl;
                        //app.clear(Color::Black);
                        window.draw(rule_screen);
                    }
                    else if (pos.x >= 1027 && pos.x <= 1401 && pos.y >= 630 && pos.y <= 732) {
                        cout << "게임 랭킹버튼 눌림" << endl;
                        //app.clear(Color::Black);
                        window.draw(rank_screen);
                    }
                    else {
                        window.draw(background);
                        window.draw(start);
                        window.draw(rule);
                        window.draw(rankBtn);
                    }
                }
                }

            }
        }

        // 프레임 스크린에 출력
        window.display();
    }

}

void mazeGame::GameSet() {

    

    
}

void mazeGame::Rank()
{
    // 파일 입출력
}


void mazeGame::GameStart()
{
    //rand 함수에 사용될 수 초기화 하기
    srand(sin(time(nullptr)) * 1000);

    // 게임 시간을 재기위한 변수
    int frameCount = 0;
    int moveTimer = 1000;

    // 플레이어의 경로를 확인하는 변수
    bool updatePath = true;
    int orderedSet[15 * 15];
    int path[100]={0};
    int pathSize = 0;
    int pathPos = 0;


    // 열쇠는 추후 개발
    /*Texture coinTex;
    coinTex.loadFromFile("images/coin.png");
    Sprite coins[5];
    int numCoins = 0;
    int score = 0;*/

    // 미로 배열을 담을 변수
    
;

    // 미로 구성하는 displayRects 세팅 (위치, 사이즈 배치시키기)
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            displayRects[i + j * 15].setPosition(i * 40.f, j * 40.f);
            displayRects[i + j * 15].setSize(Vector2f(40.f, 40.f));
            displayRects[i + j * 15].setOutlineThickness(1.f);
            displayRects[i + j * 15].setOutlineColor(Color::Black);


            // 플레이어의 좌표값과 적의 좌표값이 같지 않으며
            // 미로 위치와 플레이어와 적 위치가 겹치지 않게 함
            if (!(i == opponent.x && j == opponent.y) && !(i == player.x && j == player.y) && !(i == door.x && j == door.y)) {
                if (rand() / (float)RAND_MAX < 0.22f || i == 0 || j == 0 || i == 14 || j == 14) {
                    gameMap[i + j * 15] = 1;
                    displayRects[i + j * 15].setFillColor(Color::Cyan);
                }
            }
        }
    }

    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
            }

            // 키보드 입력 (충돌처리)

            else if (event.type == Event::KeyPressed) {

                // 플레이어 좌표값을 가져와서 미로배열이 막혀있지 않으면 무브무브!!

                switch (event.key.code) {

                case Keyboard::Up:
                    if (gameMap[player.x + (player.y - 1) * 15] != 1) player.y -= 1;
                    break;

                case Keyboard::Down:
                    if (gameMap[player.x + (player.y + 1) * 15] != 1) player.y += 1;
                    break;

                case Keyboard::Right:
                    if (gameMap[(player.x + 1) + player.y * 15] != 1) player.x += 1;
                    break;

                case Keyboard::Left:
                    if (gameMap[(player.x - 1) + player.y * 15] != 1) player.x -= 1;
                    break;
                }
            }

            // 경로 설정해주긔~
            updatePath = true;
            pathSize = 0;
            pathPos = 0;
            playerSprite.setPosition(player.x * 40.f, player.y * 40.f);
        }

        // 코인 (실행x 추후 수정 예정)
        /*while (numCoins < 3) {
            int col = (rand() / (float)RAND_MAX) * 15.f;
            int row = (rand() / (float)RAND_MAX) * 15.f;

            if (gameMap[col + row * 15] == 0) {
                gameMap[col + row * 15] = 2;
                coins[numCoins].setTexture(coinTex);
                coins[numCoins].setPosition(col * 40.f, row * 40.f);
                numCoins += 1;
            }
        }*/

        

        // 미로 그려주기
        for (int i = 0; i < 15 * 15; i++) {
            window.draw(displayRects[i]);
        }

        /*for (int i = 0; i < numCoins; i++) {
            window.draw(coins[i]);
        }*/

        // 플레이어의 좌표값을 계산하여 적이 플레이어의 좌표값에 근접하게 이동
        // a* 알고리즘 활용
        if (updatePath == true) {
            int counter = 0;

            int fullSet[2000];
            int fullSetSize = 0;

            int openSet[100];
            int openSetSize = 2;
            openSet[0] = player.x + player.y * 15;
            openSet[1] = counter;

            int currentIndex = player.x + player.y * 15;

            while (currentIndex != opponent.x + opponent.y * 15) {
                currentIndex = openSet[0];
                counter = openSet[1] + 1;
                int neighbors[4];

                neighbors[0] = currentIndex - 1;
                neighbors[1] = currentIndex + 1;
                neighbors[2] = currentIndex - 15;
                neighbors[3] = currentIndex + 15;

                for (int i = 0; i < 8; i += 2) {
                    bool alreadyExists = false;

                    for (int j = 0; j < fullSetSize; j += 2) {
                        if (neighbors[i / 2] == fullSet[j]) {
                            alreadyExists = true;
                            break;
                        }
                    }

                    if (alreadyExists == false) {
                        if (gameMap[neighbors[i / 2]] != 1) {
                            fullSet[fullSetSize] = neighbors[i / 2];
                            fullSet[fullSetSize + 1] = counter;
                            fullSetSize += 2;

                            openSet[openSetSize] = neighbors[i / 2];
                            openSet[openSetSize + 1] = counter;
                            openSetSize += 2;
                        }
                        else {
                            fullSet[fullSetSize] = neighbors[i / 2];
                            fullSet[fullSetSize + 1] = 100000;
                            fullSetSize += 2;
                        }
                    }
                }

                for (int i = 0; i < openSetSize; i++) {
                    openSet[i] = openSet[i + 2];
                }

                openSetSize -= 2;
            }

            for (int i = 0; i < 15 * 15; i++) {
                orderedSet[i] = 100000;
            }

            for (int i = 0; i < fullSetSize; i += 2) {
                orderedSet[fullSet[i]] = fullSet[i + 1];
            }

            orderedSet[player.x + player.y * 15] = 0;

            int pathIndex = opponent.x + opponent.y * 15;

            while (pathIndex != player.x + player.y * 15) {
                int neighbors[4];

                neighbors[0] = pathIndex - 1;
                neighbors[1] = pathIndex + 1;
                neighbors[2] = pathIndex - 15;
                neighbors[3] = pathIndex + 15;

                int lowest[2]{ 0, 100000 };
                for (int i = 0; i < 4; i++) {
                    if (orderedSet[neighbors[i]] < lowest[1]) {
                        lowest[0] = i;
                        lowest[1] = orderedSet[neighbors[i]];
                    }
                }

                pathIndex = neighbors[lowest[0]];

                path[pathSize] = pathIndex;

                pathSize += 1;
            }

            updatePath = false;
        }

        // 시간 조정
        if (frameCount % moveTimer == 0) {
            opponent.x = path[pathPos] % 15;
            opponent.y = floor(path[pathPos] / 15);
            opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);
            pathPos += 1;

            if (moveTimer >= 250) {
                moveTimer = 1000 - floor(frameCount / 1000) * 4;
            }
        }


        // 플레이어, 적, 도착지 그려주기
        window.draw(playerSprite);
        window.draw(opponentSprite);
        window.draw(doorSprite);

        window.display();

        /*/if (gameMap[player.x + player.y * 15] == 2) {
            gameMap[player.x + player.y * 15] = 0;

            int coinIndex = -1;
            for (int i = 0; i < numCoins; i++) {
                if (coins[i].getPosition().x / 40 == player.x && coins[i].getPosition().y / 40 == player.y) {
                    coinIndex = i;
                }
            }

            if (coinIndex != numCoins - 1) {
                coins[coinIndex] = coins[numCoins - 1];
            }

            score += 1;
            numCoins -= 1;
        }
        */
        frameCount += 1;

        // 도착지에 도달했을 때 종료 (다음 맵으로 넘어가게 하기)

        if (player == door) {
            cout << "도착지 도착!" << endl;
            cout << frameCount/1000 << "초" << endl;
            break;
        }

        // 플레이어와 적이 충돌했을 때
        // To:Do 코인 획득에 따른 점수 출력

        if (player == opponent) {
            cout << "게임 종료입니당~~: " << endl;
            break;
        }
    }
}
