#include "animatedButton.hpp"

AnimatedButton::AnimatedButton(QWidget *parent)
        : QPushButton(parent), m_opacityEffect(new QGraphicsOpacityEffect(this)) {
    setGraphicsEffect(m_opacityEffect);
    setOpacity(1.0);

    connect(this, &QPushButton::pressed, this, &AnimatedButton::animatePress);
    connect(this, &QPushButton::released, this, &AnimatedButton::animateRelease);
//    connect(this, &QPushButton::clicked, this, &AnimatedButton::animateClicked);
}

qreal AnimatedButton::opacity() const {
    return m_opacityEffect->opacity();
}

void AnimatedButton::setOpacity(qreal opacity) {
    m_opacityEffect->setOpacity(opacity);
}

bool AnimatedButton::event(QEvent *event) {
//    if (event->type() == QEvent::Enter) {
//        animateHover(true);
//    } else if (event->type() == QEvent::Leave) {
//        animateHover(false);
//    }
    return QPushButton::event(event);
}

//void AnimatedButton::animateHover(bool entering) {
//    QPropertyAnimation *animation = new QPropertyAnimation(m_opacityEffect, "opacity", this);
//    animation->setDuration(300);
//    animation->setStartValue(m_opacityEffect->opacity());
//    animation->setEndValue(entering ? 0.6 : 1.0);
//
//    animation->setEasingCurve(QEasingCurve::InOutQuad);
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
//}

void AnimatedButton::animatePress() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(geometry());
    animation->setEndValue(QRect(geometry().x() + 2, geometry().y() + 2, geometry().width() - 4, geometry().height() - 4));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

//void AnimatedButton::animateClicked() {
//    QPropertyAnimation *animation = new QPropertyAnimation(m_opacityEffect, "backgroundColor", this);
//    this->setStyleSheet(
//            "QPushButton { "
//            "outline: none; "
//            "border: none; "
//            "border-radius: 20px; "
//            "background-color: #8393A3"
//            "}"
//    );
//
//
//    animation->setDuration(300);
//    animation->setStartValue(m_opacityEffect->opacity());
//    animation->setEndValue(1.0);
//
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
//}

void AnimatedButton::animateRelease() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(geometry());
    animation->setEndValue(QRect(geometry().x() - 2, geometry().y() - 2, geometry().width() + 4, geometry().height() + 4));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}