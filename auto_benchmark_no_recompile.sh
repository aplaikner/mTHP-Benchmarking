#!/bin/bash
echo $(date)
first=$2
last=$3

rm -f output.txt
rm -f outputs/*
rm -f graphs/*

benchmark_dir="benchmarks/thesis/"
dirlen=${#benchmark_dir}


#mthp_settings=("enable_all_hugepages.sh" "disable_all_but_pmd.sh")
mthp_settings=("enable_all_hugepages.sh")
#mthp_settings=("enable_all_but_pmd_hugepages.sh" "enable_all_hugepages.sh" "disable_all_but_pmd.sh")

for setting in "${mthp_settings[@]}"; do
	sh "settings/$setting"
	for filename in "$benchmark_dir"*; do
	  if [[ -x "$filename" ]]; then  # Check if it's an executable
 	    clean=${filename:$dirlen}
	    if ((${clean#0} >= $first )) && ((${clean#0} <= $last)); then
		    echo "Benchmark: $filename" >> "output.txt" 
		    echo "Setting: $setting" >> "output.txt" 
		    for((i=0; i < $1; i++)); do
			echo "Run: $i" >> "output.txt"
			./"$filename" &   # Run in background with '&'
			pid=$!
			sh mthp_stats $pid >> "output.txt"
			sed -i '$d' "output.txt"
		    done
		    echo $filename
            fi
	  fi
	done
done

echo $(date)
