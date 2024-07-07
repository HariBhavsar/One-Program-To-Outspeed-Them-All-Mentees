#!/bin/bash

# Directory containing the test files
TEST_DIR="tests"

# Executable
EXECUTABLE="./cdcl"

# Iterate over each file in the directory
for test_file in "$TEST_DIR"/*; do
    echo "Running $EXECUTABLE on $test_file..."
    
    # Use timeout to run the executable for a maximum of 5 seconds
    timeout 1s $EXECUTABLE < "$test_file"
    
    # Check the exit status of timeout
    if [ $? -eq 124 ]; then
        # Timeout occurred
        echo "Not completed!"
    fi
done
