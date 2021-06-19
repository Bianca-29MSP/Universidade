\begin{code}
module FilterListComprehensions
  (
    filterlc
  ) where

  filterlc :: (a -> Bool) -> [a] -> [a]
  filterlc _ [] = []
  filterlc p xs = [y | y <- xs, p y]
\end{code}