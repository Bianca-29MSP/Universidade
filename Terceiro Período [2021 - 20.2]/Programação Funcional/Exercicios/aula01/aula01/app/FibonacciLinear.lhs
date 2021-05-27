\begin{code}
module FibonacciLinear
  ( fibonacciLinear
  ) where

fibonacciLinear :: Int -> Int
fibonacciLinear 0 = 0
fibonacciLinear 1 = 1
fibonacciLinear n = fib' 0 1 n
    where fib' a b n | n <= 1 = b
                     | otherwise = fib' b (a+b) (n-1)
\end{code}
