#include "timerApp.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QInputDialog>
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

    history_el = createHistoryWrapper(this);
    if (results.size() == 0) {
        history_el->hide();
    }
    historyLayout->addStretch();
    historyLayout->addWidget(history_el);
    historyLayout->addStretch();

    mainLayout->addLayout(buttonsLayout);
    mainLayout->addLayout(historyLayout);
    mainLayout->addStretch();

    // Кнопки управлениея таймером
    playButton = buttons_el->findChild<QPushButton*>("play_button");
    pauseButton = buttons_el->findChild<QPushButton*>("pause_button");
    clearButton = buttons_el->findChild<QPushButton*>("clear_button");
    saveButton = buttons_el->findChild<QPushButton*>("save_button");

    // Кнопки управлениея историей
    clearHistoryButton = history_el->findChild<QPushButton*>("cleanUpButtons");

    if (clearHistoryButton) {
        connect(clearHistoryButton, &QPushButton::clicked, this, &TimerApp::clearHistory);
    } else {
        qDebug() << "Ошибка: Не удалось получить указатель на кнопку clearHistoryButton";
    }

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

    TimerResult result = {"Результат: "};
    results.push_back(result);

    timer->stop();
    seconds = 0;
    *timerStatus = "stop";
    updateDisplay();
    playButton->show();
    pauseButton->hide();

    // Создаем новый элемент и добавляем его в макет истории
    QString titleText = QString::fromStdString(result.title);
    QString resultText = QString::number(hrs) + " ч " + QString::number(mins) + " мин " + QString::number(secs) + " сек";
    QFrame* resultFrame = files(titleText, resultText);

    // Подключаем сигналы кнопок к слотам
    QPushButton* editButton = resultFrame->findChild<QPushButton*>("edit_buttons");
    if (editButton) {
        connect(editButton, &QPushButton::clicked, this, &TimerApp::editHistoryItem);
    } else {
        qDebug() << "Ошибка: Не удалось получить указатель на кнопку редактирования";
    }

    QPushButton* deleteButton = resultFrame->findChild<QPushButton*>("delete_buttons");
    if (deleteButton) {
        connect(deleteButton, &QPushButton::clicked, this, &TimerApp::deleteHistoryItem);
    } else {
        qDebug() << "Ошибка: Не удалось получить указатель на кнопку удаления";
    }

    historyLayout->insertWidget(historyLayout->count(), resultFrame);
    historyFrames.push_back(resultFrame);

    history_el->show();
}

void TimerApp::filterHistory(const QString& searchText) {
    for (QFrame* frame : historyFrames) {
        QLabel* title = frame->findChild<QLabel*>();
        if (title && title->text().contains(searchText, Qt::CaseInsensitive)) {
            frame->show();
        } else {
            frame->hide();
        }
    }
}

void TimerApp::clearHistory() {
    QLayoutItem* item;
    while ((item = historyLayout->takeAt(0))) {
        QWidget* widget = item->widget();
        if (widget) {
            widget->deleteLater();
        }
        delete item;
    }

    results.clear();
    historyFrames.clear();
}

void TimerApp::editHistoryItem() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QFrame* frame = qobject_cast<QFrame*>(button->parent()->parent());
        if (frame) {
            QLabel* label = frame->findChild<QLabel*>("title_label");
            if (label) {
                bool ok;
                QString text = QInputDialog::getText(this, tr("Редактирование элемента"),
                                                     tr("Измените результат:"), QLineEdit::Normal,
                                                     label->text(), &ok);
                if (ok && !text.isEmpty()) {
                    label->setText(text);
                }
            }
        }
    }
}

void TimerApp::deleteHistoryItem() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QFrame* frame = qobject_cast<QFrame*>(button->parent()->parent());
        if (frame) {
            historyLayout->removeWidget(frame);
            historyFrames.erase(std::remove(historyFrames.begin(), historyFrames.end(), frame), historyFrames.end());
            frame->deleteLater();
        }
    }
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