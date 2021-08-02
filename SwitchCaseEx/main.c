#include <stdio.h>
#include <stdlib.h>

int main()
{
    int islem, bakiye=1000, tutar;

    printf("islemler:  \n1:Para cekme  \n2:para yatirma  \n3:havale yapma    \n\n\nislem seciniz: ");

    scanf("%d", &islem);

    switch(islem){

        case 1:
            printf("Bakiyeniz %d\n ", bakiye);
            printf("Cekilecek tutar: ");
            scanf("%d",&tutar);
            if(tutar>bakiye)
                printf("bakiye yetersiz\n");

            bakiye-=tutar;
            printf("Bakiyeniz %d\n ", bakiye);
            break;

        case 2:
            printf("Bakiyeniz %d\n ", bakiye);
            printf("Yatirilcak tutar: ");
            scanf("%d",&tutar);

            bakiye+=tutar;
            printf("Bakiyeniz %d\n ", bakiye);
            break;

        case 3:
            printf("Bakiyeniz %d\n ", bakiye);
            printf("Havale yapicak tutar: ");
            scanf("%d",&tutar);
            if(tutar>bakiye)
                printf("bakiye yetersizz  \n");

            bakiye-=tutar;
            printf("Bakiyeniz %d\n ", bakiye);
            break;

        default:
            printf("gecersiz islem!! ");
            break;

    }


    return 0;
}
