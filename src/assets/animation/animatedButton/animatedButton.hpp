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
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    AnimatedButton(QWidget *parent = nullptr);

    qreal opacity() const;
    void setOpacity(qreal opacity);

protected:
    bool event(QEvent *event) override;

private slots:
//    void animateHover(bool entering);
    void animatePress();
//    void animateClicked();
    void animateRelease();

private:
    QGraphicsOpacityEffect *m_opacityEffect;
};

#endif // ANIMATEDBUTTON_HPP