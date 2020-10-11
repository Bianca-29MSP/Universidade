class BlocoMemoria:

    def __init__(self):
        self.endBloco = -1
        self.atualizado = False
        self.custo = 0
        self.cacheHit = 0
        self.timeUtilizado = 0
        self.palavras = []

    def getCusto(self):
        return self.custo

    def setCusto(self, custoAux):
        self.custo = custoAux

    def getPalavras(self):
        return self.palavras 

    def setPalavras(self, palavrasAux):
        self.palavras = palavrasAux

    def getEndBloco(self):
        return self.endBloco

    def setEndBloco(self, endBlocoAux):
        self.endBloco = endBlocoAux

    def isAtualizado(self):
        return self.atualizado

    def setAtualizado(self):
        self.atualizado = True

    def setNotAtualizado(self):
        self.atualizado = False

    def getCacheHit(self):
        return self.cacheHit

    def setCacheHit(self, cacheHitAux):
        self.cacheHit = cacheHitAux

    def getTimeUtilizado(self):
        return self.timeUtilizado

    def setTimeUtilizado(self, timeUtilizadoAux):
        self.timeUtilizado = timeUtilizadoAux