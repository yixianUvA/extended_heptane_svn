if [ $# -lt 1 ] || [ $# -gt 5 ]
then
    echo "usage: $0 benchmark_name arch solver [-q]"
    echo "   -q for quiet "
    exit 1
fi

#echo "\nThe number of paras are $#\n"
if [ "$#" = 5 ]
    then
    if [ "$5" = "-q" ]
	then
	./extract.sh $1 $3 
	./analysis.sh $1 $3 $4 -t
    else
	echo "usage: $0 benchmark_name arch solver [-q]"
	exit 1
    fi
else
    ./extract.sh $1 $3 
	./analysis.sh $1 $3 $4 -t
fi


echo "\nThis is the second program analysis\n"
if [ "$#" = 5 ]
    then
    if [ "$5" = "-q" ]
	then
	./extract.sh $2 $3 
	./analysis.sh $2 $3 $4 -t
    else
	echo "usage: $0 benchmark_name arch solver [-q]"
	exit 1
    fi
else
    ./extract.sh $2 $3 
	./analysis.sh $2 $3 $4 -t
fi

echo "\nThis is the cacheinterence analysis\n"
if [ "$#" = 5 ]
    then
    if [ "$5" = "-q" ]
	then
	./extract.sh $1 $3 
	./analysis_inter.sh $1 $3 $4 -t $2
    else
	echo "usage: $0 benchmark_name arch solver [-q]"
	exit 1
    fi
else
    ./extract.sh $1 $3 
	./analysis_inter.sh $1 $3 $4 -t $2
fi