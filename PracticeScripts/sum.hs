sum' [Int] -> Int
sum' [] = 0
sum' (first:rest) = first + sum' rest
