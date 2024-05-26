#include <QLabel>
#include <QVBoxLayout>
#include "files.hpp"

QFrame* files(const QString &text) {
    QFrame* global_frame = new QFrame();
    QVBoxLayout* globalLayout = new QVBoxLayout(global_frame);
    global_frame->setFrameShape(QFrame::StyledPanel);
    global_frame->setFixedSize(477, 50);
    global_frame->setStyleSheet("QFrame { background-color: #323941; border-radius: 15px; }");

    QLabel* label = new QLabel(text);
    label->setStyleSheet("QLabel { color: white; }");

    globalLayout->addStretch();
    globalLayout->addWidget(label);
    globalLayout->addStretch();

    return global_frame;
}