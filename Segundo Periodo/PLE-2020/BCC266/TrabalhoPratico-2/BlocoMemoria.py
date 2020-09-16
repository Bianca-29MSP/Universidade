class BlocoMemoria():

    palavras = []
    endBloco = 0
    atualizacao = False
    custo = 0
    cacheHit = 0       

    def getCusto(self):
        return self.custo

    def setCusto(self, custo):
        self.custo = custo

    def setPlavras(self, palavras):
        self.palavras = palavras

    def getPalavras(self):
        return self.palavras 

    def getEndBloco(self):
        return self.endBloco

    def setEndBloco(self, endBloco):
        self.endBloco = endBloco

    def isAtualizado(self):
        return self.atualizacao

    def setAtualizado(self):
        self.atualizacao = not self.atualizacao

    def getCacheHit(self):
        return self.cacheHit

    def setCacheHit(self, cacheHit):
        self.cacheHit = cacheHit