//#include "animatedbutton.hpp"
//#include <QEnterEvent>
//#include <QPalette>
//
//AnimatedButton::AnimatedButton(QWidget* parent)
//        : QPushButton(parent), m_color(QColor(75, 86, 98)) {
//    setAutoFillBackground(true);
//    setColor(m_color);
//}
//
//QColor AnimatedButton::color() const {
//    return m_color;
//}
//
//void AnimatedButton::setColor(const QColor& color) {
//    m_color = color;
//    QPalette pal = palette();
//    pal.setColor(QPalette::Button, m_color);
//    setPalette(pal);
//    update();
//}
//
//void AnimatedButton::enterEvent(QEnterEvent* event) {
//    animateColor(QColor(131, 147, 163)); // Hover color
//    QPushButton::enterEvent(event);
//}
//
//void AnimatedButton::leaveEvent(QEvent* event) {
//    animateColor(QColor(75, 86, 98)); // Initial color
//    QPushButton::leaveEvent(event);
//}
//
//void AnimatedButton::animateColor(const QColor& endColor) {
//    QPropertyAnimation* animation = new QPropertyAnimation(this, "color");
//    animation->setDuration(300); // Duration of the transition in milliseconds
//    animation->setStartValue(m_color);
//    animation->setEndValue(endColor);
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
//}
