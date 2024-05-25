#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>

#include "app/timerApp.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TimerApp window;

    window.setWindowTitle("Time Tracker");
    window.setStyleSheet("QWidget { background-color: #131619 }");
//    window.setFixedSize(600, 650);

    window.show();

    return app.exec();
}