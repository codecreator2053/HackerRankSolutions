#!bin/bash

declare -A arr

initialize(){
    for r in {0..62}; do
        for c in {0..99}; do
            arr[$r,$c]="_"
        done
    done
}
print(){
    for r in {0..62}; do
        for c in {0..99}; do
            echo -n ${arr[$r,$c]}
        done
        echo
    done
}

draw(){
    local cnt=$1
    local r=$2
    local c=$3
    for ((i=0; i<cnt; i++ )); do
        arr[$r,$c]=1
        (( r -= 1 ))
    done
    for ((i=0; i<cnt; i++ )); do
        arr[$r,$((c-i-1))]=1
        arr[$r,$((c+i+1))]=1
        (( r -= 1 ))
    done

    if [[ $4 -gt 1 ]]; then
        draw $(($cnt>>1)) $r $(($c-cnt)) $(($4-1))
        draw $(($cnt>>1)) $r $(($c+cnt)) $(($4-1))
    fi
}

initialize
read x

if [[ $x -gt 0 ]]; then
    draw 16 62 49 x
fi

print
