//
// Created by unifcjunior on 19/09/2023.
//
#include "laboratorio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Cliente clientes[MAX_CLIENTES];
int num_clientes = 0;

void novo_cliente() {
    if (num_clientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido. Impossível adicionar novos clientes.\n");
        return;
    }

    printf("Nome Cliente: :\n");
    scanf("%[^\n]s", cliente.nome);

    Cliente novo;

    printf("Nome: ");
    scanf("%s", novo.nome);

    printf("CPF: ");
    scanf("%s", novo.cpf);

    printf("Tipo de conta (Comum ou Plus): ");
    scanf("%s", novo.tipo_conta);

    printf("Valor inicial: ");
    scanf("%f", &novo.saldo);

    printf("Senha (4 dígitos numéricos): ");
    scanf("%s", novo.senha);

    // Validar a senha (deve conter apenas dígitos e ter exatamente 4 caracteres)
    if (strlen(novo.senha) != 4) {
        printf("Senha inválida. Deve conter exatamente 4 dígitos.\n");
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (novo.senha[i] < '0' || novo.senha[i] > '9') {
            printf("Senha inválida. Deve conter apenas dígitos.\n");
            return;
        }
    }

    // Adiciona o novo cliente à lista de clientes
    clientes[num_clientes] = novo;
    num_clientes++;

    printf("Cliente criado!\n");
}


void apaga_cliente() {
    char cpf[15];
    int i, encontrado = 0;

    printf("Digite o CPF do cliente que deseja apagar: ");
    scanf("%s", cpf);

    for (i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        // Remove o cliente da lista
        for (int j = i; j < num_clientes - 1; j++) {
            clientes[j] = clientes[j + 1];
        }
        num_clientes--;
        printf("Cliente apagado com sucesso!\n");
    } else {
        printf("Cliente não encontrado.\n");
    }
}


void listar_clientes() {
    if (num_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Lista de Clientes:\n");

    for (int i = 0; i < num_clientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de conta: %s\n", clientes[i].tipo_conta);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("\n");
    }
}


void debitar() {
    char cpf[15];
    char senha[5];
    float valor;

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    printf("Digite a senha: ");
    scanf("%s", senha);

    int i;
    for (i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            break;
        }
    }

    if (i == num_clientes) {
        printf("CPF ou senha inválidos.\n");
        return;
    }

    printf("Digite o valor para débito: ");
    scanf("%f", &valor);

    if (strcmp(clientes[i].tipo_conta, "Comum") == 0) {
        if (clientes[i].saldo - valor < -1000) {
            printf("Saldo insuficiente para débito.\n");
            return;
        }
        clientes[i].saldo -= valor * 1.05; // Debita 5% de taxa
    } else if (strcmp(clientes[i].tipo_conta, "Plus") == 0) {
        if (clientes[i].saldo - valor < -5000) {
            printf("Saldo insuficiente para débito.\n");
            return;
        }
        clientes[i].saldo -= valor * 1.03; // Debita 3% de taxa
    }

    printf("Débito realizado com sucesso. Novo saldo: %.2f\n", clientes[i].saldo);
}


void depositar() {
    char cpf[15];
    float valor;

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    int clienteEncontrado = -1;

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clienteEncontrado = i;
            break;
        }
    }

    if (clienteEncontrado == -1) {
        printf("CPF inválido.\n");
        return;
    }

    printf("Digite o valor para depósito: ");
    scanf("%f", &valor);

    clientes[clienteEncontrado].saldo += valor;

    printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", clientes[clienteEncontrado].saldo);
}



void extrato() {
    char cpf[15];
    char senha[5];
    int clienteEncontrado = -1;

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            clienteEncontrado = i;
            break;
        }
    }

    if (clienteEncontrado == -1) {
        printf("CPF ou senha inválidos.\n");
        return;
    }

    // abrir um arquivo para escrever o extrato
    char nomeArquivo[50];
    sprintf(nomeArquivo, "extrato_%s.txt", cpf);
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de extrato.\n");
        return;
    }

    fprintf(arquivo, "Extrato para o cliente %s\n", clientes[clienteEncontrado].nome);
    fprintf(arquivo, "CPF: %s\n", cpf);
    fprintf(arquivo, "Tipo de conta: %s\n", clientes[clienteEncontrado].tipo_conta);

    // imprimir todas as operações do cliente
    for (int i = 0; i < num_operacoes; i++) {
        if (strcmp(operacoes[i].cpf, cpf) == 0) {
            fprintf(arquivo, "Operação: %s - Valor: %.2f\n", operacoes[i].tipo_operacao, operacoes[i].valor);
        }
    }

    fclose(arquivo);
    printf("Extrato gerado com sucesso.\n");
}


void transferencia() {
    char cpf_origem[15];
    char senha_origem[5];
    char cpf_destino[15];
    float valor;

    printf("Digite o CPF de origem: ");
    scanf("%s", cpf_origem);

    printf("Digite a senha: ");
    scanf("%s", senha_origem);

    int clienteOrigem = -1;

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf_origem) == 0 && strcmp(clientes[i].senha, senha_origem) == 0) {
            clienteOrigem = i;
            break;
        }
    }

    if (clienteOrigem == -1) {
        printf("CPF ou senha de origem inválidos.\n");
        return;
    }

    printf("Digite o CPF de destino: ");
    scanf("%s", cpf_destino);

    int clienteDestino = -1;

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf_destino) == 0) {
            clienteDestino = i;
            break;
        }
    }

    if (clienteDestino == -1) {
        printf("CPF de destino inválido.\n");
        return;
    }

    printf("Digite o valor para transferência: ");
    scanf("%f", &valor);

    if (clientes[clienteOrigem].saldo - valor < -1000) {
        printf("Saldo insuficiente para transferência.\n");
        return;
    }

    clientes[clienteOrigem].saldo -= valor;

    clientes[clienteDestino].saldo += valor;

    printf("Transferência realizada com sucesso. Novo saldo de origem: %.2f\n", clientes[clienteOrigem].saldo);
    printf("Novo saldo de destino: %.2f\n", clientes[clienteDestino].saldo);
}



#include "laboratorio.h"
