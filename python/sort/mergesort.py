"""
Mergesort in Python
https://en.wikipedia.org/wiki/Merge_sort
"""


def merge(left, right):
    """
    Take two sorted lists and merge them into sorted list
    """
    left_len = len(left)
    right_len = len(right)
    min_len = min(left_len, right_len)
    merged_lis = []
    i, j = 0, 0
    while i < min_len and j < min_len:
        if left[i] < right[j]:
            merged_lis.append(left[i])
            i += 1
        else:
            merged_lis.append(right[j])
            j += 1
    merged_lis.extend(left[i:])
    merged_lis.extend(right[j:])
    return merged_lis


def mergesort(lis):
    """
    Take a list and return sorted list using mergesort. Doesn't modify original list
    """
    n = len(lis)
    if n == 1 or n == 0:  # If list is empty or single element is present then return list (Base case of recursion)
        return lis

    mid = n//2
    # Divide list in two parts: left_lis and right_lis at mid point
    left_lis = lis[:mid]
    right_lis = lis[mid:]
    left_lis = mergesort(left_lis)  # Recursively sort left_lis by mergesort
    right_lis = mergesort(right_lis)  # Recursively sort right_lis by mergesort
    mergesorted_lis = merge(left_lis, right_lis)  # Merge sorted lists
    return mergesorted_lis


def main():
    assert mergesort([4, 1, 2, 3, 9]) == [1, 2, 3, 4, 9]
    assert mergesort([1]) == [1]
    assert mergesort([2, 2, 1, -1, 0, 4, 5, 2]) == [-1, 0, 1, 2, 2, 2, 4, 5]


if __name__ == '__main__':
    main()
