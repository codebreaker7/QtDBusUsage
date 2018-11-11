#include "publisher.h"

#include <QTimer>
#include <QCoreApplication>

Publisher::Publisher(QObject *obj): QDBusAbstractAdaptor(obj)
{

}

QString Publisher::value() const {
    return _value;
}

void Publisher::setValue(const QString &newvalue) {
    _value = newvalue;
}

QDBusVariant Publisher::query(const QString &query) {
    QString q = query.toLower();
    if (q == "hello") {
        return QDBusVariant("World");
    }
    if (q == "ping") {
        return QDBusVariant("Pong");
    }
    if (q.indexOf("the answer to life") != -1) {
        return QDBusVariant(42);
    }
    if (q.indexOf("unladden swallow") != -1) {
        if (q.indexOf("european") != -1) {
            return QDBusVariant(11.0);
        }
        return QDBusVariant("Don't know the answer");
    }
}

void Publisher::quit() {
    QTimer::singleShot(0, QCoreApplication::instance(), &QCoreApplication::quit);
}

