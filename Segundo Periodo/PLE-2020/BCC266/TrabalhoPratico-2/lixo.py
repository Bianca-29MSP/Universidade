import sys
from time import time
from pprint import pprint
from BlocoMemoria import BlocoMemoria


def buscarNasMemorias(e, RAM, cache1, cache2, cache3):
    custo = 0
    posicaoCache1 = e.getEndBloco() % len(cache1)
    posicaoCache2 = e.getEndBloco() % len(cache2)
    posicaoCache3 = e.getEndBloco() % len(cache3)



    


    if cache1[posicaoCache1].getEndBloco() == e.getEndBloco():
        custo += 10
        cache1[posicaoCache1].setCusto(custo)
        cache1[posicaoCache1].setCacheHit(1)
        cache1[posicaoCache1].setTimeUtilizado(time())
        return cache1[posicaoCache1]
    else:
        if cache2[posicaoCache2].getEndBloco() == e.getEndBloco():
            custo += 110
            cache2[posicaoCache2].setCacheHit(2)
            cache2[posicaoCache2].setTimeUtilizado(time())
            return testaCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)
        else:
            custo += 1110
            if not cache2[posicaoCache2].isAtualizado():
                cache2[posicaoCache2] = RAM[e.getEndBloco()]
                cache2[posicaoCache2].setCacheHit(3)
                return testaCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)
            else:
                cache2[posicaoCache2].setNotAtualizado()
                RAM[cache2[posicaoCache2].getEndBloco()] = cache2[posicaoCache2]
                cache2[posicaoCache2] = RAM[e.getEndBloco()]
                cache2[posicaoCache2].setCacheHit(3)
                return testaCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)


def testaCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo):
    if not cache1[posicaoCache1].isAtualizado():
        cache1[posicaoCache1] = cache2[posicaoCache2]
        cache1[posicaoCache1].setAtualizado()
    else:
        aux = BlocoMemoria()
        aux = cache1[posicaoCache1]
        cache1[posicaoCache1] = cache2[posicaoCache2]
        cache2[posicaoCache2] = aux
    cache1[posicaoCache1].setCusto(custo)
    return cache1[posicaoCache1]

def espacoLivreCache(cache):
    for posicaoCache in range(len(cache)):
        if not cache[posicaoCache].isAtualizado():
            return posicaoCache
    return -1

    