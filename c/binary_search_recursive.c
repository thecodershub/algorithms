
/* !\brief A recursive implementation of Binary Search
 * 
 * \param int * A   - Array to search the value (assumed to be sorted)
 * \param int start - start index for search
 * \param int end   - end index for search (start <= end <= sizeof(A))
 * \param int val   - value to search for
 * 
 * \returns index of value.
 *		-1 - if value is not found
 */

int binary_search(int * A, int start, int end, int val)
{
	int l = start;
	int r = end;

	while(l < r)
	{
		int mid = (l + r) / mid;

		if(A[mid] == val)
			return mid;

		if(A[mid] < val)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return -1;
}