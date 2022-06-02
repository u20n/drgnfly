#!/bin/sh

# run headless, log PID, push to appropriate log file
if [[ $# < 1 ]]
then
  echo "[!] Need Script"
  exit -1
else
  nohup sh $1 > "./logs/$(date +"%m-%d-%Y_%T")_$1.log" 2>&1 & 
  echo "Task Begun, use \"pgrep -lnu $USER\" to see all running tasks"
fi
