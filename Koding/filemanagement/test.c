#include <stdio.h>
#include <string.h>

//DECLARE VARIABLES HERE
char username[120],password[120];

int main(){
    FILE *database;

    database = fopen("database.txt", "a+");

    if(database == NULL){
        printf("FILE TIDAK ADA!");
    }else{
        printf("Masukkan username : "); scanf("%s", username);
        printf("Masukkan password : "); scanf("%s", password);

        printf("Username anda : "); fprintf(database, username); 
        printf("\nPassword anda : "); fprintf(database, password);
    }

    fclose(database);

    

    



}