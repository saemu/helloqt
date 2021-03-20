
#include "demowidget.h"

#include <QApplication>
#include <QDebug>

namespace {
class Helper : public QObject {

public:
    void printText (const QString &text) {
        qDebug () << text;
        if(text == "exit") {
            QApplication::quit();
        }
    }
};
}


int main (int argc, char *argv[]) {
    QApplication a (argc, argv);
    Helper helper;
    DemoWidget widget;
    QObject::connect(&widget, &DemoWidget::sendText, &helper, &Helper::printText);
    widget.show();
    return QApplication::exec ();
}
