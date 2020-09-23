import sys
from time import time
from pprint import pprint
from BlocoMemoria import BlocoMemoria

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
        
    custo += 10610
    posicaoCache3 = espacoLivreCache(cache3)
    if posicaoCache3 != -1:
        cache3[posicaoCache3] = RAM[e.getEndBloco()]
        cache3[posicaoCache3].setCacheHit(4)
        cache3[posicaoCache3].setTimeUtilizado(time())
        return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo)
    else:
        posicaoCache3 = leastRecentlyUsed(cache3) #melhor posição na cache
        cache3[posicaoCache2].setNotAtualizado()
        RAM[cache3[posicaoCache3].getEndBloco()] = cache3[posicaoCache3]
        cache3[posicaoCache3] = RAM[e.getEndBloco()]
        cache3[posicaoCache3].setCacheHit(4)
        cache3[posicaoCache3].setTimeUtilizado(time())
        return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo)


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