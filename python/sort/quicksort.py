"""
In place quicksort implementation in Python 3
https://en.wikipedia.org/wiki/Quicksort
"""


def quicksort(lis, start, end):
    """
    Take a non-empty list and do in-place quicksort
    :param lis: list to be sorted
    :param start: starting index of the partition
    :param end: ending index of the partition (inclusive)
    """
    assert 0 <= start <= end < len(lis)
    if start == end:
        return

    pivot = lis[start]  # Taking first element as pivot
    lis[start], lis[end] = lis[end], lis[start]  # Exchange pivot and last element of partition

    # Now move all elements smaller than or equal to pivot to the left of partition
    # If element is smaller than pivot then swap leftmost un-swapped element with current element
    left_index = start
    iterator = start
    while iterator < end:  # pivot is in the end
        if lis[iterator] <= pivot:
            lis[left_index], lis[iterator] = lis[iterator], lis[left_index]
            left_index += 1
        iterator += 1

    # Now move pivot to its sorted position i.e. right after left partition
    lis[left_index], lis[end] = lis[end], lis[left_index]

    if left_index > start:
        # If left partition is non-empty then recursively sort that
        quicksort(lis, start, left_index - 1)
    if end > (left_index + 1):
        # If right partition is non-empty then recursively sort that
        quicksort(lis, left_index + 1, end)


def main():
    lis1 = [4, 1, 2, 3, 9]
    lis2 = [1]
    lis3 = [2, 2, 1, -1, 0, 4, 5, 2]

    quicksort(lis1, 0, 4)
    assert lis1 == [1, 2, 3, 4, 9]

    quicksort(lis2, 0, 0)
    assert lis2 == [1]

    quicksort(lis3, 0, 7)
    assert lis3 == [-1, 0, 1, 2, 2, 2, 4, 5]


if __name__ == '__main__':
    main()
