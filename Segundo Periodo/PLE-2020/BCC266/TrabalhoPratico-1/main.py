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


def addInstructionsProgram(address1, address2, address3):
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 1
    _oneInstruction[1] = address1
    _oneInstruction[2] = address2
    _oneInstruction[3] = address3
    return _oneInstruction


def subInstructionsProgram(address1, address2, address3):
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 2
    _oneInstruction[1] = address1
    _oneInstruction[2] = address2
    _oneInstruction[3] = address3
    return _oneInstruction


def pushMemoryInstructionsProgram(value, address):
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
    _oneInstruction = [-1] * 4
    instructionMemory[9] = _oneInstruction


def constructorMultInstructionsProgram(multiplicando, multiplicador):
    for n in range(len(instructionMemory), multiplicador + 3):
        instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(multiplicando, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(0, 1)
    instructionMemory[1] = _oneInstruction

    for i in range(multiplicador):
        _oneInstruction = [0] * 4
        _oneInstruction = addInstructionsProgram(0, 1, 1)
        instructionMemory[i + 2] = _oneInstruction

    _oneInstruction = [-1] * 4

    instructionMemory[multiplicador + 2] = _oneInstruction

    machine()


def constructorPotenciacaoInstructionsProgram(base, expoente):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    if base < 0 and expoente % 2 == 0:
        base *= -1

    _oneInstruction = pushMemoryInstructionsProgram(base, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    result = RAM[1]

    for i in range(expoente - 1):
        constructorMultInstructionsProgram(result, base)
        result = RAM[1]


def constructorDivInstructionsProgram(dividendo, divisor):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    #Levando o dividendo para o endereço 0 da RAM
    _oneInstruction = pushMemoryInstructionsProgram(dividendo,0)
    instructionMemory[0] = _oneInstruction

    # Levando o divisor para o endereço 1 da RAM
    _oneInstruction = pushMemoryInstructionsProgram(divisor, 1)
    instructionMemory[1] = _oneInstruction

    #Halt para parar o loop
    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction

    #Executando as instruções da memoria
    machine()

    count = 0
    while RAM[0] >= divisor:
        _oneInstruction = [0] * 4
        #Subitraindo o VALOR no ENDEREÇO 0 com o VALOR do ENDEREÇO 1 e guardando no 0
        _oneInstruction = subInstructionsProgram(0, 1, 0)
        instructionMemory[0] = _oneInstruction

        # Halt para parar o loop
        _oneInstruction = [-1] * 4
        instructionMemory[1] = _oneInstruction

        # Executando as instruções da memoria
        machine()

        count += 1

    #Guardando resultado na memoria
    _oneInstruction = pushMemoryInstructionsProgram(count, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    #Executando as instruções da memoria
    machine()


def constructorFatorialInstructionsProgram(num):
    for n in range(len(instructionMemory), 3):
      instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    aux = RAM[1]

    while num != 0:
        constructorMultInstructionsProgram(aux, num)

        _oneInstruction = pushMemoryInstructionsProgram(RAM[1], 1)
        instructionMemory[0] = _oneInstruction

        _oneInstruction = [-1] * 4
        instructionMemory[1] = _oneInstruction

        machine()
        
        aux = RAM[1]
        num -= 1


def constructorTriangleInstructionsProgram(base, altura):
    constructorMultInstructionsProgram(base, altura)

    result = RAM[1]

    constructorDivInstructionsProgram(result, 2)


def constructorVelocityInstructionsProgram(posicaoInicial, posicaoFinal, tempoInical, tempoFinal):
    for n in range(len(instructionMemory), 7):
        instructionMemory.append(0)

    #Variação da posição
    _oneInstruction = pushMemoryInstructionsProgram(posicaoFinal, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(posicaoInicial, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction = subInstructionsProgram(0, 1, 2)
    instructionMemory[2] = _oneInstruction

    #Variação do tempo
    _oneInstruction = pushMemoryInstructionsProgram(tempoFinal, 3)
    instructionMemory[3] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(tempoInical, 4)
    instructionMemory[4] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction = subInstructionsProgram(3, 4, 5)
    instructionMemory[5] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[6] = _oneInstruction

    machine()

    variacaoPosicao = RAM[2]
    variacaoDistancia = RAM[5]

    constructorDivInstructionsProgram(variacaoPosicao, variacaoDistancia)


def constructorFibonacciInstructionsProgram(num):    
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(1, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(0, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(0, 2)
    instructionMemory[2] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[3] = _oneInstruction

    machine()

    i = 0
    while(i < num):
        print(RAM[2])
        _oneInstruction = [0] * 4
        _oneInstruction = addInstructionsProgram(0, 1, 2)
        instructionMemory[0] = _oneInstruction

        _oneInstruction = [0] * 4
        _oneInstruction = [-1] * 4
        instructionMemory[1] = _oneInstruction

        machine()

        _oneInstruction = pushMemoryInstructionsProgram(RAM[1], 0)
        instructionMemory[0] = _oneInstruction
        
        _oneInstruction = pushMemoryInstructionsProgram(RAM[2], 1)
        instructionMemory[1] = _oneInstruction

        _oneInstruction = [-1] * 4
        instructionMemory[2] = _oneInstruction

        machine()

        i+= 1


def constructorPercentInstructionsProgram(num, porcentual):
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

    constructorMultInstructionsProgram(porcentual, num)

    result = RAM[1]

    constructorDivInstructionsProgram(result, 100)


def constructorDeltaInstructionsProgram(a, b, c):
    for n in range(len(instructionMemory), 2):
        instructionMemory.append(0)

    #Potenciação b²
    constructorPotenciacaoInstructionsProgram(b, 2)
    result = RAM[1]

    #Guardando na RAM[5] o resultado
    _oneInstruction = pushMemoryInstructionsProgram(result, 5)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    #Multiplicação 4 x a
    constructorMultInstructionsProgram(4, a)
    machine()
    result = RAM[1]
    
    #Multiplicação 4 x a x c
    constructorMultInstructionsProgram(result, c)
    machine()
    
    #Guardando na RAM[6] o resultado
    result = RAM[1]
    _oneInstruction = pushMemoryInstructionsProgram(result, 6)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction
    
    machine()

    _oneInstruction = subInstructionsProgram(5, 6, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()


def constructorPAInstructionsProgram(primeiroTermo, pEnesimoTermo, razao):
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(pEnesimoTermo, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(1, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(primeiroTermo, 5)
    instructionMemory[2] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[3] = _oneInstruction
    
    machine()

    _oneInstruction = subInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    result = RAM[1]

    constructorMultInstructionsProgram(result, razao)

    _oneInstruction = addInstructionsProgram(1, 5, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()


def constructorPGInstructionsProgram(primeiroTermo, pEnesimoTermo, razao):
  for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)

  _oneInstruction = pushMemoryInstructionsProgram(pEnesimoTermo, 1)
  instructionMemory[0] = _oneInstruction

  _oneInstruction = pushMemoryInstructionsProgram(razao, 2)
  instructionMemory[1] = _oneInstruction

  _oneInstruction = pushMemoryInstructionsProgram(1, 3)
  instructionMemory[2] = _oneInstruction

  _oneInstruction = [-1] * 4
  instructionMemory[3] = _oneInstruction

  machine()

  _oneInstruction = subInstructionsProgram(1, 3, 1)
  instructionMemory[0] = _oneInstruction

  _oneInstruction = [-1] * 4
  instructionMemory[1] = _oneInstruction

  machine()

  result = RAM[1]

  constructorPotenciacaoInstructionsProgram(RAM[2], result)

  result = RAM[1]

  _oneInstruction = pushMemoryInstructionsProgram(primeiroTermo, 0)
  instructionMemory[0] = _oneInstruction

  _oneInstruction = [-1] * 4
  instructionMemory[1] = _oneInstruction

  machine()

  constructorMultInstructionsProgram(RAM[0], RAM[1])


def constructorSimpleInterestInstructionsProgram(capital, taxa, periodo):
    for n in range(len(instructionMemory), 4):
        instructionMemory.append(0)
   
    constructorMultInstructionsProgram(capital, taxa)

    result = RAM[1]

    constructorMultInstructionsProgram(result, periodo)

    result = RAM[1]

    constructorDivInstructionsProgram(result, 100)


def constructorCelsiusToKelvinInstructionsProgram(celsius):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(celsius, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(273, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = addInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()


def constructorKelvinToCelsiusInstructionsProgram(kelvin):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(kelvin, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(273, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = subInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()


def constructorSquareRootInstructionsProgram(num):
    #Numero primos entre 1 e 100
    _numerosPrimos = [
        2, 3, 5, 7, 11, 13, 17, 19, 
        23, 31, 37, 41, 43, 47, 53, 
        59, 61, 67, 71, 73, 79, 83, 
        97
    ]

    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    for i in range(len(_numerosPrimos)):
        _oneInstruction = pushMemoryInstructionsProgram(_numerosPrimos[i], i + 5)
        instructionMemory[0] = _oneInstruction

        _oneInstruction = [-1] * 4
        instructionMemory[1] = _oneInstruction
        
        machine()

    resto = INT_MAX
    i = 5
    values = []
    aux = num
    n = INT_MAX

    while n != 0:
        constructorDivInstructionsProgram(aux, RAM[i])
        resultDiv = RAM[1]
        constructorMultInstructionsProgram(resultDiv, RAM[i])
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
        constructorMultInstructionsProgram(f[i], result)
        result = RAM[1]
    

def constructorPitagorasInstructionsProgram(b, c):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    constructorPotenciacaoInstructionsProgram(b, 2)

    resultPotenciacaoA = RAM[1]

    _oneInstruction = pushMemoryInstructionsProgram(resultPotenciacaoA, 2)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction
    
    machine()

    constructorPotenciacaoInstructionsProgram(c, 2)

    _oneInstruction = addInstructionsProgram(1, 2, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    _resultMul = RAM[1]

    constructorSquareRootInstructionsProgram(_resultMul)
    

def constructorDistanceBetween2PointsInstructionsProgram(xa, xb, ya, yb):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(xa, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(xb, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = subInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    resultX = RAM[1]

    _oneInstruction = pushMemoryInstructionsProgram(ya, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(yb, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = subInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    resultY = RAM[1]

    constructorPotenciacaoInstructionsProgram(resultX, 2)

    resultX = RAM[1]
    

    constructorPotenciacaoInstructionsProgram(resultY, 2)

    resultY = RAM[1]

    _oneInstruction = pushMemoryInstructionsProgram(resultX, 3)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction
    
    machine()

    _oneInstruction = addInstructionsProgram(1, 3, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    resultXY = RAM[1]

    constructorSquareRootInstructionsProgram(resultXY)


def constructorAddInstructionsProgram(num1, num2):
    for n in range(len(instructionMemory), 3):
      instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(num1, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(num2, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = addInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()


def constructorSubInstructionsProgram(num1, num2):
    for n in range(len(instructionMemory), 3):
      instructionMemory.append(0)

    _oneInstruction = pushMemoryInstructionsProgram(num1, 0)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = pushMemoryInstructionsProgram(num2, 1)
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction
    
    machine()

    _oneInstruction = subInstructionsProgram(0, 1, 1)
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()


if __name__ == '__main__':
    print('01 - Instruções Aleatorias')
    print('02 - Soma')
    print('03 - Subtração')
    print('04 - Multiplicação')
    print('05 - Divisão')
    print('06 - Potenciação')
    print('07 - Fatorial')
    print('08 - Área do Triangulo ')
    print('09 - Velocidade Média')
    print('10 - Sequência Fibonacci')
    print('11 - Porcentagem')
    print('12 - Delta')
    print('13 - Termo Geral da P.A.')
    print('14 - Termo Geral da P.G.')
    print('15 - Juros Simples')
    print('16 - Celsius para Kelvin')
    print('17 - Kelvin para Fahrenheit')
    print('18 - Raiz Quadrada Exata')
    print('19 - Teorema de Pitágoras')
    print('20 - Distancia Entre Dois Pontos')
    print('-1 - Sair')

    op = INT_MAX

    while op != -1:
        op = eval(input())
        constructorRam()
        if op == 1:
            constructorRandomInstructionsProgram()
            machine()
        elif op == 2:
            num1 = eval(input())
            num2 = eval(input())
            constructorAddInstructionsProgram(num1, num2)
        elif op == 3:
            num1 = eval(input())
            num2 = eval(input())
            constructorSubInstructionsProgram(num1, num2)
        elif op == 4:
            multiplicando = eval(input())
            multiplicador = eval(input())
            constructorMultInstructionsProgram(multiplicando, multiplicador)
        elif op == 5:
            dividendo = eval(input())
            divisor = eval(input())
            constructorDivInstructionsProgram(dividendo, divisor)
        elif op == 6:
            base = eval(input())
            expoente = eval(input())
            constructorPotenciacaoInstructionsProgram(base, expoente)
        elif op == 7:
            num = eval(input())
            constructorFatorialInstructionsProgram(num)
        elif op == 8:
            base = eval(input())
            altura = eval(input())
            constructorTriangleInstructionsProgram(base, altura)
        elif op == 9:
            posicaoInicial = eval(input())
            posicaoFinal = eval(input())
            tempoInical = eval(input())
            tempoFinal = eval(input())
            constructorVelocityInstructionsProgram(posicaoInicial, posicaoFinal, tempoInical, tempoFinal)
        elif op == 10:
            num = eval(input())
            constructorFibonacciInstructionsProgram(num)
        elif op == 11:
            num = eval(input())
            porcentual = eval(input())
            constructorPercentInstructionsProgram(num, porcentual)
        elif op == 12:
            a = eval(input())
            b = eval(input())
            c = eval(input())
            constructorDeltaInstructionsProgram(a, b, c)
        elif op == 13:
            primeiroTermo = eval(input())
            pEnesimoTermo = eval(input())
            razao = eval(input())
            constructorPAInstructionsProgram(primeiroTermo, pEnesimoTermo, razao)
        elif op == 14:
            primeiroTermo = eval(input())
            pEnesimoTermo = eval(input())
            razao = eval(input())
            constructorPGInstructionsProgram(primeiroTermo, pEnesimoTermo, razao)
        elif op == 15:
            capital = eval(input())
            taxa = eval(input())
            periodo = eval(input())
            constructorSimpleInterestInstructionsProgram(capital, taxa, periodo)
        elif op == 16:
            celsius = eval(input())
            constructorCelsiusToKelvinInstructionsProgram(celsius)
        elif op == 17:
            kelvin = eval(input())
            constructorKelvinToCelsiusInstructionsProgram(kelvin)
        elif op == 18:
            num = eval(input())
            constructorSquareRootInstructionsProgram(num)
        elif op == 19:
            b = eval(input())
            c = eval(input())
            constructorPitagorasInstructionsProgram(b, c)
        elif op == 20:
            xa = eval(input())
            xb = eval(input())
            ya = eval(input())
            yb = eval(input())
            constructorDistanceBetween2PointsInstructionsProgram(xa, xb, ya, yb)
        else:
            if op != -1: print('ERROR!')
            continue
        print('#Resultado:', RAM[1])