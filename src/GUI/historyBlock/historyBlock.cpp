#include "historyBlock.hpp"

QFrame* createHistoryWrapper() {
    QFrame* global_frame = new QFrame();
    QFrame* frame = new QFrame();

    frame->setFrameShape(QFrame::StyledPanel);
    frame->setMinimumSize(500, 220);
//    frame->setStyleSheet("QFrame { border: 2px solid green }");
    frame->setStyleSheet("QFrame { background-color: #1D2227; border-radius: 20px; }");

    return frame;
}