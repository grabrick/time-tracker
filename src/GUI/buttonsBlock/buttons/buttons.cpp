#include <QPushButton>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include "buttons.hpp"

QPushButton* createButton(QFrame* frame, QIcon icons) {
    QPushButton* button = new QPushButton(frame);
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;

    button->setIcon(icons);
    button->setIconSize(QSize(35, 35));
    button->setFixedSize(55, 55);
    button->setStyleSheet("QPushButton { background-color: #4B5662; outline: none; border: none; border-radius: 20px }");

    shadowEffect->setBlurRadius(5);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(2);
    shadowEffect->setColor(QColor(255, 255, 255, 64));
    button->setGraphicsEffect(shadowEffect);

    return button;
}