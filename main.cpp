#include <QCoreApplication>
#include <QtDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug()<<"Hello World!"<<Qt::endl;

    return a.exec();
}
