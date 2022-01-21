import random
import pickle
from BlocoMemoria import BlocoMemoria
from time import time

tamanhoDisco = 10000
quantidadePalavrasBloco = 4

def montarDisco():
    try:
        for i in range(tamanhoDisco):
            path = "0" + str(i) + ".dat" if i < 10 else str(i) + ".dat"
            path = './hardDisk/' + path
            with open(path, mode='wb') as file:
                aux = BlocoMemoria()
                aux.setEndBloco(i)
                palavras = []
                for _j in range(quantidadePalavrasBloco):
                    palavras.append(random.randint(0, 1000000))
                aux.setPalavras(palavras)
                pickle.dump(aux, file)
                file.close()
    except:
        print("Problemas com o arquivo.")

def lerDisco(endBloco):
    try:
        path = "0" + str(endBloco) + ".dat" if endBloco < 10 else str(endBloco) + ".dat"
        path = './hardDisk/' + path
        with open(path, mode='rb') as file:
            bloco = pickle.load(file)
            file.close()
        return bloco
    except:
        print("Problemas com o arquivo.")
        return -1

def atualizarDisco(endBloco, bloco):
    try:
        path = "0" + str(endBloco) + ".dat" if endBloco < 10 else str(endBloco) + ".dat"
        path = './hardDisk/' + path
        with open(path, mode='r+b') as file:
            file.seek(0)
            pickle.dump(bloco, file)
            file.close()
    except:
        print("Problemas com o arquivo.")
        return -1