#include "uLCD_4DGL.h"

#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H
class ScreenObject
{
    public:
        virtual void draw(uLCD_4DGL &) = 0;
        virtual void update(uLCD_4DGL &) = 0;
        void setXPos(int xPos) { this->xPos = xPos; };
        void setYPos(int yPos) { this->yPos = yPos; };
        void setSpeed(int speed) { this->speed = speed;};
        void setAlive(bool alive) { this->alive = alive;};
        void setPill(bool isPill) {this->isPill = isPill;};
        int getXPos() { return xPos; };
        int getYPos() { return yPos; };
        int getSpeed() { return speed; };
        bool getAlive() { return alive; };
        bool getPill() {return isPill; };
    protected:
        bool alive;
        bool isPill;
        int speed;
        int xPos;
        int yPos;
};
#endif