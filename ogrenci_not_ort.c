#include <stdio.h>

int main() {

    float not1,not2,not3,ortalama;

    printf("1. Notu giriniz: ");
    scanf("%f",&not1);

    printf("2. Notu giriniz: ");
    scanf("%f",&not2);

    printf("3. Notu giriniz: ");
    scanf("%f",&not3);

    ortalama = (not1+not2+not3)/3;

    printf("Toplam notunuz:""%f",ortalama);

}