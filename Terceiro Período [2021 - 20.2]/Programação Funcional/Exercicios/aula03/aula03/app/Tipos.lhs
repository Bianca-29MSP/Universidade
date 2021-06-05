\begin{code}
module Tipos
  ( 
    bools,
    nums,
    add,
    copy,
    swap
  ) where

bools :: [Bool]
bools = [True, False, True, True]

nums :: [[Int]]
nums = [[1, 3, 5, 7, 9],[0, 2, 4, 6, 8]]

add :: Int -> Int -> Int -> Int
add a b c = a + b + c

copy :: a -> (a, a)
copy a = (a, a)

swap :: (a,b) -> (b,a)
swap (a, b) = (b, a)
\end{code}