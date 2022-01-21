\begin{code}
module RemoveAll
  (
    removeAll,
    removeAllComprehensions
  ) where

removeAll :: Int -> [Int] -> [Int]
removeAll _ [] = []
removeAll x (xs:xss)
  | x == xs = removeAll x xss
  | otherwise = xs : removeAll x xss

removeAllComprehensions :: Int -> [Int] -> [Int]
removeAllComprehensions _ [] = []
removeAllComprehensions x xs = [y | y <- xs, y /= x]
\end{code}