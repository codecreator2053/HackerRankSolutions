#!bin/bash
declare -a countries

while read line || [ -n "$line" ]
do
    countries=("${countries[@]}" "$line")
done

countries=("${countries[@]}" "${countries[@]}" "${countries[@]}")
echo ${countries[@]}
