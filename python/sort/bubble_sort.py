"""
Bubble sort implementation in Python 3
https://en.wikipedia.org/wiki/Bubble_sort
"""


def bubble_sort(lis):
    """
    Implementation of bubble sort.
    :param lis: list to be sorted
    """
    n = len(lis)
    while n > 0:
        temp_n = 0
        for i in range(1, n):
            if lis[i-1] > lis[i]:
                lis[i-1], lis[i] = lis[i], lis[i-1]
                temp_n = i
        n = temp_n
    return lis


def main():
    lis1 = [4, 1, 2, 3, 9]
    lis2 = [1]
    lis3 = [2, 2, 1, -1, 0, 4, 5, 2]
    lis4 = []

    lis1 = bubble_sort(lis1)
    assert lis1 == [1, 2, 3, 4, 9]

    lis2 = bubble_sort(lis2)
    assert lis2 == [1]

    lis3 = bubble_sort(lis3)
    assert lis3 == [-1, 0, 1, 2, 2, 2, 4, 5]

    lis4 = bubble_sort(lis4)
    assert lis4 == []

if __name__ == '__main__':
    main()
