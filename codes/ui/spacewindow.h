#ifndef SPACEWINDOW_H
#define SPACEWINDOW_H

#include <QGraphicsScene>
#include <QTimer>
#include <queue>
#include <map>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QGraphicsPolygonItem>

#include "../main/games/entitys/Entity.h"
#include "FlyObject.hpp"
#include "../tools/Color.h"

using std::shared_ptr;

class SpaceWindow : public QGraphicsView
{
//    Q_OBJECT

public:
    explicit SpaceWindow(QWidget *parent = nullptr);
    ~SpaceWindow();
    void addData(std::map<int, shared_ptr<Entity>>);

public slots:
    void update_map();

private:
    QGraphicsScene *m_scene;
    QTimer *game_monitor;
    std::map<int, shared_ptr<FlyObject>> last_tick_snapshot;
    
    std::queue<std::map<int, shared_ptr<Entity>>> status_copy_queue;
    int tick;
    QParallelAnimationGroup *m_lettersGroupFading;
    QSequentialAnimationGroup * lettersGroupMoving;
    void startGame();
//    void setAnimation(int x, int y, int nextX, int nextY, QGraphicsPolygonItem *item, QParallelAnimationGroup *animationGroup);
};

#endif // MAINWINDOW_H
