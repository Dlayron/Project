
#include <SFML/Graphics.hpp>
#include "windows.h"
#include <SFML/Audio.hpp>
using namespace sf;

bool Collide(Sprite sp1, Sprite sp2) {
    return sp1.getGlobalBounds().intersects(sp2.getGlobalBounds());

}

class Sprites {

public:
    Sprite background, name_game, start, exit, stick, background_game, ball,
        background_1, background_2, background_3, win, lose;
};
class Bool_class {
public:
    bool menu = true, game = false, moveball = true, level1 = false,
        level2 = false, level3 = false, blocks = false, gaming = false, block_1 = false, block_2 = false, block_3 = false, win = false, lose = false, win_back = false, lose_back = false;
};

int main()
{

    RenderWindow window(VideoMode(1200, 800), "Arkanoid");
    window.setFramerateLimit(60);
    bool arkanoid_game = true;
    srand(time(0));
    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, win_t, lose_t;
    t1.loadFromFile("pic/background2.jpg");
    t4.loadFromFile("pic/arka.png");
    t6.loadFromFile("pic/22.jpg");
    t5.loadFromFile("pic/stick.png");
    t7.loadFromFile("pic/ball4.png");
    t8.loadFromFile("pic/brick3.png");
    t9.loadFromFile("pic/3.jpg");
    t10.loadFromFile("pic/4.jpg");
    t11.loadFromFile("pic/444.jpg");
    t12.loadFromFile("pic/ball5.png");
    win_t.loadFromFile("pic/win.jpg");
    lose_t.loadFromFile("pic/lose.jpg");
    //for (int i = 0; i < 6; i++)
    //    for (int j = 0; j < 3; j++) {
    //        spr.block[j * 6 + i].setTexture(t8);
    //        spr.block[j * 6 + i].setTextureRect(IntRect(0, 0, 100, 50));
    // 
    //    }
    bool a = true;
    while (a==true) {
        Clock repeatClock;
        Sprites spr;
        Bool_class bl;
        Sprite stick;
        Sprite brick[400];
        Sprite ball_girl;
        spr.background.setTexture(t1);
        spr.name_game.setTexture(t4);
        spr.name_game.setPosition(70, 120);
        spr.background.setPosition(0, 0);
        ball_girl.setTexture(t12);
        spr.win.setTexture(win_t);
        spr.lose.setTexture(lose_t);

        SoundBuffer ball_audio;
        ball_audio.loadFromFile("pic/sfx-ball.ogg");
        Sound sound_ball(ball_audio);

        SoundBuffer ball2_audio;
        ball2_audio.loadFromFile("pic/sfx-ball2.ogg");
        Sound sound_ball2(ball2_audio);

        SoundBuffer stick_audio;
        stick_audio.loadFromFile("pic/sfx-stick.ogg");
        Sound sound_stick(stick_audio);

        int x = 0;
        Sprite ball;

        ball.setTexture(t7);

        stick.setTexture(t5);

        stick.setPosition(500, 630);
        ball.setPosition(525, 590);
        int coord_px_stick = 120;

        float x_coord = 6;
        float y_coord = 5;

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed) {
                    a = false;
                    window.close();
                }
                if (event.type == Event::MouseButtonPressed)
                    if (event.key.code == Mouse::Left) {
                        Vector2i pos = Mouse::getPosition(window);

                        if (bl.menu) {
                            if (pos.x >= 85 && pos.x <= 200 && pos.y >=
                                540 && pos.y <= 620) {
                                a = false;
                                window.close();
                            }

                            if (pos.x >= 85 && pos.x <= 360 && pos.y >=
                                440 && pos.y <= 500) {
                                bl.menu = false;
                                bl.game = true;
                            }




                        }
                    }
                if (bl.game == true) {
                    if (event.type == Event::MouseButtonPressed)
                        if (event.key.code == Mouse::Left) {
                            Vector2i pos2 = Mouse::getPosition(window);


                            if (pos2.x >= 240 && pos2.x <= 340 &&
                                pos2.y >= 320 && pos2.y <= 400) {
                                bl.menu = false;
                                bl.game = false;
                                bl.level1 = true;
                                bl.block_1 = true;

                            }
                            if (pos2.x >= 500 && pos2.x <= 640 &&
                                pos2.y >= 320 && pos2.y <= 400) {
                                bl.menu = false;
                                bl.game = false;
                                bl.level2 = true;
                                bl.block_2 = true;

                            }
                            if (pos2.x >= 750 && pos2.x <= 940 &&
                                pos2.y >= 320 && pos2.y <= 400) {
                                bl.menu = false;
                                bl.game = false;
                                bl.level3 = true;
                                bl.block_3 = true;

                            }
                        }

                }

            }

            window.clear();
            window.draw(spr.background);
            if (bl.menu == true) {
                window.draw(spr.background);
                window.draw(spr.name_game);
                window.draw(spr.background_game);

            }

            if (bl.game == true) {
                spr.background_game.setTexture(t6);
                spr.background_game.setPosition(0, 0);
                window.draw(spr.background_game);



            }



            if (bl.block_1 == true) {
                for (int i = 1; i <= 10; i++) {
                    for (int j = 1; j <= 10; j++) {
                        brick[x].setTexture(t8);
                        brick[x].setPosition(275 + i * 50, j * 25 + 9);
                        x++;
                    }
                }
                ball_girl.setPosition(550, 10);
                bl.block_1 = false;
                bl.gaming = true;

            }

            if (bl.block_2 == true) {
                for (int i = 1; i <= 14; i++) {
                    for (int j = 1; j <= 14; j++) {
                        brick[x].setTexture(t8);
                        brick[x].setPosition(200 + i * 50, j * 25 + 9);
                        x++;
                    }
                }
                ball_girl.setPosition(570, 10);
                bl.block_2 = false;
                bl.gaming = true;
            }

            if (bl.block_3 == true) {
                for (int i = 1; i <= 18; i++) {
                    for (int j = 1; j <= 18; j++) {
                        brick[x].setTexture(t8);
                        brick[x].setPosition(100 + i * 50, j * 25 + 9);
                        x++;
                    }
                }
                ball_girl.setPosition(570, 10);
                bl.block_3 = false;
                bl.gaming = true;
            }


            if (bl.gaming == true) {
                if (bl.level1 == true) {
                    spr.background_1.setTexture(t9);
                    spr.background_1.setPosition(0, 0);
                    window.draw(spr.background_1);
                    //bl.gaming = true;

                }
                if (bl.level2 == true) {
                    spr.background_2.setTexture(t10);
                    window.draw(spr.background_2);
                    // bl.gaming = true;



                }
                if (bl.level3 == true) {

                    spr.background_3.setTexture(t11);
                    window.draw(spr.background_3);
                    // bl.gaming = true;


                }
                ball.move(x_coord, 0);

                for (int i = 0; i < x; i++) {
                    if (Collide(ball, brick[i])) {
                        brick[i].setPosition(-100, 0); x_coord = -x_coord;
                        sound_ball.play();

                    }
                }

                ball.move(0, y_coord);
                for (int i = 0; i < x; i++) {
                    if (Collide(ball, brick[i])) {
                        brick[i].setPosition(-100, 0); y_coord = -y_coord;
                        sound_ball.play();
                    }
                }

                if (stick.getPosition().x < 0)
                    stick.setPosition(0, stick.getPosition().y);
                else if (stick.getPosition().x > 1100)
                    stick.setPosition(1100, stick.getPosition().y);


                Vector2f coord_ball = ball.getPosition();
                if (coord_ball.x < 0 || coord_ball.x>1200) x_coord = -x_coord;
                if (coord_ball.y < 0 || coord_ball.y>800) y_coord = -y_coord;



                if (Keyboard::isKeyPressed(Keyboard::Right)) stick.move(8, 0);
                if (Keyboard::isKeyPressed(Keyboard::Left)) stick.move(-8, 0);

                if (Collide(stick, ball)) {
                    sound_stick.play();
                    y_coord = -(rand() % 3 + 3);
                }
                if (Collide(ball, ball_girl)) {
                    sound_ball2.play();
                    repeatClock.restart();
                    bl.win_back = true;
                    bl.gaming = false;
                }

                if (ball.getPosition().y > 650) {
                    repeatClock.restart();
                    bl.lose_back = true;
                    bl.gaming = false;
                    ball.setPosition(0, 0);
                    ball.move(0, 0);
                }
                //window.clear();
                //spr.background_game.setTexture(t6);
                //spr.background_game.setPosition(0, 0);
                //window.draw(spr.background_game);
                for (int k = 0; k < x; k++) {
                    window.draw(brick[k]);
                }
                window.draw(ball);
                window.draw(stick);
                window.draw(ball_girl);





            }
            if (bl.win_back==true) {
                window.clear();
                window.draw(spr.win);
                Event event2{};
                 if (repeatClock.getElapsedTime().asSeconds() > 7.0f) {

                        bl.win = true;
                        repeatClock.restart();
                    }

                if (bl.win == true) {
                    window.clear();
                    break;


                }

            }


            else if (bl.lose_back == true) {
                window.clear();
                window.draw(spr.lose);
                Event event;
                if (repeatClock.getElapsedTime().asSeconds() > 7.0f) {
                     bl.lose = true;
                      repeatClock.restart();
                 }

                
                if (bl.lose == true) {
                    window.clear();
                    break;


                }
            }



            window.display();

        }


    }
}

