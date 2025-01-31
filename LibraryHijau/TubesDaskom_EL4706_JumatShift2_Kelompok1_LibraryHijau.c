#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 300

//DEKLARASIKAN VARIABEL GLOBAL DISINI
int limit_login = 3;

//DEKLARASIKAN STRUCT DISINI
struct user{
    char username[300];
    char password[300];
};

struct peminjam{
    char username[300];
    char judul[300];
    char tanggal_pinjam[20];
    int denda;
};

struct buku{
    char judul[300];
    char jenis[300];
    char genre[300];
    char subgenre[300];
    int  stok;
}sortir_buku[100];

struct masukan{
    char username[300];
    char isi_feedback[1000];
};

//DEKLARASIKAN SEMUA FUNGSI YANG ADA DISINI
void users();
void lihat_acc();
void manage_lib();
void manage_guest();
void reg_guest();
void login_guest();
void menu_lib();
void menu_guest();
void ke_menu_utama();
void swap_buku();
void tambah_buku();
void hapus_buku();
void lihat_buku();
void tambah_lihat_peminjam();
void lihat_tulis_feedback();
void kembalikan_buku();
void lihat_tambah_denda();
void ubah_password();
void hapus_acc();


//EKSEKUSI FUNGSI DISINI
int main(){
    users();
}

//DEFINISIKAN FUNGSI UMUM DISINI
void users(){
    system("cls");
    printf("Selamat datang! Anda akan menggunakan program ini sebagai :\n1. Librarian\n2. User\n3. Keluar\nSilahkan pilih : ");
    int pilih; scanf("%d", &pilih); getchar();

    switch(pilih){
        do{
            case 1 :
            manage_lib(limit_login);
            break;
            case 2 :
            manage_guest();
            break;
            case 3 :
            exit(0);
            break;
            default :
            printf("Pilihan tidak ada! Silahkan pilih pilihan yang ada dan coba lagi!\n");
            system("pause");
        }while(pilih < 0 || pilih > 4);
    }
}

//DEKLARASIKAN FUNGSI LIBRARIAN DISINI
void manage_lib(int limit){
    system("cls");
    struct user user;
    printf("Selamat datang! Untuk melanjutkan, silahkan masukkan :\n");
    printf("Username  : "); gets(user.username);
    printf("Password  : "); gets(user.password);

    if((strcmp(user.username, "1") == 0) && (strcmp(user.password, "1") == 0)){
        menu_lib();
    }else{
        if(limit > 1){
            printf("Username atau password salah! Kesempatan login tersisa %d lagi\n", limit-1);
            system("pause");
            manage_lib(limit-1);
        }else{
            printf("Maaf, kesempatan login sudah habis!\n");
            system("pause");
        }
    }
}

void manage_guest(){
    system("cls");
    struct user user;
    printf("Selamat datang! Apakah anda sudah memiliki akun sebelumya? (Y/N) : ");
    char ans; scanf("%c", &ans); getchar();

    if(ans == 'Y' || ans == 'y'){
        login_guest(limit_login);
    }else if(ans == 'N' || ans == 'n'){
        reg_guest();
    }
}

void reg_guest(){
    system("cls");
    FILE *registrasi;
    struct user guest;
    registrasi = fopen("data_guest.dat", "ab");

    printf("Menu Mendaftar Pengguna Baru\n");
    printf("Masukkan username : "); gets(guest.username);
    printf("Masukkan password : "); gets(guest.password);
    fwrite(&guest, sizeof(guest), 1, registrasi);

    printf("Proses mendaftar berhasil! Silahkan login dengan menekan tombol setelah ini\n");
    system("pause");
    
    fclose(registrasi);
    
    login_guest(limit_login);
}

void login_guest(int limit){
    system("cls");
    struct user check;
    char username[300];
    char password[300];
    int flag_masuk;

    FILE *login;
    login = fopen("data_guest.dat", "rb");
    fseek(login, 0, SEEK_SET);

    printf("Selamat datang! Untuk melanjutkan, silahkan masukkan :\n");
    printf("Username  : "); gets(username); fflush(stdin);
    printf("Password  : "); gets(password); fflush(stdin);


    int i = 0;
    while(fread(&check, sizeof(check), 1, login) != 0){
        if((strcmp(username, check.username) == 0) && (strcmp(password, check.password) == 0)){
            flag_masuk = 1;
            break;
        }else{
            flag_masuk = 0;
        }
    }

    fclose(login);

    if(flag_masuk == 1){
        menu_guest();
    }else{
            if(limit > 1){
                printf("Username atau password salah! Kesempatan login tersisa %d lagi\n", limit-1);
                system("pause");
                login_guest(limit-1);
            }else{
                printf("Maaf, kesempatan login sudah habis!\n");
                flag_masuk = 0;
                system("pause");
                exit(0);
            }
    }
}

void menu_lib(){
    system("cls");
    int role = 1;
    printf("Selamat datang! Berikut adalah menu yang tersedia untuk mulai bekerja\n1. Lihat akun pengguna\n2. Tambah buku\n3. Hapus buku\n4. Lihat buku\n5. Lihat daftar peminjam buku\n6. Tambah denda\n7. Lihat feedback\n8. Keluar dari akun\n9. Keluar dari aplikasi\nSilahkan pilih : ");
    int pilih; scanf("%d", &pilih); getchar();

    switch (pilih){
    case 1 :
        lihat_acc(role);
        break;
    case 2 :
        tambah_buku(role);
        break;
    case 3 :
        hapus_buku(role);
        break;
    case 4 :
        lihat_buku(role);
        break;
    case 5 : 
        tambah_lihat_peminjam(role);
        break;
    case 6 : 
        lihat_tambah_denda(role);
        break;
    case 7 :
        lihat_tulis_feedback(role);
        break;
    case 8 :
        users();
        break;
    case 9 :
        exit(0);
    default:
        printf("Pilihan tidak ada! Silahkan pilih menu yang tersedia!");
        system("pause");
        menu_lib();
    }
}

void menu_guest(){
    system("cls");
    int role = 2;
    printf("Selamat datang! Berikut adalah menu yang tersedia\n1. Ubah password\n2. Hapus akun\n3. Lihat buku\n4. Pinjam buku\n5. Kembalikan buku\n6. Lihat denda\n7. Beri feedback\n8. Keluar dari akun\n9. Keluar dari aplikasi\nSilahkan pilih : ");
    int pilih; scanf("%d", &pilih); getchar();

    switch (pilih)
    {
    case 1 :
        ubah_password(role);
        break;
    case 2 :
        hapus_acc(role);
        break;
    case 3 :
        lihat_buku(role);
        break;
    case 4 : 
        tambah_lihat_peminjam(role);
        break;
    case 5 :
        kembalikan_buku(role);
        break;
    case 6 :
        lihat_tambah_denda(role);
        break;
    case 7 :
        lihat_tulis_feedback(role);
        break;
    case 8 :
        users();
        break;
    case 9 :
        exit(0);
        break;
    default:
        printf("Pilihan salah! Silahkan cek kembali pilihan yang benar dan masukkan kembali pilihan tersebut!");
        menu_guest();
    }
}


void ubah_password(int role){
    //system("cls");
    struct user input;
    struct user check;
    struct user temp;

    char passTemp[300];

    int found;
    printf("Menu Mengganti Password\n");
    printf("Masukkan username : "); gets(input.username);

    FILE *cari_user;
    FILE *data_baru;

    cari_user = fopen("data_guest.dat", "rb");
    while(fread(&check, sizeof(check), 1, cari_user) == 1){
        if((strcmp(input.username, check.username) == 0)){
            found = 1;
            break;
        }
        else{
            found = 0;
        }
    }
    fclose(cari_user);

    if(found == 1){
        cari_user = fopen("data_guest.dat", "rb");
        data_baru = fopen("data_guest1.dat", "wb");

        int flag;
            do{
                flag = 0;
                printf("Masukkan password baru                : "); gets(input.password);
                printf("Silahkan masukkan konfirmasi password : "); gets(passTemp);
            
                if(strcmp(input.password, passTemp) != 0){
                    printf("password dan konfirmasinya tidak cocok!\n");
                    flag = 1;
                }
            }while(flag == 1);

            while(fread(&check, sizeof(check), 1, cari_user) == 1){
                if((strcmp(input.username, check.username) != 0)){
                    fwrite(&check, sizeof(check), 1, data_baru);
                }
            }

            strcpy(temp.username, input.username);
            strcpy(temp.password, input.password);
            fwrite(&temp, sizeof(temp), 1, data_baru);

            fclose(cari_user);
            fclose(data_baru);

            if(remove("data_guest.dat") == 0){
                printf("Data berhasil dihapus!");
                system("pause");
            }
            rename("data_guest1.dat", "data_guest.dat");

            printf("Password berhasil diubah! Silahkan login kembali\n");
            login_guest(limit_login);
        
    }else{
        printf("Data tidak ditemukan!");
        system("pause");

        printf("Kembali ke menu utama (Y/N) : "); char ans; scanf("%c", &ans); getchar();

        if(ans == 'Y' || ans == 'y'){
            ke_menu_utama(role);
        }else if(ans == 'N' || ans == 'n'){
            ubah_password(role);
        }
    }
}

void hapus_acc(int role){
    system("cls");
    struct user check;
    FILE *baca_akun;
    FILE *akun_baru;

    baca_akun = fopen("data_guest.dat", "rb");
    akun_baru = fopen("data_guest1.dat", "wb");

    char username[300];
    printf("Silahkan masukkan username yang akan dihapus : "); gets(username);
  
    while(fread(&check, sizeof(check), 1, baca_akun) == 1){
        if(strcmp(check.username, username) != 0){
            fwrite(&check, sizeof(check), 1, akun_baru);
        }
    }
    fclose(akun_baru);
    fclose(baca_akun);

    remove("data_guest.dat");
    rename("data_guest1.dat", "data_guest.dat");

    printf("Akun berhasil dihapus!");
    //system("pause");
    users();
}


void lihat_acc(int role){
    system("cls");
    struct peminjam pinjam;
    printf("Masukkan username anda : "); char username[300]; gets(username); fflush(stdin);
    char temp[300];

    strcpy(temp, username);
    strcat(temp, ".dat");

    system("pause");
    system("cls");

    printf("Informasi Akun\n");
    FILE *buka_data;
    buka_data = fopen(temp, "rb");

    if(buka_data == NULL){
        printf("Data yang dicari tidak ada!\n");
    }

    printf("Berikut adalah data untuk username : %s\n", username);
    while(fread(&pinjam, sizeof(pinjam), 1, buka_data) == 1){
        printf("Berikut adalah data untuk username : %s\n", username);
        printf("Buku yang pernah dipinjam          : %s\n", pinjam.judul);
        printf("Tanggal peminjaman buku            : %s\n", pinjam.tanggal_pinjam);
        printf("Denda yang diberikan               : %d\n", pinjam.denda);
    }
    fclose(buka_data);
    system("pause");
    printf("<< Kembali\n");
    system("pause");
    ke_menu_utama(role);
}

void tambah_buku(int role){
    system("cls");
    FILE *data_buku;
    struct buku add_buku;
    //struct buku temp_buku[MAX];
    struct buku cek_buku;

    printf("Menu Menambahkan Buku Beserta Informasinya\n");
    data_buku = fopen("data_buku.dat", "ab");
    printf("Masukkan judul buku    : "); 
    gets(add_buku.judul);
    
    printf("Masukkan jenis buku :\n1. Fiksi\n2. Non-Fiksi\nSilahkan pilih : ");
    int pilih;
    scanf("%d", &pilih);
    getchar();
    printf("\n");

if (pilih == 1) {
    strcpy(add_buku.jenis, "Fiksi");
    printf("Masukkan genre buku     :\n1. Komik\n2. Novel\nSilahkan pilih : ");
    scanf("%d", &pilih);
    getchar();
    printf("\n");

    if (pilih == 1) {
        strcpy(add_buku.genre, "Komik");
        printf("Masukkan subgenre buku  :\n1. Manga\n2. Action\nSilahkan pilih : ");
        scanf("%d", &pilih);
        getchar();
        printf("\n");

        if (pilih == 1) {
            strcpy(add_buku.subgenre, "Manga");
        } else if (pilih == 2) {
            strcpy(add_buku.subgenre, "Action");
        }
    } else if (pilih == 2) {
        strcpy(add_buku.genre, "Novel");
        printf("Masukkan subgenre buku  :\n1. Fantasi\n2. Romance\nSilahkan pilih : ");
        scanf("%d", &pilih);
        getchar();
        printf("\n");

        if (pilih == 1) {
            strcpy(add_buku.subgenre, "Fantasi");
        } else if (pilih == 2) {
            strcpy(add_buku.subgenre, "Romance");
        }
    }
} else if (pilih == 2) {
    strcpy(add_buku.jenis, "Non-Fiksi");
    printf("Masukkan genre buku     :\n1. Buku pelajaran\n2. Ensiklopedia\nSilahkan pilih : ");
    scanf("%d", &pilih);
    getchar();
    printf("\n");

    if (pilih == 1) {
        strcpy(add_buku.genre, "Buku pelajaran");
        printf("Masukkan subgenre buku  :\n1. IPA\n2. IPS\nSilahkan pilih : ");
        scanf("%d", &pilih);
        getchar();
        printf("\n");

        if (pilih == 1) {
            strcpy(add_buku.subgenre, "IPA");
        } else if (pilih == 2) {
            strcpy(add_buku.subgenre, "IPS");
        }
    } else if (pilih == 2) {
        strcpy(add_buku.genre, "Ensiklopedia");
        printf("Masukkan subgenre buku  :\n1. Ensiklopedia Indonesia\n2. Ensiklopedia dunia\nSilahkan pilih : ");
        scanf("%d", &pilih);
        getchar();
        printf("\n");

        if (pilih == 1) {
            strcpy(add_buku.subgenre, "Ensiklopedia Indonesia");
        } else if (pilih == 2) {
            strcpy(add_buku.subgenre, "Ensiklopedia dunia");
        }
    }
}

    printf("Masukkan banyak buku     : "); scanf("%d", &add_buku.stok); getchar();
    fwrite(&add_buku, sizeof(add_buku), 1, data_buku);
    fclose(data_buku);

    //PROSES HITUNG BUKU DIMULAI DARI SINI
    data_buku = fopen("data_buku.dat", "rb");
    int end = 0;
    while(fread(&cek_buku, sizeof(cek_buku), 1, data_buku) != 0){
        sortir_buku[end] = cek_buku;
        end++;
    }
    fclose(data_buku);

    //PROSES SORTIR BUKU DIMULAI DARI SINI
    for(int a = 0; a < end; a++){
        for(int b = 0; b < end-1; b++){
            if(strcmp(sortir_buku[b].judul, sortir_buku[b+1].judul) > 0){
                swap_buku(&sortir_buku[b], &sortir_buku[b+1]);
            }
        }
    }

    data_buku = fopen("data_buku.dat", "wb");
    int flag;
    for(int a = 0; a < end; a++){
        fwrite(&sortir_buku[a], sizeof(sortir_buku[a]), 1, data_buku);
    }
    fclose(data_buku);
    
    printf("<< Kembali\n");
    system("pause");
    ke_menu_utama(role);
}

void hapus_buku(int role){
    system("cls");
    FILE *data_buku;
    FILE *data_buku_baru;

    struct buku del_buku;
    
    char buku_dihapus[300];
    printf("Masukkan judul buku yang ingin dihapus : "); gets(buku_dihapus);

    data_buku = fopen("data_buku.dat", "rb");
    data_buku_baru = fopen("data_buku1.dat", "wb");

    while(fread(&del_buku, sizeof(del_buku), 1, data_buku) == 1){
        if(strcmp(buku_dihapus, del_buku.judul) != 0){
            fwrite(&del_buku, sizeof(del_buku), 1, data_buku_baru);
        }
    }

    fclose(data_buku);
    fclose(data_buku_baru);

    remove("data_buku.dat");
    rename("data_buku1.dat", "data_buku.dat");

    printf("Buku berhasil dihapus!\n");
    printf("<< Kembali");
    system("pause");
    ke_menu_utama(role);
}

void lihat_buku(int role){
    system("cls");
    struct buku cek_buku;
    struct buku simpan_temp;
    struct buku list[300];
    
    FILE *data_buku;

    if(role == 1){
        printf("Menu mencari buku\n");
        printf("Jenis buku tersedia :\n1. Fiksi\n2. Non-Fiksi\nSilahkan pilih : "); int pilih; scanf("%d", &pilih); getchar();
    
        if(pilih == 1){
            strcpy(simpan_temp.jenis, "Fiksi");
            printf("Genre buku tersedia :\n1. Komik\n2. Novel\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
                if(pilih == 1){
                    strcpy(simpan_temp.genre, "Komik");
                    printf("Subgenre buku tersedia :\n1. Manga\n2. Action\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
                        if(pilih == 1){
                            strcpy(simpan_temp.subgenre, "Manga");
                        }else if(pilih == 2){
                            strcpy(simpan_temp.subgenre, "Action");
                        }
                }else if(pilih == 2){
                    strcpy(simpan_temp.genre, "Novel"); 
                    printf("Subgenre buku tersedia :\n1. Fantasi\n2. Romance\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
                        if(pilih == 1){
                            strcpy(simpan_temp.subgenre, "Fantasi");
                        }else if(pilih == 2){
                            strcpy(simpan_temp.subgenre, "Romance");
                        }
                }
        }else if(pilih == 2){
            strcpy(simpan_temp.jenis, "Non-Fiksi");
            printf("Genre buku tersedia :\n1. Buku pelajaran\n2. Ensiklopedia\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
            if(pilih == 1){
                strcpy(simpan_temp.genre, "Buku pelajaran");
                printf("Subgenre buku tersedia :\n1. IPA\n2. IPS\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
                if(pilih == 1){
                    strcpy(simpan_temp.subgenre, "IPA");
                }else if(pilih == 2){
                    strcpy(simpan_temp.subgenre, "IPS");
                }
            }else if(pilih == 2){
                strcpy(simpan_temp.genre, "Ensiklopedia");
                printf("Subgenre buku tersedia :\n1. Ensiklopedia Indonesia\n2. Ensiklopedia dunia\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
                
                if(pilih == 1){
                    strcpy(simpan_temp.subgenre, "Ensiklopedia Indonesia");
                }else if(pilih == 2){
                    strcpy(simpan_temp.subgenre, "Ensiklopedia dunia");
                }
            }
        }


    int count = 0;
    data_buku = fopen("data_buku.dat", "rb");
    system("cls");
    printf("Data buku yang sesuai dengan pencarian\n");
    printf("Pencarian disortir berdasarkan %s >> %s >> %s\n",simpan_temp.jenis, simpan_temp.genre, simpan_temp.subgenre);
    while(fread(&cek_buku, sizeof(cek_buku), 1, data_buku) == 1){
        if((strcmp(simpan_temp.jenis, cek_buku.jenis) == 0) && (strcmp(simpan_temp.genre, cek_buku.genre) == 0) && (strcmp(simpan_temp.subgenre, cek_buku.subgenre) == 0)){
            
            printf("Buku ke-%d\n", count+1);
            printf("Judul buku    : %s\n", cek_buku.judul);
            printf("Jenis buku    : %s\n", cek_buku.jenis);
            printf("Genre buku    : %s\n", cek_buku.genre);
            printf("Subgenre buku : %s\n", cek_buku.subgenre);
            printf("Stok buku     : %d\n", cek_buku.stok);
            printf("\n");
            count++;
        }
    }

    printf("<< Kembali\n");
    system("pause");
    ke_menu_utama(role);
    }else if(role == 2){
        printf("Menu mencari buku\n");
        printf("Jenis buku tersedia :\n1. Fiksi\n2. Non-Fiksi\nSilahkan pilih : "); int pilih; scanf("%d", &pilih); getchar();
    
        if(pilih == 1){
            strcpy(simpan_temp.jenis, "Fiksi");
        }else if(pilih == 2){
            strcpy(simpan_temp.jenis, "Non-Fiksi");
        }

    printf("Genre buku tersedia :\n1. Komik\n2. Novel\n3. Buku pelajaran\n4. Ensiklopedia\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
    if(pilih == 1){
        strcpy(simpan_temp.genre, "Komik");
    }else if(pilih == 2){
        strcpy(simpan_temp.genre, "Novel");
    }if(pilih == 3){
        strcpy(simpan_temp.genre, "Buku pelajaran");
    }else if(pilih == 4){
        strcpy(simpan_temp.genre, "Ensiklopedia");
    }

    printf("Subgenre buku tersedia :\n1. Manga\n2. Action\n3. Fantasi\n4. Romance\n5. IPA\n6. IPS\n7. Ensiklopedia Indonesia\n8. Ensiklopedia dunia\nSilahkan pilih : "); scanf("%d", &pilih); getchar();
    if(pilih == 1){
        strcpy(simpan_temp.subgenre, "Manga");
    }else if(pilih == 2){
        strcpy(simpan_temp.subgenre, "Action");
    }if(pilih == 3){
        strcpy(simpan_temp.subgenre, "Fantasi");
    }else if(pilih == 4){
        strcpy(simpan_temp.subgenre, "Romance");
    }else if(pilih == 5){
        strcpy(simpan_temp.subgenre, "IPA");
    }else if(pilih == 6){
        strcpy(simpan_temp.subgenre, "IPS");
    }if(pilih == 7){
        strcpy(simpan_temp.subgenre, "Ensiklopedia Indonesia");
    }else if(pilih == 8){
        strcpy(simpan_temp.subgenre, "Ensiklopedia dunia");
    }

    int count = 0;
    data_buku = fopen("data_buku.dat", "rb");
    system("cls");
    printf("Data buku yang sesuai dengan pencarian\n");
    printf("Pencarian disortir berdasarkan %s >> %s >> %s\n",simpan_temp.jenis, simpan_temp.genre, simpan_temp.subgenre);
    while(fread(&cek_buku, sizeof(cek_buku), 1, data_buku) == 1){
        if((strcmp(simpan_temp.jenis, cek_buku.jenis) == 0) && (strcmp(simpan_temp.genre, cek_buku.genre) == 0) && (strcmp(simpan_temp.subgenre, cek_buku.subgenre) == 0) && cek_buku.stok > 0){
            
            printf("Buku ke %d\n", count+1);
            printf("Judul buku    : %s\n", cek_buku.judul);
            printf("Jenis buku    : %s\n", cek_buku.jenis);
            printf("Genre buku    : %s\n", cek_buku.genre);
            printf("Subgenre buku : %s\n", cek_buku.subgenre);
            printf("Stok buku     : %d\n", cek_buku.stok);
            printf("\n");
            count++;
        }
    }

    printf("<< Kembali\n");
    system("pause");
    ke_menu_utama(role);
    }
}

void tambah_lihat_peminjam(int role) {
    system("cls");
    struct peminjam pinjam;
    struct buku info_buku;

    FILE *data_peminjam;
    FILE *database_utama;
    FILE *data_buku;

    int user_ada;

    if (role == 1) {
        //MELIHAT DATA PEMINJAM BUKU
        data_peminjam = fopen("data_peminjam.dat", "rb");

        while (fread(&pinjam, sizeof(pinjam), 1, data_peminjam) == 1) {
            printf("Data peminjam dan Buku yang Dipinjam\n");
            printf("Username             : %s\n", pinjam.username);
            printf("Judul buku           : %s\n", pinjam.judul);
            printf("Tanggal pinjam       : %s\n", pinjam.tanggal_pinjam);
            printf("Denda yang diberikan : %d\n", pinjam.denda);
            printf("\n");
        }

            fclose(data_peminjam);
            system("pause");
            printf("<< Kembali\n");
            system("pause");
            ke_menu_utama(role);
            
    } 
    else if (role == 2) {
        struct buku info_buku;
        struct user check;
        struct peminjam pinjam;

        FILE *data_buku;
        FILE *data_user;
        FILE *simpan_data_peminjam;

        char username[300];
        char judul_buku[300];

        int user_ada;
        int buku_ada;

        //CEK APAKAH USER SUDAH MENDAFTAR
        printf("Masukkan username : "); gets(username);
        data_user = fopen("data_guest.dat", "rb");
        while(fread(&check, sizeof(check), 1, data_user) == 1){
            if(strcmp(username, check.username) == 0){
                user_ada = 1;
                break;
            }else{
                user_ada = 0;
            }
        }
        fclose(data_user);

        //SETELAH DATANYA DI CEK, CEK APAKAH BUKU SUDAH ADA DALAM DATABASE
        if(user_ada){
            printf("Masukkan judul buku : "); gets(judul_buku);

            //CEK APAKAH BUKU SUDAH TERDAFTAR DALAM DATABASE
            data_buku = fopen("data_buku.dat", "rb");
            if(data_buku == NULL){
                printf("Database buku tidak ada!");
            }

            while(fread(&info_buku, sizeof(info_buku), 1, data_buku) == 1){
                if(strcmp(info_buku.judul, judul_buku) == 0){
                    buku_ada = 1;
                    break;
                }else{
                    buku_ada = 0;
                }
            }
            fclose(data_buku);
        }else{
            printf("User yang dicari tidak ada!\n");
        }

        //SETELAH BUKU ADA, PROSES PEMINJAMAN BUKU DIMULAI
        if(buku_ada == 1){
            struct buku temp;
            char tempFile[300];
            strcpy(tempFile, username);
            strcat(tempFile, ".dat");

            FILE *buka_data_user;
            FILE *database_utama;
            FILE *temp_buku;

            buka_data_user = fopen(tempFile, "ab");
            database_utama = fopen("data_peminjam.dat", "ab");

            strcpy(pinjam.username, username);
            strcpy(pinjam.judul, judul_buku);
            printf("Tanggal peminjaman : "); gets(pinjam.tanggal_pinjam);
            pinjam.denda = 0;

            fwrite(&pinjam, sizeof(pinjam), 1, buka_data_user);
            fwrite(&pinjam, sizeof(pinjam), 1, database_utama);
    
            fclose(buka_data_user);
            fclose(database_utama);

            //PERBARUI DATA PERSEDIAAN BUKU
            temp_buku = fopen("data_buku.dat", "rb");
            database_utama = fopen("data_buku1.dat", "wb");

            while(fread(&info_buku, sizeof(info_buku), 1, temp_buku) == 1){
                if(strcmp(info_buku.judul, judul_buku) != 0){
                    fwrite(&info_buku, sizeof(info_buku), 1, database_utama);
                }
            }

            strcpy(temp.judul, info_buku.judul);
            strcpy(temp.jenis, info_buku.jenis);
            strcpy(temp.genre, info_buku.genre);
            strcpy(temp.subgenre, info_buku.subgenre);
            temp.stok = info_buku.stok-1;
            fwrite(&temp, sizeof(temp), 1, database_utama);

            fclose(temp_buku);
            fclose(database_utama);

        remove("data_buku.dat");
        rename("data_buku1.dat", "data_buku.dat");

        }else{
            printf("Buku yang dicari tidak ada!\n");
        }
        
        printf("<< Kembali\n");
        system("pause");
        ke_menu_utama(role);
    }
}


void lihat_tulis_feedback(int role){
    system("cls");
    struct masukan fb;
    printf("Menu Feedback\n");
    if(role == 1){
        FILE *baca_feedback;
        baca_feedback = fopen("file_feedback.dat", "rb");

        if(baca_feedback == NULL){
            printf("Tidak ada feedback untuk saat ini ya! Yay!!! :D\n");
        }else{
            printf("Silahkan baca feedbacknya yaa!\n");
            while(fread(&fb, sizeof(fb), 1, baca_feedback) == 1){
                printf("Feedback dari : %s\n", fb.username);
                printf("Isi feedback  : %s\n", fb.isi_feedback);
            }
        fclose(baca_feedback);
        }
    }else if(role == 2){
        FILE *baca_feedback;
        baca_feedback = fopen("file_feedback.dat", "ab");

        printf("Silahkan tulis feedbacknya!\n");
        printf("Masukkan username        : "); gets(fb.username);
        printf("Isi feedback untuk kami  : "); gets(fb.isi_feedback);
        fwrite(&fb, sizeof(fb), 1, baca_feedback);
        fclose(baca_feedback);

        printf("Feedback sudah terkirim! Terima kasih untuk feedbacknya!\n");
    }
    printf("<< Kembali\n");
    system("pause");
    ke_menu_utama(role);
}

void kembalikan_buku(int role){
    system("cls");
    struct buku info_buku;
    struct buku temp;
    FILE *temp_buku;
    FILE *update_buku;
    
    char judul_buku[300];
    int success, buku_ada;

    temp_buku = fopen("data_buku.dat", "rb");
    update_buku = fopen("data_buku1.dat", "wb");
    printf("Masukkan judul buku disini : "); gets(judul_buku);
    while(fread(&info_buku, sizeof(info_buku), 1, update_buku) == 1){
        if(strcmp(info_buku.judul, judul_buku) != 0){
            fwrite(&info_buku, sizeof(info_buku), 1, update_buku);
        }
    }

    strcpy(temp.judul, info_buku.judul);
    strcpy(temp.jenis, info_buku.jenis);
    strcpy(temp.genre, info_buku.genre);
    strcpy(temp.subgenre, info_buku.subgenre);
    temp.stok = info_buku.stok+1;
    fwrite(&temp, sizeof(temp), 1, update_buku);

    fclose(temp_buku);
    fclose(update_buku);

    remove("data_buku.dat");
    rename("data_buku.dat1", "data_buku.dat");

    
    if(success){
        printf("Buku berhasil dikembalikan!\n");
    }

    printf("<< Kembali\n");
    system("pause");
    ke_menu_utama(role);
}

void lihat_tambah_denda(int role){
    system("cls");
    struct peminjam pinjam;
    int temp = role;

    printf("Menu denda\n");
    if(temp == 1){
        printf("Masukkan username : "); char username[300]; gets(username);
        char temp[300];

        strcpy(temp, username);
        strcat(temp, ".dat");

        FILE *buka_data_user;
        buka_data_user = fopen(temp, "r+b");

        long int tempDenda;
        
        printf("Masukkan denda untuk user : "); scanf("%d", &tempDenda);
        pinjam.denda = pinjam.denda + tempDenda;
        fseek(buka_data_user, -sizeof(pinjam), SEEK_CUR);
        
        if(fwrite(&pinjam, sizeof(pinjam), 1, buka_data_user) != 0){
            printf("Nilai denda berhasil ditambah!\n");
        }
        fclose(buka_data_user);

        printf("<< Kembali\nTekan untuk melanjutkan\n");
        system("pause");
        ke_menu_utama(role);
    }else if(temp == 2){
        printf("Masukkan username : "); char username[300]; gets(username);
        char temp[300];

        strcpy(temp, username);
        strcat(temp, ".dat");

        FILE *buka_data_user;
        buka_data_user = fopen(temp, "rb");

        while(fread(&pinjam, sizeof(pinjam), 1, buka_data_user) == 1){
            printf("Denda untuk buku          : %s\n", pinjam.judul);
            printf("Tanggal peminjaman        : %s\n", pinjam.tanggal_pinjam);
            printf("Denda yang diberikan user : %d\n", pinjam.denda); 
            printf("\n");
        }

        fclose(buka_data_user);
        printf("<< Kembali\nTekan untuk melanjutkan\n");
        system("pause");
        ke_menu_utama(role);
    }
}

void swap_buku(struct buku *p, struct buku *q){
    struct buku temp;
    temp = *p;
    *p   = *q;
    *q   = temp;
}

void ke_menu_utama(int role){
    if(role == 1){
        menu_lib();
    }else if(role == 2){
        menu_guest();
    }
}

