if [ $# -lt 1 ] || [ $# -gt 5 ]
then
    echo "usage: $0 benchmark_name arch solver [-t]"
    exit 1
fi

HERE=`pwd`
#RESULT_DIR=${HERE}/TECSBench/$1
RESULT_DIR=${HERE}/benchmarks/$1

if [ ! -d "${RESULT_DIR}" ];then
    echo ">>> ERROR: The directory benchmarks/$1 does not exist ! exiting ...";
    exit -1
fi

if [ "$3" != "lp_solve" ] && [ "$3" != "cplex" ]
then
    echo ">>> ERROR: Unknown solver: $3 !, waiting for lp_solve or cplex."
    exit -1
fi

if [ "$2" = "MIPS" ] || [ "$2" = "ARM" ]
then
    cd ${RESULT_DIR}
    sed  -e "s#BENCH_DIR#${RESULT_DIR}#g" -e "s/X_BENCH/$1/g" -e "s/_SOLVER_/$3/g"  -e "s#_CROSS_COMPILER_DIR_#/home/yixian/heptane_svn/CROSS_COMPILERS/$2/bin#g" /home/yixian/heptane_svn/config_files/configWCET_template_$2.xml > configWCET.xml
    chmod gou+x configWCET.xml
    #echo "analysis.h The number of paras is \n$*\n"
    /home/yixian/heptane_svn/bin/HeptaneAnalysis $4 ./configWCET.xml $5 | tee cacheInfer.log
    #/home/yixian/heptane_svn/bin/HeptaneAnalysis $4 ./configWCET.xml  | tee analysis_$1_$2_$3.log

    #clean: uncomment if you want to clean
     #rm configWCET.xml
    cd $HERE
else
 echo ">>> ERROR: unknown target= $2, waiting for MIPS or ARM"
fi