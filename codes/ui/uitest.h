#ifndef UITEST_H
#define UITEST_H

#include <QWidget>
#include <map>
#include <string>
#include <memory>
using std::map, std::string, std::shared_ptr;

namespace Ui {
class UITest;
}

class UITest : public QWidget
{
    Q_OBJECT

public:
    void readData(map<string, const char*> datas);
    explicit UITest(QWidget *parent = nullptr);
    ~UITest();

private slots:
    void on_pb_enter_clicked();

private:
    Ui::UITest *ui;
};

#endif // UITEST_H
