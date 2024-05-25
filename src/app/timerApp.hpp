#ifndef TIMER_TIMERAPP_HPP
#define TIMER_TIMERAPP_HPP

#include <QWidget>
#include <QFrame>
#include <QTimer>
#include <iostream>
#include <string>
#include <QPushButton>

using std::string;

class TimerApp : public QWidget {
    Q_OBJECT

public:
    TimerApp(QWidget* parent = nullptr);

private slots:
    void startTimer();
    void pauseTimer();
    void resetTimer();
    void saveResult();
    void updateTime();
    void updateDisplay();

private:
    QFrame* hourBlock;
    QFrame* minuteBlock;
    QFrame* secondBlock;
    QTimer* timer;
    int seconds;

    string* timerStatus;

    QPushButton* playButton;
    QPushButton* pauseButton;
    QPushButton* clearButton;
    QPushButton* saveButton;
};

#endif //TIMER_TIMERAPP_HPP
