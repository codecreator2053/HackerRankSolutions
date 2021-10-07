#!bin/bash
friends[0]=lean
friends[1]='mr nobody'
friends[110]=emy
#echo ${friends[0]}

declare -a friends=('eman' 'mr_nobody' 'lean' 'jeshan' 'prom' 'yaman')
#echo ${friends[@]/nobody/somebody}

friends=("${friends[@]}" "rae" "gamar")

echo ${friends[4]}
unset friends[4]
echo ${friends[4]}

rem_pos=1
echo ${friends[@]}
friends=(${friends[@]:0:$rem_pos} ${friends[@]:$(($rem_pos + 1))})
echo ${friends[@]}

mitras=("${friends[@]}")
echo ${mitras[@]}

together=("${friends[@]}" "${mitras[@]}")
echo ${together[@]}

unset together
echo ${#together[@]}

filecontent=(`cat logfile.txt`)
for t in "${filecontent[@]}"
do
	echo $t
done
echo "Read file content!"
