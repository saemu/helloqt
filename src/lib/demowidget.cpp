//
// Created by Samuel Brand on 20.03.21.
//

#include "demowidget.h"
#include "ui_demowidget.h"

DemoWidget::DemoWidget (QWidget *parent) : QWidget (parent), ui (new Ui::DemoWidget) {
    ui->setupUi (this);
    connect(ui->send, &QAbstractButton::clicked, [this]() {
        Q_EMIT sendText(ui->text->text());
    });
}

DemoWidget::~DemoWidget () {
    delete ui;
}
