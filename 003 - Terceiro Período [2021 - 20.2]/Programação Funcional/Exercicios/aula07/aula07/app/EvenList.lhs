\begin{code}
module EvenList
  (
    evenList,
  ) where

evenList :: [Int] -> [Bool]
evenList xs = map isPair xs
  where
    isPair x 
      | x `mod` 2 == 0 = True
      | otherwise = False
\end{code}
