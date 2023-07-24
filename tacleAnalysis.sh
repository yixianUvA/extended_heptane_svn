#!/bin/sh

#---------------------------------------------------------------------
#
# Copyright IRISA, 2003-2017
#
# This file is part of Heptane, a tool for Worst-Case Execution Time (WCET)
# estimation.
# APP deposit IDDN.FR.001.510039.000.S.P.2003.000.10600
#
# Heptane is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Heptane is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details (COPYING.txt).
#
# See CREDITS.txt for credits of authorship
#
#---------------------------------------------------------------------

if [ $# -lt 1 ] || [ $# -gt 4 ]
then
    echo "usage: $0 benchmark_name arch solver [-t]"
    exit 1
fi

HERE=`pwd`
RESULT_DIR=${HERE}/tacle-bench-master/$1

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
    /home/yixian/heptane_svn/bin/HeptaneAnalysis $4 ./configWCET.xml | tee analysis_$2_$3.log
    #/home/yixian/heptane_svn/bin/HeptaneAnalysis $4 ./configWCET.xml  | tee analysis_$1_$2_$3.log

    #clean: uncomment if you want to clean
     #rm configWCET.xml
    cd $HERE
else
 echo ">>> ERROR: unknown target= $2, waiting for MIPS or ARM"
fi
