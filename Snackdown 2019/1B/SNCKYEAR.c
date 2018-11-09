#include <stdio.h>
#include <stdlib.h>
int main(){
  int i,x,y; 
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&y);
    switch(y){
      case 2010:
      case 2015:
      case 2016:
      case 2017:
      case 2019:
        printf("HOSTED\n");
        break;
      default:
        printf("NOT HOSTED\n");
        break;
    }
  } 
  return 0;
}
