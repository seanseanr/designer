#include "qlampplugin.h"
#include "qlamp.h"

QLampPlugin::QLampPlugin(QObject *parent) :
    QObject(parent)
{
    initialized = false;
}

QStringList QLampPlugin::keys() const
{
    return QStringList()<<"*.png"<<"*.jpg";
}

QLamp* QLampPlugin::create(QWidget *parent ,const QString &filename,
                           const QString &filename2)
{
    return new QLamp(parent, filename, filename2);
}

QWidget* QLampPlugin::createWidget(QWidget *parent)
{
    return create(parent, QString("c:/Users/user/Downloads/LED_OFF.jpg"),
                  QString("c:/Users/user/Downloads/LED_ON.jpg"));
}

QString QLampPlugin::name() const
{
    return "QLamp";
}

QString QLampPlugin::group() const
{
    return "Extension Widgets";
}

QString QLampPlugin::includeFile() const
{
    return "qlamp.h";
}

bool QLampPlugin::isContainer() const
{
    return false;
}

bool QLampPlugin::isInitialized() const
{
    return initialized;
}

void QLampPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if(initialized)
        return;

    initialized = true;
}

QIcon QLampPlugin::icon() const
{
    return QIcon();
}

QString QLampPlugin::toolTip() const
{
    return "";
}

QString QLampPlugin::whatsThis() const
{
    return "";
}

QString QLampPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
            " <widget class=\"QLamp\" name=\"qLamp\">\n"
            "  <property name=\"geometry\">\n"
            "   <rect>\n"
            "    <x>0</x>\n"
            "    <y>0</y>\n"
            "    <width>64</width>\n"
            "    <height>64</height>\n"
            "   </rect>\n"
            "  </property>\n"
            "  <property name=\"toolTip\" >\n"
            "   <string>Show images of off and on states</string>\n"
            "  </property>\n"
            "  <property name=\"whatsThis\" >\n"
            "   <string>The Lamp widget displays images of different states.</string>\n"
            "  </property>\n"
            " </widget>\n"
            "</ui>\n";
}

Q_EXPORT_PLUGIN2(QLampPlugin, QLampPlugin)
