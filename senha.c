#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma senha aleatória
void gerarSenha(char senha[], int comprimento) {
    const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$^&*():/?.,";
    int i;

    // Semente para a função rand()
    srand((unsigned int)time(NULL));

    for (i = 0; i < comprimento - 1; ++i) {
        int indice = rand() % (sizeof(caracteres) - 1);
        senha[i] = caracteres[indice];
    }

    senha[comprimento - 1] = '\0';
}

int main() {
    int comprimento;

    printf("Digite o comprimento da senha desejada: ");
    scanf("%d", &comprimento);

    // Verifica se o comprimento é válido
    if (comprimento <= 0) {
        printf("Comprimento inválido. Por favor, digite um valor positivo.\n");
        return 1; // Código de erro
    }

    // Aloca espaço para a senha
    char *senha = (char *)malloc(comprimento * sizeof(char));

    // Gera a senha
    gerarSenha(senha, comprimento);

    // Exibe a senha gerada
    printf("Senha gerada: %s\n", senha);

    // Libera a memória alocada
    free(senha);

    return 0;
}
