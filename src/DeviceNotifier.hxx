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

#ifndef _DeviceNotifier_H_
#define _DeviceNotifier_H_

#include "SysTrayItem.hxx"
#include <QTimer>

class DeviceList;

class DeviceNotifier : public SysTrayItem {
    Q_OBJECT

    public:
        DeviceNotifier(QWidget *parent);

    protected:
        QWidget *getDetailsList() override;
        bool eventFilter(QObject *watched, QEvent *event) override;

    private Q_SLOTS:
        void checkDeviceList();

    private:
        DeviceList *deviceList = nullptr;
        QTimer timer;
};

#endif