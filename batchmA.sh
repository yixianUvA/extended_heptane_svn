#!/bin/bash
path=./benchmarks
files=$(ls $path)
for filename in $files
do 
   echo -e $filename >> WCET1.txt
   echo -e $filename >> original_analysis.txt
done
#cd $path
#files=$(ls -F |grep "/$")
#files=$(ls -d *)
#files=$(ls -l|grep "^d" |awk '{print $8}')

for filename in $files
do  
   echo -e $filename >> original_analysis.txt
   ./run_benchmark.sh $filename ARM lp_solve
done
# for filename in $files
# do 
#    echo -e $filename >> ../WCET1.txt
#    #./run_benchmark.sh $filename ARM lp_solve
#    echo $filename > ../filename.txt
# done
