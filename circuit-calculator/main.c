#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int ende= 1, ende1 = 1;

float maxwiederstand=0;
float minwiederstand=0;

int reihe1[4]= {0};
int reihe2[4]= {0};
int reihe3[4]= {0};
int reihe4[4]= {0};
int reihe5[4]= {0};
int reihe6[4]= {0};
int reihe7[4]= {0};
int reihe8[4]= {0};
int reihe9[4]= {0};

typedef struct
{
    float minWiederstand;
    float maxWiederstand;
    float maxI;
    float maxV;
} TResistor;

TResistor w[45];

void show_W()
{
    int i;
    for(i=0; i<46; i++)
    {
        printf("Wiederstand:            %i\n",i);
        printf("Minimaler Wiederstand:  %f\n",w[i].minWiederstand);
        printf("Maximaler Wiederstand:  %f\n",w[i].maxWiederstand);
        printf("Maximale Stromst\204rke    %f\n",w[i].maxI);
        printf("Maximale Spannung       %f\n",w[i].maxV);
        printf("\n");
    }
}

void clearen()
{
    int i;
    for(i=0; i<MAX; i++)
    {
        reihe1[i]=0;
        reihe2[i]=0;
        reihe3[i]=0;
        reihe4[i]=0;
        reihe5[i]=0;
        reihe6[i]=0;
        reihe7[i]=0;
        reihe8[i]=0;
        reihe9[i]=0;
    }

    for(i=0; i<46; i++)
    {
        w[i].minWiederstand=0;
        w[i].maxWiederstand=0;
        w[i].maxI=0;
        w[i].maxV=0;
    }

}
void berechnen()
{
    int i;

    float maxew1=0, maxew2=0, maxew3=0, maxew4=0, maxew5=0, maxew6=0, maxew7=0, maxew8=0, maxew9=0;

    float minew1=0, minew2=0, minew3=0, minew4=0, minew5=0,minew6=0, minew7=0, minew8=0, minew9=0;

    float max1=0, max2=0, max3=0;
    float min1=0, min2=0, min3=0;

    float maxwiederstand2=0;
    float minwiederstand2=0;

    for(i=0; i<MAX; i++)
    {

        if(reihe1[i] != 0)
        {
            maxew1+=w[reihe1[i]].maxWiederstand;
            minew1+=w[reihe1[i]].minWiederstand;
        }
        if(reihe2[i]!= 0)
        {
            maxew2+=w[reihe2[i]].maxWiederstand;
            minew2+=w[reihe2[i]].minWiederstand;
        }
        if(reihe3[i]!=0)
        {
            maxew3+=w[reihe3[i]].maxWiederstand;
            minew3+=w[reihe3[i]].minWiederstand;
        }
        if(reihe4[i]!=0)
        {
            maxew4+=w[reihe4[i]].maxWiederstand;
            minew4+=w[reihe4[i]].minWiederstand;
        }
        if(reihe5[i]!=0)
        {
            maxew5+=w[reihe5[i]].maxWiederstand;
            minew5+=w[reihe5[i]].minWiederstand;
        }
        if(reihe6[i]!=0)
        {
            maxew6+=w[reihe6[i]].maxWiederstand;
            minew6+=w[reihe6[i]].minWiederstand;
        }
        if(reihe7[i]!=0)
        {
            maxew7+=w[reihe7[i]].maxWiederstand;
            minew7+=w[reihe7[i]].minWiederstand;
        }
        if(reihe8[i]!=0)
        {
            maxew8+=w[reihe8[i]].maxWiederstand;
            minew8+=w[reihe8[i]].minWiederstand;
        }
        if(reihe9[i]!=0)
        {
            maxew9+=w[reihe9[i]].maxWiederstand;
            minew9+=w[reihe9[i]].minWiederstand;
        }
    }


    if(maxew1 != 0 || maxew4 != 0 || maxew7 != 0 )
    {
        if(maxew1 != 0 && maxew4 != 0 && maxew7 != 0 )
        {
            max1 = 1/ ( 1/maxew1 + 1/maxew4 + 1/maxew7);
        }
        if(maxew1 != 0 && maxew4 != 0 && maxew7 == 0 )
        {
            max1 = 1/ ( 1/maxew1 + 1/maxew4);
        }
        if(maxew1 != 0 && maxew7 != 0 && maxew4 == 0)
        {
            max1 = 1/ ( 1/maxew1 + 1/maxew7);
        }
        if(maxew7 != 0 && maxew4 != 0 && maxew1 == 0)
        {
            max1 = 1/ ( 1/maxew7 + 1/maxew4);
        }
        if(maxew1 != 0 && maxew4 == 0 && maxew7 == 0)
        {
            max1 = maxew1;
        }
        if(maxew1 == 0 && maxew4 != 0 && maxew7 == 0)
        {
            max1 = maxew4;
        }
        if(maxew1 == 0 && maxew4 == 0 && maxew7 != 0)
        {
            max1 = maxew7;
        }
    }

    if(maxew2 != 0 || maxew5 != 0 || maxew8 != 0 )
    {
        if(maxew2 != 0 && maxew5 != 0 && maxew8 != 0 )
        {
            max2 = 1/ ( 1/maxew2 + 1/maxew5 + 1/maxew8);
        }
        if(maxew2 != 0 && maxew5 != 0 && maxew8 == 0 )
        {
            max2 = 1/ ( 1/maxew2 + 1/maxew5);
        }
        if(maxew2 != 0 && maxew8 != 0 && maxew5 == 0)
        {
            max2 = 1/ ( 1/maxew2 + 1/maxew8);
        }
        if(maxew8 != 0 && maxew5 != 0 && maxew2 == 0)
        {
            max2 = 1/ ( 1/maxew8 + 1/maxew5);
        }
        if(maxew2 != 0 && maxew5 == 0 && maxew8 == 0)
        {
            max2 = maxew2;
        }
        if(maxew2 == 0 && maxew5 != 0 && maxew8 == 0)
        {
            max2 = maxew5;
        }
        if(maxew2 == 0 && maxew5 == 0 && maxew8 != 0)
        {
            max2 = maxew8;
        }
    }

    if(maxew3 != 0 || maxew6 != 0 || maxew9 != 0 )
    {
        if(maxew3 != 0 && maxew6 != 0 && maxew9 != 0 )
        {
            max3 = 1/ ( 1/maxew3 + 1/maxew6 + 1/maxew9);
        }
        if(maxew3 != 0 && maxew6 != 0 && maxew9 == 0 )
        {
            max3 = 1/ ( 1/maxew3 + 1/maxew6);
        }
        if(maxew3 != 0 && maxew9 != 0 && maxew6 == 0)
        {
            max3 = 1/ ( 1/maxew3 + 1/maxew9);
        }
        if(maxew9 != 0 && maxew6 != 0 && maxew3 == 0)
        {
            max3 = 1/ ( 1/maxew9 + 1/maxew6);
        }
        if(maxew3 != 0 && maxew6 == 0 && maxew9 == 0)
        {
            max3 = maxew3;
        }
        if(maxew3 == 0 && maxew6 != 0 && maxew9 == 0)
        {
            max3 = maxew6;
        }
        if(maxew3 == 0 && maxew6 == 0 && maxew9 != 0)
        {
            max3 = maxew9;
        }
    }

    if(minew1 != 0 || minew4 != 0 || minew7 != 0 )
    {
        if(minew1 != 0 && minew4 != 0 && minew7 != 0 )
        {
            min1 = 1/ ( 1/minew1 + 1/minew4 + 1/minew7);
        }
        if(minew1 != 0 && minew4 != 0 && minew7 == 0 )
        {
            min1 = 1/ ( 1/minew1 + 1/minew4);
        }
        if(minew1 != 0 && minew7 != 0 && minew4 == 0)
        {
            min1 = 1/ ( 1/minew1 + 1/minew7);
        }
        if(minew7 != 0 && minew4 != 0 && minew1 == 0)
        {
            min1 = 1/ ( 1/minew7 + 1/minew4);
        }
        if(minew1 != 0 && minew4 == 0 && minew7 == 0)
        {
            min1 = minew1;
        }
        if(minew1 == 0 && minew4 != 0 && minew7 == 0)
        {
            min1 = minew4;
        }
        if(minew1 == 0 && minew4 == 0 && minew7 != 0)
        {
            min1 = minew7;
        }
    }

    if(minew2 != 0 || minew5 != 0 || minew8 != 0 )
    {
        if(minew2 != 0 && minew5 != 0 && minew8 != 0 )
        {
            min2 = 1/ ( 1/minew2 + 1/minew5 + 1/minew8);
        }
        if(minew2 != 0 && minew5 != 0 && minew8 == 0 )
        {
            min2 = 1/ ( 1/minew2 + 1/minew5);
        }
        if(minew2 != 0 && minew8 != 0 && minew5 == 0)
        {
            min2 = 1/ ( 1/minew2 + 1/minew8);
        }
        if(minew8 != 0 && minew5 != 0 && minew2 == 0)
        {
            min2 = 1/ ( 1/minew8 + 1/minew5);
        }
        if(minew2 != 0 && minew5 == 0 && minew8 == 0)
        {
            min2 = minew2;
        }
        if(minew2 == 0 && minew5 != 0 && minew8 == 0)
        {
            min2 = minew5;
        }
        if(minew2 == 0 && minew5 == 0 && minew8 != 0)
        {
            min2 = minew8;
        }
    }
    if(minew3 != 0 || minew6 != 0 || minew9 != 0 )
    {
        if(minew3 != 0 && minew6 != 0 && minew9 != 0 )
        {
            min3 = 1/ ( 1/minew3 + 1/minew6 + 1/minew9);
        }
        if(minew3 != 0 && minew6 != 0 && minew9 == 0 )
        {
            min3 = 1/ ( 1/minew3 + 1/minew6);
        }
        if(minew3 != 0 && minew9 != 0 && minew6 == 0)
        {
            min3 = 1/ ( 1/minew3 + 1/minew9);
        }
        if(minew9 != 0 && minew6 != 0 && minew3 == 0)
        {
            min3 = 1/ ( 1/minew9 + 1/minew6);
        }
        if(minew3 != 0 && minew6 == 0 && minew9 == 0)
        {
            min3 = minew3;
        }
        if(minew3 == 0 && minew6 != 0 && minew9 == 0)
        {
            min3 = minew6;
        }
        if(minew3 == 0 && minew6 == 0 && minew9 != 0)
        {
            min3 = minew9;
        }
    }

    printf("maxe: %f\n",maxew1);
    printf("maxe: %f\n",maxew2);
    printf("maxe3: %f\n",maxew3);
    printf("maxe: %f\n",maxew4);
    printf("maxe: %f\n",maxew5);
    printf("maxe6: %f\n",maxew6);
    printf("maxe: %f\n",maxew7);
    printf("maxe: %f\n",maxew8);
    printf("maxe9: %f\n\n",maxew9);



    printf("\nmine: %f\n",minew1);
    printf("mine: %f\n",minew2);
    printf("mine: %f\n",minew3);
    printf("mine: %f\n",minew4);
    printf("mine: %f\n",minew5);
    printf("mine: %f\n",minew6);
    printf("mine: %f\n",minew7);
    printf("mine: %f\n",minew8);
    printf("mine: %f\n\n",minew9);



    maxwiederstand2=max1+max2+max3;
    minwiederstand2=min1+min2+min3;

    maxwiederstand=maxwiederstand2;
    minwiederstand=minwiederstand2;




}
void addwiederstand(int temp, int temp2, int temp3)
{
    int kn=0;
    printf("Geben sie eine Kennnummer f\201r den Wiederstand an: \n");
    printf("WICHTIG jede Nummer darf nur einmal verwendet werden\nund muss von 1-45 sein!\n");
    while(ende1==1)
    {
        scanf("%d",&kn);
        if(kn != 0 && kn <=45)
        {
            break;
            ende1=0;
        }
        else
        {
            printf("Die Zahl muss gr\224\341er als 0 und kleiner als 45 sein!\n");
        }
    }
    if(temp==1)
    {
        if(temp2 == 1)
        {
            reihe1[temp3] = kn;
        }
        else if(temp2 == 2)
        {
            reihe2[temp3] = kn;
        }
        else
        {
            reihe3[temp3] = kn;
        }
    }
    if(temp==2)
    {
        if(temp2 == 1)
        {
            reihe4[temp3] = kn;
        }
        else if(temp2 == 2)
        {
            reihe5[temp3] = kn;
        }
        else
        {
            reihe6[temp3] = kn;
        }
    }
    if(temp==3)
    {
        if(temp2 == 1)
        {
            reihe7[temp3] = kn;
        }
        else if(temp2 == 2)
        {
            reihe8[temp3] = kn;
        }
        else
        {
            reihe9[temp3] = kn;
        }
    }

    printf("Minimaler Widerstandswert:\n");
    scanf("%f",&w[kn].minWiederstand);
    printf("Maximaler Widerstandswert:\n");
    scanf("%f",&w[kn].maxWiederstand);
    printf("Maximale Stromst\204rke:\n");
    scanf("%f",&w[kn].maxI);
    printf("Maximale Spannung:\n");
    scanf("%f",&w[kn].maxV);



}
void reihenzeichnen(int reihen1, int reihen2, int reihen3, int spalte)
{
    int i;

    if(spalte == 1 || spalte == 2 || spalte == 3 )
    {
        for(i=0; i<MAX; i++)
        {
            printf("%d ",reihe1[i]);
        }
        printf("   ");
    }

    if(reihen1 == 2 || reihen1== 3)
    {
        for(i=0; i<MAX; i++)
        {
            printf("%d ",reihe2[i]);
        }
        printf("   ");
    }
    if(reihen1== 3)
    {
        for(i=0; i<MAX; i++)
        {
            printf("%d ",reihe3[i]);
        }


    }
    //nächste spalte 2
    if(spalte == 2 || spalte == 3)
    {
        if(reihen2 == 1||reihen2 == 2 || reihen2 == 3)
        {
            printf("\n\n   ");
            for(i=0; i<MAX; i++)
            {
                printf("%d ",reihe4[i]);
            }
            printf("   ");
        }
        if(reihen2 == 2 || reihen2 == 3)
        {
            for(i=0; i<MAX; i++)
            {
                printf("%d ",reihe5[i]);
            }
            printf("   ");
        }
        if(reihen2==3)
        {
            for(i=0; i<MAX; i++)
            {
                printf("%d ",reihe6[i]);
            }

        }
    }
    //nächste spalte 3
    if(spalte==3)
    {
        if(reihen3 == 1||reihen3 == 2 || reihen3 == 3)
        {
            printf("\n\n   ");
            for(i=0; i<MAX; i++)
            {
                printf("%d ",reihe7[i]);
            }
            printf("   ");
        }
        if(reihen3 == 2 || reihen3==3)
        {
            for(i=0; i<MAX; i++)
            {
                printf("%d ",reihe8[i]);
            }
            printf("   ");
        }
        if(reihen3 == 3)
        {
            for(i=0; i<MAX; i++)
            {
                printf("%d ",reihe9[i]);
            }
        }
    }
}



int main()
{

    char x;
    int reihen1=3, spalte=3,reihen2=3,reihen3=3,i;


    while(ende==1)
    {
        int temp=0, temp2=0,temp3=0;

        printf("\n   Raster anpassen                  [1]\n");
        printf("   Wiederstand hinzuf\201gen           [2]\n");
        printf("   Berechnen                        [3]\n");
        printf("   Alle Wiederst\204nde anzeigen       [4]\n");
        printf("   Clearen                          [5]\n");
        printf("   Programm beenden                 [6]\n");

        printf("\n\n   ");
        reihenzeichnen(reihen1,reihen2,reihen3,spalte);
        printf("\n");

        scanf("%c",&x);
        system("cls");

        switch(x)
        {
        case 49:
            printf("Spalten:  ");
            scanf("%d",&spalte);
            printf("\n");
            if(spalte == 1 || spalte == 2 || spalte == 3 )
            {
                printf("Reihen in Spalte 1 (max = 3): ");
                scanf("%d",&reihen1);
                printf("\n");
            }
            if(spalte == 2 || spalte == 3)
            {
                printf("Reihen in Spalte 2 (max = 3): ");
                scanf("%d",&reihen2);
                printf("\n");
            }
            if(spalte == 3)
            {
                printf("Reihen in Spalte 3 (max = 3): ");
                scanf("%d",&reihen3);
                printf("\n");
            }
            break;
        case 50:
            printf("Wiederstand hinzuf\201gen in\n");
            printf("Spalte: \n");
            scanf("%d",&temp);
            printf("Reihe: \n");
            scanf("%d",&temp2);
            printf("An Stelle: \n");
            scanf("%d",&temp3);
            addwiederstand(temp, temp2, temp3);
            break;
        case 51:
            berechnen();
            printf("Maximaler Wiederstand: %f\n",maxwiederstand);
            printf("Minimaler Wiederstand: %f\n",minwiederstand);
            system("Pause");
            break;
        case 52:
            show_W();
            system("Pause");
            break;
        case 53:
            clearen();
            break;
        case 54:
            exit(0);
            ende = 0;
            break;
        }
    }
}
