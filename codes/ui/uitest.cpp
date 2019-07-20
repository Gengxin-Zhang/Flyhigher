#include "uitest.h"
#include "ui_uitest.h"
#include "../main/games/Judger.h"
#include <QScrollBar>
#include "../main/systems/Engine.h"
#include "../tools/DataReader.h"
#define log Engine::getInstance()->getLogger()

UITest::UITest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UITest)
{
    ui->setupUi(this);
    ui->te_input->setAcceptRichText(false);
}

UITest::~UITest()
{
    delete ui;
}

void UITest::on_pb_enter_clicked()
{
    log->debug(ui->te_input->toPlainText().toStdString());
    DataReader::getMsgPool().push(ui->te_input->toPlainText().toStdString());
    ui->te_backup->setText(ui->te_input->toPlainText() + "\n");
    ui->te_input->setText("");
}

void UITest::output(QString s){
    ui->te_output->setText(s);

}
