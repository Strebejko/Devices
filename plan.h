void inicjalizuj(char dom [20][50]) {
	
	
	for(int x=0;x<20;x++){ //wypełnienie spacjami
		for (int y=0;y<50;y++){
			dom[x][y]=' ';
		}
	}
	
	
	for (int a=0;a<=48;a++){//poziome u góry
		dom[0][a]='#';}
	for (int b=1;b<=19;b++){//pionowe z lewej
		dom[b][0]='#';}
	for (int c=1;c<=48;c++){//poziome na dole
		dom[19][c]='#';}
	for (int d=1;d<=18;d++){//pionowe z prawej
		dom[d][48]='#';}
	for (int e=0;e<=18;e++){//nowe linie na końcu wiersza
		dom[e][49]='\n';}
		
	
	dom[19][49]='\0';//koniec macierzy
	
	
	for (int f=1;f<=29;f++){//salon dół
		dom[13][f]='-';}
	for (int g=1;g<=18;g++){//salon łazienka prawo
		dom[g][30]='|';}
	for (int h=14;h<=18;h++){//łazienka lewo
		dom[h][15]='|';}
	for (int k=31;k<=47;k++){//kuchnia dół
		dom[8][k]='-';}
}



void nazwij(char dom [20][50]) {
	/*przedpokój*/dom[14][1]='P';dom[14][2]='R';dom[14][3]='Z';dom[14][4]='E';dom[14][5]='D';dom[14][6]='P';dom[14][7]='O';dom[14][8]='K';dom[14][9]='O';dom[14][10]='J';
	/*salon*/dom[1][1]='S';dom[1][2]='A';dom[1][3]='L';dom[1][4]='O';dom[1][5]='N';
	/*kuchnia*/dom[1][31]='K';dom[1][32]='U';dom[1][33]='C';dom[1][34]='H';dom[1][35]='N';dom[1][36]='I';dom[1][37]='A';
	/*łazienka*/dom[14][16]='L';dom[14][17]='A';dom[14][18]='Z';dom[14][19]='I';dom[14][20]='E';dom[14][21]='N';dom[14][22]='K';dom[14][23]='A';
	/*sypialnia*/dom[9][31]='S';dom[9][32]='Y';dom[9][33]='P';dom[9][34]='I';dom[9][35]='A';dom[9][36]='L';dom[9][37]='N';dom[9][38]='I';dom[9][39]='A';
}



void umiesc(char dom [20][50]) {
	/*pralka*/dom[17][28]='P';dom[17][29]='P';dom[18][28]='P';dom[18][29]='P';
	/*nawilżacz*/dom[10][36]='N';dom[11][36]='N';dom[12][36]='N';dom[10][37]='N';dom[11][37]='N';dom[12][37]='N';
	/*lodówka*/dom[6][46]='L';dom[6][47]='L';dom[7][46]='L';dom[7][47]='L';
	/*roomba*/dom[16][12]='R';
	/*lampa*/dom[3][15]='O';
}
