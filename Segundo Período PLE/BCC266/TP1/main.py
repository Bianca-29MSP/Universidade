import sys
import random


INT_MAX = sys.maxsize
instructionMemory = []
RAM = [0] * 100


def constructorRam():
    for i in range(100):
        RAM[i] = random.randint(0, 1000)


def machine():
    _PC = 0
    _opcode = INT_MAX
    while _opcode != -1:
        _oneInstruction = [0] * 4
        _oneInstruction = instructionMemory[_PC]
        _opcode = _oneInstruction[0]
        if _opcode == 0:
            RAM[_oneInstruction[2]] = _oneInstruction[1]
            #print('{0} na memoria {1}'.format(RAM[_oneInstruction[2]], _oneInstruction[2]))
        elif _opcode == 1:
            _end1 = _oneInstruction[1]
            _end2 = _oneInstruction[2]
            _contentRam1 = RAM[_end1]
            _contentRam2 = RAM[_end2]
            _soma = _contentRam1 + _contentRam2
            RAM[_oneInstruction[3]] = _soma
            #print('Somando {0}'.format(_soma))
        elif _opcode == 2:
            _end1 = _oneInstruction[1]
            _end2 = _oneInstruction[2]
            _contentRam1 = RAM[_end1]
            _contentRam2 = RAM[_end2]
            _sub = _contentRam1 - _contentRam2
            RAM[_oneInstruction[3]] = _sub
            #print('Subtraindo {0}'.format(_sub))
        elif _opcode == 3:
            _oneInstruction[1] = RAM[_oneInstruction[2]]
        _PC += 1


def contructorSomaInstructionsProgram(address1, address2, address3):
    oneInstruction = [0] * 4
    oneInstruction[0] = 1
    oneInstruction[1] = address1
    oneInstruction[2] = address2
    oneInstruction[3] = address3
    return oneInstruction


def contructorSubInstructionsProgram(address1, address2, address3):
    oneInstruction = [0] * 4
    oneInstruction[0] = 2
    oneInstruction[1] = address1
    oneInstruction[2] = address2
    oneInstruction[3] = address3
    return oneInstruction


def contructorHaltInstructionsProgram():
    oneInstruction = [-1] * 4
    return oneInstruction


def contructorLevarParaMemoriaInstructionsProgram(value, address):
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = value
    _oneInstruction[2] = address
    _oneInstruction[3] = -1
    return _oneInstruction


def constructorRandomInstructionsProgram():
    for n in range(len(instructionMemory), 10):
        instructionMemory.append(0)
    for i in range(9):
        _oneInstruction = [0] * 4
        _oneInstruction[0] = random.randint(0, 2)
        _oneInstruction[1] = random.randint(0, 99)
        _oneInstruction[2] = random.randint(0, 99)
        _oneInstruction[3] = random.randint(0, 99)
        instructionMemory[i] = _oneInstruction
    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[9] = _oneInstruction


def contructorMultInstructionsProgram(multiplicando, multiplicador):
    for n in range(len(instructionMemory), multiplicador + 3):
        instructionMemory.append(0)

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(multiplicando, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(0, 1)
    instructionMemory[1] = _oneInstruction

    for i in range(multiplicador):
        _oneInstruction = [0] * 4
        _oneInstruction = contructorSomaInstructionsProgram(0, 1, 1)
        instructionMemory[i + 2] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()

    instructionMemory[multiplicador + 2] = _oneInstruction

    machine()


def contructorPotenciacaoInstructionsProgram(base, expoente):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    if base < 0 and expoente % 2 == 0:
        base *= -1

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(base, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()

    result = RAM[1]

    for i in range(expoente - 1):
        contructorMultInstructionsProgram(result, base)
        result = RAM[1]


def contructorDivInstructionsProgram(dividendo, divisor):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    #Levando o dividendo para o endereço 0 da RAM
    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(dividendo,0)
    instructionMemory[0] = _oneInstruction

    # Levando o divisor para o endereço 1 da RAM
    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(divisor, 1)
    instructionMemory[1] = _oneInstruction

    #Halt para parar o loop
    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[2] = _oneInstruction

    #Executando as instruções da memoria
    machine()

    count = 0
    while RAM[0] >= divisor:
        _oneInstruction = [0] * 4
        #Subitraindo o VALOR no ENDEREÇO 0 com o VALOR do ENDEREÇO 1 e guardando no 0
        _oneInstruction = contructorSubInstructionsProgram(0, 1, 0)
        instructionMemory[0] = _oneInstruction

        # Halt para parar o loop
        _oneInstruction = [-1] * 4
        instructionMemory[1] = _oneInstruction

        # Executando as instruções da memoria
        machine()

        count += 1

    #Guardando resultado na memoria
    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(count, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    #Executando as instruções da memoria
    machine()


def contructorFatorialInstructionsProgram(num):
    aux = 1
    while num != 0:
        contructorMultInstructionsProgram(aux, num)
        aux = RAM[1]
        num -= 1

def contructorAreaTrianguloInstructionsProgram(base, altura):
    contructorMultInstructionsProgram(base, altura)

    result = RAM[1]

    contructorDivInstructionsProgram(result, 2)


def contructorVelocidadeMediaInstructionsProgram(posicaoInicial, posicaoFinal, tempoInical, tempoFinal):
    for n in range(len(instructionMemory), 7):
        instructionMemory.append(0)

    #Variação da posição
    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(posicaoFinal, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(posicaoInicial, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction = contructorSubInstructionsProgram(0, 1, 2)
    instructionMemory[2] = _oneInstruction

    #Variação do tempo
    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(tempoFinal, 3)
    instructionMemory[3] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(tempoInical, 4)
    instructionMemory[4] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction = contructorSubInstructionsProgram(3, 4, 5)
    instructionMemory[5] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[6] = _oneInstruction

    machine()

    variacaoPosicao = RAM[2]
    variacaoDistancia = RAM[5]

    contructorDivInstructionsProgram(variacaoPosicao, variacaoDistancia)


def contructorFibonacciInstructionsProgram(num):    
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(1, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(0, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(0, 2)
    instructionMemory[2] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[3] = _oneInstruction

    machine()

    i = 0
    while(i < num):
        print(RAM[2])
        _oneInstruction = [0] * 4
        _oneInstruction = contructorSomaInstructionsProgram(0, 1, 2)
        instructionMemory[0] = _oneInstruction

        _oneInstruction = [0] * 4
        _oneInstruction = contructorHaltInstructionsProgram()
        instructionMemory[1] = _oneInstruction

        machine()

        _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(RAM[1], 0)
        instructionMemory[0] = _oneInstruction
        
        _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(RAM[2], 1)
        instructionMemory[1] = _oneInstruction

        _oneInstruction = contructorHaltInstructionsProgram()
        instructionMemory[2] = _oneInstruction

        machine()

        i+= 1


def contructorPorcentagemInstructionsProgram(num, porcentual):
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

    contructorMultInstructionsProgram(porcentual, num)

    result = RAM[1]

    contructorDivInstructionsProgram(result, 100)



def contructorDeltaInstructionsProgram(a, b, c):
    for n in range(len(instructionMemory), 2):
        instructionMemory.append(0)

    #Potenciação b²
    contructorPotenciacaoInstructionsProgram(b, 2)
    result = RAM[1]

    #Guardando na RAM[5] o resultado
    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(result, 5)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()

    #Multiplicação 4 x a
    contructorMultInstructionsProgram(4, a)
    machine()
    result = RAM[1]
    
    #Multiplicação 4 x a x c
    contructorMultInstructionsProgram(result, c)
    machine()
    
    #Guardando na RAM[6] o resultado
    result = RAM[1]
    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(result, 6)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction
    
    machine()

    _oneInstruction = contructorSubInstructionsProgram(5, 6, 7)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()


def contructorPAInstructionsProgram(primeiroTermo, pEnesimoTermo, razao):
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(pEnesimoTermo, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(1, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(primeiroTermo, 5)
    instructionMemory[2] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[3] = _oneInstruction
    
    machine()

    _oneInstruction = contructorSubInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()

    result = RAM[1]

    contructorMultInstructionsProgram(result, razao)

    _oneInstruction = contructorSomaInstructionsProgram(1, 5, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()


def contructorPGInstructionsProgram(primeiroTermo, pEnesimoTermo, razao):
  for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

  _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(pEnesimoTermo, 1)
  instructionMemory[0] = _oneInstruction

  _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(razao, 2)
  instructionMemory[1] = _oneInstruction

  _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(1, 3)
  instructionMemory[2] = _oneInstruction

  _oneInstruction = contructorHaltInstructionsProgram()
  instructionMemory[3] = _oneInstruction

  machine()

  _oneInstruction = contructorSubInstructionsProgram(1, 3, 1)
  instructionMemory[0] = _oneInstruction

  _oneInstruction = contructorHaltInstructionsProgram()
  instructionMemory[1] = _oneInstruction

  machine()

  result = RAM[1]

  contructorPotenciacaoInstructionsProgram(RAM[2], result)

  result = RAM[1]

  _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(primeiroTermo, 0)
  instructionMemory[0] = _oneInstruction

  _oneInstruction = contructorHaltInstructionsProgram()
  instructionMemory[1] = _oneInstruction

  machine()

  contructorMultInstructionsProgram(RAM[0], RAM[1])


def contructorJurosSimplesInstructionsProgram(capital, taxa, periodo):
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)
   
    contructorMultInstructionsProgram(capital, taxa)

    result = RAM[1]

    contructorMultInstructionsProgram(result, periodo)

    result = RAM[1]

    contructorDivInstructionsProgram(result, 100)


def contructorCelsiusToKelvinInstructionsProgram(celsius):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(celsius, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(273, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = contructorSubInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()


def contructorKelvinToFahrenheitInstructionsProgram(kelvin):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(kelvin, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(457, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = contructorSubInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()

def contructorRaizQuadradaInstructionsProgram(num):
    #Numero primos entre 1 e 100
    #22
    _numerosPrimos = [
        2, 3, 5, 7, 11, 13, 17, 19, 
        23, 31, 37, 41, 43, 47, 53, 
        59, 61, 67, 71, 73, 79, 83, 
        97
    ]

    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    for i in range(len(_numerosPrimos)):
        _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(_numerosPrimos[i], i + 5)
        instructionMemory[0] = _oneInstruction

        _oneInstruction = contructorHaltInstructionsProgram()
        instructionMemory[1] = _oneInstruction
        
        machine()

    resto = INT_MAX
    i = 5
    values = []
    aux = num
    n = INT_MAX

    while n != 0:
        contructorDivInstructionsProgram(aux, RAM[i])
        resultDiv = RAM[1]
        contructorMultInstructionsProgram(resultDiv, RAM[i])
        resultMult = RAM[1]
        resto = aux - resultMult

        if(resto == 0):
            values.append(RAM[i])
            n = aux - RAM[i]
            aux = resultDiv
            i = 5
        else:
            i += 1 
    valuesOrganizados = sorted(values)
    f = []
    
    i = 0
    while i < len(valuesOrganizados):
        if(valuesOrganizados[i] == valuesOrganizados[i + 1]):
            f.append(valuesOrganizados[i])
            i += 2
        else:
            i += 1

    result = 1

    for i in range(len(f)):
        contructorMultInstructionsProgram(f[i], result)
        result = RAM[1]
    
def contructorTeoremaPitagorasInstructionsProgram(b, c):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    contructorPotenciacaoInstructionsProgram(b, 2)

    resultPotenciacaoA = RAM[1]

    _oneInstruction = contructorLevarParaMemoriaInstructionsProgram(resultPotenciacaoA, 2)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction
    
    machine()

    contructorPotenciacaoInstructionsProgram(c, 2)

    _oneInstruction = contructorSomaInstructionsProgram(1, 2, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = contructorHaltInstructionsProgram()
    instructionMemory[1] = _oneInstruction

    machine()

    _resultMul = RAM[1]

    contructorRaizQuadradaInstructionsProgram(_resultMul)
    
if __name__ == '__main__':
  print('01 - Instruções Aleatorias')
  print('02 - Multiplicação')
  print('03 - Divisão')
  print('04 - Potenciação')
  print('05 - Fatorial')
  print('06 - Área do Triangulo ')
  print('07 - Velocidade Média')
  print('08 - Sequência Fibonacci')
  print('09 - Porcentagem')
  print('10 - Delta')
  print('11 - Termo Geral da P.A.')
  print('12 - Termo Geral da P.G.')
  print('13 - Juros Simples')
  print('14 - Celsius para Kelvin')
  print('15 - Kelvin para Fahrenheit')
  print('16 - Raiz Quadrada Exata')
  print('17 - Teorema de Pitágoras**')
  print('-1 - Sair')

  op = INT_MAX

  while op != -1:
    op = eval(input())
    constructorRam()
    if op == 1:
        constructorRandomInstructionsProgram()
        machine()
    elif op == 2:
        multiplicando = eval(input())
        multiplicador = eval(input())
        contructorMultInstructionsProgram(multiplicando, multiplicador)
        print('#Resultado:', RAM[1])
    elif op == 3:
        dividendo = eval(input())
        divisor = eval(input())
        contructorDivInstructionsProgram(dividendo, divisor)
        print('#Resultado:', RAM[1])
    elif op == 4:
        base = eval(input())
        expoente = eval(input())
        contructorPotenciacaoInstructionsProgram(base, expoente)
        print('#Resultado:', RAM[1])
    elif op == 5:
        num = eval(input())
        contructorFatorialInstructionsProgram(num)
        print('#Resultado:', RAM[1])
    elif op == 6:
        base = eval(input())
        altura = eval(input())
        contructorAreaTrianguloInstructionsProgram(base, altura)
        print('#Resultado:', RAM[1])
    elif op == 7:
        posicaoInicial = eval(input())
        posicaoFinal = eval(input())
        tempoInical = eval(input())
        tempoFinal = eval(input())
        contructorVelocidadeMediaInstructionsProgram(posicaoInicial, posicaoFinal, tempoInical, tempoFinal)
        print('#Resultado:', RAM[1])
    elif op == 8:
        num = eval(input())
        contructorFibonacciInstructionsProgram(num)
    elif op == 9:
        num = eval(input())
        porcentual = eval(input())
        contructorPorcentagemInstructionsProgram(num, porcentual)
        print('#Resultado:', RAM[1])
    elif op == 10:
        a = eval(input())
        b = eval(input())
        c = eval(input())
        contructorDeltaInstructionsProgram(a, b, c)
        print('#Resultado:', RAM[7])
    elif op == 11:
        primeiroTermo = eval(input())
        pEnesimoTermo = eval(input())
        razao = eval(input())
        contructorPAInstructionsProgram(primeiroTermo, pEnesimoTermo, razao)
        print('#Resultado:', RAM[1])
    elif op == 12:
        primeiroTermo = eval(input())
        pEnesimoTermo = eval(input())
        razao = eval(input())
        contructorPGInstructionsProgram(primeiroTermo, pEnesimoTermo, razao)
        print('#Resultado:', RAM[1])
    elif op == 13:
        capital = eval(input())
        taxa = eval(input())
        periodo = eval(input())
        contructorJurosSimplesInstructionsProgram(capital, taxa, periodo)
        print('#Resultado:', RAM[1])
    elif op == 14:
        celsius = eval(input())
        contructorCelsiusToKelvinInstructionsProgram(celsius)
        print('#Resultado:', RAM[1])
    elif op == 15:
        kelvin = eval(input())
        contructorKelvinToFahrenheitInstructionsProgram(kelvin)
        print('#Resultado:', RAM[1])
    elif op == 16:
        num = eval(input())
        contructorRaizQuadradaInstructionsProgram(num)
        print('#Resultado:', RAM[1])
    elif op == 17:
        b = eval(input())
        c = eval(input())
        contructorTeoremaPitagorasInstructionsProgram(b, c)
        print('#Resultado:', RAM[1])
    else:
        if op != -1: print('ERROR!')