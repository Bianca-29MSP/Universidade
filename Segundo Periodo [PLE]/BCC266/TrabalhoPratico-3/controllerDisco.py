import random
from BlocoMemoria import BlocoMemoria
from time import time

tamanhoDisco = 5000
quantidadePalavrasBloco = 4

def montarDisco():
    try:
        for i in range(tamanhoDisco):
            nameFile = "0" + str(i) + ".txt" if i < 10 else str(i) + ".txt"
            arquivoDisco = open('./disco/' + nameFile, "w")
            arquivoDisco.write(str(i) + '\n') #endBloco 
            arquivoDisco.write(str(False) + '\n') #atualizado
            arquivoDisco.write(str(0) + '\n') #custo
            arquivoDisco.write(str(0) + '\n') #cacheHit
            arquivoDisco.write(str(0) + '\n') #timeUtilizado
            for j in range(quantidadePalavrasBloco):
                palavras = random.randint(0, 1000000)
                arquivoDisco.write(str(palavras) + '\n') #.palavras
        arquivoDisco.close()
    except:
        print("Problemas com o arquivo.")


def lerDisco(end):
    try:
        nameFile = "0" + str(end) + ".txt" if end < 10 else str(end) + ".txt"
        arquivo = open('./disco/' + nameFile, "r")
        itens = []
        cont = 0
        for linha in arquivo:
            if cont == 1:
                if linha.strip() == 'False':
                    itens.append(False)
                else:
                    itens.append(True)
            elif cont == 4:
                itens.append(float(linha.strip()))
            else:
                itens.append(int(linha.strip()))
            cont += 1
        arquivo.close()
        return itens
    except:
        print("Problemas com o arquivo.")


def alterarDisco(end, bloco):
    try:
        endBloco = bloco.getEndBloco()
        att = bloco.isAtualizado()
        custo = bloco.getCusto()
        cacheHit = bloco.getCacheHit()
        timeU = bloco.getTimeUtilizado()
        palavras = bloco.getPalavras()
        print(bloco.getCacheHit())
        nameFile = "0" + str(end) + ".txt" if end < 10 else str(end) + ".txt"
        arquivoDisco = open('./disco/' + nameFile, "w")
        arquivoDisco.write(str(endBloco) + '\n') #endBloco 
        arquivoDisco.write(str(att) + '\n') #atualizado
        arquivoDisco.write(str(custo) + '\n') #custo
        arquivoDisco.write(str(cacheHit) + '\n') #cacheHit
        arquivoDisco.write(str(timeU) + '\n') #timeUtilizado
        for j in range(len(palavras)):
            arquivoDisco.write(str(palavras[j]) + '\n') #.palavras
        arquivoDisco.close()
    except:
        print("Problemas com o arquivo.")


if __name__ == "__main__":
    montarDisco()
    print(lerDisco(0))
    bloco = BlocoMemoria()
    bloco.setEndBloco(0)
    bloco.setPalavras( [ 10, 0, 0, 0 ] )
    bloco.setAtualizado()
    bloco.setCusto(100)
    bloco.setCacheHit(1)
    bloco.setTimeUtilizado(time())
    alterarDisco(0, bloco)
    lerDisco(0)