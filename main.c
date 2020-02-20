#include <stdio.h>
#include<string.h>
#include<stdlib.h>


  char nome1[20];
  char nome2[20];
  int x,y;
  char sequencia[20][20];
  int matriz[20][20];
  int i,j;

 void imprimir(int k, int l){
       if(k==0 || l==0)
          return;
                if(sequencia[k][l]=='c'){
                  imprimir(k-1,l-1);
                  printf("%c",nome1[k-1]);
                }else if(sequencia[k][l]=='u'){
                    imprimir(k-1,l);
                }
                else{
                  imprimir(k,l-1);
                }
  }
  
  void lcs(){
  x=strlen(nome1) ;
  y=strlen(nome2) ;


     for(i=0;i<=x;i++){
 		matriz[i][0]=0;
 	}
    
    for(i=0;i<=y;i++){
    	matriz[0][i]=0;
	}
        
    //aqui que o preenchimento da matriz acontece

    for(i=1;i<=x;i++){
      for(j=1;j<=y;j++){
        if(nome1[i-1]==nome2[j-1]){
           matriz[i][j]= matriz[i-1][j-1] + 1 ;
            sequencia[i][j]='c';
        }else if(matriz[i-1][j]>=matriz[i][j-1]){
            matriz[i][j]=matriz[i-1][j];
            sequencia[i][j]='u';
        }else{
            matriz[i][j]=matriz[i][j-1];
            sequencia[i][j]='l';
         }
      }
    }
  }

 
int main(void) {

  printf("Digite a primeira palavra: ");
  scanf("%s",nome1);

  printf("Digite a segunda palavra: ");
  scanf("%s",nome2);
  printf("\n");
  printf("A subsequencia maxima eh: ");
  lcs();
  imprimir(x,y);
  
}