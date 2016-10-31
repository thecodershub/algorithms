
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
	int mid = (start + end)/2;

	if(A[mid] == val)
		return mid;

	if(start < end)
		if(A[mid] < val)
			return binary_search(A, mid+1, end, val);
		else
			return binary_search(A, start, mid-1, val);
}