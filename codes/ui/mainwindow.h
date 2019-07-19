#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <map>
#include "spacewindow.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = nullptr);
    void setMapSize(const int, const int);
    void setMap();


signals:

public slots:
    
private:
    int map_width, map_height;
    SpaceWindow *space;
};

#endif // MAINWINDOW_H
