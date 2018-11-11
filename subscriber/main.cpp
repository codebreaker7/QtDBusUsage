#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QProcess>
#include <QtDBus>
#include <cstdio>
#include "subscriber.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (!QDBusConnection::sessionBus().isConnected()) {
        fprintf(stderr, "Cannot connect to session.\n");
        return 1;
    }
    QDBusServiceWatcher watcher("org.example.QtDBus.PingExample", QDBusConnection::sessionBus(),
                                QDBusServiceWatcher::WatchForRegistration);
    Subscriber subs;
    QObject::connect(&watcher, &QDBusServiceWatcher::serviceRegistered, &subs, &Subscriber::start);
    QProcess p;
    p.start("./../publisher/publisher");
    return a.exec();
}

