#!/bin/bash

echo -e "Run your counter simultaneously with another counter, both as normal processes.\nHow long does it take to count?\n"

echo "First normal process queued" &
./mem_normal.sh &
echo -e "Second normal process queued \n" &
./mem_normal.sh
