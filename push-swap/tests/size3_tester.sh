#!/bin/bash

function generate_permutations {
    local numbers=("$@")
    local n=${#numbers[@]}

    if [ $n -eq 1 ]; then
        echo "${numbers[0]}"
    else
        for ((i = 0; i < $n; i++)); do
            local current=${numbers[$i]}
            local rest=("${numbers[@:0:i]}" "${numbers[@]:i+1}")
            local permutations_of_rest=($(generate_permutations "${rest[@]}"))
            
            for perm in "${permutations_of_rest[@]}"; do
                echo "$current $perm"
            done
        done
    fi
}

echo "Permutations of 1:"
permutations_1=($(generate_permutations 1))
for perm in "${permutations_1[@]}"; do
    echo "$perm"
done

echo -e "\nPermutations of 1 and 2:"
permutations_12=($(generate_permutations 1 2))
for perm in "${permutations_12[@]}"; do
    echo "$perm"
done

echo -e "\nPermutations of 1, 2, and 3:"
permutations_123=($(generate_permutations 1 2 3))
for perm in "${permutations_123[@]}"; do
    echo "$perm"
done
