#include "uiconfig.h"
#include "ui_uiconfig.h"
#include "../main/systems/Engine.h"
#include "readonlydelegate.h"
#define log Engine::getInstance()->getLogger()

UIConfig::UIConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIConfig)
{
    ui->setupUi(this);
}

void UIConfig::init(){
    QStandardItemModel* itemModel = new QStandardItemModel(this);
    QStringList strList;
    strList.append("loop配置");
    strList.append("map配置");
    strList.append("母舰配置");
    strList.append("轰炸机配置");
    strList.append("战斗机配置");
    strList.append("大行星配置");
    strList.append("小行星配置");
    int nCount = strList.size();
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    ui->lv_subtitle->setModel(itemModel);
    connect(ui->lv_subtitle,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));
}

void UIConfig::showClick(QModelIndex index)
{
    QString strTemp = index.data().toString();
    if(strTemp == "loop配置"){
        showLoop();
    }else if(strTemp == "map配置"){
        showMap();
    }else if(strTemp == "母舰配置"){
        showCarrier();
    }else if(strTemp == "轰炸机配置"){
        showBomber();
    }else if(strTemp == "战斗机配置"){
        showFighter();
    }else if(strTemp == "大行星配置"){
        showLargeStar();
    }else if(strTemp == "小行星配置"){
        showLittleStar();
    }else {
        log->severe("这不可能！");
    }
}

void UIConfig::showLoop(){
    log->debug("选择了loop配置");
    QStandardItemModel* itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    QStringList strList;
    strList.append("每tick的最小时间(单位:ms)");
    strList.append("一局游戏允许的最大tick数");
    strList.append("每次读取玩家数据允许的最大延迟(单位:ms)");
    int nCount = strList.size();
//    QList<QStandardItem*> list;
//    list.append(keys);
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
//        list.append(item);
        itemModel->appendRow(item);
    }
//    itemModel->insertRows(list);
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
    ui->tv_config->setColumnWidth(0, 280);
    ui->tv_config->setColumnWidth(1, 60);
    ui->tv_config->setItemDelegateForColumn(0, new ReadOnlyDelegate());
}

void UIConfig::showMap(){
}

void UIConfig::showCarrier(){
}

void UIConfig::showBomber(){
}

void UIConfig::showFighter(){
}

void UIConfig::showLargeStar(){
}

void UIConfig::showLittleStar(){

}

UIConfig::~UIConfig()
{
    delete ui;
}
