\begin{code}
module Length
  ( func,
    func2,
    length
  ) where

  func :: [a] -> Int
  func [] = 0
  func (x:[]) = 1
  func (a:as:[]) = 2
  func (a:as) = -1
  
  func2 :: [a] -> Int
  func2 a
    | len <= 2 = len
    | otherwise = -1
    where 
      len = length a
\end{code}