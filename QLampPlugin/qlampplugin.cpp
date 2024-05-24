#include "qlampplugin.h"
#include "qlamp.h"

QLampPlugin::QLampPlugin(QObject *parent) :
    QIconEnginePluginV2(parent)
{
}

QStringList QLampPlugin::keys() const
{
    return QStringList()<<"*.png"<<"*.jpg";
}

QLamp* QLampPlugin::create(const QString &filename)
{
    return new QLamp();
}

//Q_EXPORT_PLUGIN2(QLampPlugin, QLampPlugin)
