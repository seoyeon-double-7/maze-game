#include "game.h"

mazeGame::mazeGame() {

    // �ð� ���� ���� ����
    srand(sin(time(nullptr)) * 1000);

    app.create(VideoMode(600, 600),"maze Game");
    app.setFramerateLimit(60);

    // �� ���� ����
    //orderedSet[15 * 15];
    //path[100];
    Maze = Color(96, 58, 18);

    // �÷��̾� ����
    player = Vector2i(13, 13);

    playerTex.loadFromFile("images/ch3.png");
    playerSprite.setTexture(playerTex);
    playerSprite.setPosition(player.x * 40.f, player.y * 40.f);

    // �� ����
    opponent = Vector2i(1, 1);

    opponentTex.loadFromFile("images/enemy2.png");
    opponentSprite.setTexture(opponentTex);
    opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);

    // ���� ����
    coinTex.loadFromFile("images/coin.png");



    numCoins = 0;
    score = 0;

    //gameMap[15 * 15];
    //displayRects[15 * 15];

    //To Do : Music �Լ� �߰�
}

void mazeGame::Intro()
{
    // �ؽ���, ��������Ʈ
    Texture Tbackground, Tstart, Trule, Trank;
    Sprite background, start, rule, rankBtn;

    Texture rankScreen, ruleScreen, mapScreen;
    Sprite rank_screen, rule_screen, map_screen;



    // �̹��� ���� �б�
    Tbackground.loadFromFile("images/bg.png");
    Tstart.loadFromFile("images/startBtn.png");
    Trule.loadFromFile("images/ruleBtn.png");
    Trank.loadFromFile("images/rankBtn.png");
    rankScreen.loadFromFile("images/rankScreen.png");
    ruleScreen.loadFromFile("images/ruleScreen.png");
    mapScreen.loadFromFile("images/mapScreen.png");

    // Sprite ����
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

    while (app.isOpen()) {
        Event event;
        //�̺�Ʈ ó��

        while (app.pollEvent(event)) {


            // ���α׷� ���� �̺�Ʈ ó��
            if (event.type == Event::EventType::Closed)
            {
                app.close();
                cout << "���� ����" << endl;
            }

            // ���콺 ��ư ���� �̺�Ʈ
            if (event.type == Event::MouseButtonPressed)
            {
                switch (event.key.code)
                {
                case Mouse::Left:
                {
                    Vector2i pos = Mouse::getPosition(app);

                    if (pos.x >= 155 && pos.x <= 500 && pos.y >= 614 && pos.y <= 720) {
                        cout << "���� ���۹�ư ����" << endl;
                        //app.clear(Color::Black);
                        app.draw(map_screen);
                    }
                    else if (pos.x >= 576 && pos.x <= 946 && pos.y >= 628 && pos.y <= 728) {
                        cout << "���� �����ư ����" << endl;
                        //app.clear(Color::Black);
                        app.draw(rule_screen);
                    }
                    else if (pos.x >= 1027 && pos.x <= 1401 && pos.y >= 630 && pos.y <= 732) {
                        cout << "���� ��ŷ��ư ����" << endl;
                        //app.clear(Color::Black);
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

        // ������ ��ũ���� ���
        app.display();
    }

}

void mazeGame::GameSet() {

    // �̷ΰ� �� �簢�� ���� (��ġ, ������, ��ġ)

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            displayRects[i + j * 15].setPosition(i * 40.f, j * 40.f);
            displayRects[i + j * 15].setSize(Vector2f(40.f, 40.f));
            //displayRects[i + j * 15].setOutlineThickness(1.f);
            //displayRects[i + j * 15].setOutlineColor(Color(0, 0, 0));

            if (!(i == opponent.x && j == opponent.y) && !(i == player.x && j == player.y)) {
                if (rand() / (float)RAND_MAX < 0.22f || i == 0 || j == 0 || i == 14 || j == 14) {
                    gameMap[i + j * 15] = 1;
                    displayRects[i + j * 15].setFillColor(Maze);
                }
            }
        }
    }

    
}

void mazeGame::Rank()
{
    // ���� �����
}

void mazeGame::GameStart()
{
    // �ð� ����   
    int frameCount = 0;
    int moveTimer = 1000;

    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed) {
                app.close();
            }

            // Ű���� �Է� (�浹ó�� ����)

            else if (event.type == Event::KeyPressed) {


                // �÷��̾� ��ǥ���� �����ͼ� �̷ΰ� �迭�� �������� ������ �̵�

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

            //path ���� ����
            updatePath = true;
            pathSize = 0;
            pathPos = 0;

            playerSprite.setPosition(player.x * 40.f, player.y * 40.f);
        }

        // ���� (����x ���� ���� ����)
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

        // app.clear(Color::Red); 


        // �̷θ� �׷���
        for (int i = 0; i < 15 * 15; i++) {
            app.draw(displayRects[i]);
        }

        /*for (int i = 0; i < numCoins; i++) {
            app.draw(coins[i]);
        }*/

        // �÷��̾��� ��ǥ���� ����Ͽ� ���� �÷��̾��� ��ǥ���� �����ϰ� �̵�
        if (updatePath == true) {
            int counter = 0;

            //int fullSet[2000];
            int fullSetSize = 0;

            //int openSet[100];
            int openSetSize = 2;
            openSet[0] = player.x + player.y * 15;
            openSet[1] = counter;

            int currentIndex = player.x + player.y * 15;

            while (currentIndex != opponent.x + opponent.y * 15) {
                currentIndex = openSet[0];
                counter = openSet[1] + 1;

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

        // �ð� ����
        if (frameCount % moveTimer == 0) {
            opponent.x = path[pathPos] % 15;
            opponent.y = floor(path[pathPos] / 15);
            opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);
            pathPos += 1;

            if (moveTimer >= 250) {
                moveTimer = 1000 - floor(frameCount / 1000) * 4;
            }
        }


        // �÷��̾� �׷��ֱ�
        app.draw(playerSprite);

        // �� �׷��ֱ�
        app.draw(opponentSprite);

        app.display();

        // ȭ�� ��ġġ �ʵ��� ����
        if (gameMap[player.x + player.y * 15] == 2) {
            gameMap[player.x + player.y * 15] = 0;
            /*
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
            numCoins -= 1;*/
        }

        frameCount += 1;

        // �÷��̾�� ���� �浹���� �� ���� ������ �������
        // ���� ȹ�濡 ���� ���� ������ ����
        if (player == opponent) {
            cout << "Final Score: " << score << endl;
        }
    }
}
