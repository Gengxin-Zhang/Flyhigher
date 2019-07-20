//
//  FlyObject.cpp
//  Flyhigher
//
//  Created by zhangone on 2019/7/19.
//

#include "FlyObject.h"
#include <random>
#include <cmath>
#include <iostream>
 
 
FlyObject::FlyObject(QGraphicsItem *parent):QObject(), QGraphicsItem() {
    this->x = 0;
    this->y = 0;
    this->nextX = 0;
    this->nextY = 0;
    this->width = 0;
    this->height = 0;
    this->color = Color(200, 0, 160, 230);
    this->speed = 0;
    this->angel = 0;
    setFlags(QGraphicsItem::ItemIsMovable);
}

FlyObject::~FlyObject(){
}

int FlyObject::getX() const{
    return this->x;
}

int FlyObject::getY() const{
    return this->y;
}

int FlyObject::getNextX() const {
    return this->nextX;
}

int FlyObject::getNextY() const {
    return this->nextY;
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

void FlyObject::msetPos(const int x, const int y){
    this->x = x;
    this->y = y;
}

void FlyObject::setNextPos(const int x, const int y){
    this->nextX = x;
    this->nextY = y;
}

Color FlyObject::getColor() const{
    return this->color;
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
    if (!(distance_x<0 ^ this->x<this->nextX)) this->x = this->nextX;
    if (!(distance_y<0 ^ this->y<this->nextY)) this->y = this->nextY;
    if (this->nextX == this->x and this->nextY == this->y){
        this->status = false;
    }else{
        this->status = true;
    }
}

void FlyObject::setAngel(int angel){
    this->angel = angel;
}

QRectF FlyObject::boundingRect() const { 
    return QRectF(this->x-this->width, this->y-this->height, this->x+this->width, this->y+this->height);
}

void FlyObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) { 
    Q_UNUSED(option)
    Q_UNUSED(widget)
    std::default_random_engine e;
    std::uniform_real_distribution<double> u(0.2,0.8);
    painter->translate(0, 0);
    painter->rotate(angel);
    if(this->name == "Bomber"){
        QPolygonF polygon;
        double temp = 1.73*width;
        painter->setBrush(QBrush(color.toQColor()));
        painter->setPen(QPen(Qt::black,4));
        polygon << QPointF(0, -width) << QPointF(0-temp, width/2.0)
                << QPointF(0-temp/2.0, width/2.0) << QPointF(0-temp/4.0, 0)
                << QPointF(0,width/2.0) << QPointF(temp/4.0, 0) << QPointF(temp/2.0, width/2)
                << QPointF(temp, width/2.0);
        painter->drawPolygon(polygon);
    }else if (this->name == "Fighter"){
        QPolygonF polygon;
        QRadialGradient Radial(0,0,120,0,15);// gradient(0-0.3*width, 0.8*width, 0-0.3*width, 1.5*width);
        
        Radial.setColorAt(0.0,QColor("#BF616A"));
        Radial.setColorAt(u(e),QColor("#EBCB8B"));
        painter->setPen(Qt::transparent);
        painter->setBrush(Radial);
        painter->drawEllipse(0-0.6*width, 0.4*width, 1.2*width, (u(e)*2)*width);
        
        painter->setBrush(QBrush(color.toQColor()));
        painter->setPen(QPen(Qt::black,4));
        double temp = 1.5*width;
        polygon << QPointF(0,0-temp) << QPointF(0-0.5*width, 0) << QPointF(0-width, 0.5*width) << QPointF(width, 0.5*width) << QPointF(0.5*width, 0);
        painter->drawPolygon(polygon);
        painter->setPen(QPen(Qt::black, 8));
        painter->drawLine(0-0.3*width, 0.6*width, 0-0.3*width, 0.8*width);
        painter->drawLine(0.3*width, 0.6*width, 0.3*width, 0.8*width);
        painter->setPen(QPen(QColor("#EBCB8B"), 1));
        
    }else if (this->name == "Carrier"){
        QPolygonF polygon;
        QRadialGradient Radial(0,0,120,0,15);// gradient(0-0.3*width, 0.8*width, 0-0.3*width, 1.5*width);
        
        Radial.setColorAt(0.0,QColor("#81A1C1"));
        Radial.setColorAt(u(e),QColor("#88C0D0"));
        painter->setPen(Qt::transparent);
        painter->setBrush(Radial);
        painter->drawEllipse(0-0.6*width, 0.4*width, 1.2*width, (u(e)*2)*width);
        
        painter->setBrush(QBrush(color.toQColor()));
        painter->setPen(QPen(Qt::black,4));
        double temp = 2*width;
        polygon << QPointF(0,0-temp) << QPointF(0-0.5*width, 0) << QPointF(0-width, 0.5*width) << QPointF(width, 0.9*width) << QPointF(0.9*width, 0);
        painter->drawPolygon(polygon);
        painter->setPen(QPen(Qt::black, 8));
        painter->drawLine(0-0.3*width, 0.6*width, 0-0.3*width, 0.8*width);
        painter->drawLine(0.3*width, 0.6*width, 0.3*width, 0.8*width);
        painter->setPen(QPen(QColor("#EBCB8B"), 1));
        
    }else if (this->name == "Bullet"){
        painter->setPen(QPen(color.toColor(), 4));
        painter->drawLine(0, 0,10,10);
    }else if (this->name == "LagerStar"){
        QRadialGradient Radial(0,0,120,0,0);// gradient(0-0.3*width, 0.8*width, 0-0.3*width, 1.5*width);
        
        Radial.setColorAt(0.0,QColor("#B48EAD"));
        Radial.setColorAt(u(e),QColor("#A3BE8C"));
        radial.setColorAt(0.9, QColor("#EBCB8B"));
        painter->setPen(Qt::transparent);
        painter->setBrush(Radial);
        painter->drawEllipse(0-width, 0-width, width, height);
        
    }else if (this->name == "LittleStar"){
        QRadialGradient Radial(0,0,120,0,0);// gradient(0-0.3*width, 0.8*width, 0-0.3*width, 1.5*width);
        
        Radial.setColorAt(0.0,QColor("#B48EAD"));
        Radial.setColorAt(u(e),QColor("#A3BE8C"));
        radial.setColorAt(0.9, QColor("#EBCB8B"));
        painter->setPen(Qt::transparent);
        painter->setBrush(Radial);
        painter->drawEllipse(0-width/2, 0-width/2, width/2, height/2);
    }
    
//    painter->restore();
    painter->resetTransform();
//    std::cout << angel << std::endl;
}

void FlyObject::setSize(double width, double height){
    this->width = width;
    this->height = height;
}
int FlyObject::getWidth(){
    return this->width;
}
int FlyObject::getHeight(){
    return this->height;
}

void FlyObject::setName(std::string name){
    this->name = name;
}

std::string FlyObject::getName() const{
    return this->name;
}

void FlyObject::setAngel(){
    
    this->angel = 90 - atan2(getNextX()-getX(), getNextY()-getY())*180/3.1415926535;
}
