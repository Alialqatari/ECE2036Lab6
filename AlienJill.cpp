#include "AlienJill.h"
using namespace std;

#define ALIEN_HEIGHT 8 
#define ALIEN_WIDTH 11 
#define _ 0x000000 // Black
#define X 0x964B00 // Brown
#define R 0xFF0000 // Red
#define Y 0xFFFF00 // Yellow
#define B 0x0000FF // Blue
#define W 0xFFFFFF // White
#define G 0x00FF00 // Green

int AlienJill_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
    _,_,_,R,R,R,R,R,_,_,_,
    _,_,R,R,R,R,R,R,R,_,_,
    _,_,R,R,R,R,R,R,R,_,_,
    _,_,W,W,W,W,W,W,W,_,_,
    _,_,W,W,W,W,W,W,W,_,_,
    _,_,B,B,B,B,B,B,B,_,_,
    _,_,B,B,B,B,B,B,B,_,_,
    _,_,_,B,B,B,B,B,_,_,_,
};

AlienJill::AlienJill()
{
    this->xPos = 0;
    this->yPos = 0;
    this->alive = true;
    this->speed = 0;
    this->isPill = true;
}

AlienJill::AlienJill(int xPos, int yPos, bool alive)
{
    this->xPos = xPos;
    this->yPos = yPos;
    this->alive = alive;
    this->speed = 10;
    this->isPill = true;
}

void AlienJill::draw(uLCD_4DGL & uLCD)
{
    uLCD.BLIT(xPos, yPos, ALIEN_WIDTH, ALIEN_HEIGHT, AlienJill_sprite);
}

void AlienJill::update(uLCD_4DGL & uLCD)
{
    uLCD.filled_rectangle(xPos, yPos, xPos + ALIEN_WIDTH, yPos + ALIEN_HEIGHT, BLACK);
    if (alive) {
        if (xPos + ALIEN_WIDTH + speed > 127 || xPos + speed < 0) {
            speed *= -1;
        }
        xPos = xPos + speed;
        uLCD.BLIT(xPos, yPos, ALIEN_WIDTH, ALIEN_HEIGHT, AlienJill_sprite);
    }
}