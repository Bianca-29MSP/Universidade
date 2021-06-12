=== Criando Tipos ===

\begin{code}
--Tipo Humor pode ser Feliz ou Triste e deriva do Show, que se faz possivel mostrar o dados
data Humor = Feliz | Triste deriving Show

{-
no terminal:
  :t Feliz
  Feliz :: Humor 
-}

showHumor :: Humor -> String
showHumor Feliz = "Feliz"
showHumor Triste = "Triste"

changeHumor :: Humor -> Humor
changeHumor Feliz = Triste
changeHumor Triste = Feliz

piorarHumor :: a -> Humor
piorarHumor _ = Triste

type Estacao = String
type Estacoes = (Estacao, Estacao, Estacao, Estacao)

f_nomes_estacoes :: Estacoes
f_nomes_estacoes = ("Verao", "Outono", "Inverno", "Primavera")

primeira_estacao :: Estacoes -> Estacao
primeira_estacao (x,_,_,_) = x

-- no terminal: primeira_estacao f_nomes_estacoes
\end{code}