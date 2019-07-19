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
#include <QPolygonF>
#include <QPointF>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QRadialGradient>
#include "../tools/Color.h"

class FlyObject : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
//
//    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry)

public:
    explicit FlyObject(QGraphicsItem *parent=nullptr);
    ~FlyObject();
//    FlyObject(std::string, int, std::string);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getX() const;
    int getY() const;
    void setX(const int);
    void setY(const int);
    void msetPos(const int, const int);
    void setSpeed(const int);
    void setSize(double, double);
    int getWidth();
    int getHeight();
    void setName(const std::string);
    std::string getName() const;
    void setNextPos(const int, const int);
    Color getColor() const;
    void setColor(const Color c);
    void move();
    int getDistance(int distance_x, int distance_y) const;
private:
    int x, y;
    int nextX, nextY;
    double width, height;
    int speed;
    std::string name;
    Color color;
    bool status;
};
#endif /* FlyObject_hpp */
