#!bin/bash
declare -a countries

while read line
do
    countries=("${countries[@]}" "$line")
done

countries=("${countries[@]/*[aA]*/}")
echo ${countries[@]}
