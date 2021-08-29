#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

def climbingLeaderboard(ranked, player):
    # def binary_search(new_scores, l, r, target):
    #     m = l + (r-l)//2
    #     if new_scores[m] == target:
    #         return m
    #     elif new_scores[m] > target and target > new_scores[m-1]:
    #         return m - 1
    #     elif new_scores[m+1] > target and target > new_scores[m]:
    #         return m
    #     elif new_scores[m] > target:
    #         return binary_search(new_scores, l, m-1, target)
    #     else:
    #         return binary_search(new_scores, m+1, r, target)
        
    new_ranks = []  
    unique_scores = sorted(set(ranked), reverse=True)
            
    check_area = len(unique_scores)-1
    for score in player:
        # print(score, check_area)
        if score < unique_scores[-1]:
            new_ranks.append(len(unique_scores)+1)
            continue
        elif score >= unique_scores[0]:
            new_ranks.append(1)
            continue
        for j in range(check_area, -1, -1):
            if score < unique_scores[j]:
                new_ranks.append(j+2)
                check_area = j+1
                break
        # print(new_ranks)

    #Much better solution
    # new_ranks = []  
    # unique_scores = sorted(set(ranked))
    
    # check_area = 0
    # for score in player:
    #     while (check_area<len(unique_scores) and score>=unique_scores[check_area]):
    #         check_area+=1
    #     new_ranks.append(len(unique_scores)+1-check_area)
                

    #Doesn't work for some long test cases
    # for score in player:
    #     if score > unique_scores[-1]:
    #         new_ranks.append(1)
    #     elif score < unique_scores[0]:
    #         new_ranks.append(len(unique_scores)+1)
    #     else:
    #         # print('got here')
    #         idx = binary_search(unique_scores, 0, len(unique_scores)-1, score)
    #         new_ranks.append(len(unique_scores)-idx)
    #     # print(new_ranks)
    return new_ranks
    # Write your code here

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()