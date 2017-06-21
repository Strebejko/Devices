#include <stdio.h>
#define ZIELONY "\x1B[32m"
#define ZWYKLY  "\x1B[0m"

	void szyfruj(char* imie) {
		int i, dl_hasla;
		int k=3; //o ile przesuwamy w szyfrze?
		char haslo[30];

 
		printf("Podaj swoje nowe hasło: ");
		system("stty -echo");
		scanf("%29s", haslo);
		system("stty echo");
		dl_hasla = strlen(haslo);
		printf("\nDługość hasła: %d\n", dl_hasla);

		for (i=0; i<dl_hasla; i++){
			if (haslo[i]>='A' && haslo[i]<='Z') //duże litery
				{
				haslo[i] = (haslo[i] - 'A' + k) % 26 + 'A';
				}
				
			else if (haslo[i]>='a' && haslo[i]<='z') //małe litery
			{
				haslo[i] = (haslo[i] - 'a' + k) % 26 + 'a';
			}
		}
		//printf(haslo); DO TESTÓW
		haslo[dl_hasla] = 0;
		
		printf(ZIELONY "Twoje nowe hasło zostało ono zapisane do pliku z Twoim imieniem.\n" ZWYKLY);

		FILE *user;
		user=fopen(imie,"w");
		fprintf(user,"%s",haslo);
		fclose(user);
	
		return;
	}