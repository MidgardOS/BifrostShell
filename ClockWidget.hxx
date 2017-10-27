#ifndef _ClockWidget_H_
#define _ClockWidget_H_

#include <QTimer>
#include <QLabel>
#include <QFrame>
#include <QCalendarWidget>

#include <DesktopPanel.hxx>

class CalendarPopup : public QFrame
{
  Q_OBJECT

  public:
    CalendarPopup(QWidget *parent);

  public slots:
    void goToday();

  private:
    QCalendarWidget *cal;
};

//--------------------------------------------------------------------------------

class ClockWidget : public QFrame
{
  Q_OBJECT
  Q_PROPERTY(QString timeFormat MEMBER timeFormat)
  Q_PROPERTY(QString dayFormat  MEMBER dayFormat)
  Q_PROPERTY(QString dateFormat MEMBER dateFormat)

  public:
    ClockWidget(DesktopPanel *parent);

  protected:
    void mousePressEvent(QMouseEvent *event) override;

  private slots:
    void fill();
    void tick();

  private:
    QTimer *timer;
    QLabel *timeLabel, *dayLabel, *dateLabel;
    CalendarPopup *calendar;

    QString timeFormat = QStringLiteral("HH:mm");
    QString dayFormat  = QStringLiteral("ddd");
    QString dateFormat = QStringLiteral("d.MMM yyyy");
};

#endif