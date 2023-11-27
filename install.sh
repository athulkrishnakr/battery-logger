#!/bin/sh
gcc main.c -o battery_log #build binary

cp battery_log /usr/bin/

cp b_log.sh /usr/lib/systemd/system-sleep/

chmod +x /usr/lib/systemd/system-sleep/b_log.sh

cp 99-battery_log.rules /etc/udev/rules.d/

systemctl reload systemd-udevd