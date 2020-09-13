#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>


//1 Faça um programa que receba o nome do usuário, idade e uma frase de texto predileta e armazene esses dados em um arquivo do tipo texto
//e em um segundo arquivo do tipo binário, ou seja, dois arquivos. (guarde o nome dos arquivos, pois serão utilizados para usá-los  próxima questão).
//2 Faça um programa que receba do usuário o nome do arquivo a ser aberto,
// o do exercício anterior, do arquivo do tipo texto, e mostre na tela seu conteúdo.
int main(void)
{
//Funções
    void arquivotxt(void);
    void arquivobinario(void);
    void abrirtxt(void);
    void abrirbinario(void);
// variável de controle
    char continuar;


// Função que cria ou abre arquivo.txt e insere dados
    arquivotxt();
// Função que cria ou abre arquivo binario e insere dados
    arquivobinario();

    do
    {
        int cont = 0;
        printf("Existem 2 arquivos,  qual deseja abrir,  DIGITE [1] para aquivo.txt   [2] para arquivo.bin \n\n");
        scanf("%d", &cont);

        if (cont == 1)
        {
            // Função  abre arquivo txt
            abrirtxt();
        }

        if (cont ==2)
        {
            // Função  abre arquivo binario
            abrirbinario();
        }

        if (cont != 1 && cont !=2)
        {
            printf("**************************");
            printf("Esse arquivo NAO existe! ");
            printf("************************** \n\n");
        }
        //Perguntar ao usuário se ele deseja ou não continuar.
        printf("Deseja continuar DIGITE [S] OU [N]: \n");
        scanf("%s", &continuar);
    }
    while(continuar == 'S' || continuar == 's');


    return 0;
}

void arquivotxt(void)
{
    //Declaração de variáveis/vetores
    FILE *arq;
    char nome[100];
    char texto[200];
    char idade[10];
    int i;


    // Função que cria ou abre arquivo.txt e insere dados
    arq = fopen("Atividade.txt","w");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }

    // Grava a string, caractere a caractere no arquivo
    printf("Digite o seu nome: \n");
    scanf("%s",nome);
    fprintf(arq, "Seu nome:  %s\n",nome);

    printf("Digite a sua idade: \n");
    scanf("%s",idade);
    fprintf(arq, "Sua idade: %s anos\n",idade);

    printf("Digite uma frase de texto predileta: \n");
    scanf("%s",texto);
    fprintf(arq, "Sua Frase Predileto eh:  %s\n",texto);


    // Função que fecha o arquivo
    fclose(arq);


}

void arquivobinario(void)
{
    //Declaração de variáveis/vetores
    FILE *arqbin;
    char nome[100];
    char texto[200];
    char idade[10];
    int i;


    // Função que cria ou abre arquivo binario e insere dados
    arqbin = fopen("binario.bin","wb");
    if (arqbin == NULL)
    {
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }

    // Grava a string, caractere no arquivo
    printf("Digite o seu nome: \n");
    scanf("%s",nome);
    fprintf(arqbin, "Seu nome:  %s\n",nome);

    printf("Digite a sua idade: \n");
    scanf("%s",idade);
    fprintf(arqbin, "Sua idade: %s anos\n",idade);

    printf("Digite uma Frase Predileta: \n");
    scanf("%s",texto);
    fprintf(arqbin, "Sua Frase Predileto:  %s\n",texto);


    // Função que fecha o arquivo
    fclose(arqbin);


}

void abrirbinario(void)
{
    //Declaração de variáveis/vetores
    FILE *abrirbin;
    char nome[100];
    char texto[200];
    char idade[10];


    // Função  abre arquivo binario
    abrirbin = fopen("binario.bin","rb");

    if (abrirbin != NULL)
    {
        while(fscanf(abrirbin, "  %[^\n]s",  nome) !=EOF)
        {

            // fscanf(abrir, "%[^\n]s", idade);
            // fscanf(abrir, "%[^\n]s", texto);
            printf(" %s\n",  nome);

        }

    }
    // Função que fecha o arquivo

    fclose(abrirbin);
}

void abrirtxt(void)
{
    //Declaração de variáveis/vetores
    FILE *abrirtxt;
    char nome[100];
    char texto[200];
    char idade[10];

    // Função  abre arquivo txt
    abrirtxt = fopen("Atividade.txt","r");

    if (abrirtxt != NULL)
    {
        while(fscanf(abrirtxt, "  %[^\n]s",  nome) !=EOF)
        {

            // fscanf(abrir, "%[^\n]s", idade);
            // fscanf(abrir, "%[^\n]s", texto);
            printf(" %s\n",  nome);

        }

    }

    fclose(abrirtxt);
}
