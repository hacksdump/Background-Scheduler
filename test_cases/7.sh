#!/bin/bash

echo -e "\nRun your counter as a SCHED_BACKGROUND process, simultaneously with another counter that is running using nice at the highest priority.\nHow long does your SCHED_BACKGROUND process take to count?\n"

echo "Normal nice with highest priority queued" &
sudo nice -n -20 ./mem_normal.sh &
echo -e "Background process queued\n" &
./mem_background.sh