// quicksort :: Ord a => [a] -> [a]
function quicksort( diff = (a, b) => a - b, array = [] ) {
	if( array.length === 0 ) return []

	const [x, ...xs] = array

	const lessThan = xs.filter(a => diff(a, x) < 0)
	const biggerThan = xs.filter(a => diff(a, x) >= 0)

	const lessThanSorted = quicksort(diff, lessThan)
	const biggerThanSorted = quicksort(diff, biggerThan)

	return [...lessThanSorted, x, ...biggerThanSorted]
}

export default quicksort

// example usage
// const diff = (a, b) => a - b
// console.log(quicksort(diff, [3, 2, 5, 7, 9123, 92, 23, 567, 23]))
// console.log(quicksort((a, b) => a.value - b.value, [{value: 3}, {value: 5}]))