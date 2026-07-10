#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> // tolower

#define reset   "\033[0m"
#define green "\033[32m"
#define cyan   "\033[36m"
#define red "\033[31m"

#define max_users 100
#define max_reservations 21

struct user_reservation {

    char name[100];
    int seat[max_reservations];
    int reserved[max_reservations];


};
typedef struct user_reservation user_reservation;

    int main (){
    
    user_reservation user[max_reservations];

    setlocale(LC_ALL, ".UTF-8");

    int opt = 0;

    do{
        printf("========================================\n");
        printf("|" cyan "              Bus Trip" reset            "              |\n" );
        printf("========================================\n");
        printf ("|" green " [1]" reset " Register user                    |  \n");
        printf ("|" green " [2]" reset " View available seats             |  \n");
        printf ("|" green " [3]" reset " View past reservations           |  \n");
        printf ("|" green " [4]" reset " Reserve a seat                   |  \n");
        printf ("|" green " [5]" reset " Exit                             |  \n"); 
        printf ("========================================\n");
        scanf ("%d", &opt);
        getchar();

        switch (opt) {
            case 1:

            break;

            case 2:

            break;

            case 3:

            break;

            case 4:

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