#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> // tolower

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

        int opt = 0, nome = 0, oldnome = 1, nusers = 1, ver = 0, nova_reserva = 0, conf = 0;
        int seat[21];      
        int reservado [21];
        char user [nusers][50];
        char olduser [nusers][50];
        


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
                        printf("Digite seu nome completo: \n");
                        fgets(user[nome], 49, stdin);

                            for (int i = 0; user[nome][i] != '\0'; i++){
                                user[nome][i] = tolower(user[nome][i]);
                            }

                            int cad = 0;
                            for (int i = 0; i < nome; i++){
                                ver = strcmp(user[i], user[nome]); // return 0 when true
                                if (ver == 0) {
                                    cad = 1;
                                    break;
                                }
                            }

                            if (cad == 0) {
                                nome++;
                                nusers++;
                                printf(green "Usuário cadastrado com sucesso!\n" reset);
                            } else {
                                printf("Você já possui cadastro.\n");
                            }
                        
                    break;

                    case 2:
                        printf (cyan "Assentos disponíveis\n" reset); // fazer o continue funcionar
                        

                        for (int i = 1; i < 21; i++){
                            int disponivel = 1;
                            for (int j = 0; j < 20; j++){
                                if (reservado[j] == i){
                                    disponivel = 0;   
                                }
                            }
                                if (disponivel == 1){
                                    printf ("%d\n", i);
                        }
                        }
                       
                            
                    

                    break;

                    case 3:
                    
                        printf (cyan "Reservas antigas\n" reset);
                        printf ("Digite seu nome completo: ");
                        fgets (olduser[oldnome], 49, stdin);
                        int achado = 0;
                            for (int i = 0; i < 8; i++){ // Conferir se ja tem cadastro, se tiver montar outra estrutura para vizualizar
                                                        // Reservas antigas
                                                        // Tolower funcionando: Jogar ele para o switch 1 para verificar o cadastro;
                                                    
                            for (int i = 0; olduser[oldnome][i] != '\0'; i++){
                            olduser[oldnome][i] = tolower(olduser[oldnome][i]);
                            }                    
                                ver = strcmp(user[i], olduser[oldnome]);
                                if (ver == 0){
                                    achado = 1;
                                    break;
                                }
                            }

                            if (achado == 1){ // Usuário verificado
                                    for (int i = 0; i < 20; i++){

                                    }
                                    break;
                                }
                                else {
                                    printf ("O nome informado está incorreto ou não foi cadastrado. \n");
                                }
                    break;
                            
                    case 4:
                
                    printf ( cyan "Reserva de assento\n" reset);
                    printf ("Qual assento você deseja reservar: ");
                    scanf ("%d", &nova_reserva);
                    int indisp = 0; 

                        for (int i = 1; i < 21; i++){
                             if (reservado[i] == nova_reserva){
                                indisp = 1;
                                break;
                            }
                            
                        }

                          if (indisp == 1){
                          printf ("Infelizmente esse assento ja foi reservado ):\n");
                          }
                            
                          else if (indisp == 0) {
                          printf (green "Assento Reservado!\n" reset);
                          reservado[conf] = nova_reserva;
                          conf++;
                          }

                    break;

                    case 5: 
                        printf( red "Saindo...\n" reset);
                    break;

                    default:
                        printf (red "ERROR:" reset "Digite uma das opções abaixo: \n");
                    break;
                }
                   
                        
            } while (opt != 5);
        

        

        return 0;
    }