#!/bin/bash

error() {
  echo "Usage: remotish.sh -t <temp>"
  exit 1
}

[ "$1" != "-t" ] && error
[ ".$2" == "." ] && error

temp=$2
echo "{\"desired\": $temp, \"current\": 30, \"humidity\": 55}"
