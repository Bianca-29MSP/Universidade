\begin{code}
module TakeList
  (
    takeList
  ) where

takeList :: Int -> [a] -> [a]
takeList _ [] = []
takeList 0 _ = []
takeList n (xs:xss) = xs : takeList (n - 1) xss
\end{code}