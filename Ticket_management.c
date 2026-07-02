#include <stdio.h>
#include <string.h>
#include <locale.h>

#define reset   "\033[0m"
#define green "\033[32m"
#define cyan   "\033[36m"
#define red "\033[31m"

// Descrição do Projeto: Sistema de Gerenciamento de Passagens de Ônibus

// O objetivo deste projeto é desenvolver um sistema em linguagem C para o gerenciamento de passagens de ônibus. 
// O programa deve interagir com o usuário por meio de um menu dinâmico, oferecendo inicialmente as seguintes funcionalidades:

// Verificar disponibilidade de assentos: Exibir visualmente quais assentos do ônibus estão livres ou ocupados.

// Reservar um assento: Permitir que o usuário escolha um assento disponível e realize a reserva, atualizando o status do mapa do ônibus.

// Consulta por Passageiro (Pesquisa)
// Consultar assentos reservados por esse passageiro
// Quero que você tente fazer esse desafio sem utilizar structs e depois utilizando structs


// Login area :
// 1- Cadastrar usuário
// 2- Vizualizar assentos disponiveis
// 3- Vizualizar reservas antigas
// 4- Reservar assento
// 5- Sair

    int main (){

        setlocale(LC_ALL, ".UTF-8");

        int opt, nome = 1, oldnome = 1, nusers = 1, ver;
        int seat[4][5] = {{1, 2, 3, 4, 5},
                          {6, 7, 8, 9, 10},
                          {11, 12, 13, 14, 15},
                          {16, 17, 18, 19, 20}};

        char users [100][50];
        char olduser [100][50];
        


            do{
            printf("========================================\n");
            printf("|" cyan "           Viagem de ônibus" reset     "           |\n" );
            printf("========================================\n");
            printf ("|" green " [1]" reset " Cadastrar usuário                |  \n");
            printf ("|" green " [2]" reset " Vizualizar assentos disponíveis  |  \n");
            printf ("|" green " [3]" reset " Vizualizar reservas antigas      |  \n");
            printf ("|" green " [4]" reset " Reservar assento                 |  \n");
            printf ("|" green " [5]" reset " Sair                             |  \n"); 
            printf ("========================================\n");
            scanf ("%d", &opt);
            getchar();

                switch (opt) {
                    case 1:
                    printf ("Digite seu nome completo: \n");
                    fgets (users[nome], 49, stdin);
                    
                    nome++;
                    nusers++;

                    break;

                    case 2:
                        printf (cyan "Assentos disponíveis\n" reset);

                        for (int i = 0; i < 4; i++){
                            for (int j = 0; j < 5; j++){
                                printf ("%d ", seat[i][j]);
                            }

                            printf ("\n");
                        }

                    break;

                    case 3:
                    
                        printf (cyan "Reservas antigas\n" reset);
                        printf ("Digite seu nome completo: ");
                        fgets (olduser[oldnome], 49, stdin);
                        int achado = 0;
                            for (int i = 0; i < 8; i++){ // Conferir se ja tem cadastro, se tiver montar outra estrutura para vizualizar
                                                        // Reservas antigas
                                                    
                                                    
                                ver = strcmp(users[i], olduser[oldnome]);
                                if (ver == 0){
                                    achado = 1;
                                    break;
                                }
                            }

                            if (achado == 1){
                                    printf ("Você já possui cadastro \n:)");
                                    break;
                                }
                                else {
                                    printf ("Não possui cadastro ainda \n");
                                }
                    break;
                            
                    case 4:

                    printf ( cyan "Reserva de assento\n" reset);
                }
                   
                        
            } while (opt != 5);
        

        

        return 0;
    }