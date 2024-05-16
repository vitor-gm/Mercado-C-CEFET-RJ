#include <stdio.h>

typedef struct {
    int produtos[10][2];
    int numDeProdutos;
} Compra;

Compra compras[2];
Compra fusao[20];

int numDeCompras = 0;

void registarProdutos() {
    int compraAtual = numDeCompras;
    int opcao;

    int produtoAtual = 0;
    while(produtoAtual < 10) {
        printf("Código de barras: ");
        scanf("%d", &compras[compraAtual].produtos[produtoAtual][0]);

        printf("Digite a quantidade de produtos: ");
        scanf("%d", &compras[compraAtual].produtos[produtoAtual][1]);

        produtoAtual++;

        printf("Registrar mais um produto ? 1 - Sim  2 - Não: ");
        scanf("%d", &opcao);
        if(opcao != 1) {
            break;
        }
    }

    numDeCompras++;

    compras[compraAtual].numDeProdutos = produtoAtual;
    int aux = 0;
    for(int i = 0; i < numDeCompras; i++) {
        for(int j = 0; j < compras[i].numDeProdutos - 1; j++) {
            if(compras[i].produtos[j][i] > compras[i].produtos[j + 1][i]) {
                aux = compras[i].produtos[j][i];
                compras[i].produtos[j][i] = compras[i].produtos[j + 1][i];
                compras[i].produtos[j + 1][i] = aux;
            }
        }
    }

}

void exibirCompra() {

    for(int i = 0; i < numDeCompras; i++){
        for(int j = 0; j < compras[i].numDeProdutos; j++) {

            printf("Produto %d, código de barras: %d, quantidade do produto: %d \n", j + 1, compras[i].produtos[j][0], compras[i].produtos[j][1]);

        }

    }
}
int codigo = 0;
void localizarProduto() {
    int qtdProdutos = 0;
    printf("Digite um código de barras para localizar o produto: ");
    scanf("%d", &codigo);
    for(int i = 0; i < numDeCompras; i++) {
        for(int j = 0; j < compras[i].numDeProdutos; j++) {
            if(compras[i].produtos[j][i] == codigo) {
                qtdProdutos++;
                printf("Produto encontrado na compra: %d\n", i + 1);

            }

        }
    }
    printf("Total de produtos encontrados: %d", qtdProdutos);
}

void uniao() {
    int indice = 0;
    for(int i = 0; i < 10; i++) {
        fusao[indice++].produtos[i][0] = compras[i].produtos[i][0];
    }

    for(int i = 0; i < 10; i++) {
        fusao[indice++].produtos[i][0] = compras[i].produtos[i][1];
    }

    for(int i = 0; i < 20; i++) {
        printf("%d ", fusao[i].produtos[i]);
    }
}
int main(void) {

    registarProdutos();
    exibirCompra();
    localizarProduto();
    uniao();
    return 0;
}
