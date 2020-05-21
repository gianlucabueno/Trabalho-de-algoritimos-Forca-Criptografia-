/*
                                    Progrma de Jogo da Forca Cripto

                                        Gabrel Bueno       RA 200320
                                        Gianluca Bueno     RA 200318
                                        Leonardo Poveda    RA 

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char cripto(char palavra [500] ){
 

    int chave,tam;
    
    system("clear");
    
    chave = 2;
    tam = strlen(palavra);
    char resposta [tam];
         for(int x=0;x<tam;x++){
             resposta [x] = toupper(palavra[x]);
         }
        
       
        for(int y=0;y<tam;y++){
            
            
    
            int enc=(int)palavra[y]+chave;
                if(enc  > 90){
                resposta[y] = 64 + (enc - 90);
                 }
        }

    return(resposta);
        
      
}    
    
    


int main(){

char palavra [500];

int fimpalavra;

printf("Digite uma palavra: ");
gets(palavra);

fimpalavra = strlen(palavra);
char resposta [fimpalavra];
resposta = cripto(palavra);

printf("%s",palavra);
printf("%s",resposta);

}