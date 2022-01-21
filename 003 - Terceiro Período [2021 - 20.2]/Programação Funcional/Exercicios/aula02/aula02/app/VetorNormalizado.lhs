\begin{code}
module VetorNormalizado
  ( vetorNormalizado
  ) where

  vetorNormalizado :: (Float, Float) -> (Float, Float)
  vetorNormalizado (x, y)
    = (rx, ry)
      where
        v = sqrt (x*x + y*y)
        rx = (x/v)
        ry = (y/v)
\end{code}