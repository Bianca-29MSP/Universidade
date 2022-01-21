\begin{code}
module Length
  ( doisElementosCasamento,
    doisElementosLength
  ) where

  doisElementosCasamento :: [a] -> Int
  doisElementosCasamento [] = 0
  doisElementosCasamento (x:[]) = 1
  doisElementosCasamento (a:as:[]) = 2
  doisElementosCasamento (a:as) = -1
  
  doisElementosLength :: [a] -> Int
  doisElementosLength a
    | len <= 2 = len
    | otherwise = -1
    where
      len = length a
\end{code}