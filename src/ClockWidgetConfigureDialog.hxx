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

#ifndef _ClockWidgetConfigureDialog_H_
#define _ClockWidgetConfigureDialog_H_

#include <QDialog>

class QTreeWidget;

class ClockWidgetConfigureDialog : public QDialog {
    Q_OBJECT

    public:
        ClockWidgetConfigureDialog(QWidget *parent, const QVector<QByteArray> &timeZoneIds);
        QVector<QByteArray> getSelectedTimeZoneIds() const;

    private:
        QTreeWidget *tree;
};

#endif
