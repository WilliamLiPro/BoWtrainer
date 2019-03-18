/********************************************************************************
** Form generated from reading UI file 'bovwtrainer.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOVWTRAINER_H
#define UI_BOVWTRAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoVWTrainerClass
{
public:
    QAction *actionHelp;
    QAction *actionExit;
    QWidget *centralWidget;
    QLabel *show_im_feature;
    QTextBrowser *text_showfile;
    QProgressBar *progressBar;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QComboBox *sample_detector;
    QLabel *label_3;
    QComboBox *sample_extractor;
    QGroupBox *groupBox_3;
    QToolButton *button_select_in_path_2;
    QLabel *load_dataset;
    QLabel *label_4;
    QComboBox *open_camera;
    QToolButton *sample_pause;
    QToolButton *sample_run;
    QToolButton *sample_stop;
    QGroupBox *groupBox;
    QLabel *label_6;
    QComboBox *trainbovw_feature;
    QSpinBox *bovw_levels;
    QLabel *label_7;
    QSpinBox *bovw_branches;
    QLabel *label_8;
    QToolButton *trainbovw_pause;
    QToolButton *trainbovw_run;
    QToolButton *trainbovw_stop;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BoVWTrainerClass)
    {
        if (BoVWTrainerClass->objectName().isEmpty())
            BoVWTrainerClass->setObjectName(QStringLiteral("BoVWTrainerClass"));
        BoVWTrainerClass->resize(680, 505);
        BoVWTrainerClass->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0.550773, y1:1, x2:0.551136, y2:0.023, stop:0 rgba(80, 120, 250, 120), stop:1 rgba(200, 240, 255, 200));"));
        actionHelp = new QAction(BoVWTrainerClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionExit = new QAction(BoVWTrainerClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(BoVWTrainerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        show_im_feature = new QLabel(centralWidget);
        show_im_feature->setObjectName(QStringLiteral("show_im_feature"));
        show_im_feature->setGeometry(QRect(20, 10, 320, 240));
        show_im_feature->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        text_showfile = new QTextBrowser(centralWidget);
        text_showfile->setObjectName(QStringLiteral("text_showfile"));
        text_showfile->setGeometry(QRect(370, 10, 296, 246));
        text_showfile->setStyleSheet(QStringLiteral("background-color: rgb(250, 255, 255);"));
        text_showfile->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        text_showfile->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        text_showfile->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(210, 260, 131, 10));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 280, 356, 151));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        groupBox_4->setFont(font);
        groupBox_4->setAcceptDrops(false);
        groupBox_4->setToolTipDuration(-1);
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.550773, y1:1, x2:0.551136, y2:0.023, stop:0 rgba(78, 114, 238, 150), stop:1 rgba(255, 255, 255, 255));\n"
"font: 75 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 0, 81);"));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 25, 51, 21));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"color: rgb(0, 0, 81);"));
        sample_detector = new QComboBox(groupBox_4);
        sample_detector->setObjectName(QStringLiteral("sample_detector"));
        sample_detector->setGeometry(QRect(60, 25, 71, 21));
        sample_detector->setFont(font);
        sample_detector->setAutoFillBackground(false);
        sample_detector->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 220);"));
        sample_detector->setMaxVisibleItems(8);
        sample_detector->setInsertPolicy(QComboBox::InsertAtCurrent);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 51, 21));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"color: rgb(0, 0, 81);"));
        sample_extractor = new QComboBox(groupBox_4);
        sample_extractor->setObjectName(QStringLiteral("sample_extractor"));
        sample_extractor->setGeometry(QRect(60, 60, 71, 21));
        sample_extractor->setFont(font);
        sample_extractor->setAutoFillBackground(false);
        sample_extractor->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 220);"));
        sample_extractor->setMaxVisibleItems(8);
        sample_extractor->setInsertPolicy(QComboBox::InsertAtCurrent);
        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(140, 15, 206, 76));
        groupBox_3->setFont(font);
        groupBox_3->setAcceptDrops(false);
        groupBox_3->setToolTipDuration(-1);
        groupBox_3->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0.550773, y1:1, x2:0.551136, y2:0.023, stop:0 rgba(78, 114, 238, 150), stop:1 rgba(255, 255, 255, 255));"));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        button_select_in_path_2 = new QToolButton(groupBox_3);
        button_select_in_path_2->setObjectName(QStringLiteral("button_select_in_path_2"));
        button_select_in_path_2->setGeometry(QRect(90, 40, 41, 31));
        button_select_in_path_2->setAcceptDrops(false);
        button_select_in_path_2->setAutoFillBackground(false);
        button_select_in_path_2->setStyleSheet(QLatin1String("border-radius:5px;border-width:0px;\n"
"border-radius:5px;border-width:0px;\\nbackground-color: qlineargradient(spread:pad, x1:0.550773, y1:1, x2:0.551136, y2:0.023, stop:0 rgba(150, 180, 238, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        button_select_in_path_2->setInputMethodHints(Qt::ImhNone);
        QIcon icon;
        icon.addFile(QStringLiteral(":/BoVWTrainer/Resources/ooopic_1489847848.ico"), QSize(), QIcon::Normal, QIcon::Off);
        button_select_in_path_2->setIcon(icon);
        button_select_in_path_2->setIconSize(QSize(48, 48));
        button_select_in_path_2->setArrowType(Qt::NoArrow);
        load_dataset = new QLabel(groupBox_3);
        load_dataset->setObjectName(QStringLiteral("load_dataset"));
        load_dataset->setGeometry(QRect(15, 45, 86, 21));
        load_dataset->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"color: rgb(0, 0, 81);"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(15, 10, 71, 21));
        label_4->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"color: rgb(0, 0, 81);"));
        open_camera = new QComboBox(groupBox_3);
        open_camera->setObjectName(QStringLiteral("open_camera"));
        open_camera->setGeometry(QRect(90, 10, 111, 21));
        open_camera->setFont(font);
        open_camera->setAutoFillBackground(false);
        open_camera->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 220);"));
        open_camera->setEditable(false);
        open_camera->setMaxVisibleItems(8);
        open_camera->setInsertPolicy(QComboBox::InsertAtCurrent);
        sample_pause = new QToolButton(groupBox_4);
        sample_pause->setObjectName(QStringLiteral("sample_pause"));
        sample_pause->setGeometry(QRect(75, 100, 41, 41));
        sample_pause->setAcceptDrops(false);
        sample_pause->setAutoFillBackground(false);
        sample_pause->setStyleSheet(QLatin1String("border-radius:5px;border-width:0px;\n"
""));
        sample_pause->setInputMethodHints(Qt::ImhNone);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/BoVWTrainer/Resources/ooopic_1489847914.ico"), QSize(), QIcon::Normal, QIcon::Off);
        sample_pause->setIcon(icon1);
        sample_pause->setIconSize(QSize(48, 48));
        sample_run = new QToolButton(groupBox_4);
        sample_run->setObjectName(QStringLiteral("sample_run"));
        sample_run->setGeometry(QRect(20, 100, 41, 41));
        sample_run->setAcceptDrops(false);
        sample_run->setAutoFillBackground(false);
        sample_run->setStyleSheet(QLatin1String("border-radius:5px;border-width:0px;\n"
""));
        sample_run->setInputMethodHints(Qt::ImhNone);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/BoVWTrainer/Resources/ooopic_1489847909.ico"), QSize(), QIcon::Normal, QIcon::Off);
        sample_run->setIcon(icon2);
        sample_run->setIconSize(QSize(48, 48));
        sample_stop = new QToolButton(groupBox_4);
        sample_stop->setObjectName(QStringLiteral("sample_stop"));
        sample_stop->setGeometry(QRect(130, 100, 41, 41));
        sample_stop->setAcceptDrops(false);
        sample_stop->setAutoFillBackground(false);
        sample_stop->setStyleSheet(QLatin1String("border-radius:5px;border-width:0px;\n"
""));
        sample_stop->setInputMethodHints(Qt::ImhNone);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/BoVWTrainer/Resources/ooopic_1489847941.ico"), QSize(), QIcon::Normal, QIcon::Off);
        sample_stop->setIcon(icon3);
        sample_stop->setIconSize(QSize(48, 48));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 280, 296, 151));
        groupBox->setFont(font);
        groupBox->setAcceptDrops(false);
        groupBox->setToolTipDuration(-1);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.550773, y1:1, x2:0.551136, y2:0.023, stop:0 rgba(78, 114, 238, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 75 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 0, 81);"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(15, 30, 71, 21));
        label_6->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"color: rgb(0, 0, 81);"));
        trainbovw_feature = new QComboBox(groupBox);
        trainbovw_feature->setObjectName(QStringLiteral("trainbovw_feature"));
        trainbovw_feature->setGeometry(QRect(80, 30, 61, 21));
        trainbovw_feature->setFont(font);
        trainbovw_feature->setAutoFillBackground(false);
        trainbovw_feature->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 220);"));
        trainbovw_feature->setMaxVisibleItems(8);
        trainbovw_feature->setInsertPolicy(QComboBox::InsertAtCurrent);
        bovw_levels = new QSpinBox(groupBox);
        bovw_levels->setObjectName(QStringLiteral("bovw_levels"));
        bovw_levels->setGeometry(QRect(235, 25, 31, 21));
        bovw_levels->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 220);"));
        bovw_levels->setMinimum(4);
        bovw_levels->setMaximum(12);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(165, 25, 56, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font);
        label_7->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"color: rgb(0, 0, 79);"));
        bovw_branches = new QSpinBox(groupBox);
        bovw_branches->setObjectName(QStringLiteral("bovw_branches"));
        bovw_branches->setGeometry(QRect(235, 55, 31, 21));
        bovw_branches->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 220);"));
        bovw_branches->setMinimum(2);
        bovw_branches->setMaximum(10);
        bovw_branches->setValue(2);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(160, 55, 66, 21));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font);
        label_8->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"color: rgb(0, 0, 79);"));
        trainbovw_pause = new QToolButton(groupBox);
        trainbovw_pause->setObjectName(QStringLiteral("trainbovw_pause"));
        trainbovw_pause->setGeometry(QRect(75, 100, 41, 41));
        trainbovw_pause->setAcceptDrops(false);
        trainbovw_pause->setAutoFillBackground(false);
        trainbovw_pause->setStyleSheet(QLatin1String("border-radius:5px;border-width:0px;\n"
""));
        trainbovw_pause->setInputMethodHints(Qt::ImhNone);
        trainbovw_pause->setIcon(icon1);
        trainbovw_pause->setIconSize(QSize(48, 48));
        trainbovw_run = new QToolButton(groupBox);
        trainbovw_run->setObjectName(QStringLiteral("trainbovw_run"));
        trainbovw_run->setGeometry(QRect(20, 100, 41, 41));
        trainbovw_run->setAcceptDrops(false);
        trainbovw_run->setAutoFillBackground(false);
        trainbovw_run->setStyleSheet(QLatin1String("border-radius:5px;border-width:0px;\n"
""));
        trainbovw_run->setInputMethodHints(Qt::ImhNone);
        trainbovw_run->setIcon(icon2);
        trainbovw_run->setIconSize(QSize(48, 48));
        trainbovw_stop = new QToolButton(groupBox);
        trainbovw_stop->setObjectName(QStringLiteral("trainbovw_stop"));
        trainbovw_stop->setGeometry(QRect(130, 100, 41, 41));
        trainbovw_stop->setAcceptDrops(false);
        trainbovw_stop->setAutoFillBackground(false);
        trainbovw_stop->setStyleSheet(QLatin1String("border-radius:5px;border-width:0px;\n"
""));
        trainbovw_stop->setInputMethodHints(Qt::ImhNone);
        trainbovw_stop->setIcon(icon3);
        trainbovw_stop->setIconSize(QSize(48, 48));
        BoVWTrainerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BoVWTrainerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 23));
        menuBar->setStyleSheet(QStringLiteral("background-color: rgb(200, 220, 255);"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        BoVWTrainerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BoVWTrainerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BoVWTrainerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BoVWTrainerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BoVWTrainerClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionHelp);
        menu->addAction(actionExit);

        retranslateUi(BoVWTrainerClass);
        QObject::connect(sample_detector, SIGNAL(currentTextChanged(QString)), BoVWTrainerClass, SLOT(setFeatureType()));
        QObject::connect(sample_extractor, SIGNAL(currentIndexChanged(QString)), BoVWTrainerClass, SLOT(setFeatureType()));
        QObject::connect(open_camera, SIGNAL(currentTextChanged(QString)), BoVWTrainerClass, SLOT(setCamera()));
        QObject::connect(button_select_in_path_2, SIGNAL(released()), BoVWTrainerClass, SLOT(selectDatasetPath()));
        QObject::connect(sample_run, SIGNAL(released()), BoVWTrainerClass, SLOT(runSampling()));
        QObject::connect(sample_pause, SIGNAL(released()), BoVWTrainerClass, SLOT(pauseSampling()));
        QObject::connect(sample_stop, SIGNAL(released()), BoVWTrainerClass, SLOT(stopSampling()));
        QObject::connect(trainbovw_feature, SIGNAL(currentIndexChanged(QString)), BoVWTrainerClass, SLOT(setBoVWFeatureType()));
        QObject::connect(bovw_levels, SIGNAL(valueChanged(int)), BoVWTrainerClass, SLOT(setBoVWlevels()));
        QObject::connect(bovw_branches, SIGNAL(valueChanged(int)), BoVWTrainerClass, SLOT(setBoVWbranches()));
        QObject::connect(trainbovw_run, SIGNAL(released()), BoVWTrainerClass, SLOT(runBoVWtrain()));
        QObject::connect(trainbovw_pause, SIGNAL(released()), BoVWTrainerClass, SLOT(pauseBoVWtrain()));
        QObject::connect(trainbovw_stop, SIGNAL(released()), BoVWTrainerClass, SLOT(stopBoVWtrain()));
        QObject::connect(open_camera, SIGNAL(highlighted(QString)), BoVWTrainerClass, SLOT(updateCameraInfo()));
        QObject::connect(actionHelp, SIGNAL(triggered()), BoVWTrainerClass, SLOT(openHelp()));
        QObject::connect(actionExit, SIGNAL(triggered()), BoVWTrainerClass, SLOT(close()));

        QMetaObject::connectSlotsByName(BoVWTrainerClass);
    } // setupUi

    void retranslateUi(QMainWindow *BoVWTrainerClass)
    {
        BoVWTrainerClass->setWindowTitle(QApplication::translate("BoVWTrainerClass", "BoVWTrainer", 0));
        actionHelp->setText(QApplication::translate("BoVWTrainerClass", "Help", 0));
        actionExit->setText(QApplication::translate("BoVWTrainerClass", "Exit", 0));
        show_im_feature->setText(QApplication::translate("BoVWTrainerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        text_showfile->setHtml(QApplication::translate("BoVWTrainerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        text_showfile->setPlaceholderText(QString());
        groupBox_4->setTitle(QApplication::translate("BoVWTrainerClass", "\347\211\271\345\276\201\351\207\207\346\240\267", 0));
        label_2->setText(QApplication::translate("BoVWTrainerClass", "<html><head/><body><p><span style=\" font-weight:400;\">\346\243\200\346\265\213\345\231\250</span></p></body></html>", 0));
        sample_detector->clear();
        sample_detector->insertItems(0, QStringList()
         << QApplication::translate("BoVWTrainerClass", "SURF", 0)
         << QApplication::translate("BoVWTrainerClass", "SIFT", 0)
         << QApplication::translate("BoVWTrainerClass", "ORB", 0)
         << QApplication::translate("BoVWTrainerClass", "BRISK", 0)
         << QApplication::translate("BoVWTrainerClass", "FAST", 0)
         << QApplication::translate("BoVWTrainerClass", "GFTT", 0)
         << QApplication::translate("BoVWTrainerClass", "MSER", 0)
         << QApplication::translate("BoVWTrainerClass", "STAR", 0)
         << QApplication::translate("BoVWTrainerClass", "HARRIS", 0)
        );
        label_3->setText(QApplication::translate("BoVWTrainerClass", "<html><head/><body><p><span style=\" font-weight:400;\">\346\217\217\350\277\260\345\255\220</span></p></body></html>", 0));
        sample_extractor->clear();
        sample_extractor->insertItems(0, QStringList()
         << QApplication::translate("BoVWTrainerClass", "SURF", 0)
         << QApplication::translate("BoVWTrainerClass", "SIFT", 0)
         << QApplication::translate("BoVWTrainerClass", "ORB", 0)
         << QApplication::translate("BoVWTrainerClass", "BRISK", 0)
         << QApplication::translate("BoVWTrainerClass", "BRIEF", 0)
         << QApplication::translate("BoVWTrainerClass", "FREAK", 0)
        );
        groupBox_3->setTitle(QString());
        button_select_in_path_2->setText(QString());
        load_dataset->setText(QApplication::translate("BoVWTrainerClass", "<html><head/><body><p>\350\257\273\345\217\226\346\225\260\346\215\256\351\233\206</p></body></html>", 0));
        label_4->setText(QApplication::translate("BoVWTrainerClass", "<html><head/><body><p>\345\220\257\347\224\250\346\221\204\345\203\217\345\244\264</p></body></html>", 0));
        open_camera->clear();
        open_camera->insertItems(0, QStringList()
         << QApplication::translate("BoVWTrainerClass", "\344\270\215\345\274\200\345\220\257", 0)
        );
        sample_pause->setText(QString());
        sample_run->setText(QString());
        sample_stop->setText(QApplication::translate("BoVWTrainerClass", "\345\201\234\346\255\242", 0));
        groupBox->setTitle(QApplication::translate("BoVWTrainerClass", "BoVW\350\256\255\347\273\203", 0));
        label_6->setText(QApplication::translate("BoVWTrainerClass", "<html><head/><body><p>\347\211\271\345\276\201\347\261\273\345\236\213</p></body></html>", 0));
        trainbovw_feature->clear();
        trainbovw_feature->insertItems(0, QStringList()
         << QApplication::translate("BoVWTrainerClass", "SURF", 0)
         << QApplication::translate("BoVWTrainerClass", "SIFT", 0)
         << QApplication::translate("BoVWTrainerClass", "ORB", 0)
         << QApplication::translate("BoVWTrainerClass", "BRISK", 0)
         << QApplication::translate("BoVWTrainerClass", "BRIEF  \345\273\272\350\256\256\347\224\250SURF/SIFT\347\211\271\345\276\201", 0)
         << QApplication::translate("BoVWTrainerClass", "FREAK  \345\273\272\350\256\256\347\224\250SURF/SIFT\347\211\271\345\276\201", 0)
        );
        label_7->setText(QApplication::translate("BoVWTrainerClass", "BoVW\345\261\202\346\225\260", 0));
        label_8->setText(QApplication::translate("BoVWTrainerClass", "\346\257\217\345\261\202\345\210\206\346\224\257\346\225\260", 0));
        trainbovw_pause->setText(QString());
        trainbovw_run->setText(QString());
        trainbovw_stop->setText(QApplication::translate("BoVWTrainerClass", "\345\201\234\346\255\242", 0));
        menu->setTitle(QApplication::translate("BoVWTrainerClass", "\350\217\234\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class BoVWTrainerClass: public Ui_BoVWTrainerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOVWTRAINER_H
