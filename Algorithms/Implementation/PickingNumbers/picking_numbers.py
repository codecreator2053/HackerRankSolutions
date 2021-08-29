#!/bin/python3
import math
import os
import random
import re
import sys

#
# Complete the 'pickingNumbers' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def pickingNumbers(a):
    counts = {i:0 for i in range(1, 100)}
    max_ = max(a)
    for i in a:
        counts[i] += 1
    max_count = 0
    for i in range(1, max_):
        if max_count < counts[i] + counts[i+1]:
            max_count = counts[i] + counts[i+1]
    return max_count
    
    x = sorted(counts.items(), key=lambda x: x[1], reverse=True)
    print(x)
    # Write your code here

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
