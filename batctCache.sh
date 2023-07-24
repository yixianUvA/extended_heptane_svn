#!/bin/bash
path=./benchmarks
files=$(ls $path)
for filename in $files
do 
   echo -e $filename >> WCET1.txt
   echo -e $filename >> original_analysis.txt
done
for filename in $files
do 
   echo -e $filename >> L2_128.txt
   echo -e $filename >> CAC_CHMC_Information.txt
   echo -e $filename >> CAC_CHMC_Information.txt
   echo -e $filename >> CAC_CHMC_Information.txt
   echo -e $filename >> CAC_CHMC_Information.txt
   echo -e $filename >> CAC_CHMC_Information.txt
   
   for interfer in $files
   do
   # echo -e $filename >> WCET1.txt
   #./run_benchmark.sh $filename ARM lp_solve
   #echo $filename > filename.txt
   echo -e "$filename   $interfer" >> infertimeprint.txt
   ./cache_infer.sh $filename $interfer ARM lp_solve
   #./cache_infer.sh ud ud ARM lp_solve
   done
done
