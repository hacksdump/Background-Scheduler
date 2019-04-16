#!/bin/bash

echo -e "\nRun your counter as a SCHED_BACKGROUND process, simultaneously with another counter that is running as a normal processes.\nHow long does your SCHED_BACKGROUND process take to count?\n"
echo "Normal process queued" &
./mem_normal.sh &
echo -e "Background process queued\n" &
./mem_background.sh