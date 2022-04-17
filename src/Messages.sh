#! /usr/bin/env bash
$EXTRACTRC `find . -name \*.ui` >> rc.cpp || exit 11
$XGETTEXT *.cxx rc.cpp -o $podir/BifrostShell.pot
rm -f rc.cpp
