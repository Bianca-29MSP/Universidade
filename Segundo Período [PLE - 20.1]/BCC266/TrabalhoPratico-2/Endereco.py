class Endereco():
    
    def __init__(self):
        self.endBloco = 0
        self.endPalavra = 0

    def getEndBloco(self):
        return self.endBloco

    def setEndBloco(self, endBlocoAux):
        self.endBloco = endBlocoAux
    
    def getEndPalavra(self):
        return self.endPalavra

    def setEndPalavra(self, endPalavraAux):
        self.endPalavra = endPalavraAux