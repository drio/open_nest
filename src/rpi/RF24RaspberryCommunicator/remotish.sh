#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

error() {
  echo "Usage: remotish.sh -t <temp>"
  exit 1
}

[ "$1" != "-t" ] && error
[ ".$2" == "." ] && error

temp=$2

#echo "{\"desired\": $temp, \"current\": 30, \"humidity\": 55}"
../RF24RaspberryCommunicator/remote -t $temp | tail -1
