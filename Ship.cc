#include <Ship.h>
using namespace std;

#define SHIP_HEIGHT 8
#define SHIP_WIDTH 11 
#define _ 0x000000 // Black
#define X 0x964B00 // Brown
#define R 0xFF0000 // Red
#define Y 0xFFFF00 // Yellow
#define B 0x0000FF // Blue
#define W 0xFFFFFF // White
#define G 0x00FF00 // Green

int ship_sprite[SHIP_HEIGHT * SHIP_WIDTH] = {
    _,_,_,_,X,X,X,R,R,_,_,
    _,X,X,X,X,X,X,X,R,Y,_,
    X,X,X,X,X,_,_,X,X,Y,Y,
    X,X,X,X,X,_,_,X,X,Y,_,
    X,X,X,X,X,X,X,X,R,R,R,
    _,_,_,X,X,_,X,X,_,_,_,
    _,_,X,X,_,_,_,X,X,_,_,
    X,X,_,_,_,X,_,_,_,X,X 
};

Ship::Ship()
{
    xPos = 0;
    yPos = 0;
}

Ship::Ship(int xPos, int yPos)
{
    this->xPos = xPos;
    this->yPos = yPos;
}

void Ship::draw(uLCD_4DGL & uLCD)
{
    uLCD.BLIT(xPos, yPos, SHIP_WIDTH, SHIP_HEIGHT, ship_sprite);
}

void Ship::update(uLCD_4DGL & uLCD)
{
    if (speed != 0) {
        uLCD.filled_rectangle(xPos, yPos, xPos + SHIP_WIDTH, yPos + SHIP_HEIGHT, BLACK);
        if (xPos + speed + SHIP_WIDTH > 127) {
            xPos = 127 - SHIP_WIDTH;
        } else if (xPos + speed < 0) {
            xPos = 0;
        } else {
            xPos += speed;
        }
        uLCD.BLIT(xPos, yPos, SHIP_WIDTH, SHIP_HEIGHT, ship_sprite);
    }
}