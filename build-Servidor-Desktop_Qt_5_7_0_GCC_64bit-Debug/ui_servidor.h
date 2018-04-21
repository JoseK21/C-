/********************************************************************************
** Form generated from reading UI file 'servidor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVIDOR_H
#define UI_SERVIDOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_servidor
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *client1;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *servidor)
    {
        if (servidor->objectName().isEmpty())
            servidor->setObjectName(QStringLiteral("servidor"));
        servidor->resize(767, 177);
        centralWidget = new QWidget(servidor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        client1 = new QPushButton(centralWidget);
        client1->setObjectName(QStringLiteral("client1"));

        horizontalLayout->addWidget(client1);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        servidor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(servidor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 767, 19));
        servidor->setMenuBar(menuBar);

        retranslateUi(servidor);

        QMetaObject::connectSlotsByName(servidor);
    } // setupUi

    void retranslateUi(QMainWindow *servidor)
    {
        servidor->setWindowTitle(QApplication::translate("servidor", "servidor", 0));
        lineEdit->setPlaceholderText(QApplication::translate("servidor", "msj:", 0));
        client1->setText(QApplication::translate("servidor", "Send msj to Client", 0));
    } // retranslateUi

};

namespace Ui {
    class servidor: public Ui_servidor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVIDOR_H
