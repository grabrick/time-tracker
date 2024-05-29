//#include "historyBlock.hpp"
//
//#include <QFrame>
//#include <QVBoxLayout>
//#include <QScrollArea>
//#include <QLineEdit>
//#include <QIcon>
//#include <QGraphicsDropShadowEffect>
//#include <QLabel>
//#include <QPushButton>
//
//QFrame* createHistoryWrapper(TimerApp* TimerApp) {
//    QFrame* global_frame = new QFrame();
//    QFrame* header_frame = new QFrame(global_frame);
//    QPushButton* cleanup_button = new QPushButton();
//
//    // Новый контейнер для поиска
//    QFrame* search_container = new QFrame();
//    QHBoxLayout* search_layout = new QHBoxLayout(search_container);
//    QLabel* search_icon = new QLabel();
//    QLineEdit* search_input = new QLineEdit();
//
//    QVBoxLayout* globalLayout = new QVBoxLayout(global_frame);
//    QHBoxLayout* headerLayout = new QHBoxLayout(header_frame);
//
//    global_frame->setFrameShape(QFrame::StyledPanel);
//    global_frame->setFixedSize(500, 390);
//    global_frame->setObjectName("globalFrame");
//    global_frame->setStyleSheet("#globalFrame { background-color: #1D2227; padding-top: 50px; border-radius: 20px; }");
//
//    header_frame->setFrameShape(QFrame::StyledPanel);
//    header_frame->setFixedSize(500, 50);
//    header_frame->setObjectName("headerFrame");
//    header_frame->setStyleSheet("#headerFrame { background-color: #39424A; border-top-left-radius: 20px; border-top-right-radius: 20px; }");
//
//    search_icon->setPixmap(QPixmap(":/icons/search-lg.png"));
//    search_icon->setFixedSize(24, 24);
//    search_icon->setStyleSheet("QLabel { background-color: transparent; }");
//    search_icon->setAlignment(Qt::AlignCenter);
//
//    search_container->setObjectName("searchInput");
//    search_container->setFixedSize(270, 40);
//    search_input->setPlaceholderText("Поиск...");
//    search_input->setStyleSheet("QLineEdit { background-color: transparent; border: none; }");
//    search_container->setStyleSheet("#searchInput { "
//                                        "background-color: #1D2227; "
//                                        "border: none; "
//                                        "border-radius: 15px; "
//                                        "color: white;"
//                                        "padding: 0 10px;"
//                                    "}"
//    );
//
//    search_layout->setContentsMargins(0, 0, 0, 0);
//    search_layout->addWidget(search_icon);
//    search_layout->setSpacing(10);
//    search_layout->addWidget(search_input);
//
//    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
//    shadowEffect->setBlurRadius(20);
//    shadowEffect->setXOffset(0);
//    shadowEffect->setYOffset(4);
//    shadowEffect->setColor(QColor(29, 34, 39, 160));
//    search_container->setGraphicsEffect(shadowEffect);
//
//    cleanup_button->setFixedSize(120, 40);
//    cleanup_button->setObjectName("cleanUpButtons");
//    cleanup_button->setStyleSheet("#cleanUpButtons {"
//                                    "background-color: #1D2227;"
//                                    "font-size: 14px; "
//                                    "color: white; "
//                                    "border-radius: 15px;"
//                                  "}"
//                                  "#cleanUpButtons:hover {"
//                                    "background-color: #5E6975;"
//                                  "}"
//    );
//    cleanup_button->setCursor(Qt::PointingHandCursor);
//    cleanup_button->setText("Очистить");
//
//    QGraphicsDropShadowEffect* buttonShadowEffect = new QGraphicsDropShadowEffect;
//    buttonShadowEffect->setBlurRadius(20);
//    buttonShadowEffect->setXOffset(0);
//    buttonShadowEffect->setYOffset(4);
//    buttonShadowEffect->setColor(QColor(29, 34, 39, 160));
//    cleanup_button->setGraphicsEffect(buttonShadowEffect);
//
//    headerLayout->addStretch();
//    headerLayout->addWidget(search_container);
//    headerLayout->setSpacing(100);
//    headerLayout->addWidget(cleanup_button);
//    headerLayout->setContentsMargins(0, 0, 0, 0);
//    headerLayout->addStretch();
//
//    // Сохраняем указатель на глобальный макет в TimerApp для добавления новых элементов
//    TimerApp->setHistoryLayout(globalLayout);
//
//    // Подключаем поле ввода поиска к слоту фильтрации
//    QObject::connect(search_input, &QLineEdit::textChanged, TimerApp, &TimerApp::filterHistory);
//
//    globalLayout->setAlignment(Qt::AlignTop);
//    globalLayout->addStretch();
//
//    return global_frame;
//}

#include "historyBlock.hpp"

#include <QFrame>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLineEdit>
#include <QIcon>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QPushButton>

QFrame* createHistoryWrapper(TimerApp* TimerApp) {
    QFrame* global_frame = new QFrame();
    QScrollArea* scrollArea = new QScrollArea();
    QFrame* header_frame = new QFrame(scrollArea);

    QPushButton* cleanup_button = new QPushButton();

    // Контейнер для поиска
    QFrame* search_container = new QFrame();
    QHBoxLayout* search_layout = new QHBoxLayout(search_container);
    QLabel* search_icon = new QLabel();
    QLineEdit* search_input = new QLineEdit();

    QVBoxLayout* globalLayout = new QVBoxLayout(global_frame);
    QHBoxLayout* headerLayout = new QHBoxLayout(header_frame);

    QWidget* scrollWidget = new QWidget();
    scrollWidget->setObjectName("scrollWidget");
    scrollWidget->setStyleSheet("#scrollWidget { background-color: transparent; }");
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollWidget);
    scrollWidget->setLayout(scrollLayout);


    scrollArea->setWidget(scrollWidget);

    scrollArea->setFrameShape(QFrame::StyledPanel);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setFixedSize(500, 390);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setStyleSheet("#scrollArea { background-color: #1D2227; padding-top: 50px; border-radius: 20px; }");

    header_frame->setFrameShape(QFrame::StyledPanel);
    header_frame->setFixedSize(500, 50);
    header_frame->setObjectName("headerFrame");
    header_frame->setStyleSheet("#headerFrame { background-color: #39424A; border-top-left-radius: 20px; border-top-right-radius: 20px; }");

    search_icon->setPixmap(QPixmap(":/icons/search-lg.png"));
    search_icon->setFixedSize(24, 24);
    search_icon->setStyleSheet("QLabel { background-color: transparent; }");
    search_icon->setAlignment(Qt::AlignCenter);

    search_container->setObjectName("searchInput");
    search_container->setFixedSize(270, 40);
    search_input->setPlaceholderText("Поиск...");
    search_input->setStyleSheet("QLineEdit { background-color: transparent; border: none; }");
    search_container->setStyleSheet("#searchInput { "
                                    "background-color: #1D2227; "
                                    "border: none; "
                                    "border-radius: 15px; "
                                    "color: white;"
                                    "padding: 0 10px;"
                                    "}"
    );

    search_layout->setContentsMargins(0, 0, 0, 0);
    search_layout->addWidget(search_icon);
    search_layout->setSpacing(10);
    search_layout->addWidget(search_input);

    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(20);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(4);
    shadowEffect->setColor(QColor(29, 34, 39, 160));
    search_container->setGraphicsEffect(shadowEffect);

    cleanup_button->setFixedSize(120, 40);
    cleanup_button->setObjectName("cleanUpButtons");
    cleanup_button->setStyleSheet("#cleanUpButtons {"
                                  "background-color: #1D2227;"
                                  "font-size: 14px; "
                                  "color: white; "
                                  "border-radius: 15px;"
                                  "}"
                                  "#cleanUpButtons:hover {"
                                  "background-color: #5E6975;"
                                  "}"
    );
    cleanup_button->setCursor(Qt::PointingHandCursor);
    cleanup_button->setText("Очистить");

    QGraphicsDropShadowEffect* buttonShadowEffect = new QGraphicsDropShadowEffect;
    buttonShadowEffect->setBlurRadius(20);
    buttonShadowEffect->setXOffset(0);
    buttonShadowEffect->setYOffset(4);
    buttonShadowEffect->setColor(QColor(29, 34, 39, 160));
    cleanup_button->setGraphicsEffect(buttonShadowEffect);

    headerLayout->addStretch();
    headerLayout->addWidget(search_container);
    headerLayout->setSpacing(100);
    headerLayout->addWidget(cleanup_button);
    headerLayout->setContentsMargins(0, 0, 0, 0);
    headerLayout->addStretch();

    scrollLayout->setAlignment(Qt::AlignTop);

    // Сохраняем указатель на глобальный макет в TimerApp для добавления новых элементов
    TimerApp->setHistoryLayout(scrollLayout);

    QObject::connect(search_input, &QLineEdit::textChanged, TimerApp, &TimerApp::filterHistory);

    globalLayout->setAlignment(Qt::AlignTop);
//    globalLayout->addWidget(header_frame);
    globalLayout->addWidget(scrollArea);
    globalLayout->addStretch();

    return scrollArea;
}