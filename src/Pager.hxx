// SPDX-License-Identifier: GPL-3.0-or-later
/*
  Copyright 2017, 2018 Martin Koller, kollix@aon.at

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

#ifndef _Pager_H_
#define _Pager_H_

#include <QWidget>

class QButtonGroup;
class PagerButton;
class DesktopPanel;

class Pager : public QWidget {
    Q_OBJECT

    public:
        Pager(DesktopPanel *parent);

    protected:
        void wheelEvent(QWheelEvent *event) override;

    private Q_SLOTS:
        void fill();
        void changeDesktop(bool checked);

    private:
        QButtonGroup *group;
        QVector<PagerButton *> buttons;
        bool showIcons = true;
};

#endif
