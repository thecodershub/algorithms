"""
KMP string matching algorithm
"""


def kmp(haystack, needle):
    """
    Run KMP search on haystack on needle and return all matching indexes

    Return empty list on no result

    :param haystack:
    :param needle:
    :return:
    """

    needle = list(needle)
    len_needle = len(needle)

    shifts = [1] * (len_needle + 1)
    shift = 1
    for pos in range(0, len_needle):
        while shift <= pos and needle[pos] != needle[pos-shift]:
            shift += shifts[pos-shift]
        shifts[pos+1] = shift

    start_pos = 0
    match_len = 0
    results = []

    for c in haystack:
        while match_len == len_needle or match_len >= 0 and needle[match_len] != c:
            start_pos += shifts[match_len]
            match_len -= shifts[match_len]
        match_len += 1
        if match_len == len(needle):
            results.append(start_pos)

    return results


def main():
    string = "aabcaabxaaaz"

    assert kmp(string, "bxa") == [6]
    assert kmp(string, "aaaa") == []

    string = "aaaaa"

    assert kmp(string, "aaa") == [0, 1, 2]
    assert kmp(string, "aaaaa") == [0]


if __name__ == '__main__':
    main()
