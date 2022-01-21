\begin{code}
module MapListComprehensions
  (
    maplc,
  ) where

maplc:: (a -> b) -> [a] -> [b]
maplc _ [] = []
maplc f xs = [ f y | y <- xs]
\end{code}
