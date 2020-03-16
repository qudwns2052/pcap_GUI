#ifndef PCAPTHREAD_H
#define PCAPTHREAD_H

#include <QObject>

class pcapthread : public QObject
{
    Q_OBJECT
public:
    explicit pcapthread(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PCAPTHREAD_H
