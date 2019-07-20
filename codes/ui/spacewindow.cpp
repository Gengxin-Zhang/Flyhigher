#include "spacewindow.h"
#include <QPainter>
#include <QRect>
#include <QPen>
#include <QPointF>
#include <iostream>
#include <QPolygonF>
#include <QApplication>
#include <random>
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
//    QPixmap temp = pix.scaled(this->width(), this->height(), Qt::KeepAspectRatioByExpanding);
//    setBackgroundBrush(temp);
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
//    shared_ptr<FlyObject> newFlyObject = shared_ptr<FlyObject>(new FlyObject());
    
    
    
    shared_ptr<FlyObject> newFlyObject = shared_ptr<FlyObject>(new FlyObject());
    newFlyObject->setName("Bomber");
    newFlyObject->setSize(20, 20);
    newFlyObject->setNextPos(80,40);
    newFlyObject->setPos(40, 40);
    newFlyObject->setColor(Color(100,0,160,230));
    newFlyObject->setAngel();
    m_scene->addItem(newFlyObject.get());
    last_tick_snapshot.insert(std::make_pair(1, newFlyObject));
    shared_ptr<FlyObject> newFlyObject1 = shared_ptr<FlyObject>(new FlyObject());
    newFlyObject1->setName("Fighter");
    newFlyObject1->setSize(20, 20);
    newFlyObject1->setNextPos(80,80);
    newFlyObject1->setPos(30, 20);
    newFlyObject1->setColor(Color(100,94,129,172));
    newFlyObject1->setAngel();
    m_scene->addItem(newFlyObject1.get());
    last_tick_snapshot.insert(std::make_pair(2, newFlyObject1));
    shared_ptr<FlyObject> newFlyObject2 = shared_ptr<FlyObject>(new FlyObject());
    newFlyObject2->setName("Carrier");
    newFlyObject2->setSize(20, 20);
    newFlyObject2->setNextPos(80,80);
    newFlyObject2->setPos(30, 20);
    newFlyObject2->setColor(Color(100,191,97,106));
    newFlyObject2->setAngel();
    m_scene->addItem(newFlyObject2.get());
    last_tick_snapshot.insert(std::make_pair(3, newFlyObject2));
    shared_ptr<FlyObject> newFlyObject3 = shared_ptr<FlyObject>(new FlyObject());
    newFlyObject3->setName("Bomber");
    newFlyObject3->setSize(20, 20);
    newFlyObject3->setNextPos(80,80);
    newFlyObject3->setPos(30, 20);
    newFlyObject3->setColor(Color(100,208,135,112));
    newFlyObject3->setAngel();
    m_scene->addItem(newFlyObject3.get());
    last_tick_snapshot.insert(std::make_pair(4, newFlyObject4));
    
    
    game_monitor = new QTimer;
    this->connect(game_monitor, SIGNAL(timeout()), this, SLOT(updateGraph()));
    QTimer *gen_rand_pos = new QTime();
    this->connect(gen_rand_pos, SIGNAL(timeout()), this, SLOT(newPos()));
    gen_rand_pos.start(2500);
    // startGame();
}

SpaceWindow::~SpaceWindow()
{
}

void SpaceWindow::updateGraph (){
    m_scene->advance();
    QParallelAnimationGroup *flyanimation = new QParallelAnimationGroup(this);

    tick++;
    if (tick == 5){
        // 每5个UI tick 更新一次目标位置
        if (!status_copy_queue.empty()){

            map<int, shared_ptr<Entity>> now_tick_snapshot = status_copy_queue.front();
            status_copy_queue.pop();
            map<int, shared_ptr<FlyObject>> new_items;
            for(auto item : now_tick_snapshot){
            //std::for_each(now_tick_snapshot.begin(), now_tick_snapshot.end(), [=](std::map<int, shared_ptr<Entity>>::reference item){
                std::string entity_name = item.second->getClassName();
                int entity_id = item.first;
                if (last_tick_snapshot.find(entity_id)!=last_tick_snapshot.end()){
                    last_tick_snapshot[entity_id]->setNextPos(item.second->getX(), item.second->getY());
                    last_tick_snapshot[entity_id]->setAngel();
                    new_items.insert(make_pair(entity_id, new_items[entity_id]));
                }else{
                    shared_ptr<FlyObject> newFlyObject = shared_ptr<FlyObject>(new FlyObject());

                    newFlyObject->setNextPos(item.second->getX(), item.second->getY());
                    newFlyObject->setPos(item.second->getX(), item.second->getY());
                    newFlyObject->setName(entity_name);
                    newFlyObject->setSize(item.second->getRadius(), item.second->getRadius());
                    newFlyObject->setColor(Color(0, 0, 160, 230));
                    newFlyObject->setAngel();
                    m_scene->addItem(newFlyObject.get());
                    new_items.insert(std::make_pair(entity_id, newFlyObject));
                }
            }
            for(auto item : last_tick_snapshot){
                int entity_id = item.first;
                if (new_items.find(entity_id) == new_items.end()){
                    m_scene->removeItem(last_tick_snapshot[entity_id].get());
                }
            }
            last_tick_snapshot.swap(new_items);
        }
        tick = 0;
    }
    for(auto item: last_tick_snapshot){
//    std::for_each(last_tick_snapshot.begin(), last_tick_snapshot.end(), [=](std::map<int, shared_ptr<FlyObject>>::reference item){
        int x = item.second->getX();
        int y = item.second->getY();
        item.second->move();
//        std::cout << item.second->getX() <<" " << item.second->getY() << std::endl;
        item.second->setPos(item.second->getNextX(), item.second->getNextY());
        
        item.second->update();
//        QPropertyAnimation *moveAnim = new QPropertyAnimation(item.second.get() ,"pos", flyanimation);
//        moveAnim->setEndValue(QPointF(item.second->getX(), item.second->getY()));
//        moveAnim->setDuration(200);
//        moveAnim->
//        setAnimation(x, y, item.second->getX(), item.second->getY(), item.second, flyanimation);
    }
    flyanimation->start();
    m_scene->update();
}

void SpaceWindow::startGame(){
//     lettersGroupMoving->stop();
    m_lettersGroupFading->start(QAbstractAnimation::DeleteWhenStopped);
    game_monitor->start(20);
    tick = 0;
}

void SpaceWindow::addData(std::map<int, shared_ptr<Entity>> newmap) { 
    
}

void SpaceWindow::newPos(){
    for (auto item : last_tick_snapshot){
        std::default_random_engine e;
    std::uniform_real_distribution<double> u(-20,20);
        int x = item.second->getX();
        int y = item.second->getY()
        item.second->setNextPose(x+u(e), y+u(e));
    }
}