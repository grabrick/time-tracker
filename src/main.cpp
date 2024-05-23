#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>

#include "GUI/timeBlock/timeBlock.hpp"
#include "GUI/buttonsBlock/buttonsBlock.hpp"
#include "GUI/historyBlock/historyBlock.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Вертикали
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *timeLayout = new QHBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QHBoxLayout *historyLayout = new QHBoxLayout;

    QWidget window;
    window.setWindowTitle("Time Tracker");
    window.setStyleSheet("QWidget { background-color: #131619 }");
    window.setFixedSize(600, 600);

//    QLabel* title = new QLabel("Time Tracker");
//    title->setStyleSheet("QLabel { font-family: Arial; font-size: 25pt; }");
//    title->setAlignment(Qt::AlignCenter);

    // Компоновка для Title
//    hLayout->addStretch();
//    hLayout->addWidget(title);
//    hLayout->addStretch();


    // Создаем три блока
    QFrame* hourBlock = createBlock("Час", "0");
    QFrame* minuteBlock = createBlock("Минута", "0");
    QFrame* secondBlock = createBlock("Секунда", "0");

    // Компоновка для основного окна
    mainLayout->addLayout(hLayout);
    timeLayout->addStretch();
    timeLayout->addWidget(hourBlock);
    timeLayout->addWidget(minuteBlock);
    timeLayout->addWidget(secondBlock);
    timeLayout->addStretch();

    mainLayout->addLayout(timeLayout);


    QFrame* buttons_el = createButtonsWrapper();

    buttonsLayout->addStretch();
    buttonsLayout->addWidget(buttons_el);
    buttonsLayout->addStretch();

    mainLayout->addLayout(buttonsLayout);
//    mainLayout->addStretch();



    QFrame* history_el = createHistoryWrapper();

    historyLayout->addStretch();
    historyLayout->addWidget(history_el);
    historyLayout->addStretch();

    mainLayout->addLayout(historyLayout);
    mainLayout->addStretch();


    window.setLayout(mainLayout);
    window.show();
    return app.exec();
}