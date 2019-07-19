//
//  FlyObject.hpp
//  Flyhigher
//
//  Created by zhangone on 2019/7/19.
//

#ifndef FlyObject_hpp
#define FlyObject_hpp

#include <stdio.h>
#include <QString>
// #include <QMath>
#include <cmath>
#include <QObject>
#include <QRectF>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "../tools/Color.h"

class FlyObject {
//    Q_OBJECT
//
//    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry) 

public:
    explicit FlyObject(QObject *parent = 0);
    ~FlyObject();
//    FlyObject(std::string, int, std::string);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setPos(int, int);
    void setSpeed(int);
    int getSpeed(); 
    void setNextPos(int, int);
    Color getColor();
    void setColor(Color c);
    void move();
    int getDistance(int distance_x, int distance_y);
private:
    int x, y;
    int nextX, nextY;
    int speed;
    Color color;
};
#endif /* FlyObject_hpp */
