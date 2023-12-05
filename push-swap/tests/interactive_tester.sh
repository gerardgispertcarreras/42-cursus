#!/bin/bash

# Prompt for the length of the numbers array
read -p "Enter the length of the numbers array: " array_length

# Populate the array with numbers from 0 to array_length-1
numbers=($(seq 0 $((array_length-1))))

# Prompt for the number of calls to make
read -p "Enter the number of calls to make: " num_calls

# Prompt for the line threshold for counting as exceeded
read -p "Enter the line threshold for counting as exceeded: " line_threshold

# Function to generate a random permutation of an array
function shuffle {
  local array=("$@")
  local size=${#array[@]}
  for ((i=size-1; i>0; i--)); do
    rand_index=$((RANDOM % (i+1)))
    # Swap elements
    temp=${array[i]}
    array[i]=${array[rand_index]}
    array[rand_index]=$temp
  done
  echo "${array[@]}"
}

# Variables to store min, max, and sum of lines
min_lines=999999  # initialize to a large value
max_lines=0
total_lines=0

# Variables to store the count of "OK" and "KO"
ok_count=0
ko_count=0

# Variable to store the count of outputs exceeding the line threshold
exceed_count=0

# Run push_swap with num_calls random permutations
for ((i=1; i<=$num_calls; i++))
do
  shuffled_numbers=($(shuffle "${numbers[@]}"))

  # Capture the lines outputted by push_swap to a file
  push_swap_output_file="push_swap_output.txt"
  ./push_swap ${shuffled_numbers[@]} > "$push_swap_output_file"

  # Capture the lines outputted by push_swap
  lines=$(wc -l < "$push_swap_output_file")

  # Update min, max, and sum
  if ((lines < min_lines)); then
    min_lines=$lines
  fi

  if ((lines > max_lines)); then
    max_lines=$lines
  fi

  total_lines=$((total_lines + lines))

  # Execute checker_linux and count "OK" and "KO"
  checker_output=$(./checker_linux ${shuffled_numbers[@]} < "$push_swap_output_file")
  if [[ "$checker_output" == "OK" ]]; then
    ((ok_count++))
  elif [[ "$checker_output" == "KO" ]]; then
    ((ko_count++))
  fi
 
  # Check if lines exceed the threshold
  if ((lines >= line_threshold)); then
    ((exceed_count++))
  fi

done
# Remove the push_swap output file
rm -f "$push_swap_output_file"

# Calculate average lines
average_lines=$((total_lines / num_calls))

# Print the results
echo "Minimum Lines: $min_lines"
echo "Maximum Lines: $max_lines"
echo "Average Lines: $average_lines"
echo "OK Count: $ok_count"
echo "KO Count: $ko_count"
echo "Exceed $line_threshold Lines Count: $exceed_count"
