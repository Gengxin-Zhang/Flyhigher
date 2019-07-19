#include "mainwindow.h"
#include "spacewindow.h"
#include <QGraphicsScene>

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->showFullScreen();
    QGraphicsScene scene;
    space = new SpaceWindow(this);
    this->map_width = 400;
    this->map_height = 400;
    space->resize(this->map_width, this->map_height);
    space->move((this->width()-this->map_width)/2, (this->height()-this->map_height)/2);
    space->show();
}

void mainWindow::setMapSize(int x, int y){
    this->map_width = x;
    this->map_height = y;
    space->resize(this->map_width, this->map_height);
    space->move((this->width()-this->map_width)/2, (this->height()-this->map_height)/2);
}
