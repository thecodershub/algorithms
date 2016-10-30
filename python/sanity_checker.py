"""
Run assertions of all file by calling main method of each file
"""

import binary_search
import binary_tree
from sort import bubble_sort, insertion_sort, mergesort, quicksort


def main():
    """
    Call main method of all files
    """
    mergesort.main()
    quicksort.main()
    binary_search.main()
    binary_tree.main()
    insertion_sort.main()
    bubble_sort.main()


if __name__ == '__main__':
    main()
