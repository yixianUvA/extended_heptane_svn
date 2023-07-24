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

if [ $# -lt 1 ] || [ $# -gt 3 ]
then
    echo "Usage: $0 benchmark_name arch [-v]"
    exit 1
fi

HERE=`pwd`
RESULT_DIR=${HERE}/tacle-bench-master/bench/sequential/$1

if [ ! -d "${RESULT_DIR}" ];then
    echo ">>> ERROR: the directory benchmarks/$1 does not exist ! exiting ...";
    exit -1
fi

if [ "$2" = "MIPS" ] || [ "$2" = "ARM" ]
then
    if [ -d "/home/yixian/heptane_svn/CROSS_COMPILERS/$2" ];then
	cd ${RESULT_DIR}
        #configExtract.xml generation
	sed -e "s#BENCH_DIR#${RESULT_DIR}#g" -e "s#X_BENCH#$1#g" /home/yixian/heptane_svn/config_files/configExtract_template_$2.xml > configExtract.xml
	chmod gou+x configExtract.xml
         #extraction
    #echo "extract.h The paras are \n$*\n"
	echo "/home/yixian/heptane_svn/bin/HeptaneExtract $3 configExtract.xml  | tee extract_$1_$2.log"
	/home/yixian/heptane_svn/bin/HeptaneExtract $3 configExtract.xml  | tee extract_$1_$2.log
	
    #clean: uncomment if you want to clean
    #rm config.xml
    #rm annot.xml
	cd $HERE
    else
	echo ">>> ERROR: the $2 cross compiler does not exist in /home/yixian/heptane_svn/CROSS_COMPILERS !!! "
    fi
else
    echo ">>> ERROR: unknown target= $2, waiting for MIPS or ARM"
fi


