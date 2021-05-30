\begin{code}
module Primes
  ( primes
  ) where

  primes :: Int -> Bool
  primes n = if length (factors n) == 2 
            then True
            else False

  factors :: Int -> [Int]
  factors n = [x | x <- [1..n], n `mod` x == 0]
\end{code}