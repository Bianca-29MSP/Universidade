/*Nathann Zini dos reis 19.2.4007
*Taylanne Patricia Mendes 19.2.4099
*Vitória Maria Silva Bispo 19.2.4109
*David Souza do Nascimento 19.2.4029
*Enya Luísa Gomes dos Santos 19.2.4201
*/
module estufa(L, U, Fe, Fd, Mh, Ma);

	input L, U, Fe, Fd; //pinos de entrada do modulo
	output Mh, Ma;      //pinas de saida do modulo

	assign Mh = ~Fd & (U | L)    //saida Mh recebe a equação obtida atraves da tabela verdade 
	assign Ma = ~(Fe & L & U)    //saida Ma recebe a equação obtida atraves da tabela verdade

endmodule;