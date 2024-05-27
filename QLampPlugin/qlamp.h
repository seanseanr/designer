#ifndef QLAMP_H
#define QLAMP_H

#include <QIconEngineV2>
#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QRect>
#include <QIcon>
#include <QColor>
#include <QtDesigner/QDesignerExportWidget>
#include <QWidget>
class QLamp : public QWidget, public QIconEngineV2
{
    Q_OBJECT
public:
    QLamp(QObject *parent = 0, const QString &filename=QString(),
          const QString &filename2=QString());
    ~QLamp();
    virtual void paint(QPainter* painter, const QRect & rect, QIcon::Mode mode, QIcon::State state);
    virtual QSize actualSize(const QSize &size, QIcon::Mode mode, QIcon::State state);
    virtual QPixmap pixmap(const QSize &size, QIcon::Mode mode, QIcon::State state);

    virtual void addPixmap(const QPixmap &pixmap, QIcon::Mode mode, QIcon::State state);
    virtual void addFile(const QString &fileName, const QSize &size, QIcon::Mode mode, QIcon::State state);

private:
    QIcon m_qIcon1;
    QIcon m_qIcon2;
    QIcon::State m_state;
    const QIcon::Mode m_mode = QIcon::Normal;

signals:

public slots:

};

#endif // QLAMP_H
