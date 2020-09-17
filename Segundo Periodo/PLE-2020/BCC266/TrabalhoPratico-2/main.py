from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from Instrucao import Instrucao
from MMU import buscarNasMemorias
import random
import sys

INT_MAX = sys.maxsize
INT_MIN = - sys.maxsize - 1 

tamanhoRam = 1000
tamanhoCache1 = 8
tamanhoCache2 = 16
tamanhoPrograma = 10001
quantidadePalavrasBloco = 4

memoriaInstrucoes = []
RAM = [BlocoMemoria()] * tamanhoRam
cache1 = [BlocoMemoria()] * tamanhoCache1
cache2 = [BlocoMemoria()] * tamanhoCache2

def montarRam():
    for i in range(tamanhoRam):
        aux = BlocoMemoria()
        aux.setEndBloco(i)
        palavras = [0] * quantidadePalavrasBloco
        for j in range(quantidadePalavrasBloco):
            palavras[j] = random.randint(0, 1000000)
        aux.setPlavras(palavras)
        RAM[i] = aux

def montarCacheVazia(tamanho, qqCache):
    for i in range(tamanho):
        aux = BlocoMemoria()
        aux.setEndBloco(INT_MIN)
        qqCache[i] = aux

def montarInstrucoesProgramaAleatorio():
    for _n in range(len(memoriaInstrucoes), tamanhoPrograma):
        memoriaInstrucoes.append(Instrucao())

    for i in range(tamanhoPrograma - 1):
        umaInstrucao = Instrucao()
        umaInstrucao.setOpcode(random.randint(0, 2))

        add1 = Endereco()
        add1.setEndBloco(random.randint(0, tamanhoRam - 1))
        add1.setEndPalavra(random.randint(0, quantidadePalavrasBloco - 1))
        umaInstrucao.setAdd1(add1)

        add2 = Endereco()
        add2.setEndBloco(random.randint(0, tamanhoRam - 1))
        add2.setEndPalavra(random.randint(0, quantidadePalavrasBloco - 1))
        umaInstrucao.setAdd2(add2)

        add3 = Endereco()
        add3.setEndBloco(random.randint(0, tamanhoRam - 1))
        add3.setEndPalavra(random.randint(0, quantidadePalavrasBloco - 1))
        umaInstrucao.setAdd3(add3)

        memoriaInstrucoes[i] = umaInstrucao
    
    umaInstrucao = Instrucao()
    umaInstrucao.setOpcode(-1)

    memoriaInstrucoes[tamanhoPrograma-1] = umaInstrucao

def maquina():
    PC = 0
    opcode = INT_MAX
    custo = 0
    missC1 = 0
    hitC1 = 0
    missC2 = 0
    hitC2 = 0

    while opcode != -1:
        umaInstrucao = Instrucao()
        umaInstrucao = memoriaInstrucoes[PC]
        opcode = umaInstrucao.getOpcode()

        if opcode != -1:
            dadoMemoriaAdd1 = buscarNasMemorias(umaInstrucao.getAdd1(), RAM, cache1, cache2)
            dadoMemoriaAdd2 = buscarNasMemorias(umaInstrucao.getAdd2(), RAM, cache1, cache2)
            dadoMemoriaAdd3 = buscarNasMemorias(umaInstrucao.getAdd3(), RAM, cache1, cache2)

            custo += dadoMemoriaAdd1.getCusto()
            custo += dadoMemoriaAdd2.getCusto()
            custo += dadoMemoriaAdd3.getCusto()

            if dadoMemoriaAdd1.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 2:
                missC1 += 1
                hitC2 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 3:
                missC1 += 1
                missC2 += 1
            
            if dadoMemoriaAdd2.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 2:
                missC1 += 1
                hitC2 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 3:
                missC1 += 1
                missC2 += 1

            if dadoMemoriaAdd3.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 2:
                missC1 += 1
                hitC2 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 3:
                missC1 += 1
                missC2 += 1

            print('Custo até o momento do programa em execução: {0}'.format(custo))
            print('Hits e Misses ate o momento: C1 hit: {0} | C1 miss: {1} | C2 hit: {2} | C2 miss: {3} |'.format(hitC1, missC1, hitC2, missC2))

            if opcode == 0:
                pass
                #print('Não há demanda por levar dados externos para as memorias.')
            elif opcode == 1:
                conteudo1 = dadoMemoriaAdd1.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                conteudo2 = dadoMemoriaAdd2.getPalavras()[umaInstrucao.getAdd2().getEndPalavra()]
                soma = conteudo1 + conteudo2
                dadoMemoriaAdd3.getPalavras()[umaInstrucao.getAdd3().getEndPalavra()] = soma
                #print('#S+: {0}'.format(soma))
            elif opcode == 2:
                conteudo1 = dadoMemoriaAdd1.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                conteudo2 = dadoMemoriaAdd2.getPalavras()[umaInstrucao.getAdd2().getEndPalavra()]
                sub = conteudo1 - conteudo2
                dadoMemoriaAdd3.getPalavras()[umaInstrucao.getAdd3().getEndPalavra()] = sub
                #print('#S-: {0}'.format(sub))

            PC += 1


if __name__ == '__main__':
    montarRam()
    montarCacheVazia(tamanhoCache1, cache1)
    montarCacheVazia(tamanhoCache2, cache2)
    montarInstrucoesProgramaAleatorio()
    maquina()