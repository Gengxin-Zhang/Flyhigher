/********************************************************************************
** Form generated from reading UI file 'uitest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITEST_H
#define UI_UITEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UITest
{
public:
    QTextEdit *te_input;
    QTextEdit *te_output;
    QPushButton *pb_enter;
    QTextEdit *te_backup;

    void setupUi(QWidget *UITest)
    {
        if (UITest->objectName().isEmpty())
            UITest->setObjectName(QString::fromUtf8("UITest"));
        UITest->resize(600, 800);
        te_input = new QTextEdit(UITest);
        te_input->setObjectName(QString::fromUtf8("te_input"));
        te_input->setGeometry(QRect(20, 20, 561, 161));
        te_output = new QTextEdit(UITest);
        te_output->setObjectName(QString::fromUtf8("te_output"));
        te_output->setGeometry(QRect(20, 390, 561, 311));
        te_output->setReadOnly(true);
        pb_enter = new QPushButton(UITest);
        pb_enter->setObjectName(QString::fromUtf8("pb_enter"));
        pb_enter->setGeometry(QRect(460, 720, 113, 32));
        te_backup = new QTextEdit(UITest);
        te_backup->setObjectName(QString::fromUtf8("te_backup"));
        te_backup->setGeometry(QRect(20, 190, 561, 191));
        te_backup->setReadOnly(true);

        retranslateUi(UITest);

        QMetaObject::connectSlotsByName(UITest);
    } // setupUi

    void retranslateUi(QWidget *UITest)
    {
        UITest->setWindowTitle(QApplication::translate("UITest", "Form", nullptr));
        pb_enter->setText(QApplication::translate("UITest", "\350\276\223\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UITest: public Ui_UITest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITEST_H
