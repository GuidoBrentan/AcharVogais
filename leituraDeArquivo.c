#include <stdio.h>
#include <string.h>


char nomeArquivo[10], frases[100];
FILE *arq;

int main()
{
    printf("Bem vindo a contagem de Vogais e Consoantes!!\n\n");
    printf("Digite o nome do arquivo que será lido: ");
    fflush(stdout);

    fgets(nomeArquivo, 10, stdin);

    arq = fopen(nomeArquivo, "r");

    if(arq == NULL)
    {
        printf("\n\n Arquivo inexistente!! \n\n");
        fflush(stdout);
        return 1;
    }

    while(!feof(arq));
    {
        fgets(frases, 100, arq);
        for(int i = 0; i < strlen(frases); i++)
        {
            if(frases[i] == '\n')
            {
                char frase[i];
                int qtdVogais = 0, qtdLetras = 0;

                for(int j = 0; j < i; j++)
                    frase[j] = frases[j];

                for(int indice = 0; indice < sizeof(frase); indice++)
                {
                    if(frase[indice] > 64 && frase[indice] < 123)
                    {
                        if(frase[indice] != 91 && frase[indice] != 92 && frase[indice] != 93 && frase[indice] != 94 && frase[indice] != 95 && frase[indice] != 96)
                        {
                            qtdLetras++;

                            if(frase[indice] == 65 || frase[indice] == 69 || frase[indice] == 73 || frase[indice] == 79 || frase[indice] == 85
                            || frase[indice] == 97 || frase[indice] == 101 || frase[indice] == 105 || frase[indice] == 111|| frase[indice] == 117)
                            {
                                qtdVogais++;
                            }
                        }
                    }
                }

                printf("A frase ''%s'' tem %d vogais e %d letras \n \n",frase, qtdVogais, qtdLetras);
                fflush(stdout);
            }
        }
    }

    fclose(arq);
    return 0;
}