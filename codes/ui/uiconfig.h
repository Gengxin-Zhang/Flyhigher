#ifndef UICONFIG_H
#define UICONFIG_H

#include <QWidget>
#include <QStringListModel>
#include <QStandardItemModel>

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
    void showLoop();
    void showMap();
    void showCarrier();
    void showBomber();
    void showFighter();
    void showLargeStar();
    void showLittleStar();

private slots:
    void showClick(QModelIndex index);
};

#endif // UICONFIG_H
