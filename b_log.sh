#!/bin/sh
if [ "${1}" == "pre" ]; then
  /usr/bin/battery_log -s
elif [ "${1}" == "post" ]; then
  /usr/bin/battery_log -r
fi