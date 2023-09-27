/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
#include <QtWidgets/QTreeWidget>
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
    QPushButton *save_network;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *Elem_number;
    QPushButton *load_button;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *EMF_Ampl;
    QLineEdit *Frequency;
    QLineEdit *Initial_Phase;
    QLineEdit *Time;
    QSpacerItem *verticalSpacer;
    QPushButton *build_graph;
    QWidget *tab_5;
    QGridLayout *gridLayout_3;
    QPushButton *delete_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *open_filters;
    QPushButton *clear;
    QPushButton *save_pattern;
    QPushButton *calculate;
    QPushButton *close_filters;
    QSpacerItem *horizontalSpacer;
    QPushButton *set_button;
    QPushButton *save_filters;
    QTreeWidget *filters_information;
    QGraphicsView *graphics_view;
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
        MainWindow->resize(1148, 631);
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
        save_network = new QPushButton(tab_3);
        save_network->setObjectName("save_network");

        gridLayout_2->addWidget(save_network, 0, 0, 1, 1);

        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName("textEdit");

        gridLayout_2->addWidget(textEdit, 2, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setObjectName("gridLayout_4");
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(tab_4);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 3, 0, 1, 1);

        Elem_number = new QLineEdit(tab_4);
        Elem_number->setObjectName("Elem_number");

        gridLayout_4->addWidget(Elem_number, 4, 3, 1, 1);

        load_button = new QPushButton(tab_4);
        load_button->setObjectName("load_button");

        gridLayout_4->addWidget(load_button, 5, 3, 1, 1);

        label = new QLabel(tab_4);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(tab_4);
        textBrowser->setObjectName("textBrowser");

        gridLayout_4->addWidget(textBrowser, 7, 3, 1, 1);

        label_5 = new QLabel(tab_4);
        label_5->setObjectName("label_5");

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(tab_4);
        label_3->setObjectName("label_3");

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        EMF_Ampl = new QLineEdit(tab_4);
        EMF_Ampl->setObjectName("EMF_Ampl");

        gridLayout_4->addWidget(EMF_Ampl, 1, 3, 1, 1);

        Frequency = new QLineEdit(tab_4);
        Frequency->setObjectName("Frequency");

        gridLayout_4->addWidget(Frequency, 0, 3, 1, 1);

        Initial_Phase = new QLineEdit(tab_4);
        Initial_Phase->setObjectName("Initial_Phase");

        gridLayout_4->addWidget(Initial_Phase, 2, 3, 1, 1);

        Time = new QLineEdit(tab_4);
        Time->setObjectName("Time");

        gridLayout_4->addWidget(Time, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 9, 0, 1, 1);

        build_graph = new QPushButton(tab_4);
        build_graph->setObjectName("build_graph");

        gridLayout_4->addWidget(build_graph, 6, 3, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        gridLayout_3 = new QGridLayout(tab_5);
        gridLayout_3->setObjectName("gridLayout_3");
        delete_button = new QPushButton(tab_5);
        delete_button->setObjectName("delete_button");

        gridLayout_3->addWidget(delete_button, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(330, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        open_filters = new QPushButton(tab_5);
        open_filters->setObjectName("open_filters");

        gridLayout_3->addWidget(open_filters, 4, 4, 1, 1);

        clear = new QPushButton(tab_5);
        clear->setObjectName("clear");
        clear->setMinimumSize(QSize(0, 90));

        gridLayout_3->addWidget(clear, 5, 3, 1, 1);

        save_pattern = new QPushButton(tab_5);
        save_pattern->setObjectName("save_pattern");

        gridLayout_3->addWidget(save_pattern, 4, 5, 1, 1);

        calculate = new QPushButton(tab_5);
        calculate->setObjectName("calculate");
        calculate->setMinimumSize(QSize(0, 90));

        gridLayout_3->addWidget(calculate, 4, 2, 2, 1);

        close_filters = new QPushButton(tab_5);
        close_filters->setObjectName("close_filters");

        gridLayout_3->addWidget(close_filters, 6, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(562, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        set_button = new QPushButton(tab_5);
        set_button->setObjectName("set_button");

        gridLayout_3->addWidget(set_button, 4, 0, 1, 1);

        save_filters = new QPushButton(tab_5);
        save_filters->setObjectName("save_filters");

        gridLayout_3->addWidget(save_filters, 6, 5, 1, 1);

        filters_information = new QTreeWidget(tab_5);
        QFont font;
        font.setBold(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem1->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem2->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem3->setFont(0, font);
        filters_information->setObjectName("filters_information");
        filters_information->setMaximumSize(QSize(330, 1000));
        filters_information->setLayoutDirection(Qt::LeftToRight);
        filters_information->setAutoFillBackground(false);

        gridLayout_3->addWidget(filters_information, 2, 0, 1, 1);

        graphics_view = new QGraphicsView(tab_5);
        graphics_view->setObjectName("graphics_view");

        gridLayout_3->addWidget(graphics_view, 2, 1, 1, 4);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1148, 21));
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
        save_network->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Open ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "EMF_Amplitude", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        load_button->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Frequency", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Elem_number", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Initial_Phase", nullptr));
        build_graph->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\321\221\321\202", nullptr));
        delete_button->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        open_filters->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        save_pattern->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        calculate->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        close_filters->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        set_button->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        save_filters->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = filters_information->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\321\213", nullptr));

        const bool __sortingEnabled = filters_information->isSortingEnabled();
        filters_information->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = filters_information->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\320\270\321\201\321\202\320\276\321\200", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = filters_information->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\320\242\320\276\320\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = filters_information->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\320\233\320\260\320\274\320\277\320\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = filters_information->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\320\227\320\265\320\274\320\273\321\217", nullptr));
        filters_information->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201 \321\201\321\205\320\265\320\274\321\213", nullptr));
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
