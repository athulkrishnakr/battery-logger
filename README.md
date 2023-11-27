# battery-logger
Simple program to log battery charge level on AC plug/unplug, suspend and resume events

## Dependencies
* systemd
* gcc

## Usage

clone the git repository and change to directory 'battery-logger'

make the script `install.sh` executable using `sudo chmod +x $PWD/install.sh`

install the program by running `./install.sh`

use `cat /etc/bat_log.log` to see logs
