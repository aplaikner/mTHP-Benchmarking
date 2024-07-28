#!/bin/bash

# Name of the Python script
PYTHON_SCRIPT="testscript.py"

# Number of times to run the script
NUM_RUNS=50

# Variable to accumulate total time
total_time=0

# Loop to execute the Python script 50 times
for i in $(seq 1 $NUM_RUNS)
do
    # Time the execution of the Python script
    start_time=$(date +%s%N)
    /foo/bin/python3 $PYTHON_SCRIPT
    end_time=$(date +%s%N)

    # Calculate the duration in nanoseconds
    duration=$((end_time - start_time))

    # Convert the duration to seconds (float)
    duration_sec=$(echo "scale=6; $duration / 1000000000" | bc)

    # Add the duration to the total time
    total_time=$(echo "scale=6; $total_time + $duration_sec" | bc)

    echo "Run #$i: $duration_sec seconds"
done

# Calculate the average time
average_time=$(echo "scale=6; $total_time / $NUM_RUNS" | bc)

# Print the average time
echo "Average time: $average_time seconds"

