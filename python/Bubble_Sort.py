"""
Bubble Sort Algorithm
https://en.wikipedia.org/wiki/Bubble_sort
"""

def bubble_sort(lis):
    """
    Return the sorted list
    :param lis: unsorted list
    """
    j = 0

    while j < len(lis):
        k = 0
        while k < (len(lis) - 1):
            if lis[k] > lis[k + 1] and len(lis) >= k+1:
                temp = lis[k + 1]
                lis[k + 1] = lis[k]
                lis[k] = temp
            k = k + 1
        j = j + 1
    return lis


        
def main():

    lis1 = [3, 6, 8, 4, 1, 2, 9]
    lis2 = bubble_sort(lis1)    
    print(lis2)

    lis1 = [3, 6, 9, 1, 8, 4, 1, 2, 9, 10, 100, 2, 2, 5, 4, 4, 1]
    lis2 = bubble_sort(lis1)    
    print(lis2)

if __name__ == '__main__':
    main()
