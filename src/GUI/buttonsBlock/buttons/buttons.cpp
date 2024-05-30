#include <QPushButton>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>

#include "buttons.hpp"
#include "../../../assets/animation/animatedButton/animatedButton.hpp"

QPushButton* createButton(QFrame* frame, QIcon icons) {
    AnimatedButton* button = new AnimatedButton(frame);

    button->setIcon(icons);
    button->setIconSize(QSize(35, 35));
    button->setFixedSize(55, 55);
    button->setStyleSheet(
            "QPushButton { "
                "outline: none; "
                "border: none; "
                "border-radius: 15px; "
                "background-color: #4B5662"
            "}"
            "QPushButton:hover { "
                "background-color: #8393A3; "
            "}"
    );

    button->setCursor(Qt::PointingHandCursor);

    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(20);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(2);
    shadowEffect->setColor(QColor(255, 255, 255, 160));
    button->setGraphicsEffect(shadowEffect);

    return button;
}