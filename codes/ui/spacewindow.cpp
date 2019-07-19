#include "spacewindow.h"
#include <QPainter>
#include <QRect>
#include <QPen>
#include <QPointF>
#include <QPolygonF>
#include <QApplication>
using std::map;


SpaceWindow::SpaceWindow(QWidget *parent) :
    QGraphicsView(parent)
{
    m_scene = new QGraphicsScene;
//    QRect screenRect = QApplication::desktop()->availableGeometry();
//    QRect screenRect = QApplication::desktop()->screenGeometry();
    tick = 0;
    m_scene->setSceneRect(0, 0, this->width(), this->height());
    setScene(m_scene);
    setWindowFlags(Qt::FramelessWindowHint);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setOptimizationFlags(QGraphicsView::DontClipPainter | QGraphicsView::DontSavePainterState);
    setRenderHint(QPainter::Antialiasing);
    QPixmap pix(this->width(), this->height());
    pix.load("/User/zhangone/bg.jpg");
    QPixmap temp = pix.scaled(this->width(), this->height(), Qt::KeepAspectRatioByExpanding);
    setBackgroundBrush(temp);
//    QPixmap pix(SCENEWIDTH, SCENEHEIGHT);
    
    //显示flyhigher动画
    static const int nLetters = 10;
    static struct {
        char const *pix;
        qreal initX, initY;
        qreal destX, destY;
    } letterData[nLetters] = {
        { "F", -1000, -1000, -120, -60 },
        { "L", -800, -1000, -70, -60 },
        { "Y", -600, -1000, -20, -60 },
        { "H", -400, -1000, -80, 0 },
        { "I", 1000, 2000, -23, 0 },
        { "G", 800, 2000, 10, 0 },
        { "H", 600, 2000, 60, 0 },
        { "E", 400, 2000, 110, 0 },
        { "R", 200, 2000, 160, 0 },
        { "Loading...", -2000, 0, 30, 60}
    };
    
    lettersGroupMoving = new QSequentialAnimationGroup(this);
    m_lettersGroupFading = new QParallelAnimationGroup(this);
    
    for (int i = 0; i < nLetters-1; ++i) {
        QString htmlText = QString("<span style=\"font-family:'Berlin Sans FB';font-size:48px;font-weight:600;color:#5E81AC;\">%1</span>").arg(letterData[i].pix);
        QGraphicsTextItem *letter = new QGraphicsTextItem();
        letter->setHtml(htmlText);
        letter->setPos(letterData[i].initX, letterData[i].initY);
        
        QPropertyAnimation *moveAnim = new QPropertyAnimation(letter, "pos", lettersGroupMoving);
        moveAnim->setEndValue(QPointF(letterData[i].destX, letterData[i].destY));
        moveAnim->setDuration(200);
        moveAnim->setEasingCurve(QEasingCurve::OutElastic);
        lettersGroupMoving->addPause(50);
        QPropertyAnimation *fadeAnim = new QPropertyAnimation(letter, "opacity", m_lettersGroupFading);
        fadeAnim->setDuration(1000);
        fadeAnim->setEndValue(0);
        fadeAnim->setEasingCurve(QEasingCurve::OutQuad);
        
        m_scene->addItem(letter);
    }
    QString htmlText = QString("<span style=\"font-family:'Berlin Sans FB';font-size:35px;font-weight:600;color:#D08770;\">%1</span>").arg(letterData[9].pix);
    QGraphicsTextItem *letter = new QGraphicsTextItem();
    letter->setHtml(htmlText);
    letter->setPos(letterData[9].initX, letterData[9].initY);
    
    QPropertyAnimation *moveAnim = new QPropertyAnimation(letter, "pos", lettersGroupMoving);
    moveAnim->setEndValue(QPointF(letterData[9].destX, letterData[9].destY));
    moveAnim->setDuration(800);
    moveAnim->setEasingCurve(QEasingCurve::OutElastic);
    lettersGroupMoving->addPause(80);
    QPropertyAnimation *fadeAnim = new QPropertyAnimation(letter, "opacity", m_lettersGroupFading);
    fadeAnim->setDuration(1000);
    fadeAnim->setEndValue(0);
    fadeAnim->setEasingCurve(QEasingCurve::OutQuad);
    
    m_scene->addItem(letter);
    lettersGroupMoving->start(QAbstractAnimation::DeleteWhenStopped);
     QGraphicsPolygonItem *pItem = new QGraphicsPolygonItem();

    // 绘制多边形
    QPolygonF polygon;
    polygon << QPointF(200.0, 120.0) << QPointF(230.0, 130.0)
        << QPointF(260.0, 180.0) << QPointF(200.0, 200.0);
    pItem->setPolygon(polygon);

    // 设置画笔、画刷
    QPen pen = pItem->pen();
    pen.setWidth(2);
    pen.setColor(Qt::black);
    pItem->setPen(pen);
    pItem->setBrush(QBrush(QColor(0, 160, 230)));

    m_scene->addItem(pItem);
    
    game_monitor = new QTimer;
    connect(game_monitor, SIGNAL(timeout()), this, SLOT(update_map()));
}

SpaceWindow::~SpaceWindow()
{
}

void SpaceWindow::update_map(){
    m_scene->advance();
    QParallelAnimationGroup *flyanimation = new QParallelAnimationGroup(this);

    tick++;
    if (tick == 5){
        // 每5个UI tick 更新一次目标位置
        if (!status_copy_queue.empty()){

            map<int, shared_ptr<Entity>> now_tick_snapshot = status_copy_queue.front();
            status_copy_queue.pop();
            map<int, shared_ptr<FlyObject>> new_items;
            std::for_each(now_tick_snapshot.begin(), now_tick_snapshot.end(), [=](std::map<int, shared_ptr<Entity>>::reference item){
                std::string entity_name = item.second->getClassName();
                int entity_id = item.first;
                if (last_tick_snapshot.find(entity_id)!=last_tick_snapshot.end()){
                    last_tick_snapshot[entity_id]->setNextPos(item.second->getX(), item.second->getY());
                    new_items.insert(make_pair(1, new_items[1]));
                }else{
                    shared_ptr<FlyObject> newFlyObject = shared_ptr<FlyObject>(new FlyObject());

                    newFlyObject->setNextPos(item.second->getX(), item.second->getY());
                    newFlyObject->setPos(item.second->getX(), item.second->getY());
                    
                    newFlyObject->setColor(Color(0, 0, 160, 230));
                    new_items.insert(std::make_pair(entity_id, newFlyObject));
                }
            });
            last_tick_snapshot.swap(new_items);

            tick = 0;
        }
    }
    std::for_each(last_tick_snapshot.begin(), last_tick_snapshot.end(), [=](std::map<int, shared_ptr<FlyObject>>::reference item){
        int x = item.second->getX();
        int y = item.second->getY();
        item.second->move();


//        setAnimation(x, y, item.second.getX(), item.second.getY(), &graph_items[item.first], flyanimation)  
              
    });
    flyanimation->start();
}

void SpaceWindow::startGame(){
//     lettersGroupMoving->stop();
    m_lettersGroupFading->start(QAbstractAnimation::DeleteWhenStopped);
    game_monitor->start(20);
    tick = 0;
}
