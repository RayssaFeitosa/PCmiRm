#!/bin/bash

max=$1 # Set here the maximum size of mirsets
min=$2   

for ((i=min;i<max;i++))
do
    j=$((i+1))
    ./modules_identification/remove_redundance_of_bigger_mirsets_based_on_smaller_mirsets.py ./data/aux/modules_${j}mirs.csv $j 0 ./data/aux/modules_${i}mirs.csv $i 0
done    
