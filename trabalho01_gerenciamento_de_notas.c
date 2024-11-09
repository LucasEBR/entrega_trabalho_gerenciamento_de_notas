#include <stdio.h>

int id[30], qtd_alunos = 0;
float nota1[30], nota2[30], nota3[30], media_individual[30];

void inserir_valores(){
    //enquanto a quantidade informada nao for entre 1 e 30 nao prossegue
    while (qtd_alunos < 1 || qtd_alunos > 30) {
        printf("Insira um numero valido de alunos (entre 1 e 30):\n");
        scanf("%d", &qtd_alunos);
    }

    //le o id de cada aluno da turma e suas tres notas
    for (int i = 0; i < qtd_alunos; i++) {
        printf("\nInsira o %do id (numero inteiro): ",i+1);
        scanf("%d", &id[i]);
        printf("Insira a 1a nota: ");
        scanf("%f", &nota1[i]);
        printf("Insira a 2a nota: ");
        scanf("%f", &nota2[i]);
        printf("Insira a 3a nota: ");
        scanf("%f", &nota3[i]);
    }
}

void print_valores(){
    //mostra o id e os valores das tres notas de cada aluno
    printf("\n");
    for (int i = 0; i < qtd_alunos; i++) {
        printf("Aluno %d possui as notas: %.2f - %.2f - %.2f\n", id[i],nota1[i],nota2[i],nota3[i]);
    }
}

int calcMedia() {
    printf("\n");
    //calcula e mostra a media das tres notas individuais de cada aluno
    for(int i = 0; i< qtd_alunos; i++){
        media_individual[i] = nota1[i] + nota2[i] +nota3[i];
        media_individual[i] = media_individual[i]/3;
        printf("Aluno %d tem media: %.2f\n",id[i],media_individual[i]);
    }
    return 0;
}

int MaiorNum(){
    //verifica todos os vetores de nota em busca da maior delas
    float cont =0;
    for(int i = 0;  i < qtd_alunos; i++ ){
        if (nota1[i] > cont){
            cont = nota1[i];
        }
        if (nota2[i] > cont){
            cont = nota2[i];
        }
        if (nota3[i] > cont){
            cont = nota3[i];
        }
    }
    printf("\nMaior nota dentre todas: %.2f\n",cont);
    return cont;
}

int MenorNum(){
    //verifica todos os vetores de nota em busca da menor delas
    float cont = 2147483647;
    for(int i = 0;  i < qtd_alunos; i++ ){
        if (nota1[i] < cont){
            cont = nota1[i];
        }
        if (nota2[i] < cont){
            cont = nota2[i];
        }
        if (nota3[i] < cont){
            cont = nota3[i];
        }
    }
    printf("\nMenor nota dentre todas: %.2f\n",cont);
    return cont;
}

int calcMediaTotal(){
    //calcula e mostra a media total. soma todas as notas de todos os alunos e divide pela quantia de alunos na classe
    printf("\n");
    float media_total = 0;
    for(int i = 0; i < qtd_alunos; i++){
        media_total += media_individual[i];
    }
    media_total = media_total/qtd_alunos;
    printf("\nA media total da sala e: %.2f\n",media_total);
    return media_total;
}

void relatorio_abaixo_media(){
    //informa quais alunos ficaram abaixo da media e suas medias
    printf("\n");
    for(int i = 0; i < qtd_alunos; i++){
        if(media_individual[i]<60){
            printf("Aluno %d ficou abaixo da media com %.2f pontos.\n",id[i],media_individual[i]);
        }
    }
}

void relatorio_acima_media(){
    //informa quais alunos ficaram acima da media e suas medias
    printf("\n");
    for(int i = 0; i < qtd_alunos; i++){
        if(media_individual[i]>=60){
                printf("Aluno %d ficou acima da media com %.2f pontos.\n",id[i],media_individual[i]);
        }
    }
}

int main() {
    inserir_valores();
    print_valores();
    calcMedia();
    MaiorNum();
    MenorNum();
    calcMediaTotal();
    relatorio_abaixo_media();
    relatorio_acima_media();
    
    return 0;
}