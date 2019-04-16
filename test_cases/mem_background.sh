#!/bin/bash
chrt --background -p 0 $$
./mem_load
echo -e "^^ Program: write_to_memory || scheduling: background || pid: $$\n"
