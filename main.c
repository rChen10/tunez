#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"
int main(){
  struct song_node *Q = insert_front(0, "brighton rock", "queen");
  insert_order(Q, "good company", "queen");
  insert_order(Q, "wish you were here", "pink floyd");
  insert_order(Q, "the man who sold the world", "david bowie");
  insert_order(Q, "the man who sold the world", "nirvana");
  insert_order(Q, "comfortably numb", "pink floyd");
  
  printf("LINKED LIST TESTS\n");
  printf("=====================\n");
  printf("Testing print_list:\n");
  print_list(Q);
	
}
