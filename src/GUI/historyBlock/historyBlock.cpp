#include "historyBlock.hpp"
#include "files/files.hpp"

#include <QFrame>
#include <QVBoxLayout>

QFrame* createHistoryWrapper() {
    QFrame* global_frame = new QFrame();
    QVBoxLayout* globalLayout = new QVBoxLayout(global_frame);

    global_frame->setFrameShape(QFrame::StyledPanel);
    global_frame->setMinimumSize(500, 80);
    global_frame->setStyleSheet("QFrame { border: 2px solid green }");
//    frame->setStyleSheet("QFrame { background-color: #1D2227; border-radius: 20px; }");


    QFrame* file1 = files("1");
//    QFrame* file2 = files("2");
//    QFrame* file3 = files("3");
//    QFrame* file4 = files("4");
    globalLayout->setAlignment(Qt::AlignTop);

//    globalLayout->addStretch();
    globalLayout->addWidget(file1);
//    globalLayout->addWidget(file2);
//    globalLayout->addWidget(file3);
//    globalLayout->addWidget(file4);
    globalLayout->addStretch();


    return global_frame;
}