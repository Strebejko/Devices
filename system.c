#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"urzadzenia.h"
#include"szyfr.h"
#define CZERWONY "\x1B[31m"
#define ZWYKLY  "\x1B[0m"

	void papa(){ //wywoływana przy zamykaniu programu
		printf("\n");
		puts("Zakończono pracę.");
		puts("Do widzenia!");
		printf("\n");
	}

	
	
	int main(int argc, char *argv[]){
		char wczytane_haslo[30];
		int k = -3; //klucz do szyfrowania
		int menu=0;

		
		printf("\n");
		printf(ZIELONY "-----SYSTEM ZARZĄDZANIA DOMEM-----\n" ZWYKLY);

		
		FILE *plikzhaslem;
		plikzhaslem=fopen(argv[1],"r");
		
		if (plikzhaslem==NULL)
		{
			printf("Nie ma takiego użytkownika!\n");
			printf("Skontaktuj się z administratorem w celu utworzenia konta.\n");
			printf("\n");
			exit(1);
		}
		
		
		else
		{
			int czy_sie_udalo;
			czy_sie_udalo = fscanf(plikzhaslem,"%s",wczytane_haslo);
			//printf(wczytane_haslo); DO TESTÓW
			if(czy_sie_udalo==EOF)//==null działa, ale powoduje warning
			{
				printf("Nie udało się odczytać hasła!\n");
				printf("Brak dostępu.\n");
				exit(1);
			}

			
			char wpisane_haslo[30];
			printf("Podaj hasło: ");
			int licz_znaki;
			system("stty -echo");
			scanf("%29s", wpisane_haslo);
			system("stty echo");
			licz_znaki = strlen(wpisane_haslo);
			wpisane_haslo[licz_znaki]=0;
			//printf("Ilość znaków wpisanego hasła: %d\n", licz_znaki); DO TESTÓW
			int licz_znaki2;
			licz_znaki2 = strlen(wczytane_haslo);
			//printf("Ilość znaków wczytanego hasła: %d\n", licz_znaki2); DO TESTÓW
			
			
			for (int i=0; i<licz_znaki2; i++){
			if (wczytane_haslo[i]>='A' && wczytane_haslo[i]<='Z') //duże litery
				{
				wczytane_haslo[i] = (wczytane_haslo[i] - 'A' + k) % 26 + 'A';
				}
				
			else if (wczytane_haslo[i]>='a' && wczytane_haslo[i]<='z') //małe litery
			{
				wczytane_haslo[i] = (wczytane_haslo[i] - 'a' + k) % 26 + 'a';
			}
		}
			
		
			if(strcmp(wczytane_haslo,wpisane_haslo) == 0) //porównanie haseł
			{
				while(menu!=3)
				{
					printf("\n");
					printf("\nWitaj, %s!\n", argv[1]);
					printf("Co chcesz teraz zrobić?\n");
					printf("1. Zarządzanie urządzeniami.\n");
					printf("2. Zmiana hasła.\n");
					printf(CZERWONY "3. -WYJŚCIE-\n" ZWYKLY);
				
					scanf("%d", &menu);

					switch(menu) {
						case 1:
							urzadzenia(); break; //w pliku urzadzenia.h
						case 2:
							szyfruj(argv[1]); break; //w pliku szyfr.h
						case 3:
							atexit(papa); break;
					}
				};
			}
			else
				{
					printf("Hasło jest nieprawidłowe!\n");
					printf("Brak dostępu.\n");
				}

		}

		fclose(plikzhaslem);
		return 0;
	}