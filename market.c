

#include <stdio.h>

int main() {
    float tost,hamburger,doner,ayran,meyve_suyu,su,tatli,kek,cay,kurabiye,toplam;

    tost = 47.45;
    hamburger = 54.65;
    doner = 50.87;
    ayran = 10.35;
    meyve_suyu = 10.25;
    su = 15.50;
    tatli = 35.55;
    kek = 21.98;
    cay = 7.50;
    kurabiye = 7.50;

    int secim;

    do {
        printf("\n>>***--- MENU ---***<< ");
        printf("\n1. yiyecek listesi");
        printf("\n2.  urun adedi");
        printf("\n3.  Cikis");
        scanf("%d",&secim);
        switch(secim) {
            // food list
            case 1: {
                printf("\nYiyecekler:\n");
                printf("\n1- tost:47.45\n");
                printf("\n2- hamburger:54.65\n");
                printf("\n3- doner:50.87\n");
                printf("\n4- ayran:10.35\n");
                printf("\n5- meyve suyu:10.25\n");
                printf("\n6- su:15.50\n");
                printf("\n7- tatli:35.55\n");
                printf("\n8- kek:21.98\n");
                printf("\n9- cay:7.50\n");
                printf("\n10- kurabiye:7.50\n");

                break;

            // food list and price
            }
            case 2: {
                int urun;
                printf("\nUrun secin(1-10)\n");
                printf("Tost adedi:");
                scanf("%d",&tost);
                toplam += tost * 47.45;
                printf("Hamburger adedi:");
                scanf("%f",&hamburger);
                toplam += hamburger * 54.65;
                printf("Doner adedi:");
                scanf("%f",&doner);
                toplam += doner * 50.87;
                printf("Ayran adedi:");
                scanf("%f",&ayran);
                toplam += ayran * 10.35;
                printf("Meyve suyu adedi:");
                scanf("%f",&meyve_suyu);
                toplam += meyve_suyu * 15.25;
                printf("Su adedi:");
                scanf("%f",&su);
                toplam += su * 10.50;
                printf("Tatli adedi:");
                scanf("%f",&tatli);
                toplam += tatli * 35.55;
                printf("Kurabiye adedi:");
                scanf("%f",&kurabiye);
                toplam += kurabiye * 7.50;
                printf("Cay adedi:");
                scanf("%f",&cay);
                toplam += cay * 7.50;
                printf("kek adedi");
                scanf("%f",&kek);
                toplam += kek * 21.98;
                printf("\nToplam ödeme: %f",toplam);
                break;
            }
            //system logout
            case 3: {
                printf("Cikis yapiliyor...\n");
                break;
                default:

                printf("\nERROR");
            }

        }

    } while (secim != 3);
    return 0;
}
