#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "The maximum value of a process ID  : $pid_max"
