#!/bin/sh
#
# profile.d script for bash-like shells
# defaults sudo -s to spawn sudosh rather than default shell

# if you have shell_noargs enabled for sudo
# set SHELL_NOARGS to 1 below
SHELL_NOARGS=0

SUDO=$( which sudo )

function sudo() {
    local ARGS
    [ "$#" -lt 1 -a "$SHELL_NOARGS" -eq 1 ] && ARGS="$ARGS sudosh"
    for arg in $*; do
        if [ "$arg" = "-s" ]; then
            ARGS="$ARGS sudosh" && shift
        else
            ARGS="$ARGS $1" && shift
        fi
    done
    $SUDO $ARGS
}
