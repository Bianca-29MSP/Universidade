from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from Instrucao import Instrucao

def buscarNasMemorias(e, RAM, cache1, cache2):
    posicaoCache1 = e.getEndBloco() % len(cache1)
    posicaoCache2 = e.getEndBloco() % len(cache2)
    custo = 0

    #Caso encontre na primeira cache
    if (cache1[posicaoCache1].getEndBloco() == e.getEndBloco()):
        custo += 10
        cache1[posicaoCache1].setCusto(custo)
        cache1[posicaoCache1].setCacheHit(1)
        cache1[posicaoCache1].setAtualizado()
        return cache1[posicaoCache1]
    else:
        if(cache2[posicaoCache1].getEndBloco() == e.getEndBloco()):
            custo += 110
            cache2[posicaoCache2].setCacheHit(2)
            cache2[posicaoCache2].setAtualizado()
            return testeCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)
        else:
            custo += 1110
            if(not cache2[posicaoCache2].isAtualizado()):
                cache2[posicaoCache2] = RAM[e.getEndBloco()]
                cache2[posicaoCache2].setCacheHit(3)
                return testeCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)
            else:
                RAM[cache2[posicaoCache2].getEndBloco()] = cache2[posicaoCache2]
                cache2[posicaoCache2].setAtualizado()
                cache2[posicaoCache2] = RAM[e.getEndBloco()]
                cache2[posicaoCache2].setCacheHit(3)
                return testeCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)


                

def testeCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo):
    if not cache1[posicaoCache1].isAtualizado():
        cache1[posicaoCache1] = cache2[posicaoCache2]
    else:
        aux = BlocoMemoria()
        aux = cache1[posicaoCache1]
        cache1[posicaoCache1] = cache2[posicaoCache2]
        cache2[posicaoCache2] = aux

    cache1[posicaoCache1].setCusto(custo)

    return cache1[posicaoCache1]

