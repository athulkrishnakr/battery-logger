#!/bin/sh
if [ "${1}" == "pre" ]; then
  battery_log -s
elif [ "${1}" == "post" ]; then
  battery_log -r
fi