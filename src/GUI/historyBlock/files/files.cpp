#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "files.hpp"
#include "../../../assets/animation/animatedButton/animatedButton.hpp"

QFrame* files(const QString &title, const QString &resultText) {
    QFrame* global_frame = new QFrame();
    QFrame* button_frame = new QFrame(global_frame);
    QFrame* text_frame = new QFrame(global_frame);
    QHBoxLayout* globalLayout = new QHBoxLayout(global_frame);

    QHBoxLayout* textWrapperLayout = new QHBoxLayout(text_frame);
    QHBoxLayout* buttonWrapperLayout = new QHBoxLayout(button_frame);

    QPixmap edit_pixmap = QPixmap(":/icons/pencil.png");
    QPixmap delete_pixmap = QPixmap(":/icons/trash-can.png");
    QIcon edit_icon(edit_pixmap);
    QIcon delete_icon(delete_pixmap);

    QPushButton* edit_buttons_raw = new QPushButton();
    AnimatedButton* edit_buttons = new AnimatedButton(edit_buttons_raw);
    QGraphicsDropShadowEffect* shadowEditEffect = new QGraphicsDropShadowEffect;
    edit_buttons->setObjectName("edit_buttons");
    edit_buttons->setIcon(edit_icon);
    edit_buttons->setIconSize(QSize(24, 24));
    edit_buttons->setFixedSize(40, 40);
    edit_buttons->setCursor(Qt::PointingHandCursor);
    edit_buttons->setStyleSheet(" #edit_buttons {"
                                    "background-color: #525F6B;"
                                    "border: none;"
                                    "border-radius: 10px;"
                                "}"
                                "#edit_buttons:hover { "
                                    "background-color: #8393A3; "
                                "}"
    );
    shadowEditEffect->setBlurRadius(20);
    shadowEditEffect->setXOffset(0);
    shadowEditEffect->setYOffset(2);
    shadowEditEffect->setColor(QColor(255, 255, 255, 160));
    edit_buttons->setGraphicsEffect(shadowEditEffect);

    QPushButton* delete_buttons_raw = new QPushButton();
    AnimatedButton* delete_buttons = new AnimatedButton(delete_buttons_raw);
    QGraphicsDropShadowEffect* shadowDeleteEffect = new QGraphicsDropShadowEffect;
    delete_buttons->setObjectName("delete_buttons");
    delete_buttons->setIcon(delete_icon);
    delete_buttons->setIconSize(QSize(24, 24));
    delete_buttons->setFixedSize(40, 40);
    delete_buttons->setCursor(Qt::PointingHandCursor);
    delete_buttons->setStyleSheet(" #delete_buttons {"
                                    "background-color: #525F6B;"
                                    "border: none;"
                                    "border-radius: 10px"
                                "}"
                                "#delete_buttons:hover { "
                                    "background-color: #8393A3; "
                                "}"
    );
    shadowDeleteEffect->setBlurRadius(20);
    shadowDeleteEffect->setXOffset(0);
    shadowDeleteEffect->setYOffset(2);
    shadowDeleteEffect->setColor(QColor(255, 255, 255, 160));
    delete_buttons->setGraphicsEffect(shadowDeleteEffect);

    buttonWrapperLayout->addStretch();
    buttonWrapperLayout->setAlignment(Qt::AlignHCenter);
    buttonWrapperLayout->addWidget(edit_buttons);
    buttonWrapperLayout->setSpacing(10);
    buttonWrapperLayout->addWidget(delete_buttons);
    buttonWrapperLayout->setContentsMargins(5, 0, 5, 0);
    buttonWrapperLayout->addStretch();

    global_frame->setFrameShape(QFrame::StyledPanel);
    global_frame->setFixedSize(477, 50);
    global_frame->setStyleSheet(" QFrame { background-color: #323941; border-radius: 15px; } ");

    text_frame->setMinimumWidth(250);

    QLabel* title_label = new QLabel(title);
    title_label->setObjectName("title_label");
    title_label->setStyleSheet("QLabel { color: white; }");

    QLabel* result_label = new QLabel(resultText);
    result_label->setObjectName("result_label");
    result_label->setMinimumWidth(150);
    result_label->setStyleSheet("#result_label { color: white; }");

    textWrapperLayout->addStretch();
    textWrapperLayout->addWidget(title_label);
    textWrapperLayout->setSpacing(0);
    textWrapperLayout->addWidget(result_label);
    globalLayout->setContentsMargins(0, 0, 0, 0);
    textWrapperLayout->addStretch();

    globalLayout->addStretch();
    globalLayout->addWidget(text_frame);
    globalLayout->setSpacing(190);
    globalLayout->addWidget(button_frame);
    globalLayout->setContentsMargins(10, 0, 0, 0);
    globalLayout->addStretch();

    return global_frame;
}