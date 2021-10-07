#!bin/bash

declare -a countries
while IFS= read -r line
do
    # echo "$line"
    countries=("${countries[@]}" "$line")
done

echo ${countries[@]}
