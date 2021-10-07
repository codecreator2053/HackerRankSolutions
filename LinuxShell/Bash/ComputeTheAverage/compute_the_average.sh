#!bin/bash
read nums
count=0
sum=0

while [[ $count -lt $nums ]]
do
    read new_num
    ((sum=sum+new_num))
    ((count++))
done

printf "%.3f" $(echo "$sum / $count" | bc -l)
