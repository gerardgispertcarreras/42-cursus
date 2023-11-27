# Set program arguments
set args 0 1 2 3 4 5 6 7

# Breakpoints
b push_swap.c:25
b push_swap.c:30

# Define printA
define printA
set $x = 0
while $x < A->size
    print A->values[$x]
    set $x = $x + 1
end
end

# Define printB
define printB
set $x = 0
while $x < B->size
    print B->values[$x]
    set $x = $x + 1
end
end
