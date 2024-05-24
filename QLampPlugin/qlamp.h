#ifndef QLAMP_H
#define QLAMP_H

#include <QIconEngineV2>

class QLamp : public QObject, public QIconEngineV2
{
    Q_OBJECT
public:
    explicit QLamp(QObject *parent = 0);
    
signals:

public slots:

};

#endif // QLAMP_H
