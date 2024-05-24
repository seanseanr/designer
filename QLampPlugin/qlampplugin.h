#ifndef QLAMPPLUGIN_H
#define QLAMPPLUGIN_H

#include <QtGui/QIconEnginePluginV2>
#include <QStringList>
#include "qlamp.h"

class QLampPlugin : public QIconEnginePluginV2
{
    Q_OBJECT
public:
    QLampPlugin(QObject *parent = 0);
    QStringList keys() const;
    QLamp* create(const QString &filename);
};

#endif // QLAMPPLUGIN_H
