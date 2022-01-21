module Exercicio where

rdFile :: FilePath -> IO ()
rdFile path 
  = do 
    contents <- readFile path
    let
      words4Line = countWords4Line contents
    putStrLn("Numero de linhas: " ++ show (length words4Line))
    putStrLn("Numero de palavras: " ++ show (countWords words4Line))

countWords4Line :: String -> [Int]
countWords4Line input = map (length.words) (lines input)

countWords :: [Int] -> Int
countWords = foldr (+) 0
