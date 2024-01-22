#!/bin/bash

GREEN='\e[32m'
NC='\e[0m'
RED='\e[31m'
EXE=s21_cat.c

printf "${GREEN}-----RUNNING TESTS-----${NC}\n"

cat test.txt >a
./s21_cat test.txt >b
result=$(diff a b)
failed=0
i=1

# TEST 1
if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 2
cat -b test1.txt >a
./s21_cat -b test1.txt >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 3
cat -n test2.txt >a
./s21_cat -n test2.txt >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 4
cat -s test3.txt >a
./s21_cat -s test3.txt >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 5
cat -t test.txt >a
./s21_cat -t test.txt >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 6
cat -e test.txt >a
./s21_cat -e test.txt >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 7
FILE=weirdo.txt
FLAGS=
cat $FILE >a
./s21_cat $FILE >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 8
FILE=weirdo.txt
FLAGS=-b
cat $FLAGS $FILE >a
./s21_cat $FLAGS $FILE >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 9
FILE=weirdo.txt
FLAGS=-n
cat $FLAGS $FILE >a
./s21_cat $FLAGS $FILE >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 10
FILE=weirdo.txt
FLAGS=-s
cat $FLAGS $FILE >a
./s21_cat $FLAGS $FILE >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

# TEST 11
FILE=weirdo.txt
FLAGS=-t
cat $FLAGS $FILE >a
./s21_cat $FLAGS $FILE >b
result=$(diff a b)

if [ $? -eq 0 ]; then
	printf " TEST #$i ${GREEN}PASSED${NC}\n"
else
	printf " TEST #$i ${RED}FAILED${NC}\n"
	printf "$result"
	((failed++))
fi

((i++))

printf " ${GREEN}-----DONE[$((i - failed))/$((i))]-----${NC}\n"

rm a b