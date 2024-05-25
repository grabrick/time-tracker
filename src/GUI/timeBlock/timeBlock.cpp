#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextEdit>

QFrame* createBlock(const QString& timeText, const QString& titleText) {
    QFrame* globalFrame = new QFrame();
    globalFrame->setFixedSize(90, 110);
//    globalFrame->setStyleSheet("QFrame { border: 2px solid yellow }");

    QTextEdit* title = new QTextEdit(timeText);
    title->setFixedSize(80, 20);
    title->setAlignment(Qt::AlignCenter);
    title->setReadOnly(true);
    title->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    title->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    title->setStyleSheet("QTextEdit { font-family: Arial; font-size: 14px; color: white; border-radius: 0px; background: transparent; border: none; }");

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

    QLabel* timeLabel = new QLabel(titleText, timeFrame);
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