#!/bin/bash
path=./tacle-bench-master
files=$(ls $path)
for filename in $files
do 
   echo -e $filename >> WCET1.txt
done
for filename in $files
do 
   # echo -e $filename >> WCET1.txt
   ./tacleRun.sh $filename ARM lp_solve
   #echo $filename > filename.txt
done
