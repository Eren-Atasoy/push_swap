#!/bin/bash

# Test script for push_swap
# Generates random numbers and tests the algorithm

echo "=== Push_swap Test Script ==="
echo ""

# Test 1: Small sets (3, 5, 10)
echo "Test 1: Small sets"
echo "Input: 2 1 3"
./push_swap 2 1 3 | wc -l
echo ""

# Test 2: 5 numbers
echo "Test 2: 5 random numbers"
ARG="5 2 8 1 9"
echo "Input: $ARG"
./push_swap $ARG | wc -l
echo ""

# Test 3: 10 numbers
echo "Test 3: 10 random numbers"
ARG="10 5 2 8 1 9 3 7 6 4"
echo "Input: $ARG"
./push_swap $ARG | wc -l
echo ""

# Test 4: Error handling
echo "Test 4: Error handling"
echo "Non-numeric input:"
./push_swap 1 2 abc 2>&1
echo "Duplicate numbers:"
./push_swap 1 2 2 2>&1
echo "Integer overflow:"
./push_swap 2147483648 2>&1
echo "No arguments:"
./push_swap
echo ""

echo "=== Tests Complete ==="

