#ifndef ANIMATEDBUTTON_HPP
#define ANIMATEDBUTTON_HPP

#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QEvent>
#include <QTimer>
#include <QPointer>

class AnimatedButton : public QPushButton {
Q_OBJECT

public:
    AnimatedButton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void animatePress();
    void animateRelease();

    QRect originalGeometry;
};

#endif // ANIMATEDBUTTON_HPP