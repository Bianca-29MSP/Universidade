\begin{code}
module DropList
  (
    dropList
  ) where

dropList :: Int -> [a] -> [a]
dropList _ [] = []
dropList 0 a = a
dropList n (xs:xss) = dropList (n - 1) xss
\end{code}