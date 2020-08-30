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
        _PC += 1


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


def contructorMultInstructionsProgram(multiplicando, multiplicador):
    for n in range(len(instructionMemory), multiplicador + 3):
        instructionMemory.append(0)

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = multiplicando
    _oneInstruction[2] = 0
    _oneInstruction[3] = -1
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = 0
    _oneInstruction[2] = 1
    _oneInstruction[3] = -1
    instructionMemory[1] = _oneInstruction

    for i in range(multiplicador):
        _oneInstruction = [0] * 4
        _oneInstruction[0] = 1
        _oneInstruction[1] = 0
        _oneInstruction[2] = 1
        _oneInstruction[3] = 1
        instructionMemory[i + 2] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = 0
    _oneInstruction[2] = 1
    _oneInstruction[3] = -1

    _oneInstruction = [-1] * 4

    instructionMemory[multiplicador + 2] = _oneInstruction


def contructorPotenciacaoInstructionsProgram(base, expoente):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = base
    _oneInstruction[2] = 1
    _oneInstruction[3] = -1
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[1] = _oneInstruction

    machine()

    for i in range(expoente - 1):
        contructorMultInstructionsProgram(RAM[1], base)
        machine()

    print(RAM[1])


def contructorDivInstructionsProgram(dividendo, divisor):
    for n in range(len(instructionMemory), 3):
        instructionMemory.append(0)

    #Levando o dividendo para o endereço 0 da RAM
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = dividendo
    _oneInstruction[2] = 0
    _oneInstruction[3] = -1
    instructionMemory[0] = _oneInstruction

    # Levando o divisor para o endereço 1 da RAM
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = divisor
    _oneInstruction[2] = 1
    _oneInstruction[3] = -1
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
        _oneInstruction[0] = 2
        _oneInstruction[1] = 0
        _oneInstruction[2] = 1
        _oneInstruction[3] = 0
        instructionMemory[0] = _oneInstruction

        # Halt para parar o loop
        _oneInstruction = [-1] * 4
        instructionMemory[1] = _oneInstruction

        # Executando as instruções da memoria
        machine()

        count += 1

    #Guardando resultado na memoria
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = count
    _oneInstruction[2] = 1
    _oneInstruction[3] = -1
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[2] = _oneInstruction

    #Executando as instruções da memoria
    machine()

    print(RAM[1])


def contructorFatorialInstructionsProgram(num):
    aux = 1
    while num != 0:
        contructorMultInstructionsProgram(aux, num)
        machine()
        aux = RAM[1]
        num -= 1

    print(RAM[1])

def contructorAreaTrianguloInstructionsProgram(base, altura):
    contructorMultInstructionsProgram(base, altura)
    machine()

    result = RAM[1]

    contructorDivInstructionsProgram(result, 2)

    print(RAM[1])


def contructorVelocidadeMediaInstructionsProgram(posicaoInicial, posicaoFinal, tempoInical, tempoFinal):
    for n in range(len(instructionMemory), 7):
        instructionMemory.append(0)

    #Variação da posição
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = posicaoFinal
    _oneInstruction[2] = 0
    _oneInstruction[3] = -1
    instructionMemory[0] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = posicaoInicial
    _oneInstruction[2] = 1
    _oneInstruction[3] = -1
    instructionMemory[1] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 2
    _oneInstruction[1] = 0
    _oneInstruction[2] = 1
    _oneInstruction[3] = 2
    instructionMemory[2] = _oneInstruction

    #Variação do tempo
    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = tempoFinal
    _oneInstruction[2] = 3
    _oneInstruction[3] = -1
    instructionMemory[3] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 0
    _oneInstruction[1] = tempoInical
    _oneInstruction[2] = 4
    _oneInstruction[3] = -1
    instructionMemory[4] = _oneInstruction

    _oneInstruction = [0] * 4
    _oneInstruction[0] = 2
    _oneInstruction[1] = 3
    _oneInstruction[2] = 4
    _oneInstruction[3] = 5
    instructionMemory[5] = _oneInstruction

    _oneInstruction = [-1] * 4
    instructionMemory[6] = _oneInstruction

    machine()

    variacaoPosicao = RAM[2]
    variacaoDistancia = RAM[5]

    contructorDivInstructionsProgram(variacaoPosicao, variacaoDistancia)

    print(RAM[1], "Km/h")
  

if __name__ == '__main__':
  print('OPÇÕES DO MENU')
  print('01 - Instruções Aleatorias')
  print('02 - Instrução de Multiplicação')
  print('03 - Instrução de Divisão')
  print('04 - Instrução de Potenciação')
  print('05 - Instrução Fatorial')
  print('06 - Instrução Área do Triangulo ')
  print('07 - Instrução Velocidade Média')
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
        machine()
        print(RAM[1])
    elif op == 3:
        dividendo = eval(input())
        divisor = eval(input())
        contructorDivInstructionsProgram(dividendo, divisor)
    elif op == 4:
        base = eval(input())
        expoente = eval(input())
        contructorPotenciacaoInstructionsProgram(base, expoente)
    elif op == 5:
        num = eval(input())
        contructorFatorialInstructionsProgram(num)
    elif op == 6:
        base = eval(input())
        altura = eval(input())
        contructorAreaTrianguloInstructionsProgram(base, altura)
    elif op == 7:
        posicaoInicial = eval(input())
        posicaoFinal = eval(input())
        tempoInical = eval(input())
        tempoFinal = eval(input())
        contructorVelocidadeMediaInstructionsProgram(posicaoInicial, posicaoFinal, tempoInical, tempoFinal)
    else:
        if op != -1: print('ERROR!')