--increasing order
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort smaller ++ [x] ++ quicksort greater
                where   
                    smaller = [a | a <- xs, a < x]
                    greater = [a | a <- xs, a >= x]

--decreasing order
quicktros :: (Ord a) => [a] -> [a]
quicktros [] = []
quicktros (x:xs) = quicktros greater ++ [x] ++ quicktros smaller
                where
                    smaller = [a | a <- xs, a <= x]
                    greater = [a | a <- xs, a > x]