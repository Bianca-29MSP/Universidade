\begin{code}
module MinList
  (
    minList
  ) where

minList :: [Int] -> Int
minList (a:[]) = a
minList (a:as) 
  | a <= minList' = a
  | otherwise = minList'
    where
      minList' = minList as
\end{code}

