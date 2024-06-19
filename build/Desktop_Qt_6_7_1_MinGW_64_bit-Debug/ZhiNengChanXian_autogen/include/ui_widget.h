/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QSpinBox *shuruhuowu;
    QSpinBox *yiyouhuowu;
    QLabel *label;
    QSpinBox *huojiachangdu;
    QSpinBox *zuixiaochangdu;
    QLabel *label_2;
    QLabel *label_16;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_14;
    QSpinBox *huowujianju;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_3;
    QSpinBox *zuidachangdu;
    QLabel *label_15;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_10;
    QSpinBox *zhongqundaxiao;
    QLabel *label_7;
    QSpinBox *diedaicishu;
    QDoubleSpinBox *jiaochagailv;
    QDoubleSpinBox *tubiangailv;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *shuchu;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1026, 586);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);

        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label_13 = new QLabel(widget);
        label_13->setObjectName("label_13");
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        shuruhuowu = new QSpinBox(widget);
        shuruhuowu->setObjectName("shuruhuowu");
        shuruhuowu->setMinimumSize(QSize(90, 30));

        gridLayout->addWidget(shuruhuowu, 6, 1, 1, 1);

        yiyouhuowu = new QSpinBox(widget);
        yiyouhuowu->setObjectName("yiyouhuowu");
        yiyouhuowu->setMinimumSize(QSize(90, 30));

        gridLayout->addWidget(yiyouhuowu, 7, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        huojiachangdu = new QSpinBox(widget);
        huojiachangdu->setObjectName("huojiachangdu");
        huojiachangdu->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(huojiachangdu, 0, 1, 1, 1);

        zuixiaochangdu = new QSpinBox(widget);
        zuixiaochangdu->setObjectName("zuixiaochangdu");
        zuixiaochangdu->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(zuixiaochangdu, 2, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_16 = new QLabel(widget);
        label_16->setObjectName("label_16");
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 4, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        label_14 = new QLabel(widget);
        label_14->setObjectName("label_14");
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 2, 2, 1, 1);

        huowujianju = new QSpinBox(widget);
        huowujianju->setObjectName("huowujianju");
        huowujianju->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(huowujianju, 1, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 6, 2, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 7, 2, 1, 1);

        zuidachangdu = new QSpinBox(widget);
        zuidachangdu->setObjectName("zuidachangdu");
        zuidachangdu->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(zuidachangdu, 4, 1, 1, 1);

        label_15 = new QLabel(widget);
        label_15->setObjectName("label_15");
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 4, 2, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName("widget_3");
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label_11 = new QLabel(widget_3);
        label_11->setObjectName("label_11");
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setFont(font);

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(widget_3);
        label_12->setObjectName("label_12");
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setFont(font);

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName("label_10");
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setFont(font);

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        zhongqundaxiao = new QSpinBox(widget_3);
        zhongqundaxiao->setObjectName("zhongqundaxiao");
        zhongqundaxiao->setMinimumSize(QSize(90, 30));

        gridLayout_3->addWidget(zhongqundaxiao, 2, 1, 1, 1);

        label_7 = new QLabel(widget_3);
        label_7->setObjectName("label_7");
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setFont(font);

        gridLayout_3->addWidget(label_7, 3, 0, 1, 1);

        diedaicishu = new QSpinBox(widget_3);
        diedaicishu->setObjectName("diedaicishu");
        diedaicishu->setMinimumSize(QSize(90, 30));

        gridLayout_3->addWidget(diedaicishu, 3, 1, 1, 1);

        jiaochagailv = new QDoubleSpinBox(widget_3);
        jiaochagailv->setObjectName("jiaochagailv");
        jiaochagailv->setMinimumSize(QSize(120, 30));

        gridLayout_3->addWidget(jiaochagailv, 0, 1, 1, 1);

        tubiangailv = new QDoubleSpinBox(widget_3);
        tubiangailv->setObjectName("tubiangailv");
        tubiangailv->setMinimumSize(QSize(70, 30));

        gridLayout_3->addWidget(tubiangailv, 1, 1, 1, 1);


        gridLayout_2->addWidget(widget_3, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        shuchu = new QTextEdit(widget_2);
        shuchu->setObjectName("shuchu");

        verticalLayout->addWidget(shuchu);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(120, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);


        gridLayout_2->addWidget(widget_2, 0, 1, 5, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "\350\264\247\347\211\251\346\234\200\345\260\217\351\225\277\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\264\247\346\236\266\351\225\277\345\272\246", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "mm", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "\350\264\247\347\211\251\346\234\200\345\244\247\351\225\277\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\350\264\247\347\211\251", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\267\262\346\234\211\350\264\247\347\211\251", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "mm", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "mm", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\344\273\266", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\350\264\247\347\211\251\351\227\264\350\267\235", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\273\266", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "mm", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\344\272\244\345\217\211\346\246\202\347\216\207", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "\347\252\201\345\217\230\346\246\202\347\216\207", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\347\247\215\347\276\244\345\244\247\345\260\217", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\224\237\346\210\220\346\216\222\346\240\267\346\226\271\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
