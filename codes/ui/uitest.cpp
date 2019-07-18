#include "uitest.h"
#include "ui_uitest.h"
#include "../main/games/Judger.h"

UITest::UITest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UITest)
{
    ui->setupUi(this);
}

UITest::~UITest()
{
    delete ui;
}

void UITest::on_pb_enter_clicked()
{
    Judger::jsons.push(ui->te_input->toPlainText().toStdString().c_str());
    ui->te_backup->setText(ui->te_input->toPlainText() + "\n");
    ui->te_input->setText("");
}

void UITest::readData(map<string, const char*> datas){
    string s = "";
    for(auto &p: datas){
        s += p.first + "\n";
        s += string(p.second) + "\n";
    }
    ui->te_output->setText(QString(s.c_str()));

}
