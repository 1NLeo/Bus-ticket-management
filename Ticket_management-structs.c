#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> // tolower

#define reset   "\033[0m"
#define green "\033[32m"
#define cyan   "\033[36m"
#define red "\033[31m"

#define max_users 100
#define max_reservas 21


    int main (){

        setlocale(LC_ALL, ".UTF-8");

        int opt = 0, nome = 0, oldnome = 1, ver = 0, nova_reserva = 0, conf = 0;
        int inic_var = 0; // inicar a variavel das reservas
        int seat[max_reservas];      
        int reservado [max_reservas];
        char user [max_users][50];
        char olduser [max_users][50];
        int reservas[max_reservas];
        


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
                                inic_var ++;
                                nome++;
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
                            for (int i = 0; i < nome; i++){ 
                                                    
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

                                    for (int i = inic_var - 1; i < conf; i++){ // verify  
                                        printf ("Assento número %d reservado\n", reservas[i]);
                                    }
                                    break;
                                }
                                else {
                                    printf ("O nome informado está incorreto ou não foi cadastrado. \n");
                                }
                    break;
                            
                    case 4:
                
                    printf ( cyan "Reserva de assento\n" reset);
                    printf ("Digite seu nome completo: ");
                    fgets (olduser[oldnome], 49, stdin);
                    int encontrado = 0;

                            for (int i = 0; i < nome; i++){  
                                                    
                                for (int j = 0; olduser[oldnome][j] != '\0'; j++){
                                olduser[oldnome][j] = tolower(olduser[oldnome][j]);
                                }                    
                                    ver = strcmp(user[i], olduser[oldnome]);
                                    if (ver == 0){
                                        encontrado = 1; // retorna acahado = 1 se os nomes forem iguais
                                        break;
                                    }
                                }

                                if (encontrado == 1){ // Usuário verificado
                                    printf ("Qual assento você deseja reservar: ");
                                    scanf ("%d", &nova_reserva);
                                    int indisp = 0; 

                                    for (int i = 0; i < max_reservas; i++){
                                        if (reservado[i] == nova_reserva){
                                            indisp = 1; // retorna indisp = 1 se o assento estiver indisponivel
                                            break;
                                        }    
                                    }

                                if (indisp == 0) {
                                    printf (green "Assento Reservado!\n" reset);
                                    reservado[conf] = nova_reserva;
                                    reservas[conf] = nova_reserva;
                                    conf++;
                                }

                                else {
                                // loop funcionando :)    
                                    while (indisp == 1) {
                                        printf ("Infelizmente esse assento ja foi reservado ):\n");
                                        printf ("Escolha outro assento: ");
                                        scanf ("%d", &nova_reserva);
                                        indisp = 0;

                                            for (int i = 0; i < 21; i++){
                                                if (reservado[i] == nova_reserva){
                                                    indisp = 1;
                                                    break;
                                                } 

                                            }
                                    }

                                    printf (green "Assento Reservado!\n" reset);
                                    reservado[conf] = nova_reserva;
                                    reservas[conf] = nova_reserva;
                                    conf++;
                                }   
                            }
                                else {
                                    printf ("O nome informado está incorreto ou não foi cadastrado. \n");
                                }
                    
                    



                    break;

                    case 5: 
                        printf( red "Saindo...\n" reset);
                    break;

                    default:
                        printf (red "ERRO:" reset "Digite uma das opções abaixo: \n");
                    break;
                }
                   
                        
            } while (opt != 5);
        

        

        return 0;
    }