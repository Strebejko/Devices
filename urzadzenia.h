#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include"plan.h"
#define ZOLTY "\x1B[33m"
#define ZWYKLY  "\x1B[0m"
#define BLEKITNY "\x1B[36m"

typedef struct BazaUrzadzen {
	char *nazwa;
	unsigned int moc;
	int onoff;
	time_t time;
} BazaUrzadzen;



void pokaz(BazaUrzadzen a) {
	printf(" Nazwa: %s\n Moc urządzenia: %d\n Czas ostatniego włączenia: %s\n", a.nazwa, a.moc, ctime(&a.time));
}



void urzadzenia() {

	char dom[20][50];
	
	inicjalizuj(dom); //rysowanie planu mieszkania, plan.h
	nazwij(dom); //podpisanie pomieszczeń, plan.h
	umiesc(dom); //umieszczenie urządzeń, plan.h

	int cmoc; //moc razem
	char numer;
	BazaUrzadzen tab[5]= //nazwa, moc, czy włączony, czas
	{
		{"Lampa",75,1,time(NULL)},
		{"Nawilżacz powietrza",400,1,time(NULL)},
		{"Lodówka",700,0,time(NULL)},
		{"Pralka",4260,0,time(NULL)},
		{"Odkurzacz Roomba",750,1,time(NULL)},
	};

	size_t dl_tablicy = sizeof(tab)/sizeof(BazaUrzadzen); //sprawdzenie długosci tablicy

	while(true)
	{
		printf("\n");
		printf(BLEKITNY "Lista włączonych urządzeń: \n" ZWYKLY);
		for(int i=0;i<dl_tablicy;i++){
			if(tab[i].onoff == 1)
			{
				pokaz(tab[i]);
				cmoc=cmoc+tab[i].moc;
			}
		}

		if(tab[0].onoff==1)//lampa
		{
			dom[4][14]='/';
			dom[4][15]='|';
			dom[4][16]='\\';
		}
		else
		{
			dom[4][14]=' ';
			dom[4][15]=' ';
			dom[4][16]=' ';
		}
		if(tab[1].onoff==1)//nawilżacz
		{
			dom[10][35]='~';
			dom[11][35]='~';
			dom[12][35]='~';
		}
		else
		{
			dom[10][35]=' ';
			dom[11][35]=' ';
			dom[12][35]=' ';
		}
		if(tab[2].onoff==1)//lodówka
		{
			dom[5][46]='=';
			dom[5][47]='=';
			dom[6][45]='=';
			dom[7][45]='=';
		}
		else
		{
			dom[5][46]=' ';
			dom[5][47]=' ';
			dom[6][45]=' ';
			dom[7][45]=' ';
		}
		if(tab[3].onoff==1)//pralka
		{
			dom[16][28]='x';
			dom[16][29]='x';
			dom[17][27]='x';
			dom[18][27]='x';
		}
		else
		{
			dom[16][28]=' ';
			dom[16][29]=' ';
			dom[17][27]=' ';
			dom[18][27]=' ';
		}
		if(tab[4].onoff==1)//roomba
		{
			dom[15][12]='*';
			dom[16][11]='*';
			dom[16][13]='*';
			dom[17][12]='*';
		}
		else{
			dom[15][12]=' ';
			dom[16][11]=' ';
			dom[16][13]=' ';
			dom[17][12]=' ';
		}

		printf("\n");
		printf(BLEKITNY "          -------PLAN MIESZKANIA-------\n" ZWYKLY);
		for(int x=0;x<20;x++){
			for (int y=0;y<50;y++){
				printf(ZOLTY "%c", dom[x][y]);
			}
		}
		printf(ZWYKLY "\n");
		
		
		printf("\nCałkowita moc: %d\n", cmoc);
		printf("\nPodaj cyfrę od 0 do 4, by zarządzać urządzeniami:\n");
		printf("0 - lampa\t1 - nawilżacz\t2 - lodówka\t3 - pralka\t4 - Roomba\t5 - powrót do menu ");
		
		
		scanf(" %c",&numer);
		if(numer=='5'){
			return;
		}
    
		numer=numer-48;
		
		switch(tab[numer].onoff)
		{
			case 0:
				tab[numer].onoff = 1;
				tab[numer].time = time(NULL);
				break;
			case 1:
				tab[numer].onoff = 0;
				break;
			default:
				printf("\n");
				break;
		}   
		cmoc = 0;

		};
    
}