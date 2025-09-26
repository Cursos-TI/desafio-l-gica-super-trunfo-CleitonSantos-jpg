#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Selecao de variaveis.
    int Populacao = 0, Populacao2 = 0, Numero_de_pontos_turisticos = 0, Numero_de_pontos_turisticos2 = 0;
    float Area = 0, Area2 = 0, PIB = 0, PIB2 = 0, PIB_per_capita = 0, PIB_per_capita2 = 0, densidade_demografica = 0, densidade_demografica2 = 0, 
    Super_Poder1 = 0, Super_Poder2 = 0, Comp1 = 0, Comp2 = 0, CompEmpate = 0;
    char atributos[8][30] = {"Atributo invalido", "Populacao", "Area", "PIB", "Numero de pontos turisticos", "Densidade demografica", "PIB per capita", "Super Poder"};
    char Estado, Nome_da_cidade [20], Codigo_da_carta [4], Codigo_str[3], Estado2, Nome_da_cidade2 [20], Codigo_da_carta2 [4], Codigo_str2[3];
    int  CompPop, CompArea, CompPIB, CompPontos, CompDensidade, CompPIBPerCapita, CompSup;
    int  Codigo, Codigo2, opcao, opcao2, opcao3;
    float Carta1[8] =  {0, Populacao, Area, PIB, Numero_de_pontos_turisticos, densidade_demografica, PIB_per_capita, Super_Poder1};
    float Carta2[8] =  {0, Populacao2, Area2, PIB2, Numero_de_pontos_turisticos2, densidade_demografica2, PIB_per_capita2, Super_Poder2};
    
    

    // Entrada de dados para carta 01.
    printf("Bem-vindo ao Super Trunfo - Desafio Mestre!\n");
    printf("Esta sera sua primeira carta (01) entao:\nDigite a letra 'A-H' que representa seu estado: ");
    scanf(" %c", &Estado);
    printf("Digite o codigo da carta (2 digitos de 01-04): ");
    scanf("%02d", &Codigo);
    printf("Digite o nome da cidade: ");
    getchar(); 
    fgets(Nome_da_cidade, sizeof(Nome_da_cidade), stdin);
    Nome_da_cidade[strcspn(Nome_da_cidade, "\n")] = '\0';
    printf("Digite o numero de pontos turisticos da cidade escolhida: ");
    scanf("%d", &Numero_de_pontos_turisticos);
    printf("Digite a populacao da cidade: ");
    scanf("%d", &Populacao);
    printf("Digite o PIB da cidade selecionada (em bilhoes de reais): ");
    scanf("%f", &PIB);
    printf("Digite a area da cidade (em KM2): ");
    scanf("%f", &Area);
    Codigo_da_carta[0] = Estado;
    Codigo_da_carta[1] = '\0';

    // Concatenacao do codigo da carta com o estado.
    sprintf(Codigo_str, "%02d", Codigo); // Converte numero inteiro para string.
    strcat(Codigo_da_carta, Codigo_str); 

    // Entrada de dados para carta 02.
    printf("\n\nAgora digite as informacoes da sua segunda carta\nDigite a letra 'A-H' que representa seu estado (diferente da carta 01): ");
    scanf(" %c", &Estado2);
    printf("Digite o codigo da segunda carta (2 digitos de 01-04): ");
    scanf("%02d", &Codigo2);
    printf("Digite o nome da cidade: ");
    getchar(); 
    fgets(Nome_da_cidade2, sizeof(Nome_da_cidade2), stdin);
    Nome_da_cidade2[strcspn(Nome_da_cidade2, "\n")] = '\0';
    printf("Digite o numero de pontos turisticos da cidade escolhida: ");
    scanf("%d", &Numero_de_pontos_turisticos2);
    printf("Digite a populacao da cidade: ");
    scanf("%d", &Populacao2);
    printf("Digite o PIB da cidade selecionada (em bilhoes de reais): ");
    scanf("%f", &PIB2);
    printf("Digite a area da cidade (em KM2): ");
    scanf("%f", &Area2);
    Codigo_da_carta2[0] = Estado2;
    Codigo_da_carta2[1] = '\0';

    // Concatenacao do codigo da carta com o estado.
    sprintf(Codigo_str2, "%02d", Codigo2); // Converte numero inteiro para string.
    strcat(Codigo_da_carta2, Codigo_str2); 

    // Calculo de PIB per capita e densidade demografica.
    PIB_per_capita = ( PIB / Populacao ) * 1000000000;
    PIB_per_capita2 = ( PIB2 / Populacao2 ) * 1000000000;
    densidade_demografica = Populacao / Area;
    densidade_demografica2 = Populacao2 / Area2;

    // Calculo dos Super Poderes.
    Super_Poder1 = (float) Populacao + Area + PIB + (float) Numero_de_pontos_turisticos + PIB_per_capita + (1 / densidade_demografica);
    Super_Poder2 = (float) Populacao2 + Area2 + PIB2 + (float) Numero_de_pontos_turisticos2 + PIB_per_capita2 + (1 / densidade_demografica2);

    // Switch interativo
    printf ("\n\n Escolha uma das opcoes:\n");
    printf ("1 - Comparar cartas\n");
    printf ("2 - Apresentar dados das cartas\n");
    printf ("3 - Sair do programa\n");
    scanf ("%d", &opcao);

    switch (opcao) {
    // Switch de comparacao do primeiro atributo.
        case 1:
        printf("\nSelecione o primeiro atributo para comparar:\n\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Numero de pontos turisticos\n");
        printf("5 - Densidade demografica\n");
        printf("6 - PIB per capita\n");
        printf("7 - Super Poder\n");
        scanf("%d", &opcao2);

        switch (opcao2) {
            case 1:
            CompPop = Populacao > Populacao2 ? 1 : 0;
            CompPop = Populacao == Populacao2 ? 2 : CompPop;
            break;

            case 2:
            CompArea = Area > Area2 ? 1 : 0;
            CompArea = Area == Area2 ? 2 : CompArea;
            break;
    
            case 3:
            CompPIB = PIB > PIB2 ? 1 : 0;
            CompPIB = PIB == PIB2 ? 2 : CompPIB;
            break;

            case 4:
            CompPontos = Numero_de_pontos_turisticos > Numero_de_pontos_turisticos2 ? 1 : 0;
            CompPontos = Numero_de_pontos_turisticos == Numero_de_pontos_turisticos2 ? 2 : CompPontos;
            break;

            case 5:
            CompDensidade = densidade_demografica < densidade_demografica2 ? 1 : 0;
            CompDensidade = densidade_demografica == densidade_demografica2 ? 2 : CompDensidade;
            break;

            case 6:
            CompPIBPerCapita = PIB_per_capita > PIB_per_capita2 ? 1 : 0;
            CompPIBPerCapita = PIB_per_capita == PIB_per_capita2 ? 2 : CompPIBPerCapita;
            break;

            case 7:
            CompSup = Super_Poder1 > Super_Poder2 ? 1 : 0;
            CompSup = Super_Poder1 == Super_Poder2 ? 2 : CompSup;
            break;

            default:
            printf("Opcao invalida\n");
            break;
        }
    // Switch de comparacao do segundo atributo.
        printf("\nSelecione o segundo atributo:\n\n");
        if (opcao2 ==1) {
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Numero de pontos turisticos\n");
            printf("5 - Densidade demografica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==2) {
            printf("1 - Populacao\n");
            printf("3 - PIB\n");
            printf("4 - Numero de pontos turisticos\n");
            printf("5 - Densidade demografica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==3) {
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("4 - Numero de pontos turisticos\n");
            printf("5 - Densidade demografica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==4) {
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("5 - Densidade demografica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==5) {
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Numero de pontos turisticos\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==6) {
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Numero de pontos turisticos\n");
            printf("5 - Densidade demografica\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==7) {
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Numero de pontos turisticos\n");
            printf("5 - Densidade demografica\n");
            printf("6 - PIB per capita\n");
            scanf("%d", &opcao3);
        }

        switch (opcao3) {
            case 1:
            CompPop = Populacao > Populacao2 ? 1 : 0;
            CompPop = Populacao == Populacao2 ? 2 : CompPop;
            break;

            case 2:
            CompArea = Area > Area2 ? 1 : 0;
            CompArea = Area == Area2 ? 2 : CompArea;
            break;
    
            case 3:
            CompPIB = PIB > PIB2 ? 1 : 0;
            CompPIB = PIB == PIB2 ? 2 : CompPIB;
            break;

            case 4:
            CompPontos = Numero_de_pontos_turisticos > Numero_de_pontos_turisticos2 ? 1 : 0;
            CompPontos = Numero_de_pontos_turisticos == Numero_de_pontos_turisticos2 ? 2 : CompPontos;
            break;

            case 5:
            CompDensidade = densidade_demografica < densidade_demografica2 ? 1 : 0;
            CompDensidade = densidade_demografica == densidade_demografica2 ? 2 : CompDensidade;
            break;

            case 6:
            CompPIBPerCapita = PIB_per_capita > PIB_per_capita2 ? 1 : 0;
            CompPIBPerCapita = PIB_per_capita == PIB_per_capita2 ? 2 : CompPIBPerCapita;
            break;

            case 7:
            CompSup = Super_Poder1 > Super_Poder2 ? 1 : 0;
            CompSup = Super_Poder1 == Super_Poder2 ? 2 : CompSup;
            break;

            default:
            printf("Opção inválida\n");
            break;
        }

    // Logica para selecionar qual carta ganhou.
        if (Carta1[opcao2] > Carta2[opcao2]) {Comp1++;
        } else if (Carta1[opcao2] < Carta2[opcao2]) {Comp2++;
        } else {CompEmpate++;}

        if (Carta1[opcao3] > Carta2[opcao3]) {Comp1++;
        } else if (Carta1[opcao3] < Carta2[opcao3]) {Comp2++;
        } else {CompEmpate++;}

    // Impressao do resultado da comparacao.
        printf("\nCidade 01: %s\nCidade 02: %s\n", Nome_da_cidade, Nome_da_cidade2);
        printf("Atributo 01: %s\nAtributo 02: %s\n", atributos[opcao2], atributos[opcao3]);
        printf("Carta 01 (%s): %.f\nCarta 02 (%s): %.2f\n", atributos[opcao2], Carta1[opcao2], atributos[opcao2], Carta2[opcao2]);
        printf("Carta 01 (%s): %.2f\nCarta 02 (%s): %.2f\n", atributos[opcao3], Carta1[opcao3], atributos[opcao3], Carta2[opcao3]);

        if (Comp1 == 2) {
            printf("\nA carta 01 venceu com 2 pontos!\n");
        } else if (Comp2 == 2) {
            printf("\nA carta 02 venceu com 2 pontos!\n");
        } else if (Comp1 == 1 && Comp2 == 1) {
            printf("\nHouve um empate com 1 ponto para cada carta!\n");
        } else if (CompEmpate == 2) {
            printf("\nHouve um empate, nenhum ponto para ambas as cartas!\n");
        } else if (Comp1 == 1 && CompEmpate == 1) {
            printf("\nA carta 01 venceu com 1 ponto!\n");
        } else if (Comp2 == 1 && CompEmpate == 1) {
            printf("\nA carta 02 venceu com 1 ponto!\n");
        }
        break;
        
            case 2:
            // Impressao dos dados.
            printf("\n\nDados da carta 01:\n");
            printf("Estado: %c\n", Estado);
            printf("Codigo da carta: %s\n", Codigo_da_carta);
            printf("Nome da cidade: %s\n", Nome_da_cidade);
            printf("Populacao: %d habitantes\n", Populacao);
            printf("Area: %.2f KM2\n", Area);
            printf("PIB: %.2f Bilhoes de reais\n", PIB);
            printf("Numero de pontos turisticos: %d\n", Numero_de_pontos_turisticos);
            printf("PIB per capita: %.2f reais\n", PIB_per_capita);
            printf("Densidade demografica: %.2f habitantes/KM2\n", densidade_demografica);
            printf("Super Poder: %.2f\n", Super_Poder1);

            printf("\nDados da carta 02:\n");
            printf("Estado: %c\n", Estado2);
            printf("Codigo da carta: %s\n", Codigo_da_carta2);
            printf("Nome da cidade: %s\n", Nome_da_cidade2);
            printf("Populacao: %d habitantes\n", Populacao2);
            printf("Area: %.2f KM2\n", Area2);
            printf("PIB: %.2f Bilhoes de reais\n", PIB2);
            printf("Numero de pontos turisticos: %d\n", Numero_de_pontos_turisticos2);
            printf("PIB per capita: %.2f reais\n", PIB_per_capita2);
            printf("Densidade demografica: %.2f habitantes/KM2\n", densidade_demografica2);
            printf("Super Poder: %.2f\n", Super_Poder2);
            break;
    // Switch de saida do programa.
            case 3:
            printf("Saindo do programa...\n");
            exit(0);
            break;

        default:
            printf("Opção invalida\n");
           break;

    return 0;
    }
}