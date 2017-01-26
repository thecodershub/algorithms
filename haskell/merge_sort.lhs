
First we define a couple of helper functions that
will be useful in splitting the list in half:

> fsthalf :: [a] -> [a]
> fsthalf xs = take (length xs `div` 2) xs

> sndhalf :: [a] -> [a]
> sndhalf xs = drop (length xs `div` 2) xs

Examples: 
  - fsthalf [1,2,3,4,5] = [1,2]
  - sndhalf [1,2,3,4,5] = [3,4,5]


Now the merge operation, defined recursively:
  - merge of a list with an empty list is just the list
  - merge of two lists is: 
      the smaller of the two list heads, concatenated with
      the result of merging the remainder of that list with 
      all of the other list

Since the recursive merge will eventually exhaust one
of the lists, we will arrive at a base case and the
recursion will terminate.

> merge :: Ord a => [a] -> [a] -> [a]
> merge xs [] = xs
> merge [] ys = ys
> merge (x:xs) (y:ys) 
>          | (x <= y)  = x:(merge xs (y:ys)) 
>          | otherwise = y:(merge (x:xs) ys)

Example: 
  - merge [1,3,7,8] [2,4,5,6] = [1,2,3,4,5,6,7,8]


Now the mergesort itself:
  - mergesort of an empty list is an empty list
    (note, this case is not the base case for recursion;
     it is a special case to consider separately)
  - mergesort of a singleton list is the singleton list
  - mergesort of an arbitrary list is the merging of:
      mergesort of the first half of the list, with
      mergesort of the second half of the list

> mergesort :: Ord a => [a] -> [a]
> mergesort [] = []
> mergesort [x] = [x]
> mergesort xs = merge (mergesort (fsthalf xs)) (mergesort (sndhalf xs))

Examples:
  - mergesort [7,4,5,2,8,1,10,3,6,9] = [1,2,3,4,5,6,7,8,9,10]
  - mergesort [100,99..1] = [1..100]
