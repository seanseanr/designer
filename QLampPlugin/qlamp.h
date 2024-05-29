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
#include <QRect>
#include <QPainter>

class QDESIGNER_WIDGET_EXPORT QLamp : public QWidget, public QIconEngineV2
{
    Q_OBJECT
    Q_PROPERTY(ICON_STATE getLampState READ getLampState WRITE setLampState)
public:
    enum ICON_STATE {ON, OFF}; // keep accordance with QIcon::State. Do this because Q_PROPERTY will get error if use QIcon:
    QLamp(QWidget *parent = 0, const QString &filename=QString(),
          const QString &filename2=QString());
    ~QLamp();
    virtual void paint(QPainter* painter, const QRect & rect, QIcon::Mode mode, QIcon::State state);
    virtual QSize actualSize(const QSize &size, QIcon::Mode mode, ICON_STATE state);
    virtual QPixmap pixmap(const QSize &size, QIcon::Mode mode, ICON_STATE state);

    virtual void addPixmap(const QPixmap &pixmap, QIcon::Mode mode, ICON_STATE state);
    virtual void addFile(const QString &fileName, const QSize &size, QIcon::Mode mode, ICON_STATE state);
    void paintEvent(QPaintEvent *event);
    void updateLamp(QString &filename);
    void update_rect(const QRect &rect);
    ICON_STATE getLampState();
    void setLampState(ICON_STATE state);
protected:
    QRect m_rect;
    QPainter m_painter;
    QIcon m_qIcon1;
    QIcon m_qIcon2;
    const QIcon::Mode m_mode = QIcon::Normal;

private:
    ICON_STATE m_state;

signals:

public slots:

};


#endif // QLAMP_H
