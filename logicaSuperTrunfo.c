//Codigo Completo1.0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// Super Trunfo - Jogo de Comparação de Países

// Definição da estrutura para representar um país
typedef struct {
    char codigo[10];
    char nome[50];
    char capital[50];
    long populacao;
    float area;
    double pib;
} Pais;

// Função para cadastrar um país
void cadastrarPais(Pais *p) {
    printf("\nCadastro do País:\n");
    printf("Código: ");
    scanf("%s", p->codigo);
    printf("Nome: ");
    scanf(" %[^\n]", p->nome); // Lê até encontrar nova linha
    printf("Capital: ");
    scanf(" %[^\n]", p->capital);
    printf("População: ");
    scanf("%ld", &p->populacao);
    printf("Área (km²): ");
    scanf("%f", &p->area);
    printf("PIB (US$): ");
    scanf("%lf", &p->pib);
}

// Função para exibir os dados de um país
void exibirPais(Pais p) {
    printf("\nDados do País:\n");
    printf("Código: %s\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Capital: %s\n", p.capital);
    printf("População: %ld habitantes\n", p.populacao);
    printf("Área: %.2f km²\n", p.area);
    printf("PIB: US$ %.2lf\n", p.pib);
}

// Função para comparar dois países em um atributo específico
void compararPaises(Pais a, Pais b, int atributo) {
    char *atributos[] = {"Código", "Nome", "Capital", "População", "Área", "PIB"};
    char *vencedor = NULL;
    
    printf("\nComparando %s:\n", atributos[atributo]);
    
    switch(atributo) {
        case 0: // Código
            printf("%s vs %s\n", a.codigo, b.codigo);
            printf("(Comparação por código não tem vencedor)\n");
            return;
        case 1: // Nome
            printf("%s vs %s\n", a.nome, b.nome);
            printf("(Comparação por nome não tem vencedor)\n");
            return;
        case 2: // Capital
            printf("%s vs %s\n", a.capital, b.capital);
            printf("(Comparação por capital não tem vencedor)\n");
            return;
        case 3: // População
            printf("%ld vs %ld habitantes\n", a.populacao, b.populacao);
            vencedor = (a.populacao > b.populacao) ? a.nome : b.nome;
            break;
        case 4: // Área
            printf("%.2f vs %.2f km²\n", a.area, b.area);
            vencedor = (a.area > b.area) ? a.nome : b.nome;
            break;
        case 5: // PIB
            printf("US$ %.2lf vs US$ %.2lf\n", a.pib, b.pib);
            vencedor = (a.pib > b.pib) ? a.nome : b.nome;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }
    
    printf("Vencedor: %s\n", vencedor);
}

int main() {
    Pais pais1, pais2;
    int opcao;
    
    printf("=== SUPER TRUNFO - PAÍSES ===\n");
    
    // Cadastro dos países
    printf("\nCadastro do Primeiro País:\n");
    cadastrarPais(&pais1);
    
    printf("\nCadastro do Segundo País:\n");
    cadastrarPais(&pais2);
    
    // Menu de comparação
    do {
        printf("\n=== MENU DE COMPARAÇÃO ===\n");
        printf("1 - Comparar por População\n");
        printf("2 - Comparar por Área\n");
        printf("3 - Comparar por PIB\n");
        printf("4 - Exibir dados dos países\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                compararPaises(pais1, pais2, 3); // 3 = População
                break;
            case 2:
                compararPaises(pais1, pais2, 4); // 4 = Área
                break;
            case 3:
                compararPaises(pais1, pais2, 5); // 5 = PIB
                break;
            case 4:
                exibirPais(pais1);
                exibirPais(pais2);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}