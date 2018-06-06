#include "alien.h"

Alien::Alien(int x,int y, int t)
{
    i=x;
    j=y;
    type=t;
}

QRectF Alien::boundingRect() const
{
    return QRectF(-25, -12, 50, 24);
}

/*
QPainterPath Alien::shape() const
{
    QPainterPath path;
    path.addRect(-28, -55, 56, 110);
    return path;
}
*/

void Alien::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(type==1){
        painter->drawPixmap(-25, -12, 50, 24,QPixmap (":/Image/A1.png"));
    }
    else if(type==0){
        painter->drawPixmap(-25, -12, 50, 24,QPixmap (":/Image/A3.png"));
    }
}

void Alien::advance(int step){
    int val=1;
    velX=5;
    velY=1+1;
    i=i+qrand()%(2*velX+1)-velX;;
    j=j+1;;

    if (j>600){
        j=0;
    }
    if(i<25){
        i=25;
    }

    if(i>775){
        i=775;
    }
    setPos(i,j);
}

int Alien::getJ(void){
    return j;
}

int Alien::getI(void){
    return i;
}

void Alien::setI(int z){
    i=z;
}

void Alien::setJ(int z){
    j=z;
}
