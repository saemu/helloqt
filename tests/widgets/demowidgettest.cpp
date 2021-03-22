
#include <gtest/gtest.h>

#include "demowidget.h"

#include <QLineEdit>
#include <QPushButton>
#include <QSignalSpy>
#include <QTest>
#include <memory>

QT_BEGIN_NAMESPACE
inline void PrintTo(const QString &qString, ::std::ostream *os)
{
    *os << qPrintable(qString);
}
QT_END_NAMESPACE

namespace {

template <class Child_t>
Child_t *child_by_name(QObject* parent, const QString &name) {
    auto *child = parent->findChild<Child_t *>(name);
    EXPECT_NE(nullptr, child);
    return child;
}

class DemoWidgetTest : public ::testing::Test {
public:
    void SetUp() override {
        Test::SetUp();
        spy = std::make_unique<QSignalSpy>(&widget, &DemoWidget::sendText);
        widget.show();
    }

    void typeCharacter(char key) {
        auto *text = child_by_name<QLineEdit>(&widget, "text");
        QTest::keyClick(text, key);
    }

    void checkSignal(const QString& expected) {
        EXPECT_EQ(1, spy->count());
        auto signalValue{spy->takeFirst().at(0)};
        EXPECT_TRUE(QVariant::String == signalValue.type());
        EXPECT_EQ(expected, signalValue.toString());
    }

    void checkText(const QString& expected) {
        auto *text = child_by_name<QLineEdit>(&widget, "text");
        EXPECT_EQ(expected, text->text());
    }

    void clickSendButton() {
        auto *button = child_by_name<QPushButton>(&widget, "send");
        QTest::mouseClick(button, Qt::LeftButton);
    }

private:
    DemoWidget widget;
    std::unique_ptr<QSignalSpy> spy = nullptr;
};
}

TEST_F(DemoWidgetTest, SimpleTest) {
    const QString testValue{"demo"};
    for (auto key : testValue) {
        typeCharacter(key.toLatin1());
    }
    clickSendButton();
    checkText(testValue);
    checkSignal(testValue);
}

TEST_F(DemoWidgetTest, ValueIsNotTrimmed) {
    const QString testValue{"  demo  "};
    for (auto key : testValue) {
        typeCharacter(key.toLatin1());
    }
    clickSendButton();
    checkText(testValue);
    checkSignal(testValue);
}
