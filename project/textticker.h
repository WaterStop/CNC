#ifndef TEXTTICKER_H
#define TEXTTICKER_H

#include <QObject>
#include "baseset.h"


class TextTicker : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)

public:
    TextTicker(QWidget *parent = nullptr);
    void setText(const QString &newText);
    QString text() const{return myText;}
    QSize sizeHint() const ;
    ~TextTicker();
protected:
    void paintEvent(QPaintEvent* event);
    void timerEvent(QTimerEvent* event);
    void showEvent(QShowEvent* event);
    void hideEvent(QHideEvent* event);
    void DealSlot();
private:
    QString myText;
    int offset;
    int myTimerId;
    //QTimer change_timer;
    QTimer *change_timer = new QTimer;
private slots:
    void timeout_slot();
signals:
    void tick_end();
};
#endif // TEXTTICKER_H
