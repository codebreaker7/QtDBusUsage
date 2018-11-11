#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <QObject>
#include <QFile>
#include <QDBusInterface>

class Subscriber : public QObject
{
    Q_OBJECT
public:
    explicit Subscriber(QObject *parent = 0);
signals:

public slots:
    void start(const QString&);
private:
    QFile qstdin;
    QDBusInterface * iface;
};

#endif // SUBSCRIBER_H
