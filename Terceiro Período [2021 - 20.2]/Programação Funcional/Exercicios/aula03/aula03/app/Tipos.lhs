\begin{code}
module Tipos
  ( 
    bools,
    nums,
    add,
    copy,
    apply,
    swap
  ) where

bools :: [Bool]
bools (head:tail) = head : True

-- nums :: [[Int]]

add :: Int -> Int -> Int -> Int
add a b c = a + b + c

copy :: a -> (a, a)
copy a = (a, a)

-- apply :: (a -> b) -> a -> b

swap :: (a,b) -> (b,a)
swap (a, b) = (b, a)
\end{code}