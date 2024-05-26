#include "timerApp.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <iostream>

#include "../GUI/timeBlock/timeBlock.hpp"
#include "../GUI/buttonsBlock/buttonsBlock.hpp"
#include "../GUI/historyBlock/historyBlock.hpp"
#include "../GUI//historyBlock/files/files.hpp"

using namespace std;

TimerApp::TimerApp(QWidget* parent) : QWidget(parent), seconds(0), timerStatus(new std::string("stop")) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* timeLayout = new QHBoxLayout();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    QHBoxLayout* historyLayout = new QHBoxLayout();

    hourBlock = createBlock("Час", "0");
    minuteBlock = createBlock("Минута", "0");
    secondBlock = createBlock("Секунда", "0");

    mainLayout->addLayout(timeLayout);
    timeLayout->addStretch();
    timeLayout->addWidget(hourBlock);
    timeLayout->addWidget(minuteBlock);
    timeLayout->addWidget(secondBlock);
    timeLayout->addStretch();

    QFrame* buttons_el = createButtonsWrapper();

    buttonsLayout->addStretch();
    buttonsLayout->addWidget(buttons_el);
    buttonsLayout->addStretch();

    QFrame* history_el = createHistoryWrapper(this);

    historyLayout->addStretch();
    historyLayout->addWidget(history_el);
    historyLayout->addStretch();

    mainLayout->addLayout(buttonsLayout);
    mainLayout->addLayout(historyLayout);
    mainLayout->addStretch();

    playButton = buttons_el->findChild<QPushButton*>("play_button");
    pauseButton = buttons_el->findChild<QPushButton*>("pause_button");
    clearButton = buttons_el->findChild<QPushButton*>("clear_button");
    saveButton = buttons_el->findChild<QPushButton*>("save_button");

    if (playButton && pauseButton && clearButton && saveButton) {
        connect(playButton, &QPushButton::clicked, this, &TimerApp::startTimer);
        connect(pauseButton, &QPushButton::clicked, this, &TimerApp::pauseTimer);
        connect(clearButton, &QPushButton::clicked, this, &TimerApp::resetTimer);
        connect(saveButton, &QPushButton::clicked, this, &TimerApp::saveResult);

        pauseButton->hide();
    } else {
        qDebug() << "Ошибка: Не удалось получить указатель на одну из кнопок";
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimerApp::updateTime);
}

void TimerApp::startTimer() {
    *timerStatus = "run";
    timer->start(1000);

    playButton->hide();
    pauseButton->show();
}

void TimerApp::pauseTimer() {
    *timerStatus = "pause";
    timer->stop();

    playButton->show();
    pauseButton->hide();
}

void TimerApp::resetTimer() {
    *timerStatus = "stop";
    timer->stop();
    seconds = 0;
    updateDisplay();

    playButton->show();
    pauseButton->hide();
}

void TimerApp::saveResult() {
    int hrs = seconds / 3600;
    int mins = (seconds % 3600) / 60;
    int secs = seconds % 60;

    TimerResult result = {"Результат " + std::to_string(results.size() + 1), hrs, mins, secs};
    results.push_back(result);

    qDebug() << "Количество сохраненных элементов: " << results.size();

    timer->stop();
    seconds = 0;
    *timerStatus = "stop";
    updateDisplay();
    playButton->show();
    pauseButton->hide();

    // Создаем новый элемент и добавляем его в макет истории
    QString resultText = QString::fromStdString(result.title) + ": " + QString::number(result.hours) + " ч " + QString::number(result.minutes) + " мин " + QString::number(result.seconds) + " сек";
    QFrame* resultFrame = files(resultText);
    historyLayout->insertWidget(historyLayout->count() - 1, resultFrame);
}

void TimerApp::updateTime() {
    ++seconds;
    updateDisplay();
}

void TimerApp::updateDisplay() {
    int hrs = seconds / 3600;
    int mins = (seconds % 3600) / 60;
    int secs = seconds % 60;

    hourBlock->findChild<QLabel*>()->setText(QString::number(hrs));
    minuteBlock->findChild<QLabel*>()->setText(QString::number(mins));
    secondBlock->findChild<QLabel*>()->setText(QString::number(secs));
}
