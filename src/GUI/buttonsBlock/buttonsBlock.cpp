#include "buttonsBlock.hpp"
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QFile>
#include <QDir>
#include <QGraphicsDropShadowEffect>

#include "./buttons/buttons.hpp"

QFrame* createButtonsWrapper() {
    QFrame* frame = new QFrame();

    QPixmap play_pixmap = QPixmap("icons/play-circle.png");
    QPixmap pause_pixmap = QPixmap("icons/pause-circle.png");
    QPixmap save_pixmap = QPixmap("icons/save-circle.png");
    QPixmap clear_pixmap = QPixmap("icons/x-circle.png");

    QIcon play_icon(play_pixmap);
    QIcon pause_icon(pause_pixmap);
    QIcon clear_icon(clear_pixmap);
    QIcon save_icon(save_pixmap);

    frame->setFrameShape(QFrame::StyledPanel);
    frame->setMaximumSize(220, 80);
    frame->setStyleSheet("QFrame { background-color: #323941; border-radius: 20px; }");

    QPushButton* play_button = createButton(frame, play_icon);
    play_button->setObjectName("play_button");

    QPushButton* pause_button = createButton(frame, pause_icon);
    pause_button->setObjectName("pause_button");

    QPushButton* clear_button = createButton(frame, clear_icon);
    clear_button->setObjectName("clear_button");

    QPushButton* save_button = createButton(frame, save_icon);
    save_button->setObjectName("save_button");

    QHBoxLayout* layout = new QHBoxLayout(frame);

    layout->addStretch();
    layout->addWidget(play_button);
    layout->addWidget(pause_button);
    layout->addWidget(clear_button);
    layout->addWidget(save_button);
    layout->addStretch();

    pause_button->hide();

    return frame;
}
