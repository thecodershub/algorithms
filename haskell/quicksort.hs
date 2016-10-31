quicksort :: (Ord a) => [a] -> [a]  
quicksort [] = []  
quicksort (x:xs) =   
    let smaller = quicksort [a | a <- xs, a <= x]  
        bigger = quicksort [a | a <- xs, a > x]  
    in  smaller ++ [x] ++ bigger 


main = do 
    print(quicksort [7,15,12,-5,14,88,52,11])
    print(quicksort "Haskell")
    print(quicksort [1.5,9.85,9.99,-2.58])
	
