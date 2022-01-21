/******************************************************************************
                                 THREADS
                        ENYA LUÍSA GOMES DOS SANTOS
                                19.2.4201
*******************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#define MAXSUM 1000
#define MAXSUB 1000

static int SALDO = 0;

typedef struct {
    int saldo;
    int countSum;
    int countSub;
    int option;
} THR__ARGS;

void *thr__sum(void *arg){
    THR__ARGS *aux__args = (THR__ARGS*)arg;
    while(1) {
        if(aux__args->option == (int)'+') {
            printf( "[Thread] %d, PID %d\n", (int)pthread_self(), getpid());
            printf("[SOMANDO 100UD]\n");
            aux__args->saldo += 100;
            aux__args->option = 0;
            aux__args->countSum += 1;
        } else if(aux__args->option == (int)'k') {
            pthread_exit(0);
        }
    }
}

void *thr__sub(void *arg){
    THR__ARGS *aux__args = (THR__ARGS*)arg;
    while(1) {
        if(aux__args->option == (int)'-') {
            printf( "[Thread] %d, PID %d\n", (int)pthread_self(), getpid());
            printf("[SUBTRAINDO 100UD]\n");
            aux__args->saldo -= 100;
            aux__args->option = 0;
            aux__args->countSub += 1;
        } else if(aux__args->option == (int)'k') {
            pthread_exit(0);
        }
    }
}

void *thr__print(void *arg){
    THR__ARGS *aux__args = (THR__ARGS*)arg;
    while(1) {
        if(aux__args->option == (int)'e') {
            printf( "[Thread] %d, PID %d\n", (int)pthread_self(), getpid());
            printf("[EXIBINDO SALDO ATUAL]\n");
            printf("SALDO: %d\n", aux__args->saldo);   
            aux__args->option = 0;
        } else if(aux__args->option == (int)'k') {
            pthread_exit(0);
        }
    }
    
}

void inicialize__args(THR__ARGS* args) {
    args->saldo = 0;
    args->countSum = 0;
    args->countSub = 0;
}

void screen() {
    printf("\n");
    printf("[+] - Somar 100 UD\n");
    printf("[-] - Subtrair 100 UD\n");
    printf("[e] - Exibir o valor do saldo\n");
    printf("[k] - Finalizar a execucao\n");
    printf("Valor inicial de saldo: 0\n");
}

int main()
{
    THR__ARGS *thr__args = (THR__ARGS *)malloc(sizeof(THR__ARGS));
    inicialize__args(thr__args);
    
    screen();
    
    // Criação das threads de soma, remoção e exibição
    pthread_t thread__1, thread__2, thread__3;
    pthread_create(&thread__1, NULL, thr__sum, (void *)thr__args);
    pthread_create(&thread__2, NULL, thr__sub, (void *)thr__args);
    pthread_create(&thread__3, NULL, thr__print, (void *)thr__args);
    
    do {
        do {
            thr__args->option = (int)getchar();
            getchar();
        } while(
            (thr__args->option != (int)'+') && 
            (thr__args->option != (int)'-') && 
            (thr__args->option != (int)'e') && 
            (thr__args->option != (int)'k')
        );
        
        if(thr__args->option == (int)'k' || thr__args->countSum >= MAXSUM || thr__args->countSub >= MAXSUB) {
            //matar as threads
            pthread_kill(thread__1, 0);
            pthread_kill(thread__2, 0);
            pthread_kill(thread__3, 0);
            printf("[KILL THREADS]\n");
        }
        
    } while(thr__args->option != (int)'k' && thr__args->countSum < MAXSUM && thr__args->countSub < MAXSUB);

    return 0;
}
