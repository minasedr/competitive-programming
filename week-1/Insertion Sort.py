#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'insertionSort1' function below.
#
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY arr
#
n = int(input().strip())

arr = list(map(int, input().rstrip().split()))


def insertionSort1(n, arr):
    # Write your code here
    for i in range(n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            for k in arr:
                print(k, end=' ')
            print()
            j -= 1
        arr[j+1] = key
    for k in arr:
        print(k, end=' ')
insertionSort1(n, arr)
