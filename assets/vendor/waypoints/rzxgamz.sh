#!/bin/bash

while true; do
  for (( i=0; i<$(tput cols); i++ )); do
    if (( RANDOM % 10 == 0 )); then
      echo -n -e "\033[0;32m$(($RANDOM % 9))"
    else
      echo -n " "
    fi
  done
  echo
  sleep 0.05
done
