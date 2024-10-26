#include <stdio.h>
int main(){
  int arr[5], smallest, sec_smallest;
  for(int i=0; i<5; i++){
    printf("\nelement - %d: " , i+1);
    scanf("%d" , &arr[i]);
  }
  smallest = arr[0];
  sec_smallest = arr[0];
  for(int i=0; i<5; i++){
    if(arr[i] < smallest){
      smallest = arr[i];
    }else{}
  }
  for(int i=0; i<5; i++){
    if(arr[i] < sec_smallest && sec_smallest > smallest && smallest != arr[i]){
      sec_smallest = arr[i];
    }else{}
  }
  printf("The second smallest element is %d" , sec_smallest);
}