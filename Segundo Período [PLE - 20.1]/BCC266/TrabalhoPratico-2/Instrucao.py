from Endereco import Endereco

class Instrucao():

	def __init__(self):
		self.add1 = Endereco()
		self.add2 = Endereco()
		self.add3 = Endereco()
		self.opcode = 0
	
	def getAdd1(self):
		return self.add1
	
	def setAdd1(self, add1Aux):
		self.add1 = add1Aux
	
	def getAdd2(self):
		return self.add2
	
	def setAdd2(self, add2Aux):
		self.add2 = add2Aux
	
	def getAdd3(self):
		return self.add3
	
	def setAdd3(self, add3Aux):
		self.add3 = add3Aux
	
	def getOpcode(self):
		return self.opcode
	
	def setOpcode(self, opcodeAux):
		self.opcode = opcodeAux