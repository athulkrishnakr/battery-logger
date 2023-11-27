#!/bin/sh
gcc main.c -o battery_log #build binary

cp $PWD/battery_log /usr/bin/

cp $PWD/b_log.sh /usr/lib/systemd/system-sleep/

chmod +x /usr/lib/systemd/system-sleep/b_log.sh

cp $PWD/99-battery_log.rules /etc/udev/rules.d/

systemctl reload systemd-udevd