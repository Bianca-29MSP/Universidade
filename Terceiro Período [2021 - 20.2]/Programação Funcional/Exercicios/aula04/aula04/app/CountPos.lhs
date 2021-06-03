\begin{code}
module CountPos
  (
    countPos
  ) where

countPos :: [Int] -> Int
countPos [] = 0
countPos [a] = countPos' [a] 0
  where
    countPos' (a:as) i
      | a >= 0 = countPos' as (i + 1)
      | as == [] = i
      | otherwise = countPos' as i
\end{code}