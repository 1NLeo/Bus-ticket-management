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


    int main (){

        setlocale(LC_ALL, ".UTF-8");

        int opt = 0, name = 0, old_name = 1, cmp_result = 0, new_reservation = 0, confirmed = 0;
        int init_var = 0; // initialize the reservations variable
        int seat[max_reservations];      
        int reserved [max_reservations];
        char user [max_users][50];
        char old_user [max_users][50];
        int reservations[max_reservations];
        

            do{
            printf("========================================\n");
            printf("|" cyan "             Bus Trip"                reset     "               |\n" );
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
                        printf("Enter your full name: \n");
                        fgets(user[name], 49, stdin);

                            for (int i = 0; user[name][i] != '\0'; i++){
                                user[name][i] = tolower(user[name][i]);
                            }

                            int registered = 0;
                            for (int i = 0; i < name; i++){
                                cmp_result = strcmp(user[i], user[name]); // returns 0 when true
                                if (cmp_result == 0) {
                                    registered = 1;
                                    break;
                                }
                            }

                            if (registered == 0) {
                                init_var ++;
                                name++;
                                printf(green "User registered successfully!\n" reset);
                            } else {
                                printf("You are already registered.\n");
                            }
                        
                    break;

                    case 2:
                        printf (cyan "Available seats\n" reset); // make continue work
                        

                        for (int i = 1; i < 21; i++){
                            int available = 1;
                            for (int j = 0; j < 20; j++){
                                if (reserved[j] == i){
                                    available = 0;   
                                }
                            }
                                if (available == 1){
                                    printf ("%d\n", i);
                        }
                        }
                       
                            
                    

                    break;

                    case 3:
                    
                        printf (cyan "Past reservations\n" reset);
                        printf ("Enter your full name: ");
                        fgets (old_user[old_name], 49, stdin);
                        int found = 0;
                            for (int i = 0; i < name; i++){ 
                                                    
                            for (int i = 0; old_user[old_name][i] != '\0'; i++){
                            old_user[old_name][i] = tolower(old_user[old_name][i]);
                            }                    
                                cmp_result = strcmp(user[i], old_user[old_name]);
                                if (cmp_result == 0){
                                    found = 1;
                                    break;
                                }
                            }

                            if (found == 1){ // user verified

                                    for (int i = init_var - 1; i < confirmed; i++){ // verify  
                                        printf ("Seat number %d reserved\n", reservations[i]);
                                    }
                                    break;
                                }
                                else {
                                    printf ("The name entered is incorrect or not registered. \n");
                                }
                    break;
                            
                    case 4:
                
                    printf ( cyan "Seat reservation\n" reset);
                    printf ("Enter your full name: ");
                    fgets (old_user[old_name], 49, stdin);
                    int found2 = 0;

                            for (int i = 0; i < name; i++){  
                                                    
                                for (int j = 0; old_user[old_name][j] != '\0'; j++){
                                old_user[old_name][j] = tolower(old_user[old_name][j]);
                                }                    
                                    cmp_result = strcmp(user[i], old_user[old_name]);
                                    if (cmp_result == 0){
                                        found2 = 1; // returns found2 = 1 if the names match
                                        break;
                                    }
                                }

                                if (found2 == 1){ // user verified
                                    printf ("Which seat would you like to reserve: ");
                                    scanf ("%d", &new_reservation);
                                    int unavailable = 0; 

                                    for (int i = 0; i < max_reservations; i++){
                                        if (reserved[i] == new_reservation){
                                            unavailable = 1; // returns unavailable = 1 if the seat is unavailable
                                            break;
                                        }    
                                    }

                                if (unavailable == 0) {
                                    printf (green "Seat reserved!\n" reset);
                                    reserved[confirmed] = new_reservation;
                                    reservations[confirmed] = new_reservation;
                                    confirmed++;
                                }

                                else {
                                // loop working :)    
                                    while (unavailable == 1) {
                                        printf ("Unfortunately this seat has already been reserved ):\n");
                                        printf ("Choose another seat: ");
                                        scanf ("%d", &new_reservation);
                                        unavailable = 0;

                                            for (int i = 0; i < 21; i++){
                                                if (reserved[i] == new_reservation){
                                                    unavailable = 1;
                                                    break;
                                                } 

                                            }
                                    }

                                    printf (green "Seat reserved!\n" reset);
                                    reserved[confirmed] = new_reservation;
                                    reservations[confirmed] = new_reservation;
                                    confirmed++;
                                }   
                            }
                                else {
                                    printf ("The name entered is incorrect or not registered. \n");
                                }
                    
                    



                    break;

                    case 5: 
                        printf( red "Exiting...\n" reset);
                    break;

                    default:
                        printf (red "ERROR:" reset " Enter one of the options below: \n");
                    break;
                }
                   
                        
            } while (opt != 5);
        

        

        return 0;
    }