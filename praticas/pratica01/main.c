#include <stdio.h>
#include "grafo_matriz.h"
#include "grafo_lista.h"

int main() {
    int n = 4;
    
    // Teste Matriz
    GrafoMatriz *gm = criar_grafo_matriz(n);
    inserir_aresta_matriz(gm, 0, 1);
    inserir_aresta_matriz(gm, 0, 2);
    
    printf("[Matriz] Grau do vertice 0: %d\n", grau_matriz(gm, 0));
    printf("[Matriz] 0 e 1 adjacentes? %s\n", sao_adjacentes_matriz(gm, 0, 1) ? "Sim" : "Nao");
    
    remover_aresta_matriz(gm, 0, 1);
    printf("[Matriz] 0 e 1 adjacentes apos remocao? %s\n", sao_adjacentes_matriz(gm, 0, 1) ? "Sim" : "Nao");
    liberar_grafo_matriz(gm);

    // Teste Lista
    GrafoLista *gl = criar_grafo_lista(n);
    inserir_aresta_lista(gl, 0, 1);
    inserir_aresta_lista(gl, 0, 2);

    printf("[Lista] Grau do vertice 0: %d\n", grau_lista(gl, 0));
    printf("[Lista] 0 e 1 adjacentes? %s\n", sao_adjacentes_lista(gl, 0, 1) ? "Sim" : "Nao");

    remover_aresta_lista(gl, 0, 1);
    printf("[Lista] 0 e 1 adjacentes apos remocao? %s\n", sao_adjacentes_lista(gl, 0, 1) ? "Sim" : "Nao");
    liberar_grafo_lista(gl);

    return 0;
}