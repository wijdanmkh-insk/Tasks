#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//GLOBAL VARIABLES
int food[3]={10000,12000,15000};
int drink[3]={10000,13000,16000};
char choice; 

//DECLARE FUNCTIONS HERE
void mainMenu();
void about();

void header(){
    printf("====================================================================================\n");
    printf("\t\t\tCASHIER MANAGEMENT PROGRAM\n");
    printf("====================================================================================\n");
}

void hargacek(){
    FILE* harga;
    harga = fopen("harga.txt","w+");
}

void cexit(){
    printf("Apakah anda ingin keluar? (Y/N)"); getchar();
        scanf("%c", &choice);
        if((choice =='Y')||(choice == 'y')){
            exit(0);
        }else if(choice=='N'||choice=='n'){
            mainMenu();
        }else{
            printf("PILIHAN SALAH! SILAHKAN MASUKKAN PILIHAN YANG BENAR!\n");
            cexit();
        }    
}

void val(char x){
    if((choice =='Y')||(choice == 'y')){
        mainMenu();
    }
}

struct data{
    char username[100];
    char pass[100];
}; 

struct data d1; 


void line(){
    printf("===============================================================\n"); 
}


void hargabarang(){
    system("cls");
    //line();
    header();
    printf("\t\tSILAHKAN CEK HARGA BARANG DISINI\n");
    printf("\t\tMakanan\n");
    //printf("1. Chitato\t%d\n2. Lay's\t%d\n3. Biskuat\t%d\n", food[0],food[1],food[2]);
    hargacek();

    printf("Kembali Ke Menu Utama? (Y/N) : "); getchar(); scanf("%c", &choice);
    val(choice);
    if(choice=='Y'||choice=='y'){
        mainMenu();
    }else{
        hargabarang();
    }
    
    
}

void options(int x){
    switch(x){
        case 1 :
            hargabarang();
        case 2 : 
            //stock();
        case 3 : 
            //checkout();
        case 4 : 
            //about();
        case 5 :
            cexit();
        default : 
            printf("PILIHAN SALAH! SILAHKAN COBA LAGI\n");
            mainMenu();
            options(x);
            break;

    }
}
void mainMenu(){
    int pilihan;
    //system("cls");
    header();
    printf("Silahkan pilih menu : \n1) Cek harga barang\n2) Hitung stok barang\n3) Checkout barang\n4) Tentang program ini\n5) Keluar dari aplikasi\n"); 
    printf("Silahkan pilih : "); scanf("%d",&pilihan); getchar();

    options(pilihan);
}       

void manageAcc(){ 
    line();
    printf("\tSILAHKAN MASUKKAN USERNAME DAN PASSWORD \n");
    printf("USERNAME\t: "); scanf("%s", d1.username);
    printf("PASSWORD\t: "); scanf("%s", d1.pass);
    line();
    system("cls");
}

void contact(){
    line();
    printf("Jika ada kendala mengenai program ini, silahkan hubungi : \n");
    printf("TELEPON\t:\t+62 823 1843 3594\n");
    printf("E-MAIL\t:\twijdaninskzf@student.telkomuniversity.ac.id\n");
    line();   
}

void backcheck(char choice){
    if((choice =='Y')||(choice == 'y')){
    manageAcc();
    }else if((choice != 'N') || (choice != 'n')){
        printf("Pilihan salah! Masukkan pilihan yang benar!");
        
    }
}

void check(){
    int trial = 2; 
    while((((strcmp(d1.username, "admin")!=0) && strcmp(d1.pass,"admin")!=0)) && trial > 0){
        if((strcmp(d1.username, "admin")!=0) && strcmp(d1.pass,"admin")!=0){
            printf("USERNAME ATAU PASSWORD SALAH!\nKESEMPATAN LOGIN : %d\n", trial);
            printf("SILAHKAN MASUKKAN USERNAME DAN PASSWORD YANG BENAR!\n"); 
            manageAcc();
            trial--;  
        }       
    }

    if(trial != 0){
        mainMenu();
    }else{
        contact();
        printf("Kembali ke menu utama? (Y/N) "); getchar(); scanf("%c", &choice);
        backcheck(choice);
    }
}

void about(){
    system("cls");
    line();
    printf("TENTANG APLIKASI LOGISTICS MANAGEMENT PROGRAM\n");
    line();
    printf("Logistics Management Program adalah salah satu program yang dibuat oleh tiga mahasiswa Universitas Telkom. Program ini digunakan untuk menghitung, memastikan stok barang yang ada di toko sehingga barang yang kurang dapat di stok ulang, dan menghitung barang yang akan di checkout beserta berkurangnya nilai stok sehingga pemilik toko dapat melakukan restock jika diperlukan");
}

void setWindow(){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Mengatur ukuran jendela lebar x tinggi (misalnya, 80x30 karakter)
    SMALL_RECT windowSize = {80, 80, 80, 80};
    SetConsoleWindowInfo(console, TRUE, &windowSize);

    // Mengatur ukuran layar lebar x tinggi (misalnya, 80x30 karakter)
    COORD bufferSize = {80, 30};
    SetConsoleScreenBufferSize(console, bufferSize);
}

int main(){
    
    //setWindow();
    manageAcc();
    check();
}