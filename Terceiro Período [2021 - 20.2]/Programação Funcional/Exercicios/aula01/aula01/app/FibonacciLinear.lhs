\begin{code}
module FibonacciLinear
  ( fibonacciLinear
  ) where

fibonacciLinear :: Int -> Int
fibonacciLinear 0 = 0
fibonacciLinear 1 = 1
fibonacciLinear n = fib' n 0 1
  where
    fib' n a1 a2
      | n <= 1 = a2
      | n > 1 = fib' (n - 1) a2 (a1+a2)
\end{code}
