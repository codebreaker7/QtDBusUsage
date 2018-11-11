#include <cstdio>
#include <QtDBus>
#include "subscriber.h"

using namespace std;
Subscriber::Subscriber(QObject *parent) : QObject(parent)
{
}

void Subscriber::start(const QString &name) {
    if (name != "org.example.QtDBus.PingExample") {
        return;
    }
    qstdin.open(stdin, QIODevice::ReadOnly);
    iface = new QDBusInterface(name, "/", "org.example.QtDBus.ComplexPong.Pong", QDBusConnection::sessionBus(), this);
    if (!iface->isValid()) {
        fprintf(stderr, "%s\n", qPrintable(QDBusConnection::sessionBus().lastError().message()));
        QCoreApplication::instance()->quit();
    }
    while (true) {
        printf("Ask your question\n");
        QString line = QString::fromLocal8Bit(qstdin.readLine()).trimmed();
        if (line.isEmpty()) {
            iface->call("quit");
            return;
        } else if (line == "value") {
            QVariant reply = iface->property("value");
            if (!reply.isNull()) {
                printf("value = %s\n", qPrintable(reply.toString()));
            }
        } else if (line.startsWith("value=")) {
            iface->setProperty("value", line.mid(6));
        } else {
            QDBusReply<QDBusVariant> reply = iface->call("query", line);
            if (reply.isValid()) {
                printf("Reply was: %s\n", qPrintable(reply.value().variant().toString()));
            }
        }
        if (iface->lastError().isValid()) {
            fprintf(stderr, "Call failed: %s\n", qPrintable(iface->lastError().message()));
        }
    }
}
