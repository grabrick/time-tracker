#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QVBoxLayout>
#include "timeBlock.hpp"

QFrame* createBlock(const QString& text) {
    QFrame* frame = new QFrame();
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFixedSize(100, 100);
    frame->setStyleSheet("QFrame { background-color: #1D2227; border-radius: 20px; }");

    // Добавляем тень к блоку
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(20);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(4);
    shadowEffect->setColor(QColor(29, 34, 39, 160));
    frame->setGraphicsEffect(shadowEffect);

    QLabel* label = new QLabel(text, frame);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel { font-family: Arial; font-size: 30pt; color: white; }");

    QVBoxLayout* layout = new QVBoxLayout(frame);
    layout->addWidget(label);
    layout->setAlignment(label, Qt::AlignCenter);

    return frame;
}