// SPDX-License-Identifier: GPL-3.0-or-later
/*
  Copyright 2017 Martin Koller, kollix@aon.at

  This file is part of BifrostShell.

  BifrostShell is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  BifrostShell is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with BifrostShell.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SysTrayNotifyItem_H_
#define _SysTrayNotifyItem_H_

#include <QLabel>
#include <QTimer>
#include <QMenu>

#include <QtThemeSupport/private/qdbusmenutypes_p.h>

class OrgKdeStatusNotifierItem;
class QDBusPendingCallWatcher;

class SysTrayNotifyItem : public QLabel {
    Q_OBJECT

    public:
        SysTrayNotifyItem(QWidget *parent, const QString &service, const QString &path);

        Q_SIGNALS:
        void initialized(SysTrayNotifyItem *);

    protected:
        void wheelEvent(QWheelEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;

    private Q_SLOTS:
        void startTimer();
        void fetchData();
        void fetchDataReply(QDBusPendingCallWatcher *w);
        void menuLayoutReply(QDBusPendingCallWatcher *w);

    private:
        QPixmap findPixmap(const QString &name, const QString &path);
        QPixmap applyOverlay(const QPixmap &pixmap, const QPixmap &overlay);
        void fillMenu(QMenu &menu, const QDBusMenuLayoutItem &item);

    private:
        QTimer fetchTimer;
        OrgKdeStatusNotifierItem *dbus;
        QString menuPath;
};

#endif
