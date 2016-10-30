#[cfg(test)]
mod tests {
	// only works if there is only one valid way of sorting the data
	fn try_sorting<T: Ord + PartialEq + Clone>(original: Vec<T>) {

		let mut sorted = original.clone();
    	super::sort(&mut sorted);

    	let mut reference = original.clone();
    	reference.sort();
    	
    	assert!(sorted == reference);
	}

    #[test]
    fn works_on_empty() {
    	try_sorting::<i8>(vec![]);
    }

    #[test]
    fn works_on_one() {
    	try_sorting(vec![1]);
    }

    #[test]
    fn five_numbers() {
    	try_sorting(vec![3,6,5,2,-1]);
    }

    #[test]
    fn sorted() {
    	try_sorting(vec![2,3,4,5]);
    }
}

fn sort<T: PartialOrd>(v: &mut Vec<T>) {

}