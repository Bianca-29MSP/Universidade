/******************************************************************************
                            PROCESSOS(FORK)
                        ENYA LUÍSA GOMES DOS SANTOS
                                19.2.4201
*******************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ  0
#define WRITE 1
#define MAXSUM 1000
#define MAXSUB 1000

void screen();

int main()
{
    const int value__default = 100;
    int balance[2], option[2], countSum[2], countSub[2], op;
    
    int current__balance = 0;
    int op__aux, countSum__aux, countSub__aux;
    
    //Criando o pipe de comunicação entre processo e verificando caso haja erro
    if(pipe(balance) == -1 || pipe(option) == -1 || pipe(countSum) == -1 || pipe(countSub) == -1) {
        perror("Erro na criação do pipe!\n");
        exit(EXIT_FAILURE);
    }

	//Escrita do valor inicial em valores do pipe
	int aux = 0;
    if (
        (write(balance[WRITE], &aux, sizeof(int)) == -1) ||
        (write(countSum[WRITE], &aux, sizeof(int)) == -1) ||
        (write(countSub[WRITE], &aux, sizeof(int)) == -1)
        ) {
        perror("Erro ao escrever no pipe.\n");
        exit(EXIT_FAILURE);
    }
    
    screen();
    
    //armazenando o valor do processo principal
    pid_t process__main = getpid();
    pid_t process__1 = fork(); //iniciando o filho do processo pai
    pid_t process__2 = -1;
    pid_t process__3 = -1;
    
    if(process__1 < 0) {
        perror("Erro na criação do fork.\n") ;
        exit(EXIT_FAILURE);
    }
    
    if(process__1 == 0) {
        printf("(1) PDI: %d | PAI: %d\n", getpid(), getppid());
    }
    
    //Garantir que o processo PAI seja o mesmo
    if(getpid() == process__main){
        process__2 = fork();
        if(process__2 < 0){
            perror ("Erro na criação do fork.\n") ;
            exit(EXIT_FAILURE);
        }
        
        if(!process__2){
            printf("(2) PDI: %d | PAI: %d\n", getpid(), getppid());
            process__1 = -1;
        }
    }
    
    //Garantir que o processo PAI seja o mesmo
    if(getpid() == process__main){
        process__3 = fork();
        if(process__3 < 0){
            perror ("Erro na criação do fork.\n") ;
            exit(EXIT_FAILURE);
        }
        
        if(!process__3){
            printf("(3) PDI: %d | PAI: %d\n", getpid(), getppid());
            process__1 = -1;
            process__2 = -1;
        }
    }
    
    
    if(getpid() == process__main) { //Processo pai
        countSum__aux = 0;
        countSub__aux = 0;
        
        while(op != (int)'k' && countSum__aux < MAXSUM && countSub__aux < MAXSUB) {
            do {
                op = (int)getchar();
                getchar();
            } while((op != (int)'+') && (op != (int)'-') && (op != (int)'e') && (op != (int)'k'));
            
            if(op == (int)'k' || countSum__aux >= MAXSUM || countSub__aux >= MAXSUB) { //matar os processos
                kill(process__1, SIGKILL);
                kill(process__2, SIGKILL);
                kill(process__3, SIGKILL);
                kill(getpid(), SIGKILL);
                exit(1);
            }
            write(option[WRITE], &op, sizeof(int));  
            
            read(countSum[READ], &countSum__aux, sizeof(int));
            write(countSum[WRITE], &countSum__aux, sizeof(int));
            read(countSub[READ], &countSub__aux, sizeof(int));
            write(countSub[WRITE], &countSub__aux, sizeof(int));
        }
    } if (process__1 == 0) { //filho 1 (Somar)
        op__aux = 0;
        current__balance = 0;
            do {
                read(option[READ], &op__aux, sizeof(int));
                
                if(op__aux == (int)'+') { //exibir saldo
                    printf("[SOMA 100UD] (Print) PID : %d\n", getpid());
                    
                    read(countSum[READ], &countSum__aux, sizeof(int));
                    countSum__aux += 1;
                    write(countSum[WRITE], &countSum__aux, sizeof(int));
                    
                    read(balance[READ], &current__balance, sizeof(int));
                    current__balance += value__default;
                    write(balance[WRITE], &current__balance, sizeof(int));
                    
                } else write(option[WRITE], &op__aux, sizeof(int));
            } while(op__aux != (int)'k' && countSum__aux < MAXSUM);
            
    } else if (process__2 == 0) { //filho 2 (Subtrair)
        op__aux = 0;
        current__balance = 0;
            do {
                read(option[READ], &op__aux, sizeof(int));
                if(op__aux == (int)'-') { //exibir saldo
                    printf("[SUBTRACAO 100UD] (Print) PID : %d\n", getpid());
                    
                    read(countSub[READ], &countSub__aux, sizeof(int));
                    countSub__aux += 1;
                    write(countSub[WRITE], &countSub__aux, sizeof(int));
                    
                    read(balance[READ], &current__balance, sizeof(int));
                    current__balance -= value__default;
                    write(balance[WRITE], &current__balance, sizeof(int));
                    
                } else write(option[WRITE], &op__aux, sizeof(int));
                
            } while(op__aux != (int)'k' && countSub__aux < MAXSUB);
            
    } else if (process__3 == 0) { //filho 3(Exibir saldo)
            op__aux = 0;
            current__balance = 0;
            do {
                read(option[READ], &op__aux, sizeof(int));
                if(op__aux == (int)'e') { //exibir saldo
                    printf("[SALDO] (Print) PID : %d\n", getpid());
                    read(balance[READ], &current__balance, sizeof(int));
                    write(balance[WRITE], &current__balance, sizeof(int));
                    printf("[Print] Saldo: %d\n", current__balance);
                } else {
                    write(option[WRITE], &op__aux, sizeof(int));
                }
            } while(op__aux != (int)'k');
    }
    
    return 0;
}

void screen(){
    printf("\n");
    printf("[+] - Somar 100 UD\n");
    printf("[-] - Subtrair 100 UD\n");
    printf("[e] - Exibir o valor do saldo\n");
    printf("[k] - Finalizar a execucao\n");
    printf("Valor inicial de saldo: 0\n");
}
