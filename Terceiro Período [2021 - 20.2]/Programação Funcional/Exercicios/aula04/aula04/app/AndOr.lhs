\begin{code}
module AndOr
  (
    conj,
    disj
  ) where

conj :: [Bool] -> Bool
conj (a:[]) = a
conj (a:as) = a && conj as

disj :: [Bool] -> Bool
disj (a:[]) = a
disj (a:as) = a || disj as
\end{code}

