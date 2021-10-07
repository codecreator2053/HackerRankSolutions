#!bin/bash
countries=($(cat))
echo "${countries[@]/[A-Z]/.}"
# or echo "${countries[@]/[[:upper:]]/.}"
