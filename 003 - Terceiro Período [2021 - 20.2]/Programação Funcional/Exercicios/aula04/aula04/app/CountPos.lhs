\begin{code}
module CountPos
  (
    countPos
  ) where

countPos :: [Int] -> Int
countPos [] = 0
countPos (x:xs)
	| x >= 0 = 1 + countPos xs
	| otherwise = countPos xs
\end{code}
