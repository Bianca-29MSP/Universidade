import sys
from time import time
from pprint import pprint
from BlocoMemoria import BlocoMemoria
from hardDiskController import *

def buscarNasMemorias(e, RAM, cache1, cache2, cache3):
    custo = 0

    for posicaoCache1 in range(len(cache1)):
        if cache1[posicaoCache1].getEndBloco() == e.getEndBloco():
            custo += 10
            cache1[posicaoCache1].setCusto(custo)
            cache1[posicaoCache1].setCacheHit(1)
            cache1[posicaoCache1].setTimeUtilizado(time())
            return cache1[posicaoCache1]

    for posicaoCache2 in range(len(cache2)):
        if cache2[posicaoCache2].getEndBloco() == e.getEndBloco():
            custo += 110
            cache2[posicaoCache2].setCacheHit(2)
            cache2[posicaoCache2].setTimeUtilizado(time())
            return testaCache1Cache2(posicaoCache2, cache1, cache2, custo)

    for posicaoCache3 in range(len(cache3)):
        if cache3[posicaoCache3].getEndBloco() == e.getEndBloco():
            custo += 610
            cache3[posicaoCache3].setCacheHit(3)
            cache3[posicaoCache3].setTimeUtilizado(time())
            return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo)

    for posicaoRAM in range(len(RAM)):
        if RAM[posicaoRAM].getEndBloco() == e.getEndBloco():
            custo += 10610
            RAM[posicaoRAM].setCacheHit(4)
            RAM[posicaoRAM].setTimeUtilizado(time())
            return testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo)
        
    custo += 100610
    posicaoRAM = espacoLivreCache(RAM)
    if posicaoRAM  != -1:
        RAM[posicaoRAM] = lerDisco(e.getEndBloco())
        RAM[posicaoRAM].setAtualizado()
        RAM[posicaoRAM].setCacheHit(5)
        RAM[posicaoRAM].setTimeUtilizado(time())
        return testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo)
    else:
        posicaoRAM = leastRecentlyUsed(RAM) #melhor posição na RAM
        RAM[posicaoRAM].setNotAtualizado()
        end = RAM[posicaoRAM].getEndBloco()
        atualizarDisco(end, RAM[posicaoRAM])
        RAM[posicaoRAM] = lerDisco(e.getEndBloco())
        RAM[posicaoRAM].setAtualizado()
        RAM[posicaoRAM].setCacheHit(5)
        RAM[posicaoRAM].setTimeUtilizado(time())
        return testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo)

def testaCache1Cache2(posicaoCache2, cache1, cache2, custo):
    posicaoCache1 = espacoLivreCache(cache1)
    if posicaoCache1 != -1:
        cache1[posicaoCache1] = cache2[posicaoCache2]
    else:
        posicaoCache1 = leastRecentlyUsed(cache1)
        aux = BlocoMemoria()
        aux = cache1[posicaoCache1]
        cache1[posicaoCache1] = cache2[posicaoCache2]
        cache2[posicaoCache2] = aux
    cache1[posicaoCache1].setAtualizado()
    cache1[posicaoCache1].setTimeUtilizado(time())
    cache1[posicaoCache1].setCusto(custo)
    return cache1[posicaoCache1]

def testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo):
    posicaoCache2 = espacoLivreCache(cache2)
    if posicaoCache2 != -1:
        cache2[posicaoCache2] = cache3[posicaoCache3]
    else:
        posicaoCache2 = leastRecentlyUsed(cache2)
        aux = BlocoMemoria()
        aux = cache2[posicaoCache2]
        cache2[posicaoCache2] = cache3[posicaoCache3]
        cache3[posicaoCache3] = aux
    cache2[posicaoCache2].setTimeUtilizado(time())
    cache2[posicaoCache2].setCusto(custo)
    return testaCache1Cache2(posicaoCache2, cache1, cache2, custo)

def testaCache3RAM(posicaoRAM, cache1, cache2, cache3, RAM, custo):
    posicaoCache3 = espacoLivreCache(cache3)
    if posicaoCache3 != -1:
        cache3[posicaoCache3] = RAM[posicaoRAM]
    else:
        posicaoCache3 = leastRecentlyUsed(cache3)
        aux = BlocoMemoria()
        aux = cache3[posicaoCache3]
        cache3[posicaoCache3] = RAM[posicaoRAM]
        RAM[posicaoRAM] = aux
    cache3[posicaoCache3].setTimeUtilizado(time())
    cache3[posicaoCache3].setCusto(custo)
    return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo)

def espacoLivreCache(cache):
    for posicaoCache in range(len(cache)):
        if not cache[posicaoCache].isAtualizado():
            return posicaoCache
    return -1

def leastRecentlyUsed(cache): #LRU
    minTime = time()
    index = -1
    for i in range(len(cache)):
        if cache[i].getTimeUtilizado() < minTime:
            minTime = cache[i].getTimeUtilizado()
            index = i
    return index