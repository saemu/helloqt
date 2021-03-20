#include <gtest/gtest.h>

#include <QApplication>
#include <QTimer>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QTimer::singleShot(0, [&]() {
      ::testing::InitGoogleTest(&argc, argv);
      auto result = RUN_ALL_TESTS();
      QApplication::exit(result);
    });

    return QApplication::exec();
}
