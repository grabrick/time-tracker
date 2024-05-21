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
    QPixmap clear_pixmap = QPixmap("icons/clear-circle.png");
    QIcon play_icon(play_pixmap);
    QIcon pause_icon(pause_pixmap);
    QIcon clear_icon(clear_pixmap);

    frame->setFrameShape(QFrame::StyledPanel);
    frame->setMinimumSize(200, 80);
    frame->setStyleSheet("QFrame { background-color: #323941; border-radius: 20px; }");

    QPushButton* play_button = createButton(frame, play_icon);
    QPushButton* pause_button = createButton(frame, pause_icon);
    QPushButton* clear_button = createButton(frame, clear_icon);

    QHBoxLayout* layout = new QHBoxLayout(frame);
    layout->addStretch();
    layout->addWidget(play_button);
    layout->addWidget(pause_button);
    layout->addWidget(clear_button);
    layout->addStretch();

    return frame;
}
