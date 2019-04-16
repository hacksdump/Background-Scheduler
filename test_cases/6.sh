#!/bin/bash

echo -e "Run your counter as a SCHED_BACKGROUND process, simultaneously with another counter that is running using nice at the lowest priority. \nHow long does your SCHED_BACKGROUND process take to count?\n"

echo "Normal nice with lowest priority queued" &
nice -n 19 ./mem_normal.sh &
echo -e "Background process queued\n" &
./mem_background.sh