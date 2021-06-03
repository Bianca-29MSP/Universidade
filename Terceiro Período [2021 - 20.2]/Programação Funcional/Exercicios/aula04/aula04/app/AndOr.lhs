\begin{code}
module AndOr
  (
    conj,
    disj
  ) where

conj :: [Bool] -> Bool
conj (a:[]) = a
conj (a:as) 
  | a && conj' = a
  | otherwise = conj'
    where
      conj' = conj as

disj :: [Bool] -> Bool
disj (a:[]) = a
disj (a:as) 
  | a || disj' = a
  | otherwise = disj'
    where
      disj' = disj as
\end{code}

