#!/bin/bash

echo -e "\nRepeat steps 1-3, but this time replace your counter with a process that reads/writes to a large file(s)."
echo -e "\n1. Run disk write as a normal process. Record how long it takes to write."
./disk_normal.sh
echo -e "\n2. Run disk write as a scheduled process. Record how long it takes to write."
./disk_background.sh
echo -e "\n3. Run disk write simultaneously with another disk write, both as normal processes.\nHow long does it take to write?"
echo "First normal write queued" &
./disk_normal.sh &
echo "Second normal write queued" &
./disk_normal.sh
