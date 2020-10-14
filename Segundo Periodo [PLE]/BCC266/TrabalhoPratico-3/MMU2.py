import sys
from time import time
from pprint import pprint
from BlocoMemoria import BlocoMemoria
from ForRange import ForRange
from hardDiskController import *

def buscarNasMemorias(e, RAM, cache1, cache2, cache3):
    custo = 0

    conjunto = e.getEndBloco() % 2

    cache1Conjunto = int(len(cache1) / 2)
    cache2Conjunto = int(len(cache2) / 2)
    cache3Conjunto = int(len(cache3) / 2)

    forRangeStartC1 = 0
    forRangeStartC2 = 0
    forRangeStartC3 = 0
    forRangeEndC1 = 0
    forRangeEndC2 = 0
    forRangeEndC3 = 0

    if conjunto == 0:
        forRangeStartC1 = 0
        forRangeStartC2 = 0
        forRangeStartC3 = 0
        forRangeEndC1 = cache1Conjunto
        forRangeEndC2 = cache2Conjunto
        forRangeEndC3 = cache3Conjunto
    elif conjunto == 1:
        forRangeStartC1 = cache1Conjunto
        forRangeStartC2 = cache2Conjunto
        forRangeStartC3 = cache3Conjunto
        forRangeEndC1 = len(cache1)
        forRangeEndC2 = len(cache2)
        forRangeEndC3 = len(cache3)

    forRange = ForRange(forRangeStartC1, forRangeStartC2, forRangeStartC3, forRangeEndC1, forRangeEndC2, forRangeEndC3, len(RAM))

    for posicaoCache1 in range(forRange.getRangeStart('C1'), forRange.getRangeEnd('C1')):
        if cache1[posicaoCache1].getEndBloco() == e.getEndBloco():
            custo += 10
            cache1[posicaoCache1].setCusto(custo)
            cache1[posicaoCache1].setCacheHit(1)
            cache1[posicaoCache1].setTimeUtilizado(time())
            return cache1[posicaoCache1]

    for posicaoCache2 in range(forRange.getRangeStart('C2'), forRange.getRangeEnd('C2')):
        if cache2[posicaoCache2].getEndBloco() == e.getEndBloco():
            custo += 110
            cache2[posicaoCache2].setCacheHit(2)
            cache2[posicaoCache2].setTimeUtilizado(time())
            return testaCache1Cache2(posicaoCache2, cache1, cache2, custo, forRange)

    for posicaoCache3 in range(forRange.getRangeStart('C3'), forRange.getRangeEnd('C3')):
        if cache3[posicaoCache3].getEndBloco() == e.getEndBloco():
            custo += 610
            cache3[posicaoCache3].setCacheHit(3)
            cache3[posicaoCache3].setTimeUtilizado(time())
            return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo, forRange)
    
    for posicaoRAM in range(len(RAM)):
        if RAM[posicaoRAM].getEndBloco() == e.getEndBloco():
            custo += 10610
            RAM[posicaoRAM].setCacheHit(4)
            RAM[posicaoRAM].setTimeUtilizado(time())
            return testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo, forRange)
        
    custo += 100610
    posicaoRAM = espacoLivreCache(RAM, forRange, 'R')
    if posicaoRAM != -1:
        RAM[posicaoRAM] = lerDisco(e.getEndBloco())
        RAM[posicaoRAM].setCacheHit(5)
        RAM[posicaoRAM].setTimeUtilizado(time())
        return testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo, forRange)
    else:
        posicaoRAM = leastRecentlyUsed(RAM, forRange, 'R') #melhor posição na cache
        RAM[posicaoRAM].setNotAtualizado()
        end = RAM[posicaoRAM].getEndBloco()
        atualizarDisco(end, RAM[posicaoRAM])
        RAM[posicaoRAM] = lerDisco(e.getEndBloco())
        RAM[posicaoRAM].setCacheHit(5)
        RAM[posicaoRAM].setTimeUtilizado(time())
        return testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo, forRange)


def testaCache1Cache2(posicaoCache2, cache1, cache2, custo, forRange):
    posicaoCache1 = espacoLivreCache(cache1, forRange, 'C1')
    if posicaoCache1 != -1:
        cache1[posicaoCache1] = cache2[posicaoCache2]
    else:
        posicaoCache1 = leastRecentlyUsed(cache1, forRange, 'C1')
        aux = BlocoMemoria()
        aux = cache1[posicaoCache1]
        cache1[posicaoCache1] = cache2[posicaoCache2]
        cache2[posicaoCache2] = aux
    cache1[posicaoCache1].setAtualizado()
    cache1[posicaoCache1].setTimeUtilizado(time())
    cache1[posicaoCache1].setCusto(custo)
    return cache1[posicaoCache1]

def testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo, forRange):
    posicaoCache2 = espacoLivreCache(cache2, forRange, 'C2')
    if posicaoCache2 != -1:
        cache2[posicaoCache2] = cache3[posicaoCache3]
    else:
        posicaoCache2 = leastRecentlyUsed(cache2, forRange, 'C2')
        aux = BlocoMemoria()
        aux = cache2[posicaoCache2]
        cache2[posicaoCache2] = cache3[posicaoCache3]
        cache3[posicaoCache3] = aux
    cache2[posicaoCache2].setTimeUtilizado(time())
    cache2[posicaoCache2].setCusto(custo)
    return testaCache1Cache2(posicaoCache2, cache1, cache2, custo, forRange)

def testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo, forRange):
    posicaoCache3 = espacoLivreCache(cache3, forRange, 'C3')
    if posicaoCache3 != -1:
        cache3[posicaoCache3] = RAM[posicaoRAM]
    else:
        posicaoCache3 = leastRecentlyUsed(cache3, forRange, 'C3')
        aux = BlocoMemoria()
        aux = cache3[posicaoCache3]
        cache3[posicaoCache3] = RAM[posicaoRAM]
        RAM[posicaoRAM] = aux
    cache3[posicaoCache3].setTimeUtilizado(time())
    cache3[posicaoCache3].setCusto(custo)
    return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo, forRange)

def espacoLivreCache(cache, forRange, c):
    for posicaoCache in range(forRange.getRangeStart(c), forRange.getRangeEnd(c)):
        if not cache[posicaoCache].isAtualizado():
            return posicaoCache
    return -1

def leastRecentlyUsed(cache, forRange, c): #LRU
    minTime = time()
    index = -1
    for i in range(forRange.getRangeStart(c), forRange.getRangeEnd(c)):
        if cache[i].getTimeUtilizado() < minTime:
            minTime = cache[i].getTimeUtilizado()
            index = i
    return index