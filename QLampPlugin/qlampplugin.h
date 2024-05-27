#ifndef QLAMPPLUGIN_H
#define QLAMPPLUGIN_H

#include <QtGui/QIconEnginePluginV2>
#include <QStringList>
#include "qlamp.h"
#include <QDesignerCustomWidgetInterface>

//class QLampPlugin : public QIconEnginePluginV2
class QLampPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    QLampPlugin(QObject *parent = 0);
    QStringList keys() const;
    QLamp* create(QWidget *parent = 0 ,const QString &filename=QString(),
                  const QString &filename2=QString());
    QString name() const;
    QString group() const;
    QString toolTip() const;
    QString whatsThis() const;
    bool isContainer() const;
    bool isInitialized() const;
    QString includeFile() const;
    QIcon icon() const;
    QString domXml() const;
    QWidget * createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);
private:
    bool initialized;

};

#endif // QLAMPPLUGIN_H
