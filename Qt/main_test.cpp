//
// Created by cloquet on 11/04/16.
//

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button("Hello mes salopes");

    button.show();
    return app.exec();
}