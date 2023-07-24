./cache_infer.sh bsort100 bsort100  ARM lp_solve
./cache_infer.sh bsort100 expint  ARM lp_solve
./cache_infer.sh bsort100 statemate  ARM lp_solve
./cache_infer.sh bsort100 nsichneu  ARM lp_solve
echo -n "\n"
./cache_infer.sh expint bsort100  ARM lp_solve
./cache_infer.sh expint expint  ARM lp_solve
./cache_infer.sh expint statemate  ARM lp_solve
./cache_infer.sh expint nsichneu  ARM lp_solve
echo -n "\n"
./cache_infer.sh statemate bsort100  ARM lp_solve
./cache_infer.sh statemate expint  ARM lp_solve
./cache_infer.sh statemate statemate  ARM lp_solve
./cache_infer.sh statemate nsichneu  ARM lp_solve
echo -n "\n"
./cache_infer.sh nsichneu bsort100  ARM lp_solve
./cache_infer.sh nsichneu expint  ARM lp_solve
./cache_infer.sh nsichneu statemate  ARM lp_solve
./cache_infer.sh nsichneu nsichneu  ARM lp_solve
echo -n "\n"
