#!/bin/bash
START=$(date +%s%N)
# do something
# start your script work here
N_EXECUTION=$1
for ((i = 1; i<= $N_EXECUTION; i++)) do
	$2 > out
done
# your logic ends here
END=$(date +%s%N)
DIFF=$(echo "($END - $START) / ($N_EXECUTION*10^9)" | bc -l)
echo "$N_EXECUTION"
echo "$DIFF"
