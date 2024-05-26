#include "historyBlock.hpp"

#include <QFrame>
#include <QVBoxLayout>

QFrame* createHistoryWrapper(TimerApp* TimerApp) {
    QFrame* global_frame = new QFrame();
    QVBoxLayout* globalLayout = new QVBoxLayout(global_frame);

    global_frame->setFrameShape(QFrame::StyledPanel);
    global_frame->setFixedWidth(500);
    global_frame->setMinimumHeight(80);
    global_frame->setStyleSheet("QFrame { background-color: #1D2227; border-radius: 20px; }");

    // Сохраняем указатель на глобальный макет в TimerApp для добавления новых элементов
    TimerApp->setHistoryLayout(globalLayout);

    globalLayout->setAlignment(Qt::AlignTop);
    globalLayout->addStretch();

    return global_frame;
}