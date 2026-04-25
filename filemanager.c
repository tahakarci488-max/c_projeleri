#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KISI 100
#define MAX_AD 50
#define MAX_SOYAD 50

typedef struct {
    int id;
    char ad[MAX_AD];
    char soyad[MAX_SOYAD];
    int yas;
    float maas;
} Kisi;

Kisi kisiler[MAX_KISI];
int kisi_sayisi = 0;
int son_id = 0;

void baslikGoster();
void menuGoster();
void kisiEkle();
void kisileriListele();
void kisiAra();
void kisiSil();
void istatistikGoster();
void cikis();

int main() {
    srand(time(NULL));

    printf("=====================================\n");
    printf("    KISILER VERITABANI SISTEMI      \n");
    printf("=====================================\n");

    int secim;

    do {
        baslikGoster();
        menuGoster();
        printf("Seciminizi yapin (0-6): ");
        scanf("%d", &secim);
        getchar(); // Buffer temizle

        switch(secim) {
            case 1: kisiEkle(); break;
            case 2: kisileriListele(); break;
            case 3: kisiAra(); break;
            case 4: kisiSil(); break;
            case 5: istatistikGoster(); break;
            case 6: cikis(); break;
            case 0: printf("Program sonlandiriliyor...\n"); break;
            default: printf("Gecersiz secim! Lutfen 0-6 arasinda bir sayi girin.\n");
        }

        if(secim != 0 && secim != 6) {
            printf("\nEnter'a basarak devam edin...");
            getchar();
        }

    } while(secim != 0);

    return 0;
}

void baslikGoster() {
    system("cls || clear"); // Windows/Linux uyumlu ekran temizleme
    printf("=====================================\n");
    printf("    KISILER VERITABANI SISTEMI      \n");
    printf("    Toplam Kisi: %d/%d\n", kisi_sayisi, MAX_KISI);
    printf("=====================================\n\n");
}

void menuGoster() {
    printf("1. Yeni Kisi Ekle\n");
    printf("2. Tum Kisileri Listele\n");
    printf("3. Kisi Ara (Ad/soyad)\n");
    printf("4. Kisi Sil\n");
    printf("5. Istatistikler\n");
    printf("6. Verileri Kaydet & Cikis\n");
    printf("0. Hemen Cikis\n");
}

void kisiEkle() {
    if(kisi_sayisi >= MAX_KISI) {
        printf("Kapasite dolu! Maksimum %d kisi saklanabilir.\n", MAX_KISI);
        return;
    }

    Kisi yeni;
    yeni.id = ++son_id;

    printf("=== YENI KISI EKLE ===\n");
    printf("Ad: ");
    fgets(yeni.ad, MAX_AD, stdin);
    yeni.ad[strcspn(yeni.ad, "\n")] = 0; // Newline karakterini sil

    printf("Soyad: ");
    fgets(yeni.soyad, MAX_SOYAD, stdin);
    yeni.soyad[strcspn(yeni.soyad, "\n")] = 0;

    printf("Yas: ");
    scanf("%d", &yeni.yas);
    getchar();

    printf("Maas: ");
    scanf("%f", &yeni.maas);
    getchar();

    kisiler[kisi_sayisi++] = yeni;
    printf("\n✅ Kisi basariyla eklendi! ID: %d\n", yeni.id);
}

void kisileriListele() {
    if(kisi_sayisi == 0) {
        printf("Henüz kisi eklenmemis!\n");
        return;
    }

    printf("\n%-5s %-15s %-15s %-5s %-10s\n", "ID", "AD", "SOYAD", "YAS", "MAAS(TL)");
    printf("----------------------------------------------------------------\n");

    for(int i = 0; i < kisi_sayisi; i++) {
        printf("%-5d %-15s %-15s %-5d %-10.2f\n",
               kisiler[i].id, kisiler[i].ad, kisiler[i].soyad,
               kisiler[i].yas, kisiler[i].maas);
    }
}

void kisiAra() {
    if(kisi_sayisi == 0) {
        printf("Henüz kisi eklenmemis!\n");
        return;
    }

    char ara[MAX_AD + MAX_SOYAD];
    printf("Aranacak isim/soyisim: ");
    fgets(ara, sizeof(ara), stdin);
    ara[strcspn(ara, "\n")] = 0;

    int bulundu = 0;
    printf("\nSonuclar:\n");
    printf("----------------------------------------------------------------\n");
    printf("%-5s %-15s %-15s %-5s %-10s\n", "ID", "AD", "SOYAD", "YAS", "MAAS(TL)");
    printf("----------------------------------------------------------------\n");

    for(int i = 0; i < kisi_sayisi; i++) {
        if(strstr(kisiler[i].ad, ara) || strstr(kisiler[i].soyad, ara)) {
            printf("%-5d %-15s %-15s %-5d %-10.2f\n",
                   kisiler[i].id, kisiler[i].ad, kisiler[i].soyad,
                   kisiler[i].yas, kisiler[i].maas);
            bulundu = 1;
        }
    }

    if(!bulundu) {
        printf("Arama sonucu bulunamadi!\n");
    }
}

void kisiSil() {
    if(kisi_sayisi == 0) {
        printf("Silinecek kisi yok!\n");
        return;
    }

    int id;
    printf("Silinecek kisinin ID'sini girin: ");
    scanf("%d", &id);
    getchar();

    for(int i = 0; i < kisi_sayisi; i++) {
        if(kisiler[i].id == id) {
            printf("'%s %s' siliniyor...\n", kisiler[i].ad, kisiler[i].soyad);

            // Soldaki elemanları kaydır
            for(int j = i; j < kisi_sayisi - 1; j++) {
                kisiler[j] = kisiler[j + 1];
            }
            kisi_sayisi--;
            printf("✅ Kisi basariyla silindi!\n");
            return;
        }
    }
    printf("❌ Bu ID'ye sahip kisi bulunamadi!\n");
}

void istatistikGoster() {
    if(kisi_sayisi == 0) {
        printf("Istatistik gosterilemez! Once kisi ekleyin.\n");
        return;
    }

    float toplam_maas = 0;
    int toplam_yas = 0;
    int max_yas = kisiler[0].yas;
    int min_yas = kisiler[0].yas;
    float max_maas = kisiler[0].maas;

    for(int i = 0; i < kisi_sayisi; i++) {
        toplam_maas += kisiler[i].maas;
        toplam_yas += kisiler[i].yas;

        if(kisiler[i].yas > max_yas) max_yas = kisiler[i].yas;
        if(kisiler[i].yas < min_yas) min_yas = kisiler[i].yas;
        if(kisiler[i].maas > max_maas) max_maas = kisiler[i].maas;
    }

    printf("\n=== ISTATISTIKLER ===\n");
    printf("Toplam Kisi Sayisi: %d\n", kisi_sayisi);
    printf("Ortalama Yas: %.1f\n", (float)toplam_yas / kisi_sayisi);
    printf("Ortalama Maas: %.2f TL\n", toplam_maas / kisi_sayisi);
    printf("Toplam Maas: %.2f TL\n", toplam_maas);
    printf("En Yuksek Yas: %d\n", max_yas);
    printf("En Dusuk Yas: %d\n", min_yas);
    printf("En Yuksek Maas: %.2f TL\n", max_maas);
}

void cikis() {
    printf("\n=== VERILER KAYDEDILIYOR ===\n");
    printf("Toplam %d kisi kaydedildi.\n", kisi_sayisi);
    printf("Program sonlandiriliyor... Gule gule! 👋\n");
    exit(0);
}