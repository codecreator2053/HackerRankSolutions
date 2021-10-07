#!bin/bash
read num
arr=(`cat`)
declare -a counts

for i in {0..100}
do
    counts[$i]=0
done


for j in ${arr[@]};
do
    # echo $j
    ((counts[j]+=1))
done

# echo "${counts[@]}"

for i in {0..100};
do
    # echo "${counts[i]}"
    if [[ "${counts[i]}" == "1" ]];
    then
        echo "$i"
        break
    fi
done
