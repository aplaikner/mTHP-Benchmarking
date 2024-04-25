#!/bin/bash

first=$2
last=$3

rm -f output.txt
rm -f outputs/*
rm -f graphs/*
# Compile directory path
benchmark_dir="benchmarks/newer/"
dirlen=${#benchmark_dir}
echo $dirlen 

# Compile all benchmark*.c files
for file in "$benchmark_dir"*.c; do
  # Extract filename without extension
  filename="${file%.*}"
  gcc -o "$filename" "$file" -Wall  # Adjust output path
  if [ $? -ne 0 ]; then
    echo "Error compiling $file"
    exit 1
  fi
done

echo "Compilation complete!"

#mthp_settings=("enable_all_hugepages.sh" "disable_all_but_pmd.sh")
mthp_settings=("enable_all_but_pmd_hugepages.sh" "enable_all_hugepages.sh" "disable_all_but_pmd.sh")

for setting in "${mthp_settings[@]}"; do
	sh "mthp_settings/$setting"
	for filename in "$benchmark_dir"*; do
	  if [[ -x "$filename" ]]; then  # Check if it's an executable
 	    clean=${filename:$dirlen}
	    if (($clean >= $first )) && (($clean <= $last)); then
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

for filename in "$benchmark_dir"/*; do
	  if [[ -x "$filename" ]]; then  # Check if it's an executable
	    rm -f $filename
	  fi
done
