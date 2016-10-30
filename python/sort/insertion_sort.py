"""
Recursive insertion sort implementation in Python 3
https://en.wikipedia.org/wiki/Insertion_sort
"""


def insertion_sort(lis):
    """
    Implementation of recursive insertion sort.
    :param lis: list to be sorted
    """
    for i in range(len(lis)):
        j = i
        while j > 0 and lis[j-1] > lis[j]:
            lis[j], lis[j-1] = lis[j-1], lis[j]
            j -= 1
    return lis


def main():
    lis1 = [4, 1, 2, 3, 9]
    lis2 = [1]
    lis3 = [2, 2, 1, -1, 0, 4, 5, 2]
    lis4 = []

    lis1 = insertion_sort(lis1)
    assert lis1 == [1, 2, 3, 4, 9]

    lis2 = insertion_sort(lis2)
    assert lis2 == [1]

    lis3 = insertion_sort(lis3)
    assert lis3 == [-1, 0, 1, 2, 2, 2, 4, 5]

    lis4 = insertion_sort(lis4)
    assert lis4 == []

if __name__ == '__main__':
    main()
