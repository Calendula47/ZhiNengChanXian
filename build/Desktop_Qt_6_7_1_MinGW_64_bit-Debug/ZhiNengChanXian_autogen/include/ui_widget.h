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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_4;
    QSpinBox *huojiachangdu;
    QLabel *label_5;
    QSpinBox *shuruhuowu;
    QSpinBox *diedaicishu;
    QSpinBox *yiyouhuowu;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_10;
    QPushButton *pushButton;
    QLabel *label_9;
    QSpinBox *huowujianju;
    QLabel *label_8;
    QTextEdit *shuchu;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(747, 423);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 0, 12, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 8, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 9, 1, 1);

        huojiachangdu = new QSpinBox(widget);
        huojiachangdu->setObjectName("huojiachangdu");
        huojiachangdu->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(huojiachangdu, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 0, 6, 1, 1);

        shuruhuowu = new QSpinBox(widget);
        shuruhuowu->setObjectName("shuruhuowu");
        shuruhuowu->setMinimumSize(QSize(90, 30));

        gridLayout->addWidget(shuruhuowu, 0, 7, 1, 1);

        diedaicishu = new QSpinBox(widget);
        diedaicishu->setObjectName("diedaicishu");
        diedaicishu->setMinimumSize(QSize(90, 30));

        gridLayout->addWidget(diedaicishu, 0, 13, 1, 1);

        yiyouhuowu = new QSpinBox(widget);
        yiyouhuowu->setObjectName("yiyouhuowu");
        yiyouhuowu->setMinimumSize(QSize(90, 30));

        gridLayout->addWidget(yiyouhuowu, 0, 10, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 11, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Source Han Serif K Heavy")});
        font1.setPointSize(14);
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 1, 6, 1, 6);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(120, 30));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        pushButton->setFont(font2);

        gridLayout->addWidget(pushButton, 1, 12, 1, 2);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        huowujianju = new QSpinBox(widget);
        huowujianju->setObjectName("huowujianju");
        huowujianju->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(huowujianju, 1, 1, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 1, 2, 1, 1);


        verticalLayout->addWidget(widget);

        shuchu = new QTextEdit(Widget);
        shuchu->setObjectName("shuchu");

        verticalLayout->addWidget(shuchu);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "mm", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\344\273\266", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\267\262\346\234\211\350\264\247\347\211\251", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\350\264\247\347\211\251", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\264\247\346\236\266\351\225\277\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\273\266", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\350\257\267\345\260\275\351\207\217\344\277\235\350\257\201\350\276\223\345\205\245\350\264\247\347\211\251\345\244\247\344\272\216\345\267\262\346\234\211\350\264\247\347\211\251\347\232\204\344\270\244\345\200\215", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\224\237\346\210\220\346\216\222\346\240\267\346\226\271\346\241\210", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\350\264\247\347\211\251\351\227\264\350\267\235", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
