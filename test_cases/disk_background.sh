#!/bin/bash
chrt --background -p 0 $$
./disk_load
echo -e "^^ Program: write_to_disk || scheduling: background || pid: $$\n"
