"""
Binary search in a sorted list
https://en.wikipedia.org/wiki/Binary_search_algorithm
"""
from bisect import bisect_left


def pythonic_binary_search(lis, elem):
    """
    Return the left most index of matched element in lis with elem using bisect_left
    Return -1 if match not found
    :param lis: sorted list
    :param elem: element to search
    """
    index = bisect_left(lis, elem)
    if index != len(lis) and lis[index] == elem:
        return index
    return -1


def binary_search(lis, elem, start, end):
    """
    Return index of matched position of elem in lis between index start and end (inclusive) or return -1
    :param lis: Sorted list
    :param elem: element to search
    """
    assert 0 <= start <= end < len(lis)
    if end == start:
        # If there is only one element to search, check that element only
        if lis[start] == elem:
            return start
        return -1

    mid = (start + end) // 2
    mid_elem = lis[mid]
    if mid_elem == elem:
        return mid
    if mid_elem < elem:
        # If middle element is less than our required element then search in the right of array
        if end > mid:
            return binary_search(lis, elem, mid + 1, end)
        return -1
    if mid_elem > elem:
        # If middle element is larger than our required element then search in the left of array
        if start < mid:
            return binary_search(lis, elem, start, mid - 1)
        return -1


def main():
    lis1 = [1, 2, 3, 4, 6, 7, 9]
    assert binary_search(lis1, 5, 0, 5) == -1
    assert pythonic_binary_search(lis1, 5) == -1

    lis2 = [-1, 0, 1, 5, 6, 9, 15, 15]
    assert pythonic_binary_search(lis2, 15) == 6
    assert binary_search(lis2, 15, 0, 7) != -1  # Our custom binary search can't tell the left most index

    lis3 = [-1, 0, 0, 0, 0, 1]
    assert pythonic_binary_search(lis3, 0) == 1
    assert binary_search(lis3, 0, 0, 5) != -1


if __name__ == '__main__':
    main()
