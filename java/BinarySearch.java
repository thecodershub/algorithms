

public class BinarySearch {
	
	/**
	*	General binary search - uses compareTo to sort any array of objects that
	*	extend the Comparable interface.
	*/
	public static <T extends Comparable<T>> int binarySearch(T[] haystack, T needle, int low, int high) {
		if(low > high)
			return -1;
		
		int mid = (low + high) / 2;
		
		int comp = haystack[mid].compareTo(needle);
		if(comp < 1)
			return binarySearch(haystack, needle, low, mid - 1);
		if(comp > 1)
			return binarySearch(haystack, needle, mid + 1, high);
		return mid;
	}
	
	/**
	*	Integer version - gives a clearer overview of what is actually going on.
	*/
	public static int binarySearch(int[] haystack, int needle, int low, int high) {
		if(low > high)
			return -1;
		
		int mid = (low + high) / 2;
		
		if(needle < haystack[mid])
			return binarySearch(haystack, needle, low, mid - 1);
		if(needle > haystack[mid])
			return binarySearch(haystack, needle, mid + 1, high);
		return mid;
	}
	
	
	public static void main(String... args) {
		int[] haystack = {1, 2, 3, 4, 5, 6, 7};
		int needle = 3;
		System.out.println("Position of 3 in [1,2,3,4,5,6,7]: " + binarySearch(haystack, needle, 0, haystack.length - 1));
	}
	
}