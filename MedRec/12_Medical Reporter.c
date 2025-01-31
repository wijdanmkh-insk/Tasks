#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//STRUCT DATA
typedef struct tanggal{
    int hari;
    int bulan;
    int tahun;
}tgl;

typedef struct obat{
    char nama[100];
    int qtc;
    int dosis[2];
}obat;

typedef struct data{
    //INFORMASI DASAR PASIEN
    char nickname[50];
    char fullname[200];
    char username[100];
    char password[200];
    char nik[38];
    char ttl[11];

    //INFO KESEHATAN PASIEN
    int berat_badan;
    int tinggi_badan;
    char gejala[20][100];
    char alergi[20][100];
    char diagnosis[20][100];
    int freq_diagnosis[20];
    obat obat[20];
    char pesan[200];
}data;

typedef struct info_karyawan{
    char fullname[200];
    char nickname[50];
    char username[50];
    char nik[38];
    char password[100];
    char role[20];
}info_karyawan;

typedef struct alamat{
    char jalan[400];
    char kec[100];
    char kota_kab[100];
}alamat;

typedef struct rs{
    char nama_rs[200];
    alamat alamat;
    char no_telp[20];
    char email[100];
}rs;

//VARIABEL GLOBAL
char roles[2][20] = {"dokter", "rekam medis"};
char username[200];
int limit = 3;

//FUNGSI DOKTER
void login_dokter(int limit);
void menu_dokter();
void saran_dokter();
void baca_pasien();
void surat_rujukan();

//FUNGSI REKAM MEDIS
void login_rekmed(int limit);
void menu_rekmed();
void reg_pasien();
void input_pasien();
void cls();

//FUNGSI PASIEN
void menu_pasien();
void login_pasien(int limit);
void beli_obat();
void info();
void rs_terdekat();

//FUNGSI ADMIN
void login_admin();
void menu_admin();
void informasi_rs();
void registrasi_karyawan();
void rs_mitra();
void decrypt(info_karyawan* data, int key);

//FUNGSI GLOBAL
void menu_utama(){
    int pilih; 
    do{
        printf("Selamat datang! Anda akan login sebagai : ");
        printf("1. Admin\n2. Dokter\n3. Rekam medis\n4. Pasien\n5. Keluar\nPilih : ");
        scanf("%d", &pilih); getchar();

        switch(pilih){
            case 1 :
            login_admin();
            break;
            case 2 : 
            login_dokter(limit);
            break;
            case 3 : 
            login_rekmed(limit);
            break;
            case 4 :
            login_pasien(limit);
            case 5 :
            exit(0);
        }
    }while(pilih > 5 || pilih < 0);
}

//DEKLARASIKAN FUNGSI ADMIN DISINI
void login_admin(){
    info_karyawan admin;
    info_karyawan check;
    FILE *cek_admin;
    bool data_ada;

    printf("Username : "); fgets(admin.username, sizeof(admin.username), stdin);
    printf("Password : "); fgets(admin.password, sizeof(admin.password), stdin);

    cek_admin = fopen("admin.dat", "rb");
    while(fread(&check, sizeof(check), 1, cek_admin) != 0){
        decrypt(&check, 5);
        if(strcmp(admin.username, check.username) == 0 && strcmp(admin.password, check.password) == 0){
            data_ada = true;
            break;
        }else{
            data_ada = false;
            printf("Username atau password salah!\n");
        }
    }
    fclose(cek_admin);

    if(data_ada){
        menu_admin();
    }else{
        printf("Data tidak ada!");
    }

}

void decrypt(info_karyawan* data, int key) {
    int i;

    for(i = 0; data->username[i] != '\0'; ++i) {
        char ch = data->username[i];
        ch = (ch - key + 128) % 128;
        data->username[i] = ch;
    }

    for(i = 0; data->password[i] != '\0'; ++i) {
        char ch = data->password[i];
        ch = (ch - key + 128) % 128;
        data->password[i] = ch;
    }
}

void menu_admin(){
    printf("Menu tersedia : \n");
    int pilih;

    switch(pilih){
        do{
            printf("1. Registrasi karyawan\n2. Informasi RS\nPilih");
            scanf("%d", &pilih); getchar();
            
            case 1:
            registrasi_karyawan();
            break;
            case 2 :
            informasi_rs();
            break;
            case 3 :
            rs_mitra();
            default :
            printf("Pilihan salah! Coba lagi!\n");
            break;
        }while(pilih > 2 || pilih < 0);
    }
}

void registrasi_karyawan(){
    info_karyawan new;
    FILE *karyawan;

    int pilih; 
    do{
        printf("pilih role :\n1. Dokter\n2. Rekam medis\nPilih : ");
        scanf("%d", &pilih); getchar();

        switch (pilih)
        {
        case 1:
            strcpy(new.role, roles[0]);
            break;
        case 2 :
            strcpy(new.role, roles[1]);
            break;
        default:
            printf("Pilihan salah!");
            break;
        }
    }while(pilih > 2 || pilih < 0);

    karyawan = fopen("karyawan.dat", "ab");
    printf("Menu registrasi karyawan\n");
    printf("Masukkan nama lengkap  : "); fgets(new.fullname, sizeof(new.fullname), stdin);
    printf("Masukkan nickname      : "); fgets(new.nickname, sizeof(new.nickname), stdin);
    printf("Masukkan username      : "); fgets(new.username, sizeof(new.username), stdin);
    printf("Masukkan password      : "); fgets(new.password, sizeof(new.password), stdin);
    printf("Masukkan NIK           : "); fgets(new.nik, sizeof(new.nik), stdin);

    if(fwrite(&new, sizeof(new), 1, karyawan) != 0){
        fclose(karyawan);
        printf("Data berhasil tercatat! Tekan tombol apa saja untuk melanjutkan."); getchar();
        menu_admin();
    }
}

void informasi_rs(){
    FILE *info_rs_utama;
    
    info_rs_utama = fopen("info_rs_utama.dat", "ab");

    rs rs;
    printf("Informasi RS\n");
    printf("Nama RS  : "); gets(rs.nama_rs);
    printf("Alamat   :\nJalan : "); gets(rs.alamat.jalan);
    printf("Kecamatan : "); gets(rs.alamat.kec); printf("Kabupaten : "); gets(rs.alamat.kota_kab);
    printf("No telp  : "); gets(rs.no_telp);
    printf("Email    : "); gets(rs.email);

    if(fwrite(&rs, sizeof(&rs), 1, info_rs_utama) != 0){
        fclose(info_rs_utama);
        printf("Data RS utama berhasil disimpan!\nTekan tombol apapun untuk melanjutkan\n"); getchar();
        menu_admin();
    }
}

void rs_mitra(){
    FILE *info_rs_mitra;
    
    info_rs_mitra = fopen("info_rs_mitra.dat", "ab");

    rs rs;
    printf("Informasi RS\n");
    printf("Nama RS  : "); gets(rs.nama_rs);
    printf("Alamat   :\nJalan : "); gets(rs.alamat.jalan);
    printf("Kecamatan : "); gets(rs.alamat.kec); printf("Kabupaten : "); gets(rs.alamat.kota_kab);
    printf("No telp  : "); gets(rs.no_telp);
    printf("Email    : "); gets(rs.email);

    if(fwrite(&rs, sizeof(&rs), 1, info_rs_mitra) != 0){
        fclose(info_rs_mitra);
        printf("Data RS utama berhasil disimpan!\nTekan tombol apapun untuk melanjutkan\n"); getchar();
        menu_admin();
    }
}

//DEKLARASIKAN FUNGSI DOKTER DISINI
void login_dokter(int limit){
    info_karyawan dokter_input;
    info_karyawan dokter_check;

    bool dokter_ada;
    bool ganti = false;
    
    printf("Masukkan username : "); gets(dokter_input.username);
    printf("Masukkan password : "); gets(dokter_input.password);

    FILE *karyawan;
    karyawan = fopen("karyawan.dat", "rb");

    while(fread(&dokter_check, sizeof(dokter_check), 1, karyawan) != 0){
        if(strcmp(dokter_check.username, dokter_input.username) == 0 && strcmp(dokter_check.password, dokter_input.password) == 0){
            dokter_ada = true;
            break;
        }else if(strcmp(dokter_check.username, dokter_input.username) == 0 ){
            ganti = true;
            dokter_ada = false;
            break;
        }else{
            dokter_ada = false;
        }
    }
    fclose(karyawan);

    if(dokter_ada == true && ganti == false){
        menu_dokter();
    }else if(dokter_ada == false && ganti == true){
        printf("Masukkan NIK : "); gets(dokter_input.nik);
        FILE *karyawan;
        karyawan = fopen("karyawan.dat", "rb");

        while(fread(&dokter_check, sizeof(dokter_check), 1, karyawan) != 0){
            if(strcmp(dokter_check.nik, dokter_input.nik) == 0){
                menu_dokter();
            }else{
                printf("Data tidak ada! Tekan tombol apa saja untuk melanjutkan ke menu utama.");
                getchar();
                menu_utama();
            }
        }
    }
}


void menu_dokter(){
    int pilihan;
    printf("1. Baca rekam medis pasien\n");
    printf("2. Tambahkan saran\n");
    printf("3. Tambahkan surat rujukan\n");
    printf("Pilih aksi yang ingin dilakukan: ");
    scanf("%d", &pilihan);

   
    switch (pilihan) {
        case 1:
            baca_pasien();
            break;
        case 2:
            saran_dokter();
            break;
        case 3:
            printf("pasien lebih baik dirujuk dari ke rumah saki \n");
                    
            break;
            default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}

void saran_dokter(){
    FILE *data_pasien;
    data_pasien = fopen("data_pasien.dat", "rb");

    data pasien;
    char fullname[200];
    bool data_ada;

    char file_pasien[200];

    printf("Masukkan nama lengkap pasien : "); gets(fullname);

    while(fread(&pasien, sizeof(&pasien), 1, data_pasien) > 0){
        if(strcmp(pasien.fullname, fullname) == 0){
            strcpy(file_pasien, pasien.username);
            data_ada = true;
        }
    }
    fclose(data_pasien);

    strcat(file_pasien, ".dat");
    data_pasien = fopen(file_pasien, "ab");

    printf("Tulis pesan untuk pasien : ");
    gets(pasien.pesan);

    if(fwrite(&pasien, sizeof(pasien), 1, data_pasien) > 0){
        printf("Pesan terkirim!");
    }
}


void baca_pasien(){
    FILE *data_pasien;
    data_pasien = fopen("data_pasien.dat", "rb");

    data pasien;
    char file_pasien[200];
    char fullname[200];

    bool data_ada;

    printf("Masukkan nama lengkap pasien : "); gets(fullname);

    while(fread(&pasien, sizeof(pasien), 1, data_pasien) == 1){
        if(strcmp(fullname, pasien.fullname) == 0){
            strcpy(file_pasien, pasien.username);
            strcat(file_pasien, ".dat");
            data_ada = true;
            break;
        }else{
            data_ada = false;
        }
    }
    fclose(data_pasien);

    if(data_ada == true){
            data_pasien = fopen(file_pasien, "rb");
            printf("================== INFORMASI PASIEN =======================\n");
            printf("Nama Lengkap   : %s\n", pasien.fullname);
            printf("Nama Panggilan : %s\n", pasien.nickname);
            printf("Berat badan    : %d\n", pasien.berat_badan);
            printf("Tinggi badan   : %d\n", pasien.tinggi_badan);
            printf("Gejala :\n");

            for(int a=0; a < 20; a++){
                if(strlen(pasien.gejala[a]) > 0){
                    printf("%d. %s\n", a+1, pasien.gejala[a]);
                }
            }

            printf("Diagnosis :\n");
            printf("%s\nfrekuensi sakit : %d\n", pasien.diagnosis, pasien.freq_diagnosis);


            printf("Obat :\n");
            printf("| no |\tnama obat\t |\tqtc\t|\tdosis  \n");
            for(int a=0; a < 20; a++){
                if(strlen(pasien.obat->nama) > 0){
                    printf("| %d | \t%s\t\t |\t%d\t|\t%d x %d\t |\n", a+1, pasien.obat->nama, pasien.obat->qtc, pasien.obat->dosis);
                }
            }
            fclose(data_pasien);
    }else{
        printf("Data tidak ada!\n");
    }
}

/*
void surat_rujukan(){

    printf("
        [Nama Klinik atau Rumah Sakit]
        [Alamat Klinik atau Rumah Sakit]
        [Nomor Telepon Klinik atau Rumah Sakit]
        [Email Klinik atau Rumah Sakit]

        Tanggal: [Tanggal Surat]

        SURAT RUJUKAN

        Kepada Yth:
        [Nama Dokter atau Fasilitas Medis yang Dirujuk]
        [Spesialisasi]
        [Alamat Fasilitas Medis yang Dirujuk]

        Dengan hormat,

        Bersama surat ini, kami bermaksud merujuk pasien kami:

        Nama          : [Nama Lengkap Pasien]
        Jenis Kelamin : [Jenis Kelamin Pasien]
        Alamat        : [Alamat Pasien]

        untuk mendapatkan pemeriksaan lebih lanjut dan penanganan medis yang lebih spesifik terkait dengan kondisi kesehatan yang dialaminya. Berikut adalah ringkasan kondisi medis pasien dan hasil pemeriksaan yang telah dilakukan:

        [Deskripsi singkat kondisi pasien]
        [Hasil pemeriksaan, jika ada]
        [Diagnosis awal, jika ada]

        Kami telah melakukan pemeriksaan awal dan menilai bahwa kondisi pasien memerlukan penilaian lebih lanjut dari spesialis di bidang **[Spesialisasi yang Dirujuk]**. Kami berharap bahwa dengan keahlian dan fasilitas yang ada di **[Nama Fasilitas yang Dirujuk]**, kondisi pasien dapat ditangani dengan lebih optimal.

        Terlampir kami sertakan dokumen medis pasien yang relevan untuk membantu proses diagnosa dan pengobatan lebih lanjut. Kami berterima kasih atas perhatian dan kerja sama yang baik dari pihak **[Nama Fasilitas yang Dirujuk]** dalam penanganan kasus ini.

        Mohon untuk dapat memberikan informasi terkait hasil pemeriksaan dan rencana pengobatan yang akan dijalankan kepada kami, sehingga kami dapat terus memantau dan mendukung proses pemulihan pasien.

        Atas perhatian dan kerjasama yang baik, kami ucapkan terima kasih.

        Hormat kami,

        [Tanda Tangan]

        [Nama Lengkap Dokter Pengirim]
        [Spesialisasi Dokter Pengirim]
        [Nomor Registrasi Dokter]");
}
*/

//DEKLARASIKAN FUNGSI REKMED DISINI
void login_rekmed(int limit){
    data rekmed;

    //cls();
    printf("================== MENU LOGIN REKAM MEDIS ==================\n");
    printf("Masukkan username : "); //fgets(rekmed.username, sizeof(rekmed.username), stdin);
    gets(rekmed.username);
    printf("Masukkan password : "); //fgets(rekmed.password, sizeof(rekmed.password), stdin);
    gets(rekmed.password);

    if(strcmp(rekmed.username, "1") == 0 && strcmp(rekmed.password, "1") == 0){
        cls();
        menu_rekmed();
    }else{
        if(limit > 0){
            printf("Username atau password salah! Kesempatan login tersisa %d lagi\n", limit);
            login_rekmed(limit-1);
        }else{
            printf("Kesempatan login habis!\n");
        }
    }
}

void menu_rekmed(){
    int pilih;

    do{
        printf("======================= MENU REKAM MEDIS ========================\n");
        printf("1. Registrasi pasien\n2. Input data pasien\n3. Keluar akun\n4. Keluar aplikasi\nPilih : ");
        scanf("%d", &pilih); getchar();

        char ans;

        switch(pilih){
            case 1 : 
            reg_pasien();
            break;
            case 2 :
            input_pasien();
            break;
            case 3 :
                do{
                    printf("Apakah anda ingin keluar dari akun? (Y/N)");  scanf("%c", &ans);
                        if(ans == 'y' || ans == 'Y'){
                            login_rekmed(limit);
                        }else if(ans == 'n' || ans == 'N'){
                            menu_rekmed();
                        }else{
                            printf("Pilihan salah!");
                        }
                }while(ans == 'Y' || ans == 'y' || ans == 'N' || ans == 'n');
                break;
            default : 
            cls();
            printf("Pilihan salah! Coba lagi!");
        }
    }while(pilih < 1 || pilih > 4);
}

void reg_pasien(){
    cls();
    data input;
    char confirm_pass[200];

    printf("======================= INFORMASI UMUM PASIEN ========================\n");
    printf("Nama lengkap         : "); gets(input.fullname);
    printf("Nickname             : "); gets(input.nickname);
    printf("Tempat/tanggal lahir : "); gets(input.ttl);
    printf("NIK                  : "); gets(input.nik);

    printf("\n======================= INFORMASI LOGIN PASIEN ========================\n");
    printf("Masukkan username        : "); gets(input.username);
    
    bool pass_cocok = true;
    do{
        printf("Masukkan password        : "); gets(input.password);
        printf("Masukkan konfirmasi pass : "); gets(confirm_pass);

        if(strcmp(input.password, confirm_pass)!=0){
            cls();
            pass_cocok = false;

            printf("Konfirmasi password tidak cocok!");
            printf("Username   : %s", input.username);
            printf("Password   : "); gets(input.password);
            printf("Konfirmasi : "); gets(confirm_pass);
        }
    }while(pass_cocok == false);
    
    FILE *data_pasien;
    data_pasien = fopen("data_pasien.dat", "ab");
    if(fwrite(&input, sizeof(input), 1, data_pasien)>0){
        printf("Data berhasil tersimpan!\nTekan tombol apa saja untuk kembali ke menu utama\n"); getchar();
        cls();
        menu_rekmed();
    }else{
        printf("Data gagal tersimpan!\nSegera hubungi customer service untuk informasi lebih lanjut\n");
    }
    fclose(data_pasien);
    cls();
}

void input_pasien(){
    data input;
    char fullname[200];
    
    //CEK APAKAH DATA PASIEN SUDAH ADA DALAM REGISTRASI
    FILE *cek_data;
    cek_data = fopen("data_pasien.dat", "rb");

    while(fread(&input, sizeof(input), 1, cek_data) != 0){
        bool data_ada = true;
        bool stop = false;

        do{
            cls();
            printf("Masukkan nama pasien : "); gets(fullname);
            if(strcmp(fullname, input.fullname) == 0){
                
                if(fopen(input.fullname, "rb") == NULL){
                    FILE *input_pasien;

                    char file_pasien[200];
                    strcat(file_pasien, input.username);
                    strcat(file_pasien, ".dat");

                    input_pasien = fopen(file_pasien, "ab");

                    printf("======================= INFORMASI UMUM PASIEN ========================\n");
                    printf("Nama lengkap         : %s\n", input.fullname);
                    printf("Nickname             : %s\n", input.nickname); 
                    printf("Tempat/tanggal lahir : %s\n", input.ttl); 

                    printf("\n======================= INFORMASI MEDIS PASIEN ========================\n");
                        int max_gejala = 19;
                        bool stop_gejala = false;
                        int mulai = 0;

                        printf("Masukkan informasi berupa gejala atau keluhan. Untuk berhenti, ketik \'stop\'\n");
                        do{
                                printf("Gejala   : "); //fgets(input.gejala[max_gejala], sizeof(input.gejala), stdin);
                                gets(input.gejala[mulai]);

                                if(strcmp(input.gejala[mulai], "stop")== 0){
                                    stop_gejala = true;
                                }
                                mulai++;
                        }while (stop_gejala == false && mulai < max_gejala);

                        printf("Berat badan    : "); scanf("%d", &input.berat_badan); getchar();
                        printf("Tinggi badan   : "); scanf("%d", &input.tinggi_badan); getchar();

                        mulai = 0;
                        int max_diagnosis = 19;
                        bool stop_diagnosis = false;

                        printf("Masukkan informasi berupa diagnosis disini. Untuk berhenti, ketik \'stop\'\n");
                        do{
                            printf("Diagnosis    : "); //fgets(input.diagnosis[max_diagnosis], sizeof(input.diagnosis), stdin);
                            gets(input.diagnosis[mulai]);
                            input.freq_diagnosis[mulai] = 0;
                            input.freq_diagnosis[mulai]++;

                            if(strcmp(input.diagnosis[mulai], "stop") == 0){
                                stop_diagnosis = true;
                            }
                            mulai++;
                        }
                        while(mulai < max_diagnosis && stop_diagnosis == false);

                        /*
                        mulai = 0;
                        int max_obat = 20;*/
                        bool stop_obat = false;
                        char ans;

                        printf("Masukkan informasi berupa obat dan dosisnya. Untuk berhenti, ketik \'stop\'\n");
                        do{
                            printf("Nama obat   : "); 
                            fgets(input.obat->nama, sizeof(input.obat->nama), stdin);
                            input.obat->nama[strcspn(input.obat->nama, "\n")] = 0;  
                            if(strcmp(input.obat->nama, "stop") == 0){
                                stop_obat = true;
                            }else {
                                printf("Jumlah obat : "); 
                                scanf("%d", &input.obat->qtc); 
                                getchar();  
                                printf("Dosis obat  : "); 
                                scanf("%d %d", &input.obat->dosis[0], &input.obat->dosis[1]); 
                                getchar(); 
                            }
                        }while(stop_obat == false);

                    if(fwrite(&input, sizeof(input), 1, input_pasien) > 0){
                        fclose(input_pasien);
                        cls();
                        printf("Data pasien berhasil disimpan!\nTekan tombol apa saja untuk melanjutkan\n"); getchar();
                        menu_rekmed();
                    }
                }
            }else{
                data_ada = false;
                printf("Nama pasien tidak ditemukan. Mungkin nama pasien typo?\nKetik \'stop\' untuk berhenti\n");

                if(strcmp(fullname, "stop") == 0){
                    stop = true;
                }
            }
        }while(data_ada == false || stop == false);
    }
}


void cls(){
    system("cls");
}

//DEKLARASIKAN FUNGSI PASIEN DISINI
void login_pasien (int limit){
    data input;
    data check;
    bool data_ada;

    FILE *data_pasien;
    data_pasien = fopen("data_pasien.dat", "rb");

    printf("Masukkan username : "); fgets(input.username, sizeof(input.username), stdin);
    printf("Masukkan password : "); fgets(input.password, sizeof(input.password), stdin);

    while(fread(&check, sizeof(check), 1, data_pasien) != 0){
        if(strcmp(input.username, check.username) == 0 && strcmp(input.password, check.password) == 0 ){
            data_ada = true;
            strcpy(username, input.username);
            break;
        }else{
            data_ada = false;
        }
    }
    fclose(data_pasien);

    if(data_ada){
        menu_pasien();
    }else{
        printf("Username atau password salah. Kesempatan tersisa %d kali lagi\n");
    }
}

void menu_pasien(){
    int pilih;
    do{
        printf("Menu tersedia :\n");
        printf("1. Beli obat\n2. Lihat informasi kesehatan sekarang\n3. Lihat RS terdekat\nPilih : "); scanf("%d", &pilih);

        switch(pilih){
            case 1 :
            beli_obat();
            break;
            case 2 :
            info();
            break;
            case 3 :
            rs_terdekat();
            break;
            default :
            printf("Pilihan salah! coba lagi!\n");
            break;
        }
    }while(pilih > 2 || pilih < 0);
}


void beli_obat(){
    printf("Hello world");
}

void info(){
    FILE *cek_data;
    data pasien;
    data *buffer;
    long int besar;
    strcat(username,".dat");

    cek_data = fopen(username, "rb");

    fseek(cek_data, 0, SEEK_END);

    besar = ftell(cek_data);

    buffer = (buffer) malloc(besar+1);
    fseek(cek_data, 0, SEEK_SET);
    fread(buffer, besar, 1, cek_data);

    while(fread(&pasien, sizeof(pasien), 1, cek_data) != 0){
        printf("Diagnosis : %s", pasien.diagnosis);
        printf("Obat      : %s || Dosis : %d x %d", pasien.obat->nama, pasien.obat->dosis[0], pasien.obat->dosis[1]);
        printf("Pesan     : %s", pasien.pesan);

    }
}

void rs_terdekat(){
    rs cari; 
    rs input;
    bool dekat;

    printf("Masukkan kabupaten tempat tinggal anda : "); gets(input.alamat.kota_kab);
    printf("Masukkan kecamatan tempat tinggal anda : "); gets(input.alamat.kec);

    FILE *data_rs;
    data_rs = fopen("rs_mitra.dat", "rb");
    while(fread(&cari, sizeof(cari), 1, data_rs) > 0){
        if(strcmp(input.alamat.kota_kab, cari.alamat.kota_kab) == 0 && strcmp(input.alamat.kec, cari.alamat.kec) == 0){
            printf("Nama rumah sakit : %s\n", cari.nama_rs); 
            printf("Kecamatan        : %s\n", cari.alamat.kec);
            printf("Kabupaten        : %s\n", cari.alamat.kota_kab);
            printf("No telpon        : %s\n\n", cari.no_telp);
        }
    }
    printf("Tekan tombol apa saja untuk kembali ke menu utama.\n"); getchar();
    menu_pasien();
}

