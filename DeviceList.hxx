#ifndef _DeviceList_H_
#define _DeviceList_H_

#include <QFrame>
#include <QVBoxLayout>
#include <QMap>

#include <Solid/Device>
#include <Solid/Predicate>
#include <Solid/SolidNamespace>
#include <QLabel>
#include <QTimer>
#include <QToolButton>

#include <KServiceAction>

//--------------------------------------------------------------------------------

struct DeviceAction
{
  DeviceAction() { }
  DeviceAction(const QString &filePath, Solid::Predicate p, KServiceAction a)
    : path(filePath), predicate(p), action(a) { }

  QString path;
  Solid::Predicate predicate;
  KServiceAction action;
};

//--------------------------------------------------------------------------------

class DeviceItem : public QFrame
{
  Q_OBJECT

  public:
    DeviceItem(Solid::Device dev, const QVector<DeviceAction> &deviceActions);

  private:
    static QString errorToString(Solid::ErrorType error);
    void fillData();

    enum Action { Mount, Unmount };
    void mountDone(Action action, Solid::ErrorType error, QVariant errorData, const QString &udi);

  private slots:
    void teardownDone(Solid::ErrorType error, QVariant errorData, const QString &udi);
    void setupDone(Solid::ErrorType error, QVariant errorData, const QString &udi);

  private:
    Solid::Device device;
    QVector<DeviceAction> actions;
    QToolButton *mountButton = nullptr;
    QLabel *textLabel, *statusLabel;
    QTimer statusTimer;
};

//--------------------------------------------------------------------------------

class DeviceList : public QFrame
{
  Q_OBJECT

  public:
    DeviceList(QWidget *parent);

    bool isEmpty() const { return items.isEmpty(); }

  signals:
    void deviceWasAdded();
    void deviceWasRemoved();

  private slots:
    void deviceAdded(const QString &dev);
    void deviceRemoved(const QString &dev);

  private:
    void loadActions();
    void addDevice(Solid::Device device);

  private:
    QVBoxLayout *vbox;
    QMap<QString, DeviceItem *> items;
    Solid::Predicate predicate;

    QVector<DeviceAction> actions;
};

#endif