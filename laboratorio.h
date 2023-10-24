//
// Created by unifcjunior on 19/09/2023.
//

#ifndef UNTITLED_LABORATORIO_H
#define UNTITLED_LABORATORIO_H
#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 1000

typedef struct {
    char nome[50];
    char cpf[11];
    char tipo_conta[10];
    float saldo;
    char senha[12];
} Cliente;

void novo_cliente();
void apaga_cliente();
void listar_clientes();
void debitar(char cpf[],char senha[],float valor,int *result);
void depositar(char cpf[],float valor,int *result);
void extrato(char cpf[]);
void gerarExtrato(char cpf[],char senha[],int *resultado);
void Transferencia(char cpf_origem[],char senha_origem[],char cpf_destino[],float valor,int *result);

#endif



//UNTITLED_LABORATORIO_H
