import Test.QuickCheck

sort :: Ord a => [a] -> [a]
sort list = foldl swaps list [0..(length list)-1]

swaps list n = foldr prepend [(last list)] (take (length list - 1) list)
	where prepend x (head:tail) =
		if x <= head then
			(x:head:tail)
		else
			(head:x:tail)

isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [a] = True
isSorted (a:b:tail) = a <= b && isSorted (b:tail)


main = quickCheck testSort

testSort :: [Integer] -> Bool
testSort list = isSorted (sort list)