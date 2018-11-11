#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <QObject>
#include <QDBusAbstractAdaptor>
#include <QDBusVariant>

class Publisher : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.QtDBus.ComplexPong.Pong")
    Q_PROPERTY(QString value READ value WRITE setValue)
public:
    QString _value;
    QString value() const;
    void setValue(const QString& newvalue);
    Publisher(QObject * obj);
signals:
    void aboutToQuit();
public slots:
    QDBusVariant query(const QString& query);
    Q_NOREPLY void quit();
};

#endif // PUBLISHER_H
