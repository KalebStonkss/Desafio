#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARMARIOS 8

void ocupar(int *status, int armario){
    *status = *status | (1<<armario);
}
void desocupar(int *status, int armario){
    *status = *status & ~(1<<armario);
}
int ja_ocupado(int status, int armario){
    return status & (1<<armario);
}
int sistema(){
    int status = 0;
    int opcao = 0;
    puts("Digite 1 para ocupar um armario \n Digite 2 para desocupar um armario \n Digite 3 para sair");
    while(opcao!=3){
        scanf("%d",&opcao);
        unsigned char armario = rand() % ARMARIOS;
        switch(opcao){
            case 1:
            if(ja_ocupado(status,armario)){
                printf("Armario ja ocupado, buscando outro armario...");
            }
            else{
                ocupar(&status,armario);
            }
            printf("Armarios ocupados -> %d",armario);
            break;
            case 2:
            puts("Digite o numero do armario que deseja desocupar");
            scanf("%hhd",&armario);
            if(ja_ocupado(status,armario)){
                desocupar(&status,armario);
            }   
            break;
            case 3:
            printf("Programa encerrado.");
            return 0;
            break;
            default:
            printf("Entrada invalida.");
            break;
        }
    }
}
int main(){
    srand(time(NULL)); 
    sistema();
    return 0;
}