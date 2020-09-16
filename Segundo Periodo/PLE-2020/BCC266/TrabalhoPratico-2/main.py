from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from Instrucoes import Instrucoes
import random

tamanhoRam = 1000
tamanhoCache1 = 8
tamanhoCache2 = 16
tamanhoPrograma = 1000
quantidadePalavrasBloco = 4

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

if __name__ == '__main__':
    montarRam()
    print(RAM[1])