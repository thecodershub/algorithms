import test from 'tape'
import quicksort from './quicksort'

const diff = (a, b) => a - b
const reverseDiff = (a, b) => b - a
const objDiff = (a, b) => a.value - b.value
const reverseObjDiff = (a, b) => b.value - a.value

test('Quicksort', t => {
	t.ok(quicksort, 'should exist')

	t.is( typeof quicksort, 'function', 'should be a function')

	t.same( quicksort(), [], 'should return empty array if nothing is passed')

	t.same( quicksort(diff, []), [], 'should return empty array if empty array is passed')

	t.same( quicksort(diff, [1]), [1], 'should return the same array if it has just one value' )
	t.same( quicksort(reverseDiff, [1]), [1], 'should return the same array if it has just one value' )

	t.same( quicksort(diff, [1, 2, 3]), [1, 2, 3], 'should return the same array if it\'s already sorted ')
	t.same( quicksort(reverseDiff, [3, 2, 1]), [3, 2, 1], 'should return the same array if it\'s already sorted ')

	t.same( quicksort(diff, [1, 3, 2]), [1, 2, 3], 'should sort an array')
	t.same( quicksort(reverseDiff, [1, 3, 2]), [3, 2, 1], 'should sort an array')

	t.same( quicksort(diff, [1, 1, 1]) , [1, 1, 1], 'should return an array with all the same values')
	t.same( quicksort(reverseDiff, [1, 1, 1]) , [1, 1, 1], 'should return an array with all the same values')

	t.same( quicksort(diff, [3, 2, 1, 0, -1]) , [-1, 0, 1, 2, 3], 'should sort a reversed array')
	t.same( quicksort(reverseDiff, [-1, 0, 1, 2, 3]) , [3, 2, 1, 0, -1], 'should sort a reversed array')

	t.same( quicksort(objDiff, [{value: -1}, {value: 30}, {value: 14}]) , [{value: -1}, {value: 14}, {value: 30}], 'should sort an array of objects')
	t.same( quicksort(reverseObjDiff, [{value: -1}, {value: 30}, {value: 14}]) , [{value: 30}, {value: 14}, {value: -1}], 'should sort an array of objects')

	t.end()
})