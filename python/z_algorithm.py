"""
String matching Z-algorithm
"""


def generate_z_array(string):
    """
    This methods takes and string as input and returns Z-array for same
    :param string:
    :return:
    """
    n = len(string)
    z_array = [0] * n
    left_index, right_index = 0, 0  # [L, R] index

    for i in range(1, n):
        if i > right_index:
            left_index, right_index = i, i
            while right_index < n and string[right_index-left_index]  == string[right_index]:
                right_index += 1
            z_array[i] = right_index - left_index
            right_index -= 1
        else:
            k = i - left_index
            if z_array[k] < right_index - i + 1:
                z_array[i] = z_array[k]
            else:
                left_index = i
                while right_index < n and string[right_index - left_index] == string[right_index]:
                    right_index += 1
                z_array[i] = right_index - left_index
                right_index -= 1

    return z_array


def search(haystack, needle):
    """
    Returns index of needle in haystack.

    It generates  z-array for needle + "$" + haystack. It assumes that $ is not part of haystack or needle.
    Since z_arrays represents longest substring at index i which is also prefix of string, we only need to search for
    equal length pattern.

    Returns -1 on non matching
    :param haystack:
    :param needle:
    :return:
    """
    combined_str = needle + "$" + haystack
    z_array = generate_z_array(combined_str)

    for i in range(0, len(combined_str)):
        if z_array[i] == len(needle):
            return i - len(needle) - 1

    return -1


def main():
    string = "aaaaaa"
    z_array = generate_z_array(string)

    assert z_array == [0, 5, 4, 3, 2, 1]
    assert search(string, "aaa") == 0
    assert search(string, "aaaaaa") == 0

    string = "aabcaabxaaaz"
    z_array = generate_z_array(string)

    assert z_array == [0, 1, 0, 0, 3, 1, 0, 0, 2, 2, 1, 0]
    assert search(string, "xyz") == -1
    assert search(string, "bxa") == 6


if __name__ == '__main__':
    main()
