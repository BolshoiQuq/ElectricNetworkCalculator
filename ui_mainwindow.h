/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *actionSave_as;
    QAction *action_print;
    QAction *action_settings;
    QAction *action_next;
    QAction *action_back;
    QAction *actionGuide;
    QAction *action_remove;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QPushButton *save_network;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *Time;
    QSpacerItem *verticalSpacer;
    QLineEdit *Elem_number;
    QLineEdit *path_file;
    QLineEdit *EMF_Ampl;
    QLineEdit *Initial_Phase;
    QLabel *label_5;
    QPushButton *load_button;
    QLabel *label;
    QPushButton *build_graph;
    QLabel *label_3;
    QLineEdit *Frequency;
    QPushButton *pushButton_2;
    QTextBrowser *text_edite;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuRun;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1146, 631);
        action_open = new QAction(MainWindow);
        action_open->setObjectName("action_open");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tools/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        action_save = new QAction(MainWindow);
        action_save->setObjectName("action_save");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/tools/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon1);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        actionSave_as->setIcon(icon1);
        action_print = new QAction(MainWindow);
        action_print->setObjectName("action_print");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/tools/image/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_print->setIcon(icon2);
        action_settings = new QAction(MainWindow);
        action_settings->setObjectName("action_settings");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/tools/image/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_settings->setIcon(icon3);
        action_next = new QAction(MainWindow);
        action_next->setObjectName("action_next");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/tools/image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_next->setIcon(icon4);
        action_back = new QAction(MainWindow);
        action_back->setObjectName("action_back");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/tools/image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_back->setIcon(icon5);
        actionGuide = new QAction(MainWindow);
        actionGuide->setObjectName("actionGuide");
        action_remove = new QAction(MainWindow);
        action_remove->setObjectName("action_remove");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/tools/image/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_remove->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName("gridLayout_2");
        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName("textEdit");

        gridLayout_2->addWidget(textEdit, 2, 0, 1, 1);

        save_network = new QPushButton(tab_3);
        save_network->setObjectName("save_network");

        gridLayout_2->addWidget(save_network, 0, 0, 1, 1);

        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(tab_3);
        textBrowser->setObjectName("textBrowser");

        gridLayout_2->addWidget(textBrowser, 3, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setObjectName("gridLayout_4");
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(tab_4);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 4, 0, 1, 1);

        Time = new QLineEdit(tab_4);
        Time->setObjectName("Time");

        gridLayout_4->addWidget(Time, 4, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 8, 0, 1, 1);

        Elem_number = new QLineEdit(tab_4);
        Elem_number->setObjectName("Elem_number");

        gridLayout_4->addWidget(Elem_number, 5, 2, 1, 1);

        path_file = new QLineEdit(tab_4);
        path_file->setObjectName("path_file");

        gridLayout_4->addWidget(path_file, 0, 2, 1, 1);

        EMF_Ampl = new QLineEdit(tab_4);
        EMF_Ampl->setObjectName("EMF_Ampl");

        gridLayout_4->addWidget(EMF_Ampl, 2, 2, 1, 1);

        Initial_Phase = new QLineEdit(tab_4);
        Initial_Phase->setObjectName("Initial_Phase");

        gridLayout_4->addWidget(Initial_Phase, 3, 2, 1, 1);

        label_5 = new QLabel(tab_4);
        label_5->setObjectName("label_5");

        gridLayout_4->addWidget(label_5, 5, 0, 1, 1);

        load_button = new QPushButton(tab_4);
        load_button->setObjectName("load_button");

        gridLayout_4->addWidget(load_button, 6, 2, 1, 1);

        label = new QLabel(tab_4);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        build_graph = new QPushButton(tab_4);
        build_graph->setObjectName("build_graph");

        gridLayout_4->addWidget(build_graph, 7, 2, 1, 1);

        label_3 = new QLabel(tab_4);
        label_3->setObjectName("label_3");

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        Frequency = new QLineEdit(tab_4);
        Frequency->setObjectName("Frequency");

        gridLayout_4->addWidget(Frequency, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_4->addWidget(pushButton_2, 0, 0, 1, 1);

        text_edite = new QTextBrowser(tab_4);
        text_edite->setObjectName("text_edite");

        gridLayout_4->addWidget(text_edite, 8, 2, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName("gridLayout_5");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");

        gridLayout_5->addWidget(lineEdit, 0, 1, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1146, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuRun = new QMenu(menubar);
        menuRun->setObjectName("menuRun");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuRun->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_open);
        menuFile->addAction(action_save);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(action_print);
        menuEdit->addAction(action_next);
        menuEdit->addAction(action_back);
        menuTools->addAction(action_settings);
        menuTools->addAction(action_remove);
        menuHelp->addAction(actionGuide);
        toolBar->addAction(action_open);
        toolBar->addAction(action_save);
        toolBar->addAction(action_print);
        toolBar->addAction(action_back);
        toolBar->addAction(action_next);
        toolBar->addAction(action_settings);
        toolBar->addAction(action_remove);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        action_print->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        action_settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        action_next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        action_back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        actionGuide->setText(QCoreApplication::translate("MainWindow", "Guide", nullptr));
        action_remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        save_network->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">[] - \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\320\265 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">{} - \320\277\320\260\321\200\320\260\320\273\320\273\320\265"
                        "\320\273\321\214\320\275\320\276\320\265 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">R(r) - \321\200\320\265\320\267\320\270\321\201\321\202\320\276\321\200 \321\201 \321\201\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265\320\274 r</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">C(r, c) - \320\272\320\276\320\275\320\264\320\265\320\275\321\201\320\260\321\202\320\276\321\200 \321\201 \320\260\320\272\321\202\320\270\320\262\320\275\321\213\320\274 \321\201\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265\320\274 r \320\270 \321\221\320\274\320\272\320\276\321\201\321\202\321\214\321\216 c</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\">L(r, l) - \320\264\321\200\320\276\321\201\321\201\320\265\320\273\321\214 \321\201 \320\260\320\272\321\202\320\270\320\262\320\275\321\213\320\274 \321\201\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265\320\274 r \320\270 \320\270\320\275\320\264\321\203\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\321\214\321\216 l</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\220\320\274\320\273\320\270\321\202\321\203\320\264\320\260 \320\255\320\224\320\241:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\274\320\265\320\275\321\202 \320\262\321\200\320\265\320\274\320\265\320\275\320\270:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260:", nullptr));
        load_button->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260:", nullptr));
        build_graph->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\204\320\260\320\267\320\260:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\321\221\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "R:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuRun->setTitle(QCoreApplication::translate("MainWindow", "Run", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
