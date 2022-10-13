#include <iostream>
#include <SFML/Graphics.hpp>
#include "PlayerSettings.h"
#include "RenderUtils.h"
#include <conio.h>
#include <sstream>
#include "MathUtils.h"
#include "2D game.h"
#include <windows.h>
using namespace sf;
using namespace std;

int main()
{
    float width = 1100, height = 600,fs = 5,grav = 2.5, gr = grav;
    int jump = 0;
    int kof = 1, mnoj = 2;
    int perekl = 0;
    RenderWindow window(VideoMode(width, height), "GAME");
    RectangleShape backgrond(Vector2f(0,0));
    RenderUtils block1;
    RenderUtils block2;
    BallSettings ball;
    MathUtils math;
    RenderUtils circle;

    RenderUtils blocks[2] = { block1, block2 };

    backgrond.setFillColor(Color(15, 15, 15));
    backgrond.setPosition(0, 0);
    backgrond.setSize(Vector2f(width,height));

    
   

    ball.x = width/2 - circle.getRad();
    ball.y = height/2 - circle.getRad();
    ball.speed = 0.12f;
    ball.fallspeed = fs;

    blocks[0].sX = 200;
    blocks[0].sY = 200;
    blocks[0].eX = 250;
    blocks[0].eY = 250;

    blocks[1].sX = 400;
    blocks[1].sY = 400;
    blocks[1].eX = 500;
    blocks[1].eY = 500;
    fs /= 1000;

    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        
        Vector2i mousecords = Mouse::getPosition(window);
        
        if (math.MouseClickedLeft(event))
        {
            int numb = 0;
            if (math.CkeckHover(mousecords, blocks[numb]))
            {
                float pXs = blocks[numb].sX, pYs = blocks[numb].sY;
                float pXe = blocks[numb].eX, pYe = blocks[numb].eY;
                blocks[numb].sX = mousecords.x; blocks[numb].sY = mousecords.y;
                blocks[numb].eX = blocks[numb].sX + (pXe - pXs); blocks[numb].eY = blocks[numb].sY + (pYe - pYs);
            }
        }

        
        if (math.MouseClickedLeft(event))
        {
            int numb = 1;
            if (math.CkeckHover(mousecords, blocks[numb]))
            {
                float pXs = blocks[numb].sX, pYs = blocks[numb].sY;
                float pXe = blocks[numb].eX, pYe = blocks[numb].eY;
                blocks[numb].sX = mousecords.x; blocks[numb].sY = mousecords.y;
                blocks[numb].eX = blocks[numb].sX + (pXe - pXs); blocks[numb].eY = blocks[numb].sY + (pYe - pYs);
            }
        }

        window.clear();

        window.draw(backgrond);
        window.draw(blocks[0].drawRoundedRect(blocks[0].sX, blocks[0].sY, blocks[0].eX - blocks[0].sX, blocks[0].eY - blocks[0].sY, 0, Color(255, 255, 0)));
        window.draw(blocks[1].drawRoundedRect(blocks[1].sX, blocks[1].sY, blocks[1].eX - blocks[1].sX, blocks[1].eY - blocks[1].sY, 0, Color(255, 0, 0)));
        window.draw(circle.drawCircle(ball.x, ball.y, 10, Color(255, 255, 255), Color(255, 0, 0)));
        
        window.display();



        //ball.y < height - circle.getRadius() * 2 &&



        if (Keyboard::isKeyPressed(Keyboard::Numpad1)) { ball.speed += 0.001f; }
        if (Keyboard::isKeyPressed(Keyboard::Numpad0) && ball.speed > 0) {
            ball.speed -= 0.001f; 
        }

        if (Keyboard::isKeyPressed(Keyboard::Right) 
            && ball.x < width - circle.getRad() * 2
            ) 
        { 
            if (math.AllCkeckBox(ball,blocks[0]) && math.AllCkeckBox(ball, blocks[1]))
            ball.x += ball.speed * mnoj; 
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)
            && ball.y < height - circle.getRad() * 2) {
            if (math.AllCkeckBox(ball, blocks[0]) && math.AllCkeckBox(ball, blocks[1]))
            {
                ball.y += (ball.speed + 0.05);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && ball.x > 0) {
            if (math.AllCkeckBox(ball, blocks[0]) && math.AllCkeckBox(ball, blocks[1]))
                ball.x -= ball.speed * mnoj;
        }


        if (ball.y < height&& ball.y > 0 && math.UpCkeckBox(ball, blocks[0],4) && math.UpCkeckBox(ball, blocks[1],4))
        {
            if (Keyboard::isKeyPressed(Keyboard::Space) && ball.y > height - circle.getRad()* 2 - 2 
                || Keyboard::isKeyPressed(Keyboard::Space) && !math.FallCkeckBox(ball,blocks[0])
                || Keyboard::isKeyPressed(Keyboard::Space) && !math.FallCkeckBox(ball, blocks[1]))
            {
                jump = 1;
            }                 
            if (Keyboard::isKeyPressed(Keyboard::Up) && ball.y > height - circle.getRad() * 2 - 2
                || Keyboard::isKeyPressed(Keyboard::Up) && !math.FallCkeckBox(ball, blocks[0])
                || Keyboard::isKeyPressed(Keyboard::Up) && !math.FallCkeckBox(ball, blocks[1]))
            {
                jump = 2;
            }        

            if (jump == 1)
                {
                    ball.y -= (ball.speed * 4);
                    grav = gr/4;

                }
            if (jump == 2)
            {
                ball.y -= (ball.speed * 6);
                grav = gr / 4;

            }

        }

        if (ball.y > height - circle.getRad() * 2)
        {
            ball.y--;
        }
        float xdif = 3;
        if (!math.LeftCkeckBox(ball, blocks[0])) { ball.x += 1; blocks[0].sX -= xdif; blocks[0].eX -= xdif; }
        if (!math.RightCkeckBox(ball, blocks[0])) { ball.x -= 1; blocks[0].sX += xdif; blocks[0].eX += xdif; }


        if (!math.LeftCkeckBox(ball, blocks[1])) ball.x += ball.speed;
        else if (!math.RightCkeckBox(ball, blocks[1])) ball.x -= ball.speed;
        else if (!math.DownCkeckBox(ball, blocks[1])) ball.y -= 2;
        else if (!math.UpCkeckBox(ball, blocks[1], 2)) ball.y += 2;

        if (ball.y > height - circle.getRad() * 2 - 2)
        {
            jump = 0;
        }
        else if (!math.FallCkeckBox(ball, blocks[0]) || !math.FallCkeckBox(ball, blocks[1]))
        {
            jump = 0;
        }
        else if (!math.UpCkeckBox(ball, blocks[0], 4) || !math.UpCkeckBox(ball, blocks[1],3))
        {
            jump = 0;
        }
        else if (ball.y < 0)
        {
            jump = 0;
        }

        if (math.FallBlockCkeckBox(blocks[0], blocks[1]) && blocks[0].eY < height)
        {
            blocks[0].sY++;
            blocks[0].eY++;
        }


        if (math.FallCkeckBox(ball,blocks[0]) && math.FallCkeckBox(ball, blocks[1]))
        {
            if (ball.y < height - circle.getRad() * 2 - 2)
            {
                ball.y += (ball.fallspeed += (fs * grav));
            }
            else
            {
                ball.fallspeed = fs;
            }
        }
        else
        {
            ball.fallspeed = fs;
        }

        cout << jump << "    " << mousecords.x << "      " << mousecords.y << "   " << ball.speed << "   " << ball.fallspeed << "     x:" << (int)ball.x << "     y:" << (int)ball.y << "    sX:" << blocks[0].sX << "    sY:" << blocks[0].sY << "    eX:" << blocks[0].eX << "    eY:" << blocks[0].eY << endl;
    }
    
    return 0;
}












