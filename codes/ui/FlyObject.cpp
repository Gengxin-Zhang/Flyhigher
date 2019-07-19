//
//  FlyObject.cpp
//  Flyhigher
//
//  Created by zhangone on 2019/7/19.
//

#include "FlyObject.h"



FlyObject::FlyObject(QObject *parent) {
    this->x = 0;
    this->y = 0;
    this->nextX = 0;
    this->nextY = 0;
    this->color = Color(0, 0, 160, 230);
    this->speed = 0;
}

FlyObject::~FlyObject(){
}

int FlyObject::getX() const{
    return this->x;
}

int FlyObject::getY() const{
    return this->y;
}

void FlyObject::setY(const int y) {
    this->y = y;
}

void FlyObject::setX(const int x){
    this->x = x;
}

void FlyObject::setSpeed(const int speed){
    this->speed = speed;
}

void FlyObject::setPos(const int x, const int y){
    this->x = x;
    this->y = y;
}

Color FlyObject::getColor() const{
//    return this->color;
}

void FlyObject::setColor(const Color c){
    this->color = c;
}

int FlyObject::getDistance(int distance_x, int distance_y) const{
    // return 1;
   return (int)sqrt(distance_x*distance_x + distance_y*distance_y);
}

void FlyObject::move(){
    int distance_x = this->nextX - this->x;
    int distance_y = this->nextY - this->y;
    int distance = getDistance(distance_x, distance_y);
    if (distance == 0)
        return;
    
    // 制造移动曲线效果。 bug is feature.
    // int speed_x  = (distance_x/distance)*speed;
    // int speed_y  = (distance_y/distance)*speed;
    int speed_x = distance_x/5;
    int speed_y = distance_y/5;
    this->x += speed_x;
    this->y += speed_y;
    
    // 调整位置
    if (!(distance_x<0 ^ this->x>this->nextX)) this->x = this->nextX;
    if (!(distance_y<0 ^ this->y>this->nextY)) this->y = this->nextY;
}