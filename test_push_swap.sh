#!/bin/bash

PS="./push_swap"
CHECKER="./checker_linux"

function print_title() {
    echo -e "\n\033[1;34m$1\033[0m"
}

function run_and_check() {
    ARG="$1"
    EXPECT="$2"
    echo -n "Test: ./push_swap $ARG → "

    OUT=$($PS $ARG 2>&1)
    if [[ "$OUT" == "$EXPECT" ]]; then
        echo -e "\033[1;32m[OK]\033[0m"
    else
        echo -e "\033[1;31m[FAIL]\033[0m Output: '$OUT'"
    fi
}

function run_checker() {
    ARG="$1"
    OUT=$($PS $ARG)
    RES=$(echo "$OUT" | $CHECKER $ARG)
    echo "ARG: $ARG"
    echo "Output: $RES"
    echo "Instructions count: $(echo "$OUT" | wc -l)"
    echo ""
}

function run_valgrind() {
    ARG="$1"
    echo -e "Testing memory leaks with valgrind for: \033[1;33m$ARG\033[0m"
    valgrind --leak-check=full --error-exitcode=1 $PS $ARG > /dev/null 2>&1
    if [[ $? -eq 0 ]]; then
        echo -e "\033[1;32mNo leaks detected\033[0m"
    else
        echo -e "\033[1;31mMemory leaks found!\033[0m"
    fi
}

print_title "❌ Error handling tests"
run_and_check "1 3 dog 35" "Error"
run_and_check "1 3 3" "Error"
run_and_check "54867543867438 3" "Error"
run_and_check "" ""

# ✅ CORREGIDO: Usamos checker para entrada válida
run_checker "1 3 5 +9 20 -4"

print_title "✅ Identity tests (already sorted)"
run_and_check "42" ""
run_and_check "0 1 2 3" ""
run_and_check "0 1 2 3 4 5 6 7 8 9" ""

print_title "🔁 Valid sorting + checker test"
run_checker "2 1 0"
run_checker "1 5 2 4 3"
run_checker "3 4 6 8 9 74 -56 +495"
run_checker "2147483647 2 4 7"
run_checker "99 -2147483648 23 545"

print_title "🧠 Random middle (100 nums)"
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
run_checker "$ARG"

print_title "🧠 Random advanced (500 nums)"
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
run_checker "$ARG"

print_title "💧 Valgrind (memory leaks)"
run_valgrind "1 2 3 4 5"
run_valgrind "3 2 1"
run_valgrind "1 3 2 6 5"
run_valgrind "0 1 2 3 4 5 6 7 8 9"
