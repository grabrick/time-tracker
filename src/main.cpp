#include <QApplication>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

#include "app/timerApp.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TimerApp window;

    QPixmap icons_pixmap = QPixmap(":/icons/w_icons.png");
    QIcon w_icon(icons_pixmap);

    window.setWindowTitle("Time Tracker");
    window.setWindowIcon(w_icon);
    window.setStyleSheet("QWidget { background-color: #131619 }");
//    window.setFixedSize(600, 650);

    window.show();

    return app.exec();
}