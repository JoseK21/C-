/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QAction *Open_File;
    QAction *Exit;
    QAction *NewFile;
    QWidget *centralWidget;
    QPushButton *Run;
    QTableWidget *tableWidget;
    QLabel *label;
    QPlainTextEdit *ptd_Stdout;
    QLabel *label_2;
    QPushButton *ButtonClear;
    QPushButton *Stop;
    QPushButton *GoOn;
    QPlainTextEdit *ptd_ApplicationLog;
    QTextEdit *ptd_CodeEdit;
    QMenuBar *menuBar;
    QMenu *menuFiles;

    void setupUi(QMainWindow *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QStringLiteral("Interface"));
        Interface->resize(1364, 736);
        QIcon icon;
        QString iconThemeName = QStringLiteral("logo.icon");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Interface->setWindowIcon(icon);
        Open_File = new QAction(Interface);
        Open_File->setObjectName(QStringLiteral("Open_File"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pics/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        Open_File->setIcon(icon1);
        Exit = new QAction(Interface);
        Exit->setObjectName(QStringLiteral("Exit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pics/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        Exit->setIcon(icon2);
        NewFile = new QAction(Interface);
        NewFile->setObjectName(QStringLiteral("NewFile"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pics/new-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        NewFile->setIcon(icon3);
        centralWidget = new QWidget(Interface);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Run = new QPushButton(centralWidget);
        Run->setObjectName(QStringLiteral("Run"));
        Run->setGeometry(QRect(0, 0, 80, 22));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Run->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("URW Palladio L"));
        font.setItalic(true);
        Run->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/pics/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        Run->setIcon(icon4);
        Run->setIconSize(QSize(20, 20));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(830, 20, 531, 421));
        tableWidget->setGridStyle(Qt::DashLine);
        tableWidget->horizontalHeader()->setDefaultSectionSize(131);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(830, 0, 131, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("URW Palladio L"));
        font1.setPointSize(14);
        font1.setItalic(true);
        label->setFont(font1);
        ptd_Stdout = new QPlainTextEdit(centralWidget);
        ptd_Stdout->setObjectName(QStringLiteral("ptd_Stdout"));
        ptd_Stdout->setGeometry(QRect(0, 460, 821, 101));
        ptd_Stdout->setReadOnly(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 560, 131, 31));
        label_2->setFont(font1);
        ButtonClear = new QPushButton(centralWidget);
        ButtonClear->setObjectName(QStringLiteral("ButtonClear"));
        ButtonClear->setGeometry(QRect(740, 570, 80, 22));
        ButtonClear->setFont(font);
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(80, 0, 80, 22));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Stop->setPalette(palette1);
        Stop->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/pics/st.png"), QSize(), QIcon::Normal, QIcon::Off);
        Stop->setIcon(icon5);
        Stop->setIconSize(QSize(20, 20));
        GoOn = new QPushButton(centralWidget);
        GoOn->setObjectName(QStringLiteral("GoOn"));
        GoOn->setGeometry(QRect(160, 0, 80, 22));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        GoOn->setPalette(palette2);
        GoOn->setFont(font);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/pics/step.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        GoOn->setIcon(icon6);
        GoOn->setIconSize(QSize(20, 20));
        ptd_ApplicationLog = new QPlainTextEdit(centralWidget);
        ptd_ApplicationLog->setObjectName(QStringLiteral("ptd_ApplicationLog"));
        ptd_ApplicationLog->setGeometry(QRect(0, 590, 821, 111));
        ptd_ApplicationLog->setReadOnly(true);
        ptd_CodeEdit = new QTextEdit(centralWidget);
        ptd_CodeEdit->setObjectName(QStringLiteral("ptd_CodeEdit"));
        ptd_CodeEdit->setGeometry(QRect(0, 20, 821, 421));
        Interface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Interface);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1364, 19));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        Interface->setMenuBar(menuBar);

        menuBar->addAction(menuFiles->menuAction());
        menuFiles->addAction(NewFile);
        menuFiles->addAction(Open_File);
        menuFiles->addSeparator();
        menuFiles->addAction(Exit);

        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QMainWindow *Interface)
    {
        Interface->setWindowTitle(QApplication::translate("Interface", "Interface", 0));
        Open_File->setText(QApplication::translate("Interface", "Open File", 0));
        Exit->setText(QApplication::translate("Interface", "Exit", 0));
        NewFile->setText(QApplication::translate("Interface", "New File", 0));
#ifndef QT_NO_TOOLTIP
        Run->setToolTip(QApplication::translate("Interface", "Excute Code", 0));
#endif // QT_NO_TOOLTIP
        Run->setText(QApplication::translate("Interface", "Run", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Interface", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Interface", "Value", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Interface", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Interface", "Count of Reference", 0));
        label->setText(QApplication::translate("Interface", "RAM Live View", 0));
#ifndef QT_NO_TOOLTIP
        ptd_Stdout->setToolTip(QApplication::translate("Interface", "StdOut", 0));
#endif // QT_NO_TOOLTIP
        ptd_Stdout->setPlaceholderText(QApplication::translate("Interface", ">", 0));
        label_2->setText(QApplication::translate("Interface", "Application Log", 0));
        ButtonClear->setText(QApplication::translate("Interface", "Clear", 0));
#ifndef QT_NO_TOOLTIP
        Stop->setToolTip(QApplication::translate("Interface", "Stop Code", 0));
#endif // QT_NO_TOOLTIP
        Stop->setText(QApplication::translate("Interface", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        GoOn->setToolTip(QApplication::translate("Interface", "Step by Step", 0));
#endif // QT_NO_TOOLTIP
        GoOn->setText(QApplication::translate("Interface", "Go on", 0));
#ifndef QT_NO_TOOLTIP
        ptd_ApplicationLog->setToolTip(QApplication::translate("Interface", "Application Log", 0));
#endif // QT_NO_TOOLTIP
        menuFiles->setTitle(QApplication::translate("Interface", "Files", 0));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
