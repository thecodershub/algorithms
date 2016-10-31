bubblesort list = sort list [] False
rev  = reverse          -- separated. To see
rev2 = reverse          --  who calls the routine
sort (x1:x2:xs) acc _
    | x1 > x2           = sort (x1:xs) (x2:acc) True
sort (x1:xs) acc flag   = sort xs (x1:acc) flag
sort [] acc True        = sort (rev acc) [] False
sort _ acc _            = rev2 acc
