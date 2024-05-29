#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "files.hpp"

QFrame* files(const QString &text) {
    QFrame* global_frame = new QFrame();
    QFrame* button_frame = new QFrame(global_frame);
    QHBoxLayout* globalLayout = new QHBoxLayout(global_frame);
    QHBoxLayout* buttonWrapperLayout = new QHBoxLayout(button_frame);

    QPixmap edit_pixmap = QPixmap(":/icons/pencil.png");
    QPixmap delete_pixmap = QPixmap(":/icons/trash-can.png");
    QIcon edit_icon(edit_pixmap);
    QIcon delete_icon(delete_pixmap);

    QPushButton* edit_buttons = new QPushButton();
    edit_buttons->setObjectName("edit_buttons");
    edit_buttons->setIcon(edit_icon);
    edit_buttons->setIconSize(QSize(24, 24));
    edit_buttons->setFixedSize(40, 40);
    edit_buttons->setCursor(Qt::PointingHandCursor);
    edit_buttons->setStyleSheet(" #edit_buttons {"
                                    "background-color: #525F6B;"
                                    "border: none;"
                                    "border-radius: 15px;"
                                "}"
    );

    QPushButton* delete_buttons = new QPushButton();
    delete_buttons->setObjectName("delete_buttons");
    delete_buttons->setIcon(delete_icon);
    delete_buttons->setIconSize(QSize(24, 24));
    delete_buttons->setFixedSize(40, 40);
    delete_buttons->setCursor(Qt::PointingHandCursor);
    delete_buttons->setStyleSheet(" #delete_buttons {"
                                    "background-color: #525F6B;"
                                    "border: none;"
                                    "border-radius: 15px"
                                "}"
    );

    buttonWrapperLayout->addStretch();
    buttonWrapperLayout->setAlignment(Qt::AlignHCenter);
    buttonWrapperLayout->addWidget(edit_buttons);
    buttonWrapperLayout->setSpacing(10);
    buttonWrapperLayout->addWidget(delete_buttons);
    buttonWrapperLayout->setContentsMargins(0, 0, 0, 0);
    buttonWrapperLayout->addStretch();

    global_frame->setFrameShape(QFrame::StyledPanel);
    global_frame->setFixedSize(477, 50);
    global_frame->setStyleSheet(" QFrame { background-color: #323941; border-radius: 15px; } ");

    QLabel* label = new QLabel(text);
    label->setStyleSheet("QLabel { color: white; }");

    globalLayout->addStretch();
    globalLayout->addWidget(label);
    globalLayout->setSpacing(180);
    globalLayout->addWidget(button_frame);
    globalLayout->setContentsMargins(20, 0, 0, 0);
    globalLayout->addStretch();

    return global_frame;
}