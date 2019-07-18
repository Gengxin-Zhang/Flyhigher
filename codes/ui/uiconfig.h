#ifndef UICONFIG_H
#define UICONFIG_H

#include <QWidget>
#include <QStringListModel>
#include <QStandardItemModel>
#include "../main/configs/Configuration.h"

namespace Ui {
class UIConfig;
}

class UIConfig : public QWidget
{
    Q_OBJECT

public:
    explicit UIConfig(QWidget *parent = nullptr);
    ~UIConfig();
    void init();

private:
    Ui::UIConfig *ui;
    shared_ptr<Configuration> config;
    QString strTemp;
    bool isChanged;
    QStandardItemModel* itemModel;
    void showLoop();
    void showMap();
    void showCarrier();
    void showBomber();
    void showFighter();
    void showLargeStar();
    void showLittleStar();
    void saveLoop();
    void saveMap();
    void saveCarrier();
    void saveBomber();
    void saveFighter();
    void saveLargeStar();
    void saveLittleStar();
public slots:
    void receiveslot(int state);
private slots:
    void showClick(QModelIndex index);
    void on_pb_apply_clicked();
    void on_pb_default_clicked();
    void on_pb_start_clicked();
};

#endif // UICONFIG_H
