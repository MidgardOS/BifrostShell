# BifrostShell - A fork of liquidshell

Forked by: Gary Greene, `greeneg at altimatos.com`
liquidshell Author: Martin Koller, `kollix at aon.at`

## Introduction

BifrostShell is a fork with major UX changes from it's parent, [liquidshell](https://github.com/KDE/liquidshell). It retains the goal of `BifrostShell` to be a basic Desktop Shell implemented using only QtWidgets.

The main changes:
- UI changes to the panel to be more similar aesthetically and functionality to KDE3's kicker
- Redesign the launch menu to mimic more of the UI of Plasma5's new Kickoff menu
- Add desktop icon support
- Extend the wallpaper settings to allow for either per desktop or same on all desktop spaces
- Replace use of krunner with a dialog that more closely resembles KDE3's krun dialog

Main Features:

- Wallpaper per virtual desktop
- Weather, Disk Usage, Picture Frame Applets (per virtual desktop or on all)
- No animations, low memory and CPU footprint
- Instant startup
- QtWidgets based, therefore follows widget style from systemsettings
- Icons are used from your globally defined icon theme from systemsettings
- Colors are used from your globally defined color theme from systemsettings
- Can additionally be styled with css by passing the commandline option -stylesheet filename.css
  (see included example stylesheet.css)
- uses existing KDE Frameworks dialogs for most configurations, e.g. StartMenu, Virtual Desktops, Bluetooth, Network

The panel layout of BifrostShell uses a single bottom DesktopPanel, containing:
- StartMenu (allowing drag of entries into konqueror/dolphin to configure QuickLaunch or AppMenu entries)
- QuickLaunch (showing icons for .desktop files from a configurable folder)
- AppMenu (showing .desktop files in a menu from a configurable folder, defaults to users desktop folder)
- Pager (for switching virtual desktops)
- WindowList (Popup showing all open windows on all desktops)
- TaskBar (showing windows on the current desktop, allowing drag of an entry onto the Pager to move to a different desktop)
- Lock/Logout buttons
- SysLoad widget including CPU, Memory, Swap and Network bars, live updated tooltip
- SysTray with integrated Network-, Notifications-, Device Notifier-, Bluetooth-, Battery- display.
- PackageKit integration.
- Clock widget (with calendar popup, tooltip for selected cities)
- DeviceList also shows devices connected and paired with KDEConnect.
- Display of StatusNotifier items from other applications (no legacy embedded icons yet).
- Notifications kept in a history list for some minutes, including timestamp and text selectable per mouse

## Dependencies for Building BifrostShell

BifrostShell requires the following development packages on openSUSE to build:

- PackageKit-Qt5-devel
- bluez-qt-devel
- karchive-devel
- kcmutils-devel
- kconfig-devel
- kcrash-devel
- kdbusaddons-devel
- kdoctools-devel
- ki18n-devel
- kiconthemes-devel
- kio-devel
- kitemviews-devel
- knewstuff-devel
- knotifications-devel
- kservice-devel
- kwidgetsaddons-devel
- kwindowsystem-devel
- libKF5NetworkManagerQt-devel
- libQt5Widgets-devel
- libqt5-qtx11extras-devel
- libQt5PlatformSupport-devel-static
- libQt5PlatformSupport-private-headers-devel
- solid-devel

## Runtime Dependencies

The following packages are required for BifrostShell to run:

- kmenuedit5
- kscreen5
- plasma-nm5
- plasma-workspace

Additionally, the following are recommeneded to allow BifrostShell to work better:

- ksysguard5
- kwin5
- bluedevil5

## Building from source

To build BifrostShell, run the following commands:

```sh
mkdir build
cd build
cmake ../src
make
```

## Configuration

To change the appearance details (beside the widget style, fonts, icon theme and color scheme selected via the systemsettings), you can use the commandline option `--stylesheet filename.css` to provide a Qt CSS widget stylesheet. For some examples see the included `stylesheet.css` file.

For details about the syntax and possible options see the [Qt5 documentation](http://doc.qt.io/qt-5/stylesheet.html).

---

To explicitly disable the Software-Updater (packagekit based), set the `~/.config/BifrostShellrc` config file entry:

```ini
[SoftwareUpdates]
enabled=false
```

The config file and a default entry will be created at first run of BifrostShell.

---

To explicitly disable icons shown on the Pager buttons, set the `~/.config/BifrostShellrc` config file entry:

```ini
[Pager]
showIcons=true
```

The config file and a default entry will be created at first run of BifrostShell.
