#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Sele  o de vari veis.
    char Estado, Nome_da_cidade [20], Codigo_da_carta [4], Codigo_str[3], Estado2, Nome_da_cidade2 [20], Codigo_da_carta2 [4], Codigo_str2[3];
    int CompPop, CompArea, CompPIB, CompPontos, CompDensidade, CompPIBPerCapita, CompSup;
    int Populacao, Numero_de_pontos_turisticos, Codigo, Populacao2, Numero_de_pontos_turisticos2, Codigo2, opcao, opcao2, opcao3, Comp1, Comp2, CompEmpate;
    float PIB, Area, PIB2, Area2;
    float PIB_per_capita, PIB_per_capita2, densidade_demografica, densidade_demografica2;
    float Super_Poder1, Super_Poder2;
    
    // Entrada de dados para carta 01.
    printf("Bem-vindo ao Super Trunfo - Desafio Mestre!\n");
    printf("Esta sera sua primeira carta (01) então:\nDigite a letra 'A-H' que representa seu estado: ");
    scanf(" %c", &Estado);
    printf("Digite o código da carta (2 digitos de 01-04): ");
    scanf("%02d", &Codigo);
    printf("Digite o nome da cidade: ");
    getchar(); 
    fgets(Nome_da_cidade, sizeof(Nome_da_cidade), stdin);
    Nome_da_cidade[strcspn(Nome_da_cidade, "\n")] = '\0';
    printf("Digite o número de pontos turísticos da cidade escolhida: ");
    scanf("%d", &Numero_de_pontos_turisticos);
    printf("Digite a população da cidade: ");
    scanf("%d", &Populacao);
    printf("Digite o PIB da cidade selecionada (em bilhões de reais): ");
    scanf("%f", &PIB);
    printf("Digite a área da cidade (em KM2): ");
    scanf("%f", &Area);
    Codigo_da_carta[0] = Estado;
    Codigo_da_carta[1] = '\0';
    // Concatena  o do c digo da carta com o estado.
    
    sprintf(Codigo_str, "%02d", Codigo); // Converte n mero inteiro para string.
    strcat(Codigo_da_carta, Codigo_str); 

    // Entrada de dados para carta 02.
    printf("\n\nAgora digite as informações da sua segunda carta\nDigite a letra 'A-H' que representa seu estado (diferente da carta 01): ");
    scanf(" %c", &Estado2);
    printf("Digite o c digo da segunda carta (2 digitos de 01-04): ");
    scanf("%02d", &Codigo2);
    printf("Digite o nome da cidade: ");
    getchar(); 
    fgets(Nome_da_cidade2, sizeof(Nome_da_cidade2), stdin);
    Nome_da_cidade2[strcspn(Nome_da_cidade2, "\n")] = '\0';
    printf("Digite o n mero de pontos tur sticos da cidade escolhida: ");
    scanf("%d", &Numero_de_pontos_turisticos2);
    printf("Digite a popula  o da cidade: ");
    scanf("%d", &Populacao2);
    printf("Digite o PIB da cidade selecionada (em bilh es de reais): ");
    scanf("%f", &PIB2);
    printf("Digite a  rea da cidade (em KM ): ");
    scanf("%f", &Area2);
    Codigo_da_carta2[0] = Estado2;
    Codigo_da_carta2[1] = '\0';
    // Concatena  o do c digo da carta com o estado.
    sprintf(Codigo_str2, "%02d", Codigo2); // Converte n mero inteiro para string.
    strcat(Codigo_da_carta2, Codigo_str2); 

    // Calculo de PIB per capita e densidade demogr fica.
    PIB_per_capita = ( PIB / Populacao ) * 1000000000;
    PIB_per_capita2 = ( PIB2 / Populacao2 ) * 1000000000;
    densidade_demografica = Populacao / Area;
    densidade_demografica2 = Populacao2 / Area2;

    // C  lculo dos Super Poderes.
    Super_Poder1 = (float) Populacao + Area + PIB + (float) Numero_de_pontos_turisticos + PIB_per_capita + (1 / densidade_demografica);
    Super_Poder2 = (float) Populacao2 + Area2 + PIB2 + (float) Numero_de_pontos_turisticos2 + PIB_per_capita2 + (1 / densidade_demografica2);

    // Switch interativo
    printf ("\n\n Esolha uma das opcoes:\n");
    printf ("1 - Comparar cartas\n");
    printf ("2 - Apresentar dados das cartas\n");
    printf ("3 - Sair do programa\n");
    scanf ("%d", &opcao);

    switch (opcao) {

        case 1:
        printf("\nSelecione o primeiro atributo para comparar:\n\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de pontos turísticos\n");
        printf("5 - Densidade demográfica\n");
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
            printf("Op ?o inv lida\n");
            break;
        }

        printf("\nSelecione o segundo atributo:\n\n");
        if (opcao2 ==1) {
            printf("2 -  rea\n");
            printf("3 - PIB\n");
            printf("4 - N mero de pontos tur sticos\n");
            printf("5 - Densidade demogr fica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==2) {
            printf("1 - Popula    o\n");
            printf("3 - PIB\n");
            printf("4 - N mero de pontos tur sticos\n");
            printf("5 - Densidade demogr fica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==3) {
            printf("1 - Popula    o\n");
            printf("2 -  rea\n");
            printf("4 - N mero de pontos tur sticos\n");
            printf("5 - Densidade demogr fica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==4) {
            printf("1 - Popula    o\n");
            printf("2 -  rea\n");
            printf("3 - PIB\n");
            printf("5 - Densidade demogr fica\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==5) {
            printf("1 - Popula    o\n");
            printf("2 -  rea\n");
            printf("3 - PIB\n");
            printf("4 - N mero de pontos tur sticos\n");
            printf("6 - PIB per capita\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==6) {
            printf("1 - Popula    o\n");
            printf("2 -  rea\n");
            printf("3 - PIB\n");
            printf("4 - N mero de pontos tur sticos\n");
            printf("5 - Densidade demogr fica\n");
            printf("7 - Super Poder\n");
            scanf("%d", &opcao3);
        } else if (opcao2 ==7) {
            printf("1 - Popula    o\n");
            printf("2 -  rea\n");
            printf("3 - PIB\n");
            printf("4 - N mero de pontos tur sticos\n");
            printf("5 - Densidade demogr fica\n");
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
            printf("Op ?o inv lida\n");
            break;
        } break;

        if ((CompPop == CompArea) || (CompPop == CompPIB) || (CompPop == CompPontos) || (CompPop == CompDensidade) || 
        (CompPop == CompPIBPerCapita) || (CompPop == CompSup) && (CompPop == 1) || (CompArea == 1) || (CompPIB == 1) || (CompPontos == 1) || 
        (CompDensidade == 1) || (CompPIBPerCapita == 1) || (CompSup == 1)) {
            Comp1 = 1;
        } else if ((CompPop == CompArea) || (CompPop == CompPIB) || (CompPop == CompPontos) || (CompPop == CompDensidade) || 
        (CompPop == CompPIBPerCapita) || (CompPop == CompSup) && (CompPop == 0) || (CompArea == 0) || (CompPIB == 0) || (CompPontos == 0) || 
        (CompDensidade == 0) || (CompPIBPerCapita == 0) || (CompSup == 0)) {
            Comp2 = 1;
        } else {
            Comp1 = 0;
            Comp2 = 0;
        }

        printf("\nCidade 01: %s\nCidade 02: %s\n", Nome_da_cidade, Nome_da_cidade2);
        if (opcao2 == 1 || opcao3 == 1) {
            printf("Atributo comparado:\n População 01 -%d habitantes\n População 02 -%d habitantes\n", Populacao, Populacao2);
        } else if (opcao2 == 2 || opcao3 == 2) {
            printf("Atributo comparado:\n Área 01 -%.2f KM2\n Área 02 -%.2f KM2\n", Area, Area2);
        } else if (opcao2 == 3 || opcao3 == 3) {
            printf("Atributo comparado:\n PIB 01 -%.2f Bilhões de reais\n PIB 02 -%.2f Bilhões de reais\n", PIB, PIB2);
        } else if (opcao2 == 4 || opcao3 == 4) {
            printf("Atributo comparado:\n Número de pontos turísticos 01 -%d\n Número de pontos turísticos 02 -%d\n", Numero_de_pontos_turisticos, Numero_de_pontos_turisticos2);
        } else if (opcao2 == 5 || opcao3 == 5) {
            printf("Atributo comparado:\n Densidade demográfica 01 -%.2f habitantes/KM2\n Densidade demográfica 02 -%.2f habitantes/KM2\n", densidade_demografica, densidade_demografica2);
        } else if (opcao2 == 6 || opcao3 == 6) {
            printf("Atributo comparado:\n PIB per capita 01 -%.2f reais\n PIB per capita 02 -%.2f reais\n", PIB_per_capita, PIB_per_capita2);
        } else if (opcao2 == 7 || opcao3 == 7) {
            printf("Atributo comparado:\n Super Poder 01 -%.2f\n Super Poder 02 -%.2f\n", Super_Poder1, Super_Poder2);
        }
        

        case 2:
            // Impress?o dos dados.
            printf("\n\nDados da carta 01:\n");
            printf("Estado: %c\n", Estado);
            printf("Código da carta: %s\n", Codigo_da_carta);
            printf("Nome da cidade: %s\n", Nome_da_cidade);
            printf("População: %d habitantes\n", Populacao);
            printf("Area: %.2f KM2\n", Area);
            printf("PIB: %.2f Bilhões de reais\n", PIB);
            printf("Número de pontos turísticos: %d\n", Numero_de_pontos_turisticos);
            printf("PIB per capita: %.2f reais\n", PIB_per_capita);
            printf("Densidade demográfica: %.2f habitantes/KM2\n", densidade_demografica);
            printf("Super Poder: %.2f\n", Super_Poder1);

            printf("\nDados da carta 02:\n");
            printf("Estado: %c\n", Estado2);
            printf("Código da carta: %s\n", Codigo_da_carta2);
            printf("Nome da cidade: %s\n", Nome_da_cidade2);
            printf("População: %d habitantes\n", Populacao2);
            printf("Area: %.2f KM2\n", Area2);
            printf("PIB: %.2f Bilhões de reais\n", PIB2);
            printf("Número de pontos turísticos: %d\n", Numero_de_pontos_turisticos2);
            printf("PIB per capita: %.2f reais\n", PIB_per_capita2);
            printf("Densidade demográfica: %.2f habitantes/KM2\n", densidade_demografica2);
            printf("Super Poder: %.2f\n", Super_Poder2);
            break;

            case 3:
            printf("Saindo do programa...\n");
            exit(0);
            break;

        default:
            printf("Opção inválida\n");
           break;

    return 0;
    }
}