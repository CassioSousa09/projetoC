#include <stdio.h>
#include "laboratorio.h"

int main() {
    int opcao;
    char cpf[12];
    char senha[20];
    float valor;
    int result;

    while (1) {
        printf("\nMenu de Opcoes:\n");
        printf("1. Novo Cliente\n");
        printf("2. Apaga Cliente\n");
        printf("3. Listar Clientes\n");
        printf("4. Debito\n");
        printf("5. Deposito\n");
        printf("6. Extrato\n");
        printf("7. Transferencia\n");
        printf("0. Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                novo_cliente();
                break;
            case 2:
                apaga_cliente();
                break;
            case 3:
                listar_clientes();
                break;
            case 4:
                printf("Digite o CPF desejado: ");
                scanf("%s",cpf);
                printf("Digite a sua senha!: ");
                scanf("%s", senha);
                printf("Digite o valor a debitar!: ");
                scanf("%f",&valor);

                debitar(cpf,senha,valor,&result);

                if (result){
                    printf("Debito realizado!\n");
                } else{
                    printf("Erro ao debitar! Verifique as informações atribuidas.\n");
                }
                break;
            case 5:
                printf("Digite O CPF:");
                scanf("%s", cpf);
                printf("Digite o valor do deposito!");
                scanf("%f",&valor);

                depositar(cpf,valor,&result);

                if(result){
                    printf("Deposito realizado com exito!\n");
                } else{
                    printf("Erro ao realizar deposito.Reveja as informações.\n");
                }
                break;
            case 6:
                printf("Digite o seu  CPF: ");
                scanf("%s",cpf);
                printf("Digite a sua senha!: ");
                scanf("%s", senha);
                extrato(cpf,senha,&result);

                if (result){
                    printf("Extrato gerado com exito\n",cpf);
                } else {
                    printf("CPF ou senha incorretos!\n");
                }
                break;
            case 7:{
                char cpf_origem[12];
                char senha_origem[20];
                char cpf_destino[12];
                printf("Digite o seu CPF: ");
                scanf("%s", cpf_origem);
                printf("Digite a senha origem: ");
                scanf("%s", senha_origem);
                printf("Digite o cpf destino: ");
                scanf("%s", cpf_destino);
                printf("Digite o valor de transferencia desejado!: ");
                scanf("%f", &valor);

               Transferencia(cpf_origem,senha_origem,cpf_destino,valor,&result);


               if (result){
                   printf("Transferencia Efetuada Com Exito! \n");
            } else {
                   printf("Erro ao realizar transferencia.\n");
               }
                break;
            }

//terminar essa ultima funcao!
            case 0:
                ex
            default:
                printf("Opcao invalida.")

        }
    } while (opcao != 0);

    return 0;
}


