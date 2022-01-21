Avaliação 2 de Programação Funcional
========================

ATENÇÃO
-------

* A interpretação dos enunciados faz parte
da avaliação.

* A avaliação deve ser resolvida INDIVIDUALMENTE.
Não serão tolerados plágios de nenhum tipo.

* Se você utilizar recursos disponíveis na internet
e que não fazem parte da bibliografia, você deverá
explicitamente citar a fonte apresentando o link
pertinente como um comentário em seu código.

* Todo código produzido por você deve ser acompanhado
por um texto explicando a estratégia usada para a
solução. Lembre-se: meramente parafrasear o código
não é considerado uma explicação!

* Não é permitido modificar a seção Setup inicial
do código, seja por incluir bibliotecas ou por
eliminar a diretiva de compilação -Wall.

* Seu código deve ser compilado sem erros e warnings
de compilação. A presença de erros acarretará em
uma penalidade de 20% para cada erro de compilação e
de 10% para cada warning. Esses valores serão descontados
sobre a nota final obtida pelo aluno.

* Todo o código a ser produzido por você está marcado
usando a função "undefined". Sua solução deverá
substituir a chamada a undefined por uma implementação
apropriada.

* Sobre a entrega da solução:

1. A entrega da solução da avaliação deve ser feita
como um único arquivo .zip contendo todo o projeto
stack usado.

2. O arquivo .zip a ser entregue deve usar a seguinte
convenção de nome: MATRÍCULA.zip, em que matrícula é
a sua matrícula. Exemplo: Se sua matrícula for
20.1.2020 então o arquivo entregue deve ser
2012020.zip. A não observância ao critério de nome e
formato da solução receberá uma penalidade de 20%
sobre a nota obtida na avaliação.

3. O arquivo de solução deverá ser entregue usando a
atividade "Entrega da Avaliação 2" no Moodle dentro do
prazo estabelecido.

4. É de responsabilidade do aluno a entrega da solução
dentro deste prazo.

5. Sob NENHUMA hipótese serão aceitas soluções fora do
prazo ou entregues usando outra ferramenta que
não a plataforma Moodle.

6. Não será aceito o envio de soluções em formato ".hs".
Avaliações enviadas nesse formato não serão consideradas
para correção.


Setup inicial
-------------

> {-# OPTIONS_GHC -Wall #-}

> module Main where

> import Data.Time.Clock
> import Data.Time.Calendar
> import ParseLib
> import System.Environment (getArgs)

Gerenciador de tarefas
======================

Introdução
----------

O objetivo dessa avaliação é a criação de uma ferramenta de linha
de comando para o gerenciamento de tarefas. A ferramenta a ser implementada
lerá um arquivo contendo as tarefas e produzirá um relatório contendo:

1. Tarefas atrasadas.
2. Tarefas que devem ser concluídas no dia atual.
3. Tarefas a serem concluídas até a próxima semana.

Para concluir a implementação dessa ferramenta, desenvolva os exercícios
especificados a seguir.

*Questão 1.* *(Valor 3,0 pontos).* Uma importante tarefa em um software para gestão de tarefas é
a correta manipulação de datas. O tipo `Date` representa datas formadas
por seu dia, mês e ano.

> data Date
>  = Date {
>      day   :: Int
>    , month :: Int
>    , year  :: Int
>    } deriving Eq

a) *(Valor 0,5 ponto)* Implemente uma instância de `Show` para o tipo `Date` de forma que
uma data seja exibida no formato DD/MM/YYYY, em que DD denota o dia,
MM o mês e YYYY o ano.

== Estratégia: Concatenação dos dados de dia mes e ano com o simbolo de barra "/" e adicionar
o 0 na frente do mes ou do dia caso seja necessario

> instance Show Date where
>    show (Date d m y) = format d ++ "/" ++ format m ++ "/" ++ show y
>     where
>       format x = if x < 10 then "0" ++ show x else show x


b) *(Valor 0,5 ponto)* Outra tarefa importante sobre o tipo data é comparação entre valores. Para isso,
implemente uma instância de `Ord` para o tipo `Date`. Para implementar a instância de
`Ord` basta implementar a função `<=` para datas.

== Estratégia: A verificação é feita de trás para frente, ou seja ano mes e ano. E de acordo com o resultado
já retorna True ou False, ou analisa o outro item da data.

> instance Ord Date where
>   (Date d m y) <= (Date d' m' y')
>     | y > y' = False
>     | y < y' = True
>     | otherwise = if m > m' then False
>                   else 
>                     if m < m' then True
>                     else d <= d'

c) *(Valor 1,0 ponto)* A função a seguir obtém o valor da data atual:

> currentDate :: IO Date
> currentDate
>       = f <$> getCurrentTime
>         where
>           g (y,m,d) = Date d m (fromInteger y)
>           f = g . toGregorian . utctDay

Observe que essa função utiliza o tipo `IO` e,
portanto, realiza uma operação de entrada e saída.
Além disso, ela deve ser chamada dentro de um bloco `do`.

Usando a função `currentDate` como modelo, implemente a função


== Estratégia: Soma 7 ao dia e de acordo com o resultado formatar a data sem que essa 
perca a propriedade, como por exemplo somas +1 ao mês e/ou +1 ao ano se for necessario.

Recurso: http://zvon.org/other/haskell/Outputprelude/or_f.html

> monthIs30 :: Int -> Bool
> monthIs30 m = or[m == 4, m == 6, m == 9, m == 11]

> monthIs31 :: Int -> Bool
> monthIs31 m = or [m == 1, m == 3, m == 5, m == 7, m == 8, m == 10, m == 12]

> sevenDaysAfter :: IO Date
> sevenDaysAfter
>   = do
>       content <- currentDate 
>       let sum' d' m' y'
>            | m' == 2 && (d' + 7 > 28) = Date ((d' + 7) - 28) (m' + 1) y'
>            | m' == 12 && (d' + 7 > 31) = Date ((d' + 7) - 31) 1 (y' + 1)
>            | monthIs30 m' && (d' + 7 > 30) = Date ((d' + 7) - 30) (m' + 1) y'
>            | monthIs31 m' && (d' + 7 > 31) = Date ((d' + 7) - 31) (m' + 1) y'
>            | otherwise  = Date (d' + 7) m' y'
>       case content of
>         (Date d m y) -> return (sum' d m y)

que retorna a data correspondente a sete dias depois da data
atual.

d) *(Valor 1,0 ponto)* Considerando o formato textual de datas, implemente
um parser para o tipo `Date`.

== Estratégia: A estrategia utilizada foi seguindo a ideia da aula sincrona apresentada
no dia 21/07/2021

Recursos: http://zvon.org/other/haskell/Outputprelude/read_f.html
          Ultima aula sincrona, do dia 21/07/2021

> repeatParser :: Int -> Parser s a -> Parser s [a]
> repeatParser 0 _ = pure []
> repeatParser n f = (:) <$> f <*> repeatParser (n - 1) f

> parseDate :: Parser Char Date
> parseDate = f <$> day' <*> forwardSlash <*> month' <*> forwardSlash <*> year'
>   where
>     day' = repeatParser 2 digitChar
>     month' = repeatParser 2 digitChar
>     year' = repeatParser 4 digitChar
>     f d' _ m' _ y' = (Date (read d') (read m') (read y'))
>     forwardSlash = symbol '/'

As próximas questões irão envolver o tipo `Task` que representa
uma tarefa armazenada em um arquivo fornecido como entrada.

> data Task
>    = Task {
>        deadline    :: Date
>      , description :: String
>      }  deriving (Eq, Ord)

O significado dos campos do tipo `Task` é como se segue: `deadline`
especifica a data limite para a realização da tarefa e `description`
a descrição textual da tarefa em questão.

Tarefas são representadas textualmente de forma simples: primeiro
especificamos a data limite para a tarefa, seguida de um ou mais espaços
e de sua descrição. Usamos o caractere de ';' para separar diferentes
tarefas em uma mesma string.
A seguir, apresentamos um exemplo deste formato de tarefas:

```
28/06/2021 Tarefa 1 ;
26/07/2021 Tarefa 2 ;
02/08/2021 Tarefa 3 ;
```

*Questão 2.* *(Valor 1,0 ponto)* Desenvolva uma instância de `Show` para o tipo `Task` que
produza uma string idêntica à sua descrição textual.

== Estratégia: Ideia central bem parecida com a questão 01) a. Com o uso da concatenaçãO
forma-se a task formatada

> instance Show Task where
>    show (Task a a') = (show a) ++ " " ++ a' ++ " ;"

*Questão 3.* *(Valor 3,0 pontos)*Com base no formato do arquivo de tarefas, construa um parser
que o processe e retorne uma lista das tarefas nele armazenadas.


== Estratégia: Utilizar o parser pronto do date e combinar com um novo parser para o restante
das tarefas. Com o listOf obtem-se um Parser de um array, que nessa caso é o [Task], e esse parser
é feito ate o ";" das tarefas. Cada Parser de Task passa pelo `taskFileParser'` função na qual 
realmente faz o parser. Também é verificado a presença de caracteres indesejados, como `\n` e espacox
Consulta: Ocorreu a consulta ao aluno André para o entendimento do array em parser

> taskFileParser :: Parser Char [Task]
> taskFileParser = g <$> listOf taskFileParser' semicolon <*> semicolon
>   where
>     g = (\x _ -> x)
>     semicolon = symbol ';'


> taskFileParser' :: Parser Char Task
> taskFileParser' = f <$> clear <*> date <*> blankSpace <*> (greedy desc)
>   where
>     date = parseDate
>     blankSpace = symbol ' '
>     desc = sat (\c -> not (c == ';'))
>     clear = many (symbol '\n' <|> blankSpace)
>     f _ d _ desc' = Task d desc'


*Questão 4.* *(Valor 1,0 ponto)* O objetivo desta questão é a produção de um relatório contendo
as tarefas atrasadas, que devem ser concluídas na data atual e que
devem ser concluídas em até 7 dias. O tipo `Report` agrupa essas informações:

> data Report
>   = Report {
>       late  :: [Task]
>     , today :: [Task]
>     , nexts :: [Task]
>     } deriving Show

Desenvolva a função

== Estratégia: Faz o uso do filter e do Ord implementado anteriormente para capturar as task com
as datas apropriadas para o seu tipo em Report.
  Observação: Porém não consegui executar a parte de pegar a data do proprio currentDate ou do sevenDaysAfter,
  pois tive dificuldade pelo fato de retornar um IO Date e ser necessario um Date

> report :: [Task] -> Report
> report [] = (Report [] [] [])
> report x = (Report (l x) (t x) (n x))
>   where
>     l :: [Task] -> [Task]
>     t :: [Task] -> [Task]
>     n :: [Task] -> [Task]
>     l s = filter isLate s
>     t s = filter isToday s
>     n s = filter isNexts s
>     isToday (Task d _) = d == (Date 26 7 2021)
>     isNexts (Task d _) = not (d <= (Date 26 7 2021))
>     isLate (Task d _) = (d <= (Date 26 7 2021) && d /= (Date 26 7 2021))


*Questão 5.* *(Valor 1,0 ponto)* O resultado final da ferramenta é um relatório classificando as tarefas.
Considerando o seguinte arquivo de modelo:

```
18/06/2021 Tarefa 1 ;
26/07/2021 Tarefa 2 ;
30/07/2021 Tarefa 3 ;
```

Temos que a Tarefa 1 está atrasada, a Tarefa 2 possui deadline para hoje e a
Tarefa 3 deve ser concluída em até 7 dias. Sua ferramenta deverá apresentar
o seguinte relatório

````
Tarefas atrasadas:

18/06/2021 Tarefa 1 ;

Tarefas para hoje:

26/07/2021 Tarefa 2;

Tarefas para concluir em uma semana:

30/07/2021 Tarefa 3
````

A partir da descrição anterior, implemente a função:

== Estratégia: Percorrendo todo os arrays de Report foi possivel imprimar cada Task de forma
recursiva e utilizando o Show do Task implementado anteriormente.

> printReport :: Report -> String
> printReport (Report l t n) =
>   "Tarefas atrasadas:\n\n"
>   ++ showItem l ++ "\n" ++
>   "Tarefas para hoje:\n\n"
>   ++ showItem t ++ "\n" ++
>   "Tarefas para concluir em uma semana:\n\n"
>   ++ showItem n
>   where
>     showItem x = case x of [] -> []
>                            (t':ts) -> show t' ++ "\n" ++ showItem ts


que gera uma string no formato apresentado para os dados do relatório
(valor do tipo `Report`).


*Questão 6.* *(Valor 1,0 ponto)* De posse de todas as implementações anteriores, implemente
a função `main` de sua ferramenta:

== Estratégia: Com o path do arquivo passado por args, os dados são pegos e colocado em um array,
esse array passa pelo parsing e com o valor retorna dessa opreção, é pego a `head` do Parcing e 
em seguida o primeiro elemento da tupla, que consiste do array de Task, esse array passará pelo
report que transforma para uma Report, e por fim é empresso na tela o resulta com o printReport.

> main :: IO ()
> main = do
>           args <- getArgs
>           let path = head args
>           content <- readFile path
>           let ln = runParser taskFileParser content
>               hln = (\ (x, _) -> x)
>           putStrLn $ "Tarefas: " ++ printReport(report((hln (head ln))))


A partir de um nome de arquivo, sua ferramenta deverá lê-lo, realizar
seu parsing e exibir o relatório de tarefas. Para obter o nome de arquivo,
você deverá usar a função `getArgs`, para obter os argumentos passados
por linha de comando para sua ferramenta.

Para executar seu programa usando o stack e passar argumentos de linha
de comando basta:

```
stack exec prova02-exe -- argumento
```

em que argumento é o valor que você deseja passar como argumento adicional para
a execução de seu programa.
