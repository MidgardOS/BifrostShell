// SPDX-License-Identifier: GPL-3.0-or-later
/*
  Copyright 2017 - 2021 Martin Koller, kollix@aon.at

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

#include "DesktopWidget.hxx"

#include <QApplication>
#include <QCommandLineParser>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusPendingCall>

#include <KCrash>
#include <KLocalizedString>
#include <KAboutData>
#include <KDBusService>

int main(int argc, char **argv) {
#if QT_VERSION >= QT_VERSION_CHECK(5,7,0)
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles);
#endif

    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);

    KLocalizedString::setApplicationDomain("BifrostShell");

    KAboutData aboutData("BifrostShell",
                         i18n("MidgardOS Desktop Workspace"), "1.9",
                         i18n("A QtWidgets based basic desktop shell"),
                         KAboutLicense::GPL_V3,
                         i18n("Copyright 2017 - 2021 Martin Koller, Copyright 2022 Gary Greene"), QString(),
                         "https://www.linux-apps.com/p/1205621/"); // homepage

    aboutData.addAuthor("Gary Greene", "", "greeneg@yggdrasilsoft.com");
    aboutData.addAuthor("Martin Koller", "", "kollix@aon.at");

    KAboutData::setApplicationData(aboutData);

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);

    KCrash::setFlags(KCrash::AutoRestart);
    KDBusService programDBusService(KDBusService::Unique | KDBusService::NoExitOnFailure);

    DesktopWidget desktop;
    desktop.show();

    QDBusMessage ksplashProgressMessage = QDBusMessage::createMethodCall(
                                            QStringLiteral("org.kde.KSplash"),
                                            QStringLiteral("/KSplash"),
                                            QStringLiteral("org.kde.KSplash"),
                                            QStringLiteral("setStage"));
    ksplashProgressMessage.setArguments(QList<QVariant>() << QStringLiteral("desktop"));
    QDBusConnection::sessionBus().asyncCall(ksplashProgressMessage);

    return app.exec();
}
