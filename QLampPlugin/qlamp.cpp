#include "qlamp.h"

QLamp::QLamp(QWidget * parent,const QString &filename, const QString &filename2) :
    QWidget(parent),QIconEngineV2()
{
    const QSize &size = QSize();
    m_qIcon1.addFile(filename, size, m_mode,QIcon::Off);
    m_qIcon2.addFile(filename2, size, m_mode,QIcon::On);
}

QLamp::~QLamp()
{

}

void QLamp::paint(QPainter *painter, const QRect &rect, QIcon::Mode mode, QIcon::State state)
{
    QBrush brush = painter->background();
    QColor color = brush.color();
    brush.setColor(Qt::transparent);
    painter->setBackground(brush);
    painter->eraseRect(rect);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    m_qIcon1.paint(painter, rect,Qt::AlignCenter, mode, state);
}

QSize QLamp::actualSize(const QSize &size, QIcon::Mode mode, QIcon::State state)
{
    if(m_state == QIcon::Off)
    {
        m_qIcon1.actualSize(size, m_mode, m_state);
    }
    else
    {
        m_qIcon2.actualSize(size, m_mode, m_state);
    }

    return size;
}

QPixmap QLamp::pixmap(const QSize &size, QIcon::Mode mode, QIcon::State state)
{
    if(m_state == QIcon::Off)
    {
        m_qIcon1.pixmap(1, m_mode, m_state);
    }
    else
    {
        m_qIcon2.pixmap(1, m_mode, m_state);
    }
}

void QLamp::addPixmap(const QPixmap &pixmap, QIcon::Mode mode, QIcon::State state)
{
    if(m_state == QIcon::Off)
    {
        m_qIcon1.addPixmap( pixmap, m_mode, m_state);
    }
    else
    {
        m_qIcon2.addPixmap( pixmap, m_mode, m_state);
    }
}

void QLamp::addFile(const QString &filename, const QSize &size, QIcon::Mode mode, QIcon::State state)
{
    if(m_state == QIcon::Off)
    {
        m_qIcon1.addFile(filename, size, m_mode, m_state);
    }
    else
    {
        m_qIcon2.addFile(filename, size, m_mode, m_state);
    }
}

