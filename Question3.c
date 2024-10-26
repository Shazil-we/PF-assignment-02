#include <stdio.h>
#include <string.h>
int main(){
  int len ,j=0 , inputamount;
  printf("How many words do you want to input?");
  scanf("%d" , &inputamount);
  char inputs[inputamount][200];
  char answer[inputamount][200];
  for(int i=0; i<inputamount; i++){
    printf("\nenter word number %d: " , i+1);
    scanf("%s" , &inputs[i]); 
  }
  for(int k=0; k<inputamount; k++){
    for(int i=0; i<strlen(inputs[k]); i++){
      if(inputs[k][i] != inputs[k][i+1]){
        answer[k][j] = inputs[k][i];
        j++;
      }
    }
    answer[k][j] = '\0';
    j=0;
    printf("\"%s\"," , answer[k]);
  }
}