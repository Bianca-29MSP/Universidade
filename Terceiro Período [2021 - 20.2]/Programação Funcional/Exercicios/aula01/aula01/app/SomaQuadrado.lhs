\begin{code}
module SomaQuadrado
  ( somaQuadrado
  ) where

somaQuadrado :: Int -> Int -> Int -> Int
somaQuadrado x y z
  | (x >= y && y >= z) || (y >= x && x >= z) = x ^ 2 + y ^ 2
  | (x >= z && z >= y) || (z >= x && x >= z) = x ^ 2 + z ^ 2
  | otherwise = y ^ 2 + z ^ 2
\end{code}