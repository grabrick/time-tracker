#include <QWidget>
#include "animatedButton.hpp"

AnimatedButton::AnimatedButton(QWidget *parent)
        : QPushButton(parent), originalGeometry(geometry()) {}

void AnimatedButton::mousePressEvent(QMouseEvent *event) {
    originalGeometry = geometry();
    animatePress();
    QPushButton::mousePressEvent(event);
}

void AnimatedButton::mouseReleaseEvent(QMouseEvent *event) {
    animateRelease();
    QPushButton::mouseReleaseEvent(event);
}

void AnimatedButton::animatePress() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(geometry());
    animation->setEndValue(QRect(originalGeometry.x() + 2, originalGeometry.y() + 2, originalGeometry.width() - 4, originalGeometry.height() - 4));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void AnimatedButton::animateRelease() {
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(geometry());
    animation->setEndValue(originalGeometry);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}