#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista.h"

GrafoLista* criar_grafo_lista(int n) {
    GrafoLista *g = (GrafoLista*) malloc(sizeof(GrafoLista));
    g->n = n;
    g->adj = (No**) malloc(n * sizeof(No*));
    for (int i = 0; i < n; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

static void adicionar_no(No **head, int dest) {
    No *novo = (No*) malloc(sizeof(No));
    novo->destino = dest;
    novo->prox = *head;
    *head = novo;
}

void inserir_aresta_lista(GrafoLista *g, int u, int v) {
    if (!g || u < 0 || u >= g->n || v < 0 || v >= g->n) return;
    if (!sao_adjacentes_lista(g, u, v)) {
        adicionar_no(&(g->adj[u]), v);
        adicionar_no(&(g->adj[v]), u); // Grafo não direcionado
    }
}

static void remover_no(No **head, int dest) {
    No *atual = *head;
    No *anterior = NULL;

    while (atual != NULL && atual->destino != dest) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return;

    if (anterior == NULL) {
        *head = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual);
}

void remover_aresta_lista(GrafoLista *g, int u, int v) {
    if (!g || u < 0 || u >= g->n || v < 0 || v >= g->n) return;
    remover_no(&(g->adj[u]), v);
    remover_no(&(g->adj[v]), u);
}

int grau_lista(GrafoLista *g, int u) {
    if (!g || u < 0 || u >= g->n) return -1;
    int grau = 0;
    No *atual = g->adj[u];
    while (atual != NULL) {
        grau++;
        atual = atual->prox;
    }
    return grau;
}

int sao_adjacentes_lista(GrafoLista *g, int u, int v) {
    if (!g || u < 0 || u >= g->n || v < 0 || v >= g->n) return 0;
    No *atual = g->adj[u];
    while (atual != NULL) {
        if (atual->destino == v) return 1;
        atual = atual->prox;
    }
    return 0;
}

void liberar_grafo_lista(GrafoLista *g) {
    if (!g) return;
    for (int i = 0; i < g->n; i++) {
        No *atual = g->adj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
}