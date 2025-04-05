#!/bin/bash

PS="./push_swap"

GREEN="\033[1;32m"
RED="\033[1;31m"
NC="\033[0m"

function print_title() {
    echo -e "\n\033[1;34m$1\033[0m"
}

function test_valid() {
    echo -n "✔️  Test válido: $1 → "
    OUT=$(eval "$PS $1" 2>&1)
    if [[ "$OUT" != "Error" ]]; then
        echo -e "${GREEN}[OK]${NC}"
    else
        echo -e "${RED}[FAIL]${NC} → respondió: '$OUT'"
    fi
}

function test_invalid() {
    echo -n "❌ Test inválido: $1 → "
    OUT=$(eval "$PS $1" 2>&1)
    if [[ "$OUT" == "Error" ]]; then
        echo -e "${GREEN}[OK]${NC}"
    else
        echo -e "${RED}[FAIL]${NC} → respondió: '$OUT'"
    fi
}


print_title "✅ Tests válidos (no deben dar 'Error')"
test_valid "2147483647 2 4 7"
test_valid "99 -2147483648 23 545"
test_valid "\"2147483647 843 56544 24394\""
test_valid "\"3 2 1\""
test_valid "\"  3     2   1    \""
test_valid "\"3\" 2 \"1\""
test_valid "+1 -1 2"
test_valid "2147483647"
test_valid "-2147483648"
test_valid "\"2147483647 -2147483648\""

print_title "❌ Tests inválidos (deben dar 'Error')"
test_invalid "1 3 dog 35 80 -3"
test_invalid "a"
test_invalid "1 2 3 5 67b778 947"
test_invalid "\" 12 4 6 8 54fhd 4354\""
test_invalid "1 -- 45 32"
test_invalid "\"1 2 4 3\" 76 90 \"348 05\""
test_invalid "1 - 1"
test_invalid "1 --1"
test_invalid "1 ++1"
test_invalid "\"1 2 3a\""
test_invalid "2b"
test_invalid "4 \"5 6dog\""
test_invalid "\"1\t2\t3\""
test_invalid "\"1\n2\n3\""
test_invalid "+"
test_invalid "-"
test_invalid "\"1 2 + -\""
test_invalid "\"1 2 💥 3\""
test_invalid "\"#$%^&*()\""
test_invalid "1 3 58 9 3"
test_invalid "3 03"
test_invalid "\"49 128 50 38 49\""
test_invalid "1 01 001"
test_invalid "54867543867438 3"
test_invalid "-2147483647765 4 5"
test_invalid "\"214748364748385 28 47 29\""
test_invalid "2147483648"
test_invalid "999999999999999999999999"
test_invalid "\"2147483647 2147483648\""
echo -n "🧪 Test sin argumentos (debe estar en silencio) → "
OUT=$(eval "$PS" 2>&1)
if [[ -z "$OUT" ]]; then
    echo -e "${GREEN}[OK]${NC}"
else
    echo -e "${RED}[FAIL]${NC} → respondió: '$OUT'"
fi

echo -n "🧪 Test con espacios vacíos (debe estar en silencio) → "
OUT=$(eval "$PS \"           \"" 2>&1)
if [[ -z "$OUT" ]]; then
    echo -e "${GREEN}[OK]${NC}"
else
    echo -e "${RED}[FAIL]${NC} → respondió: '$OUT'"
fi

test_invalid "\"3 2\" \"1\""
