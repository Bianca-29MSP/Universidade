import random
import sys
import time
from pprint import pprint
from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from Instrucao import Instrucao
from hardDiskController import montarDisco 
from MMU2 import buscarNasMemorias
from generator import generator

INT_MAX = sys.maxsize
INT_MIN = (sys.maxsize * -1) - 1

cachesM1 = [8, 16, 32]
cachesM2 = [32, 64, 128]
cachesM3 = [16, 64, 256]
cachesM4 = [8, 32, 128]
cachesM5 = [16, 32, 64]

tamanhoRam = 1000
M = 'M3'
tamanhoCache1 = cachesM3[0]
tamanhoCache2 = cachesM3[1]
tamanhoCache3 = cachesM3[2]
tamanhoPrograma = 10001
quantidadePalavrasBloco = 4
tamanhoProgramaInterrupcao = 101

memoriaInstrucoes = []
RAM = [BlocoMemoria()] * tamanhoRam
cache1 = [BlocoMemoria()] * tamanhoCache1
cache2 = [BlocoMemoria()] * tamanhoCache2
cache3 = [BlocoMemoria()] * tamanhoCache3

fileName = './instructions/INST_20_75'

def montarRam():
    for i in range(tamanhoRam):
        aux = BlocoMemoria()
        aux.setEndBloco(i)
        palavras = [0] * quantidadePalavrasBloco
        for j in range(quantidadePalavrasBloco):
            palavras[j] = random.randint(0, 1000000)
        aux.setPalavras(palavras)
        RAM[i] = aux

def montarRamVazia():
    for i in range(tamanhoRam):
        aux = BlocoMemoria()
        aux.setEndBloco(INT_MIN)
        RAM[i] = aux

def montarCacheVazia(tamanho, qqCache):
    for i in range(tamanho):
        aux = BlocoMemoria()
        aux.setEndBloco(INT_MIN)
        qqCache[i] = aux

def montarInstrucaoGerador(nome, tamanho):

    for _n in range(len(memoriaInstrucoes), tamanho):
        memoriaInstrucoes.append(Instrucao())
    
    try:
        file = open(nome + '.txt', 'r')
        file.readline()
        fileLines = file.read().split('\n')
        for i in range(tamanho - 1):
            palavras = [0] * 7
            palavras = fileLines[i].split(' ')
            
            umaInstrucao = Instrucao()
            umaInstrucao.setOpcode(int(palavras[0]))

            e1 = Endereco()
            e1_endBloco = int(palavras[1])
            e1_endPalavra = int(palavras[2])
            e1.setEndBloco(e1_endBloco)
            e1.setEndPalavra(e1_endPalavra)
            umaInstrucao.setAdd1(e1)

            e2 = Endereco()
            e2_endBloco = int(palavras[3])
            e2_endPalavra = int(palavras[4])
            e2.setEndBloco(e2_endBloco)
            e2.setEndPalavra(e2_endPalavra)
            umaInstrucao.setAdd2(e2)

            e3 = Endereco()
            e3_endBloco = int(palavras[5])
            e3_endPalavra = int(palavras[6])
            e3.setEndBloco(e3_endBloco)
            e3.setEndPalavra(e3_endPalavra)
            umaInstrucao.setAdd3(e3)

            memoriaInstrucoes[i] = umaInstrucao

        file.close()

        umaInstrucao = Instrucao()
        umaInstrucao.setOpcode(-1)
        memoriaInstrucoes[tamanho - 1] = umaInstrucao

    except FileNotFoundError:
        print('Arquivo não encontrado!')

    except:
        print("Erro ao abrir arquivo!")

def maquina(programa):
    PC = 0
    opcode = INT_MAX
    custo = 0
    hitC1 = 0
    missC1 = 0
    hitC2 = 0
    missC2 = 0
    hitC3 = 0
    missC3 = 0
    hitRAM = 0
    missRAM = 0
    totalMiss = 0
    totalHit = 0
    hitHD = 0

    numInterrInternas = 0
    numInterrExternas = 0

    while opcode != -1:
        umaInstrucao = Instrucao()
        umaInstrucao = memoriaInstrucoes[PC]
        opcode = umaInstrucao.getOpcode()

        if opcode != -1:
            dadoMemoriaAdd1 = buscarNasMemorias(umaInstrucao.getAdd1(), RAM, cache1, cache2, cache3)
            dadoMemoriaAdd2 = buscarNasMemorias(umaInstrucao.getAdd2(), RAM, cache1, cache2, cache3)
            dadoMemoriaAdd3 = buscarNasMemorias(umaInstrucao.getAdd3(), RAM, cache1, cache2, cache3)

            custo += dadoMemoriaAdd1.getCusto()
            custo += dadoMemoriaAdd2.getCusto()
            custo += dadoMemoriaAdd3.getCusto()

            if dadoMemoriaAdd1.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 2:
                hitC2 += 1
                missC1 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 3:
                hitC3 += 1
                missC1 += 1
                missC2 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 4:
                hitRAM += 1
                missC1 += 1
                missC2 += 1
                missC3 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 5:
                hitHD += 1
                missC1 += 1
                missC2 += 1
                missC3 += 1
                missRAM += 1

            if dadoMemoriaAdd2.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 2:
                hitC2 += 1
                missC1 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 3:
                hitC3 += 1
                missC1 += 1
                missC2 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 4:
                hitRAM += 1
                missC1 += 1
                missC2 += 1
                missC3 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 5:
                hitHD += 1
                missC1 += 1
                missC2 += 1
                missC3 += 1
                missRAM += 1

            if dadoMemoriaAdd3.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 2:
                hitC2 += 1
                missC1 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 3:
                hitC3 += 1
                missC1 += 1
                missC2 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 4:
                hitRAM += 1
                missC1 += 1
                missC2 += 1
                missC3 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 5:
                hitHD += 1
                missC1 += 1
                missC2 += 1
                missC3 += 1
                missRAM += 1

            print('Custo até o momendo da execução do programa: {0}'.format( custo ))
            print('C1 hit: {0} | C1 miss: {1} | C2 hit: {2} | C2 miss: {3} | C3 hit: {4} | C3 miss: {5} | RAM hit: {6} | RAM miss: {7}'
            .format( hitC1, missC1, hitC2, missC2, hitC3, missC3, hitRAM, missRAM ))

            if opcode == 0:
                if programa == "instructions":
                    chance = random.randint(0, 5) #20% de chance
                    if chance == 0:
                        numInterrInternas += 1
                        print('#INICIO - TRATADOR DE INTERRUPCAO')

                        fileNameIntr = './interruptions/INTR'
                        tamanho = random.randint(20, tamanhoProgramaInterrupcao)
                        generator('./interruptions/INTR', tamanho, 10, 70)
                        montarInstrucaoGerador(fileNameIntr, tamanho)
                        maquina("interruption")

                        print('#FIM - TRATADOR DE INTERRUPCAO')
                        montarInstrucaoGerador(fileName, tamanhoPrograma)

            elif opcode == 1:
                conteudo1 = dadoMemoriaAdd1.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                conteudo2 = dadoMemoriaAdd2.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                soma = conteudo1 + conteudo2
                dadoMemoriaAdd3.getPalavras()[umaInstrucao.getAdd3().getEndPalavra()] = soma

            elif opcode == 2:
                conteudo1 = dadoMemoriaAdd1.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                conteudo2 = dadoMemoriaAdd2.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                sub = conteudo1 - conteudo2
                dadoMemoriaAdd3.getPalavras()[umaInstrucao.getAdd3().getEndPalavra()] = sub
                
            PC += 1
        
        if programa == "instructions":
            chance = random.randint(0, 8) #12.5% de chance
            if chance == 0:
                numInterrExternas += 1
                print('#INICIO - TRATADOR DE INTERRUPCAO')

                fileNameIntr = './interruptions/INTR'
                tamanho = random.randint(20, tamanhoProgramaInterrupcao)
                generator('./interruptions/INTR', tamanho, 10, 70)
                montarInstrucaoGerador( fileNameIntr, tamanho)

                maquina("interruption")

                print('#FIM - TRATADOR DE INTERRUPCAO')
                montarInstrucaoGerador(fileName, tamanhoPrograma)

    if programa == "instructions":
        totalHit = hitC1 + hitC2 + hitC3 + hitRAM
        totalMiss = missC1 + missC2 + missC3 + missRAM

    if opcode == -1 and programa == "instructions":
        taxaC1 = round((hitC1 * 100) / (hitC1 + missC1), 2)
        taxaC2 = round((hitC2 * 100) / (hitC2 + missC2), 2)
        taxaC3 = round((hitC3 * 100) / (hitC3 + missC3), 2)
        taxaRam = round((hitRAM * 100) / (hitRAM + missRAM), 2)
        print("FIM")
        print('Custo total do programa: {0}'.format(custo))
        print('Hit e Misses do programa:')
        print('C1 hit:  {0}  | C1 miss:  {1}'.format( hitC1, missC1 ))
        print('C2 hit:  {0}  | C2 miss:  {1}'.format( hitC2, missC2 ))
        print('C3 hit:  {0}  | C3 miss:  {1}'.format( hitC3, missC3 ))
        print('RAM hit: {0}  | RAM miss: {1}'.format( hitRAM, missRAM ))
        print('Interrupções  | Internas: {0} | Externas: {1}'.format(numInterrInternas, numInterrExternas))
        print('Cache C1  | HIT: {0}% | MISS: {1}%'.format(taxaC1, round((100 - taxaC1), 2)))
        print('Cache C2  | HIT: {0}% | MISS: {1}%'.format(taxaC2, round((100 - taxaC2), 2)))
        print('Cache C3  | HIT: {0}% | MISS: {1}%'.format(taxaC3, round((100 - taxaC3), 2)))
        print('Cache RAM | HIT: {0}% | MISS: {1}%'.format(taxaRam, round((100 - taxaRam), 2)))
        print('HD        | HIT: {0} | MISS: {1}%'.format(hitHD, 0))
        print('Total     | HIT: {0} | MISS: {1}'.format( totalHit, totalMiss ))
        
if __name__ == "__main__":
    tempo_inicial = time.time()
    montarRamVazia()
    montarDisco()
    montarCacheVazia(tamanhoCache1, cache1)
    montarCacheVazia(tamanhoCache2, cache2)
    montarCacheVazia(tamanhoCache3, cache3)
    montarInstrucaoGerador(fileName, tamanhoPrograma)
    maquina("instructions")
    print('#Done!')
    tempo_final = time.time()
    tempoTotal = round( ( ( tempo_final  - tempo_inicial) / 60 ) , 2)
    print("#Tempo de execução: {0} minutos".format(tempoTotal) )
    print("File: {0}   {1}".format(fileName, M))