# https://www.hackerrank.com/challenges/count-triplets-1/problem

from logging import lastResort


def countTriplets(arr, r):
    results = 0
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            for k in range(j+1, len(arr)):
                if arr[i] * r == arr[j] and arr[j]*r == arr[k]:
                    results += 1
    return results


"""This solution doesn't work due to the constraint i<j<k"""
# Complete the countTriplets function below.
# def countTriplets(arr, r):
#     def binSearch(array, l, r, target):
#         if target < array[l] or target > array[r] or r < l:
#             return -1
#         mid = l+(r-l)//2
#         if array[mid] > target:
#             return binSearch(array, l, mid, target)
#         elif array[mid] < target:
#             return binSearch(array, mid+1, r, target)
#         else:
#             return mid

#     def get_num_count(arr, idx):
#         count = 0
#         l_end = idx - 1
#         r_end = idx+1
#         while (l_end > 0 and arr[l_end] == arr[idx]):
#             count += 1
#             l_end -= 1
#         while (r_end < len(arr) and arr[r_end] == arr[idx]):
#             count += 1
#             r_end += 1
#         return count+1, l_end+1, r_end-1

#     result = 0
#     arr.sort()
#     print(arr[0], arr[-1])
#     prev = -float('inf')

#     for i in range(len(arr)):
#         if prev == arr[i]:
#             continue

#         next_idx = binSearch(arr, 0, len(arr)-1, arr[i]*r)
#         last_idx = binSearch(arr, 0, len(arr)-1, arr[i]*r*r)

#         # print(next_idx, last_idx)
#         if next_idx != -1:
#             last_idx != -1:
#             count1 = get_num_count(arr, i)
#             if r == 1:
#                 result += int((count1 * (count1-1) * (count1-2))/6)
#             else:
#                 count2 = get_num_count(arr, next_idx)
#                 count3 = get_num_count(arr, last_idx)
#                 result += count1 * count2 * count3
#         if i == 0:
#             print(arr[i],)
#         prev = arr[i]
#     return result


# Complete the countTriplets function below.
def countTriplets(arr, r):
    val2idx = {}
    result = 0
    for i, num in enumerate(arr):
        if num in val2idx:
            val2idx[num].append(i)
        else:
            val2idx[num] = [i]
    last_sum = 0

    for i in range(len(arr)):

        mid_num = arr[i] * r
        last_num = arr[i] * r * r

        cur_candidates = val2idx[arr[i]]
        if mid_num in val2idx and last_num in val2idx:
            mid_candidates = [c for c in val2idx[mid_num] if c > i]
            if not mid_candidates:
                continue

            max_mid = max(mid_candidates)
            last_candidates = [c for c in val2idx[last_num] if c > max_mid]
            if not last_candidates:
                continue
            last_sum = len(mid_candidates) * len(last_candidates)
            result += last_sum

    return result


# input = [int(n) for n in open("data.txt", "r").read().split()]
input = [1, 2, 2, 4]
# print(len(input))
r = 2
print(countTriplets(input, r))
