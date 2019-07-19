/********************************************************************************
** Form generated from reading UI file 'uiconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UICONFIG_H
#define UI_UICONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIConfig
{
public:
    QListView *lv_subtitle;
    QPushButton *pb_start;
    QTableView *tv_config;
    QLabel *lb_intro;
    QPushButton *pb_apply;
    QPushButton *pb_default;

    void setupUi(QWidget *UIConfig)
    {
        if (UIConfig->objectName().isEmpty())
            UIConfig->setObjectName(QString::fromUtf8("UIConfig"));
        UIConfig->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UIConfig->sizePolicy().hasHeightForWidth());
        UIConfig->setSizePolicy(sizePolicy);
        UIConfig->setMinimumSize(QSize(600, 400));
        UIConfig->setMaximumSize(QSize(600, 400));
        lv_subtitle = new QListView(UIConfig);
        lv_subtitle->setObjectName(QString::fromUtf8("lv_subtitle"));
        lv_subtitle->setGeometry(QRect(10, 30, 221, 321));
        lv_subtitle->setMinimumSize(QSize(187, 311));
        lv_subtitle->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lv_subtitle->setBatchSize(100);
        pb_start = new QPushButton(UIConfig);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));
        pb_start->setGeometry(QRect(476, 360, 121, 35));
        pb_start->setMinimumSize(QSize(0, 0));
        tv_config = new QTableView(UIConfig);
        tv_config->setObjectName(QString::fromUtf8("tv_config"));
        tv_config->setGeometry(QRect(250, 30, 341, 321));
        tv_config->horizontalHeader()->setVisible(false);
        tv_config->horizontalHeader()->setMinimumSectionSize(0);
        tv_config->horizontalHeader()->setDefaultSectionSize(280);
        tv_config->verticalHeader()->setVisible(false);
        tv_config->verticalHeader()->setMinimumSectionSize(20);
        tv_config->verticalHeader()->setDefaultSectionSize(20);
        lb_intro = new QLabel(UIConfig);
        lb_intro->setObjectName(QString::fromUtf8("lb_intro"));
        lb_intro->setGeometry(QRect(10, 5, 187, 21));
        lb_intro->setMinimumSize(QSize(187, 21));
        pb_apply = new QPushButton(UIConfig);
        pb_apply->setObjectName(QString::fromUtf8("pb_apply"));
        pb_apply->setGeometry(QRect(244, 360, 121, 35));
        pb_apply->setMinimumSize(QSize(0, 0));
        pb_default = new QPushButton(UIConfig);
        pb_default->setObjectName(QString::fromUtf8("pb_default"));
        pb_default->setGeometry(QRect(360, 360, 121, 35));
        pb_default->setMinimumSize(QSize(0, 0));

        retranslateUi(UIConfig);

        QMetaObject::connectSlotsByName(UIConfig);
    } // setupUi

    void retranslateUi(QWidget *UIConfig)
    {
        UIConfig->setWindowTitle(QApplication::translate("UIConfig", "\351\205\215\347\275\256\344\275\240\347\232\204\346\270\270\346\210\217", nullptr));
        pb_start->setText(QApplication::translate("UIConfig", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        lb_intro->setText(QApplication::translate("UIConfig", "\350\257\267\350\260\203\346\225\264\346\255\244\345\244\204\345\217\202\346\225\260\351\205\215\347\275\256\346\202\250\347\232\204\346\270\270\346\210\217\357\274\232", nullptr));
        pb_apply->setText(QApplication::translate("UIConfig", "\345\272\224\347\224\250\346\233\264\346\224\271", nullptr));
        pb_default->setText(QApplication::translate("UIConfig", "\350\256\276\347\275\256\351\273\230\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIConfig: public Ui_UIConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UICONFIG_H
