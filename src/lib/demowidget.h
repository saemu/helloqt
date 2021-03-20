//
// Created by Samuel Brand on 20.03.21.
//

#ifndef HELLOQT_DEMOWIDGET_H
#define HELLOQT_DEMOWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class DemoWidget;
}
QT_END_NAMESPACE

class DemoWidget : public QWidget {
    Q_OBJECT

public:
    explicit DemoWidget (QWidget *parent = nullptr);
    ~DemoWidget () override;

private:
    Ui::DemoWidget *ui;

Q_SIGNALS:
    void sendText(const QString&);
};

#endif//HELLOQT_DEMOWIDGET_H
