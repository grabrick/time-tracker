#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QVBoxLayout>

QFrame* createBlock(const QString& titleText, const QString& timeText) {
    QFrame* globalFrame = new QFrame();
    globalFrame->setFixedSize(90, 110);
//    globalFrame->setStyleSheet("QFrame { border: 2px solid yellow }");

    QLabel* title = new QLabel(titleText, globalFrame);
    title->setFixedSize(80, 20);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel { font-family: Arial; font-size: 14px; color: white; border-radius: 0px; }");

    QFrame* timeFrame = new QFrame(globalFrame);
    timeFrame->setFrameShape(QFrame::StyledPanel);
    timeFrame->setFixedSize(80, 80);
    timeFrame->setStyleSheet("QFrame { background-color: #1D2227; border-radius: 20px; }");

    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(20);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(4);
    shadowEffect->setColor(QColor(29, 34, 39, 160));
    timeFrame->setGraphicsEffect(shadowEffect);

    QLabel* timeLabel = new QLabel(timeText, timeFrame);
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setStyleSheet("QLabel { font-family: Arial; font-size: 30pt; color: white }");

    // Главный макет для глобального фрейма
    QVBoxLayout* globalLayout = new QVBoxLayout(globalFrame);
    globalLayout->addWidget(title, 0, Qt::AlignCenter);
    globalLayout->addWidget(timeFrame, 0, Qt::AlignCenter);
    globalLayout->setAlignment(Qt::AlignVCenter);
    globalLayout->setContentsMargins(0, 0, 0, 0);
    globalLayout->setSpacing(0);

    // Макет для фрейма времени
    QVBoxLayout* timeLayout = new QVBoxLayout(timeFrame);
    timeLayout->addWidget(timeLabel);
    timeLayout->setAlignment(timeLabel, Qt::AlignCenter);
    timeLayout->setContentsMargins(0, 0, 0, 0);

    return globalFrame;
}