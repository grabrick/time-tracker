#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>

#include "GUI/timeBlock/timeBlock.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    // Вертикали
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *timeLayout = new QHBoxLayout;

    QWidget window;
    window.setWindowTitle("Time Tracker");
    window.setStyleSheet("QWidget { background-color: #131619 }");
    window.setFixedSize(600, 400);

    QLabel* title = new QLabel("Time Tracker");
    title->setStyleSheet("QLabel { font-family: Arial; font-size: 25pt; }");
    title->setAlignment(Qt::AlignCenter);



    // Создаем три блока
    QFrame* hourBlock = createBlock("0H");
    QFrame* minuteBlock = createBlock("0M");
    QFrame* secondBlock = createBlock("0S");


    // Компоновка для фрейма
    hLayout->addStretch();
    hLayout->addWidget(title);
    hLayout->addStretch();

    // Компоновка для основного окна
    mainLayout->addLayout(hLayout);

    timeLayout->addStretch();
    timeLayout->addWidget(hourBlock);
    timeLayout->addWidget(minuteBlock);
    timeLayout->addWidget(secondBlock);
    timeLayout->addStretch();

//    mainLayout->addStretch();
    mainLayout->addLayout(timeLayout);
    mainLayout->addStretch();

    window.setLayout(mainLayout);

    window.show();
    return app.exec();
}