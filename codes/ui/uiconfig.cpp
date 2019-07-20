#include "uiconfig.h"
#include "ui_uiconfig.h"
#include "../main/systems/Engine.h"
#include "readonlydelegate.h"
#include <QMessageBox>
#include <QMap>
#define log Engine::getInstance()->getLogger()
#define myroot config->getRoot()
using std::to_string;

UIConfig::UIConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIConfig)
{
    ui->setupUi(this);
    std::map<int, shared_ptr<Engine>> a;
    a.insert(make_pair(1, Engine::getInstance()));
}

void UIConfig::init(){
    strTemp = "";
    isChanged = false;
    config = Configuration::getInstance();
    QStandardItemModel *itemModel = new QStandardItemModel(this);
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
    if(strTemp != "" && isChanged){
        if(QMessageBox::warning(this, "警告", "您确定要离开此页面吗？未保存的更改将会丢失！", QMessageBox::Yes | QMessageBox::No)
                == QMessageBox::No)
            return;
    }
    isChanged = false;
    strTemp = index.data().toString();
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
    ui->tv_config->setColumnWidth(0, 275);
    ui->tv_config->setColumnWidth(1, 60);
    ui->tv_config->setItemDelegateForColumn(0, new ReadOnlyDelegate());
//    ui->tv_config->setItemDelegateForColumn(1, new MyOperDelegate());
    ui->tv_config->setItemDelegateForRow(0, new ReadOnlyDelegate());
}

void UIConfig::showLoop(){
    log->debug("选择了loop配置");
    itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    QStringList strList;
    strList.append("每tick的最小时间(单位:ms)");
    strList.append("一局游戏允许的最大tick数");
    strList.append("每次读取玩家数据允许的最大延迟(单位:ms)");
    strList.append("玩家个数");
    int nCount = strList.size();
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    list.append(new QStandardItem(QString::number(myroot["loop"]["timePerTick"].as<long>())));
    list.append(new QStandardItem(QString::number(myroot["loop"]["allowMaxTick"].as<long>())));
    list.append(new QStandardItem(QString::number(myroot["loop"]["allowWaitTime"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["loop"]["playerNumber"].as<int>())));
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
}

void UIConfig::showMap(){
    log->debug("选择了map配置");
    itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    int maxAllowPlayer = myroot["map"]["maxAllowPlayer"].as<int>();
    QStringList strList;
    strList.append("地图高度(单位:px)");
    strList.append("地图宽度(单位:px)");
    strList.append("允许的最大玩家数");
    strList.append("出生点");
    for(int i=1; i<=maxAllowPlayer; ++i){
        strList.append("    出生点" + QString::number(i));
        strList.append("        中心x坐标：");
        strList.append("        中心y坐标：");
    }
    int nCount = strList.size();
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    list.append(new QStandardItem(QString::number(myroot["map"]["height"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["map"]["width"].as<int>())));
    list.append(new QStandardItem(QString::number(maxAllowPlayer)));
    list.append(new QStandardItem(""));
    for(int i=1; i<=maxAllowPlayer; ++i){
        list.append(new QStandardItem(""));
        list.append(new QStandardItem(QString::number(myroot["map"]["birthPlaces"][to_string(i)]["x"].as<double>())));
        list.append(new QStandardItem(QString::number(myroot["map"]["birthPlaces"][to_string(i)]["y"].as<double>())));
    }
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
}

void UIConfig::showCarrier(){
    log->debug("选择了母舰配置");
    itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    QStringList strList;
    strList.append("生命值");
    strList.append("速度");
    strList.append("碰撞半径");
    strList.append("恢复速率(单位:/tick)");
    strList.append("恢复的能量消耗(单位:p/tick)");
    strList.append("视角(单位:rad)");
    strList.append("静态视野半径");
    strList.append("动态视野半径");
    strList.append("武器");
    strList.append("    子弹碰撞半径");
    strList.append("    子弹速度");
    strList.append("    子弹伤害");
    strList.append("    射击冷却时间(单位:tick)");
    strList.append("核武器");
    strList.append("    中心伤害");
    strList.append("    伤害范围");
    strList.append("    伤害衰减(单位:/px)");
    strList.append("    子弹碰撞半径");
    strList.append("    子弹速度");
    int nCount = strList.size();
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["health"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["speed"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["healRate"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["healPower"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["sightAngle"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["longSight"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["normal"]["shortSight"].as<double>())));
    list.append(new QStandardItem(""));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["weapon"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["weapon"]["speed"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["weapon"]["damage"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["weapon"]["cd"].as<int>())));
    list.append(new QStandardItem(""));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["nuke"]["aoeDamage"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["nuke"]["aoeRadius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["nuke"]["damageDecrease"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["nuke"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["carrier"]["nuke"]["speed"].as<double>())));
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
}

void UIConfig::showBomber(){
    log->debug("选择了轰炸机配置");
    itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    QStringList strList;
    strList.append("生命值");
    strList.append("速度");
    strList.append("碰撞半径");
    strList.append("恢复速率(单位:/tick)");
    strList.append("恢复的能量消耗(单位:p/tick)");
    strList.append("视角(单位:rad)");
    strList.append("静态视野半径");
    strList.append("动态视野半径");
    strList.append("武器");
    strList.append("    子弹碰撞半径");
    strList.append("    子弹速度");
    strList.append("    子弹伤害");
    strList.append("    射击冷却时间(单位:tick)");
    int nCount = strList.size();
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["health"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["speed"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["healRate"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["healPower"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["sightAngle"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["longSight"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["normal"]["shortSight"].as<double>())));
    list.append(new QStandardItem(""));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["weapon"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["weapon"]["speed"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["weapon"]["damage"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["bomber"]["weapon"]["cd"].as<int>())));
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
    ui->tv_config->setItemDelegateForRow(9, new ReadOnlyDelegate());
}

void UIConfig::showFighter(){
    log->debug("选择了战斗机配置");
    itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    QStringList strList;
    strList.append("生命值");
    strList.append("速度");
    strList.append("碰撞半径");
    strList.append("恢复速率(单位:/tick)");
    strList.append("恢复的能量消耗(单位:p/tick)");
    strList.append("视角(单位:rad)");
    strList.append("静态视野半径");
    strList.append("动态视野半径");
    strList.append("武器");
    strList.append("    子弹碰撞半径");
    strList.append("    子弹速度");
    strList.append("    子弹伤害");
    strList.append("    射击冷却时间(单位:tick)");
    strList.append("重造");
    strList.append("    重造所需时间(单位:tick)");
    strList.append("    重造所需资源");
    int nCount = strList.size();
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["health"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["speed"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["healRate"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["healPower"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["sightAngle"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["longSight"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["normal"]["shortSight"].as<double>())));
    list.append(new QStandardItem(""));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["weapon"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["weapon"]["speed"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["weapon"]["damage"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["weapon"]["cd"].as<int>())));
    list.append(new QStandardItem(""));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["rebuild"]["tick"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["fighter"]["rebuild"]["power"].as<int>())));
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
}

void UIConfig::showLargeStar(){
    log->debug("选择了大行星配置");
    itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    QStringList strList;
    strList.append("资源量");
    strList.append("半径(资源实体不具有碰撞性)");
    strList.append("采集所需时间(单位:tick)");
    int nCount = strList.size();
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    list.append(new QStandardItem(QString::number(myroot["largeStar"]["power"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["largeStar"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["largeStar"]["collectTick"].as<int>())));
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
}

void UIConfig::showLittleStar(){
    log->debug("选择了小行星配置");
    itemModel = new QStandardItemModel(this);
    QStandardItem *keys = new QStandardItem("配置项");
    QStringList strList;
    strList.append("资源量");
    strList.append("半径(资源实体不具有碰撞性)");
    strList.append("采集所需时间(单位:tick)");
    int nCount = strList.size();
    itemModel->appendRow(keys);
    for(int i = 0; i<nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        itemModel->appendRow(item);
    }
    QList<QStandardItem*> list;
    QStandardItem* values = new QStandardItem("值");
    list.append(values);
    list.append(new QStandardItem(QString::number(myroot["littleStar"]["power"].as<int>())));
    list.append(new QStandardItem(QString::number(myroot["littleStar"]["radius"].as<double>())));
    list.append(new QStandardItem(QString::number(myroot["littleStar"]["collectTick"].as<int>())));
    itemModel->appendColumn(list);
    ui->tv_config->setModel(itemModel);
}

void UIConfig::saveLoop(){
    log->debug("保存loop配置");
    myroot["loop"]["timePerTick"] = itemModel->takeItem(1,1)->text().toLong();
    myroot["loop"]["allowMaxTick"] = itemModel->takeItem(2,1)->text().toLong();
    myroot["loop"]["allowWaitTime"] = itemModel->takeItem(3,1)->text().toInt();
    myroot["loop"]["playerNumber"] = itemModel->takeItem(4,1)->text().toInt();
}

void UIConfig::saveMap(){
    log->debug("保存map配置");
    log->debug("暂未有好的改变maxAllowPlayer的设计，因此出生点请手动修改config.yml");
    //TODO: 需要一个好的改变maxAllowPlayer的设计
    myroot["map"]["height"] = itemModel->takeItem(1,1)->text().toInt();
    myroot["map"]["width"] = itemModel->takeItem(2,1)->text().toInt();
    for(int i=1; i<=myroot["map"]["maxAllowPlayer"].as<int>(); ++i){
        myroot["map"]["birthPlaces"][to_string(i)]["x"] = itemModel->takeItem(2+i*3+1,1)->text().toDouble();
        myroot["map"]["birthPlaces"][to_string(i)]["y"] = itemModel->takeItem(2+i*3+2,1)->text().toDouble();
    }
}

void UIConfig::saveCarrier(){
    log->debug("保存母舰配置");
    myroot["carrier"]["normal"]["health"] = itemModel->takeItem(1,1)->text().toInt();
    myroot["carrier"]["normal"]["speed"] = itemModel->takeItem(2,1)->text().toDouble();
    myroot["carrier"]["normal"]["radius"] = itemModel->takeItem(3,1)->text().toDouble();
    myroot["carrier"]["normal"]["healRate"] = itemModel->takeItem(4,1)->text().toInt();
    myroot["carrier"]["normal"]["healPower"] = itemModel->takeItem(5,1)->text().toInt();
    myroot["carrier"]["normal"]["sightAngle"] = itemModel->takeItem(6,1)->text().toDouble();
    myroot["carrier"]["normal"]["longSight"] = itemModel->takeItem(7,1)->text().toDouble();
    myroot["carrier"]["normal"]["shortSight"] = itemModel->takeItem(8,1)->text().toDouble();
    myroot["carrier"]["weapon"]["radius"] = itemModel->takeItem(10,1)->text().toDouble();
    myroot["carrier"]["weapon"]["speed"] = itemModel->takeItem(11,1)->text().toDouble();
    myroot["carrier"]["weapon"]["damage"] = itemModel->takeItem(12,1)->text().toInt();
    myroot["carrier"]["weapon"]["cd"] = itemModel->takeItem(13,1)->text().toInt();
    myroot["carrier"]["nuke"]["aoeDamage"] = itemModel->takeItem(15,1)->text().toInt();
    myroot["carrier"]["nuke"]["aoeRadius"] = itemModel->takeItem(16,1)->text().toDouble();
    myroot["carrier"]["nuke"]["damageDecrease"] = itemModel->takeItem(17,1)->text().toInt();
    myroot["carrier"]["nuke"]["radius"] = itemModel->takeItem(18,1)->text().toDouble();
    myroot["carrier"]["nuke"]["speed"] = itemModel->takeItem(19,1)->text().toDouble();
}

void UIConfig::saveBomber(){
    log->debug("保存轰炸机配置");
    myroot["bomber"]["normal"]["health"] = itemModel->takeItem(1,1)->text().toInt();
    myroot["bomber"]["normal"]["speed"] = itemModel->takeItem(2,1)->text().toDouble();
    myroot["bomber"]["normal"]["radius"] = itemModel->takeItem(3,1)->text().toDouble();
    myroot["bomber"]["normal"]["healRate"] = itemModel->takeItem(4,1)->text().toInt();
    myroot["bomber"]["normal"]["healPower"] = itemModel->takeItem(5,1)->text().toInt();
    myroot["bomber"]["normal"]["sightAngle"] = itemModel->takeItem(6,1)->text().toDouble();
    myroot["bomber"]["normal"]["longSight"] = itemModel->takeItem(7,1)->text().toDouble();
    myroot["bomber"]["normal"]["shortSight"] = itemModel->takeItem(8,1)->text().toDouble();
    myroot["bomber"]["weapon"]["radius"] = itemModel->takeItem(10,1)->text().toDouble();
    myroot["bomber"]["weapon"]["speed"] = itemModel->takeItem(11,1)->text().toDouble();
    myroot["bomber"]["weapon"]["damage"] = itemModel->takeItem(12,1)->text().toInt();
    myroot["bomber"]["weapon"]["cd"] = itemModel->takeItem(13,1)->text().toInt();
}

void UIConfig::saveFighter(){
    log->debug("保存战斗机配置");
    myroot["bomber"]["normal"]["health"] = itemModel->takeItem(1,1)->text().toInt();
    myroot["bomber"]["normal"]["speed"] = itemModel->takeItem(2,1)->text().toDouble();
    myroot["bomber"]["normal"]["radius"] = itemModel->takeItem(3,1)->text().toDouble();
    myroot["bomber"]["normal"]["healRate"] = itemModel->takeItem(4,1)->text().toInt();
    myroot["bomber"]["normal"]["healPower"] = itemModel->takeItem(5,1)->text().toInt();
    myroot["bomber"]["normal"]["sightAngle"] = itemModel->takeItem(6,1)->text().toDouble();
    myroot["bomber"]["normal"]["longSight"] = itemModel->takeItem(7,1)->text().toDouble();
    myroot["bomber"]["normal"]["shortSight"] = itemModel->takeItem(8,1)->text().toDouble();
    myroot["bomber"]["weapon"]["radius"] = itemModel->takeItem(10,1)->text().toDouble();
    myroot["bomber"]["weapon"]["speed"] = itemModel->takeItem(11,1)->text().toDouble();
    myroot["bomber"]["weapon"]["damage"] = itemModel->takeItem(12,1)->text().toInt();
    myroot["bomber"]["weapon"]["cd"] = itemModel->takeItem(13,1)->text().toInt();
    myroot["fighter"]["rebuild"]["tick"] = itemModel->takeItem(15,1)->text().toInt();
    myroot["fighter"]["rebuild"]["power"] = itemModel->takeItem(16,1)->text().toInt();
}

void UIConfig::saveLargeStar(){
    log->debug("保存大行星配置");
    myroot["largeStar"]["power"] = itemModel->takeItem(1,1)->text().toInt();
    myroot["largeStar"]["radius"] = itemModel->takeItem(2,1)->text().toInt();
    myroot["largeStar"]["collectTick"] = itemModel->takeItem(3,1)->text().toInt();
}

void UIConfig::saveLittleStar(){
    log->debug("保存小行星配置");
    myroot["littleStar"]["power"] = itemModel->takeItem(1,1)->text().toInt();
    myroot["littleStar"]["radius"] = itemModel->takeItem(2,1)->text().toInt();
    myroot["littleStar"]["collectTick"] = itemModel->takeItem(3,1)->text().toInt();
}

UIConfig::~UIConfig()
{
    delete ui;
}

void UIConfig::on_pb_apply_clicked()
{
    if(strTemp == "loop配置"){
        saveLoop();
    }else if(strTemp == "map配置"){
        saveMap();
    }else if(strTemp == "母舰配置"){
        saveCarrier();
    }else if(strTemp == "轰炸机配置"){
        saveBomber();
    }else if(strTemp == "战斗机配置"){
        saveFighter();
    }else if(strTemp == "大行星配置"){
        saveLargeStar();
    }else if(strTemp == "小行星配置"){
        saveLittleStar();
    }
    config->writeToYaml();
    config->reload();
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
    }
    QMessageBox::information(this, "提示", "保存成功！");
}

void UIConfig::on_pb_default_clicked()
{
    QMessageBox::information(this, "提示", "成功恢复到默认配置！");
    config->setDefault();
    config->writeToYaml();
    config->reload();
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
    }
}

void UIConfig::on_pb_start_clicked()
{
    this->hide();
    mw = new mainWindow;
    mw->show();
//    Judger::jsons.push("{\"uid\": \"A\", \"name\": \"XHH\", \"color_a\": 100, \"color_r\": 127, \"color_g\": 221, \"color_b\": 87}");
//    Judger::jsons.push("{\"uid\": \"B\", \"name\": \"NMD\", \"color_a\": 100, \"color_r\": 87, \"color_g\": 89, \"color_b\": 123}");
    Engine::getInstance()->startGame(Configuration::getInstance()->getGameConfiguration());
}


void UIConfig::receiveslot(int state){
    if(state == 1){
        QMessageBox::warning(nullptr, "警告", "由于长时间未能开始游戏，游戏中止。");
        mw->showNormal();
        mw->hide();
        mw->close();
        delete mw;
    }
    this->showNormal();
}
