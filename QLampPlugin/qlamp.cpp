#include "qlamp.h"
#include <QPaintEvent>
#include <QtCore/QMetaType>

QLamp::QLamp(QWidget * parent,const QString &filename, const QString &filename2) :
    QWidget(parent),QIconEngineV2()
{
    const QSize &size = QSize();
    m_state = OFF;
    m_qIcon1.addFile(filename, size, m_mode,QIcon::Off);
    m_qIcon2.addFile(filename2, size, m_mode,QIcon::On);
    //m_rect = QRect();
    //m_painter = QPainter();
}

QLamp::~QLamp()
{

}

void QLamp::paint(QPainter *painter, const QRect &rect, QIcon::Mode mode, QIcon::State state)
{
    QBrush brush = painter->brush();
    QColor color = brush.color();
    brush.setColor(color);
    //painter->setBackground(brush);
    //painter->eraseRect(rect);
    painter->setBrush(brush);
    int side = qMin(rect.width(), rect.height());
    painter->scale(side/52, side/52);
    //QPixmap pm("c:/Users/user/Downloads/LED_OFF.jpg");
    //painter->drawPixmap(10,70,50,50,pm);
    //m_qIcon1.paint(painter, rect,Qt::AlignCenter, m_mode, m_state);
    //painter->drawPixmap(rect.x(),rect.y(),rect.width(),rect.height(), pixmap(QSize(32,32), m_mode, m_state));
    if(m_state == QIcon::Off)
    {
        QImage img(":/img/LED_OFF.jpg");
        painter->drawImage(rect.x(), rect.y(), img);
    }
    else
    {
        QImage img(":/img/LED_ON.jpg");
        painter->drawImage(rect.x(), rect.y(), img);
    }

}

QSize QLamp::actualSize(const QSize &size, QIcon::Mode mode, ICON_STATE state)
{
    if(m_state == QIcon::Off)
    {
        m_qIcon1.actualSize(size, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }
    else
    {
        m_qIcon2.actualSize(size, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }

    return size;
}

QPixmap QLamp::pixmap(const QSize &size, QIcon::Mode mode, ICON_STATE state)
{
    if(m_state == QIcon::Off)
    {
        return m_qIcon1.pixmap(1, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }
    else
    {
        return m_qIcon2.pixmap(1, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }
}

void QLamp::addPixmap(const QPixmap &pixmap, QIcon::Mode mode, ICON_STATE state)
{
    if(m_state == QIcon::Off)
    {
        m_qIcon1.addPixmap( pixmap, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }
    else
    {
        m_qIcon2.addPixmap( pixmap, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }
}

void QLamp::addFile(const QString &filename, const QSize &size, QIcon::Mode mode, ICON_STATE state)
{
    if(m_state == QIcon::Off)
    {
        m_qIcon1.addFile(filename, size, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }
    else
    {
        m_qIcon2.addFile(filename, size, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    }
}

void QLamp::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QColor(255,255,255));
    painter.setBrush(QColor(255,255,255));

    paint(&painter, event->rect(),
                       m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
    update_rect(event->rect());
}

void QLamp::update_rect(const QRect &rect)
{
    m_rect = rect;
}

void QLamp::setLampState(ICON_STATE state)
{
    m_state = state;
    paint(&m_painter, m_rect, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
}

QLamp::ICON_STATE QLamp::getLampState()
{
    return m_state;
}

void QLamp::updateLamp(QString &filename)
{
    addFile(filename, QSize(m_rect.width(), m_rect.height()), m_mode, m_state);
    paint(&m_painter, m_rect, m_mode, m_state==OFF ? QIcon::Off : QIcon::On);
}

//Q_DECLARE_OPAQUE_POINTER(QLamp); not supported in QT 4

Q_DECLARE_METATYPE(QLamp*)
