#include <QLabel>
#include <QVBoxLayout>
#include "files.hpp"

QFrame* files(const QString &text) {
    QFrame* global_frame = new QFrame();
    QVBoxLayout* globalLayout = new QVBoxLayout(global_frame);
    global_frame->setFrameShape(QFrame::StyledPanel);
    global_frame->setFixedSize(500, 80);
    global_frame->setStyleSheet("QFrame { border: 2px solid green }");

    QLabel* label = new QLabel(text);

    globalLayout->addStretch();
    globalLayout->addWidget(label);
    globalLayout->addStretch();

//    frame->setStyleSheet("QFrame { background-color: #1D2227; border-radius: 20px; }");

    return global_frame;
}