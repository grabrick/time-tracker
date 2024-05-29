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

    void clearHistory();

public slots:
    void filterHistory(const QString& searchText);

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
    QPushButton* clearHistoryButton;

    QVBoxLayout* historyLayout;
    QFrame* history_el;
    std::vector<QFrame*> historyFrames;
};

#endif //TIMER_TIMERAPP_HPP
