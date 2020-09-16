from Endereco import Endereco

class Instrucoes():
	add1 = Endereco()
	add2 = Endereco()
	add3 = Endereco()
	opcode = 0
	
	def getAdd1(self):
		return self.add1
	
	def setAdd1(self, add1):
		self.add1 = add1
	
	def getAdd2(self):
		return self.add2
	
	def setAdd2(self, add2):
		self.add2 = add2
	
	def getAdd3(self):
		return self.add3
	
	def setAdd3(self, add3):
		self.add3 = add3
	
	def getOpcode(self):
		return self.opcode
	
	def setOpcode(self, opcode):
		self.opcode = opcode
