\begin{code}
module IndexOf
  (
    indexOf
  ) where

indexOf :: Int -> [Int] -> Int
indexOf x [] = -1
indexOf x (xs:xss)
  | x == xs = 0
  | otherwise = indexOf' xss x 1
  where
    indexOf' (a:as) n i
      | a == n = i
      | as == [] = -1
      | otherwise = indexOf' as n (i + 1)
\end{code}