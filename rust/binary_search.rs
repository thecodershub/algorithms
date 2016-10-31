/// Binary search a sorted list `list` for value `value`. This function conforms to
/// `Vec::binary_search` from the Rust standard library.
///
/// If the value is in the list, the function will return `Ok(index)`, with `index` the
/// index of the element that had to be found.
/// If the value is _not_ in the list it will return `Err(index)`, with `index` being the
/// index where the element would be before if it had been in the list.
///
/// # Example
///
/// ```
/// # use binary_search::binary_search;
/// let list = [1, 4, 9, 16, 25, 36];
/// assert_eq!(binary_search(&list, 16), Ok(3));
/// assert_eq!(binary_search(&list, 20), Err(4));
///
/// let list2 = ["Alice", "Bob", "Charlie"];
/// assert_eq!(binary_search(&list2, "Bob"), Ok(1));
/// assert_eq!(binary_search(&list2, "Daniel"), Err(3));
/// ```
pub fn binary_search<T: Ord>(list: &[T], value: T) -> Result<usize, usize> {
    let (mut start, mut end) = (0, list.len());
    while end - start > 1 {
        let middle = (start + end) / 2;
        if value <= list[middle] {
            end = middle;
        } else {
            start = middle;
        }
    }

    match () {
        _ if list.get(start) == Some(&value) => Ok(start),
        _ if list.get(end) == Some(&value) => Ok(end),
        _ if list.get(start).map_or(false, |x| &value < x) => Err(start),
        _ => Err(end),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn numbers() {
        let list = [1, 2, 2, 2, 3, 4, 7, 10, 32, 55];
        assert_eq!(binary_search(&list, 1), Ok(0));
        assert_eq!(binary_search(&list, 55), Ok(9));
        assert_eq!(binary_search(&list, 11), Err(8));
        assert_eq!(binary_search(&list, 0), Err(0));
        assert_eq!(binary_search(&list, 100), Err(10));
        let two_index = binary_search(&list, 2);
        assert!(match two_index { Ok(1...3) => true, _ => false, });
    }

    #[test]
    fn str_slice() {
        let list = ["a", "crafty", "foamy", "porter"];
        assert_eq!(binary_search(&list, ""), Err(0));
        assert_eq!(binary_search(&list, "porter"), Ok(3));
        assert_eq!(binary_search(&list, "beer"), Err(1));
        assert_eq!(binary_search(&list, "spam"), Err(4));
    }

    #[test]
    fn empty_list() {
        let list = [];
        assert_eq!(binary_search(&list, 3), Err(0));
    }
}
