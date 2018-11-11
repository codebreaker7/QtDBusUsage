#include <cstdio>
#include <cstdlib>
#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusError>
#include "publisher.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QObject obj;
    Publisher * publ = new Publisher(&obj);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, publ, &Publisher::aboutToQuit);
    publ->setProperty("value", "initial value");
    QDBusConnection::sessionBus().registerObject("/", &obj);
    if (!QDBusConnection::sessionBus().registerService("org.example.QtDBus.PingExample")) {
        fprintf(stderr, "%s\n", qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }
    return a.exec();
}

