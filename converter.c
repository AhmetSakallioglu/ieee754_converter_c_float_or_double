#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>


int main()
{
    
    int tur;
    float sayi;
    float ondalikKisim;
    int tamKisim;
    int signBit;
    
    
    
    printf("Hangi ture cevirmek istiyorsunuz ? \n Float = 1 \n Double = 2 \nCevirmek istediginiz turu tuslayiniz = ");
    scanf("%d", &tur);
    
    
    if(tur == 1){ // float kısım işlemleri
        printf("Float secimi yaptiniz. \nCevirmek istediginiz sayiyi giriniz = ");
        scanf("%f", &sayi);
        
        if(sayi >= 0){
            signBit = 0;
        }else{
            signBit = 1;
        }
        
        sayi = fabs(sayi);
        tamKisim = (int)sayi;
        ondalikKisim = sayi - tamKisim;
        
        // tam kisim ikilik sisteme çevirme
        
        int bolumSonuc;
        int kalan;
        int tamKisimIkilik[100];
        int diziIndex = 1;
        
        bolumSonuc = tamKisim;
        
        while(bolumSonuc != 0){
            tamKisimIkilik[diziIndex++] = bolumSonuc % 2;
            bolumSonuc = bolumSonuc / 2;
        }
        
        
        // ondalik kisim ikilik sisteme cevirme
        
        
        double carpimSonuc;
        int sayacBir = 0;
        int kalanlarDizi[100];
        carpimSonuc = ondalikKisim *2;
        
        
        int a;
        for(a = 0; a < 23; a++){
            sayacBir++;
            
            if(carpimSonuc == 1){
                kalanlarDizi[a] = 1;
                break;
            }else if(carpimSonuc < 1){
                kalanlarDizi[a] = 0;
                carpimSonuc = carpimSonuc *2;
                continue;
            }else if(carpimSonuc > 1){
                carpimSonuc = carpimSonuc - 1;
                carpimSonuc = carpimSonuc *2;
                kalanlarDizi[a] = 1;
                continue;
            }

        }
        
        // virgül kaydirma
        int kaydirmaSayisi;
        int kaydirmaSayac = 0;
        kaydirmaSayisi = diziIndex-2;
        
        if(0 < sayi && sayi < 1){
            int b;
            for(b = 0; b < 100; b++){
                kaydirmaSayac++;
                if(kalanlarDizi[b] == 1){
                    break;
                }
            }
            kaydirmaSayisi = kaydirmaSayac * -1;
        }
        
        
        // 
        printf("-----------------------------------------------------\n");
        printf("32 Bit - Float\n");
        printf("Sign = %d", signBit);
        
        // exponent ikilik sisteme çevirme 
        
        
        int exponentOnlu;
        exponentOnlu = kaydirmaSayisi+127;
        
        int bolumSonuc2;
        int exponentIkilik[100];
        int diziIndex2 = 1;
        bolumSonuc2 = exponentOnlu;
        
        while(bolumSonuc2 != 0){
            exponentIkilik[diziIndex2++] = bolumSonuc2 % 2;
            bolumSonuc2 = bolumSonuc2 / 2;
        }
        
        // exponent yazdırma
        
        printf("\nExponent = ");
        int sayacExponent = 0;
        
        if(0<sayi && sayi < 1){
            
            int j;
            for(j = diziIndex2-1; j > 0; j--){
                sayacExponent++;
            }
            int a;
            for(a = 0; a < diziIndex2-sayacExponent; a++){
                printf("0");
            }
            for(j = diziIndex2-1; j > 0; j--){
                printf("%d", exponentIkilik[j]);
            }
            
        }else if(sayi == 0){
            int y;
            for(y = 0; y < 8; y++){
                printf("0");
            }
        }else{
            if(1<= sayi && sayi <2){
                printf("0");
            }
            int j;
            for(j = diziIndex2-1; j>0; j--){
                printf("%d", exponentIkilik[j]);
            }
        }
        
        // mantissa kısmı
        
        printf("\nMantissa = ");
        
        int sayacMantissa = 0;
        
        if(0 < sayi && sayi < 1){
            int m;
            for(m = kaydirmaSayisi * (-1); m < sayacBir; m++){
                sayacMantissa++;
                if(sayacMantissa == 23){
                    break;
                }
            }
            if(sayacMantissa < 24){
                int i;
                for(i = 0; i < (23-sayacMantissa); i++){
                    printf("0");
                }
            }
        }else{
            int m;
            for(m = diziIndex-2; m > 0; m--){
                printf("%d", tamKisimIkilik[m]);
                sayacMantissa++;
            }
            for(m = 0; m < sayacBir; m++){
                printf("%d", kalanlarDizi[m]);
                sayacMantissa++;
                if(sayacMantissa == 23){
                    break;
                    
                }
            }
            if(sayacMantissa < 23){
                int i;
                for(i = 0; i < (23-sayacMantissa); i++){
                    printf("0");
                }
            }
        }
        
                
        
    }else if(tur == 2){ //double deger cevirimi
        
    double sayi;
    double ondalikKisim;
    
        printf("Double secimi yaptiniz. \nCevirmek istediginiz sayiyi giriniz = ");
        scanf("%lf", &sayi);
        
        if(sayi >= 0){
            signBit = 0;
        }else{
            signBit = 1;
        }
        
        sayi = fabs(sayi);
        tamKisim = (int)sayi;
        ondalikKisim = sayi - tamKisim;
        
        // tam kisim ikilik sisteme çevirme
        
        int bolumSonuc;
        int kalan;
        int tamKisimIkilik[100];
        int diziIndex = 1;
        
        bolumSonuc = tamKisim;
        
        while(bolumSonuc != 0){
            tamKisimIkilik[diziIndex++] = bolumSonuc % 2;
            bolumSonuc = bolumSonuc / 2;
        }
        
        
        // ondalik kisim ikilik sisteme cevirme
        
        
        double carpimSonuc;
        int sayacBir = 0;
        int kalanlarDizi[100];
        carpimSonuc = ondalikKisim *2;
        
        
        int a;
        for(a = 0; a < 52; a++){
            sayacBir++;
            
            if(carpimSonuc == 1){
                kalanlarDizi[a] = 1;
                break;
            }else if(carpimSonuc < 1){
                kalanlarDizi[a] = 0;
                carpimSonuc = carpimSonuc *2;
                continue;
            }else if(carpimSonuc > 1){
                carpimSonuc = carpimSonuc - 1;
                carpimSonuc = carpimSonuc *2;
                kalanlarDizi[a] = 1;
                continue;
            }

        }
        
        // virgül kaydirma işlemi
        int kaydirmaSayisi;
        int kaydirmaSayac = 0;
        kaydirmaSayisi = diziIndex-2;
        
        if(0 < sayi && sayi < 1){
            int b;
            for(b = 0; b < 100; b++){
                kaydirmaSayac++;
                if(kalanlarDizi[b] == 1){
                    break;
                }
            }
            kaydirmaSayisi = kaydirmaSayac * -1;
        }
        
        
        // 
        printf("-----------------------------------------------------\n");
        printf("64 Bit - Double\n");
        printf("Sign = %d", signBit);
        
     	//exponent ikilik sisteme çevirme işlemi
     	
        int exponentOnlu;
        exponentOnlu = kaydirmaSayisi+1023;
        
        int bolumSonuc2;
        int exponentIkilik[100];
        int diziIndex2 = 1;
        bolumSonuc2 = exponentOnlu;
        
        while(bolumSonuc2 != 0){
            exponentIkilik[diziIndex2++] = bolumSonuc2 % 2;
            bolumSonuc2 = bolumSonuc2 / 2;
        }
        
        //exponent yazdırma işlemi
        
        printf("\nExponent = ");
        int sayacExponent = 0;
        
        if(0<sayi && sayi < 1){
            
            int j;
            for(j = diziIndex2-1; j > 0; j--){
                sayacExponent++;
            }
            int a;
            for(a = 0; a < diziIndex2-sayacExponent; a++){
                printf("0");
            }
            for(j = diziIndex2-1; j > 0; j--){
                printf("%d", exponentIkilik[j]);
            }
            
        }else if(sayi == 0){
            int y;
            for(y = 0; y < 11 ; y++){
                printf("0");
            }
        }else{
            if(1<= sayi && sayi <2){
                printf("0");
            }
            int j;
            for(j = diziIndex2-1; j>0; j--){
                printf("%d", exponentIkilik[j]);
            }
        }
        
        //mantissa işlemleri
        
        printf("\nMantissa = ");
        
        int sayacMantissa = 0;
        
        if(0 < sayi && sayi < 1){
            int m;
            for(m = kaydirmaSayisi * (-1); m < sayacBir; m++){
                sayacMantissa++;
                if(sayacMantissa == 52){
                    break;
                }
            }
            if(sayacMantissa < 53){
                int i;
                for(i = 0; i < (52-sayacMantissa); i++){
                    printf("0");
                }
            }
        }else{
            int m;
            for(m = diziIndex-2; m > 0; m--){
                printf("%d", tamKisimIkilik[m]);
                sayacMantissa++;
            }
            for(m = 0; m < sayacBir; m++){
                printf("%d", kalanlarDizi[m]);
                sayacMantissa++;
                if(sayacMantissa == 52){
                    break;
                    
                }
            }
            if(sayacMantissa < 52){
                int i;
                for(i = 0; i < (52-sayacMantissa); i++){
                    printf("0");
                }
            }
        }
        
        
        
    }else{
        printf("Hatali bir tur secimi tusladiniz. ");
    }
    
    
    return 0;
}
