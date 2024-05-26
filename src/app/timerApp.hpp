#ifndef TIMER_TIMERAPP_HPP
#define TIMER_TIMERAPP_HPP

#include <QWidget>
#include <QFrame>
#include <QTimer>
#include <iostream>
#include <string>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>

using std::string;

struct TimerResult {
    std::string title;
    int hours;
    int minutes;
    int seconds;
};

class TimerApp : public QWidget {
    Q_OBJECT

public:
    TimerApp(QWidget* parent = nullptr);

    void setHistoryLayout(QVBoxLayout* layout) {
        historyLayout = layout;
    }

private slots:
    void startTimer();
    void pauseTimer();
    void resetTimer();
    void updateTime();
    void saveResult();

private:
    void updateDisplay();

    QTimer* timer;
    int seconds;
    std::string* timerStatus;
    std::vector<TimerResult> results;

    QFrame* hourBlock;
    QFrame* minuteBlock;
    QFrame* secondBlock;
    QPushButton* playButton;
    QPushButton* pauseButton;
    QPushButton* clearButton;
    QPushButton* saveButton;
    QVBoxLayout* historyLayout;
};

#endif //TIMER_TIMERAPP_HPP
