#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void escolhe(char palavra [],int num){

    char palavras [12] [50] ={"alce","andorinha","camelo","canguru",
                              "carneiro","castor","cervo","cobra","coelho",
                              "coruja","corvo","crocodilo","leao","zebra"};


        do{
           printf("Digite um numero de 1 a 12: ");
            scanf("%i",&num);
        }while( num > 12 || num < 1);
        num = num - 1;

    strcpy(palavra,palavras[num]);
}

int cripto(char troca [],int chave){

	int tam;



    tam = strlen(troca);
         for(int x=0;x<tam;x++){
             troca[x] = toupper(troca[x]);
         }
    do{
        printf("Digite um numero de 0 a 26: ");
        scanf("%i",&chave);
   }while(chave < 0 || chave > 26);

        for(int y=0;y<tam;y++){

            int enc=(int)troca[y]+chave;
                if(enc  > 90){
                 enc = 64 + (enc - 90);
                 }
                troca[y] = ((char)enc);
        }

        return chave;
}
char cabecalho(){
            system("cls");
	  		printf("\n                                                  Extreme Forca \n");
	  		printf("________________________________________________________________________________________________________________________\n\n\n");


}

int main ()	{


	 char palavra[50], certas[50], troca[50],cifra[50],resposta [50];
	 int i, fim, encontrei, num , chave,denovo;
	 int numTentativas, limTentativas, acerto;
	 char tentativa;
    do{
     acerto = 0;
	 numTentativas = 0;
     fim = 0;

    system("cls");
    cabecalho();
	escolhe(palavra,num);
	strcpy(cifra,palavra);

	chave = cripto(cifra,chave);
	strcpy(troca,cifra);



	 limTentativas = 10;


	 for (i=0; i<strlen(cifra); i++)
	 	 certas [i] = ' ';

	  do {
	  		cabecalho();


	  		for(i=0; i<strlen(cifra); i++){
	  			 printf(" %c  ", certas[i]);
	  		}

	  		printf("\n");


	  		 for(i=0; i<strlen(cifra); i++){
	  		 	printf("___ ");
	  		 }

	  		 printf("\n");

	  		printf("\n\n________________________________________\n\n");
			printf("Restantes: %d", limTentativas - numTentativas);
			printf(" - Acerto(s): %d", acerto);
			printf("\n\n_________________________________________\n\n");



	  		 fflush(stdin);
	  		 printf("\n\nEntre com uma letra (ou * para encerrar) + <enter>: ");
	  		 scanf("%c", &tentativa);



	  		 encontrei = 0;
	  		 for (i=0; i<strlen(cifra); i++)
	  		 	  if (toupper(troca[i]) == toupper(tentativa))  {
	  		 	  		troca[i] = "*";
	  		 	  		certas[i] = toupper(tentativa);
						acerto++;
						encontrei = 1;
					 }

			 if (encontrei == 0)
	  			   numTentativas++;

			 if (numTentativas >= limTentativas || acerto == strlen(cifra) || tentativa == '*')
			  		fim = 1;

	  }	while (fim == 0);

	  system("cls");


        if(numTentativas >= limTentativas) {
            cabecalho();
            printf("\n                                                         ***** Que pena!! ***** \n\n");
            printf("\n                                          ************** Voce errou todas as letras ***************\n");
            printf("                                                        A Chave era : %i\n",chave);
            printf("                                                         A Cifra era: %s\n", cifra);
            printf("                                                       A Palavra era: %s\n", palavra);
        }

	  else if (tentativa != '*') {
            cabecalho();
            printf("a criptografia era %s\n",cifra);
            printf("Digite qual eh a palavra: ");
            scanf("%s",resposta);
            for (i=0; i<strlen(resposta); i++){
                resposta[i] = toupper(resposta[i]);
                palavra[i] = toupper(palavra[i]);
            }
            if(strcmp(palavra,resposta)==0){
                system("cls");
                cabecalho();
                printf("\n                                           ******* PARABENS! *******\n");
                printf("\n                                           ****** Voce Acertou ******\n");
                printf("                                            A Chave era : %i\n",chave);
                printf("                                             A Cifra era: %s\n", cifra);
                printf("                                           A Palavra era: %s\n", palavra);

            }
	  		else{
                system("cls");
                cabecalho();
                            printf("\n                                        ***** Que pena!! ***** \n\n");
            printf("\n                                             ************** Voce Errou a palavra ***************\n");
                printf("                                                 A Chave era : %i\n",chave);
                printf("                                                  A Cifra era: %s\n", cifra);
                printf("                                                A Palavra era: %s\n", palavra);
	  		}

	  }
	  printf("\nGostaria de jogar de novo aperte 1 se nao aperte 0: ");
	  scanf("%i",&denovo);
    }while(denovo != 0);

	return 0;
}













