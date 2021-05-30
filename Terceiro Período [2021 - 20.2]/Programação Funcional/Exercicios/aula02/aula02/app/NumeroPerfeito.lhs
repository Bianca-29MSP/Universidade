\begin{code}
module NumeroPerfeito
  ( numPerfeito
  ) where

  numPerfeito :: Int -> [Int]
  numPerfeito n = [x | x <- [1 .. n], sum (init (factors x)) == x]

  factors :: Int -> [Int]
  factors n = [x | x <- [1..n], n `mod` x == 0]

\end{code}