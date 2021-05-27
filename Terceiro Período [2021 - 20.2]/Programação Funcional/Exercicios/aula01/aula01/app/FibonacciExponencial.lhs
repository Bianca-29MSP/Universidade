\begin{code}
module FibonacciExponencial
  ( fibonacciExponencial
  ) where

fibonacciExponencial :: Int -> Integer
fibonacciExponencial 0 = 0
fibonacciExponencial 1 = 1
fibonacciExponencial n = fibonacciExponencial(n - 1) + fibonacciExponencial(n - 2)
\end{code}