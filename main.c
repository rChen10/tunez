<<<<<<< HEAD
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"

int main(){
  struct song_node *Q = insert_front(0, "the man who sold the world", "david bowie");
  insert_order(Q, "brighton rock", "queen");
  insert_order(Q, "good company", "queen");
  insert_order(Q, "wish you were here", "pink floyd");
  insert_order(Q, "the man who sold the world", "nirvana");
  insert_order(Q, "comfortably numb", "pink floyd");
  
  printf("LINKED LIST TESTS\n");
  printf("=====================\n");
  printf("Testing print_list:\n");
  print_list(Q);
  
  printf("=====================\n");
  printf("Testing print_node:\n");
  print_node(Q);
  
  printf("=====================\n");
  printf("Testing lfind_sa (list find song artist):\n");
  printf("Looking for [pink floyd | wish you were here]:\n");
  print_node(lfind_sa(Q, "wish you were here", "pink floyd"));
  
  printf("=====================\n");
  printf("Testing lfind_a (list find artist):\n");
  printf("Looking for [pink floyd]:\n");
  print_list(lfind_a(Q, "pink floyd"));
  
  printf("=====================\n");
  printf("Testing lfind_random:\n");
  print_node(lfind_random(Q));
  

  printf("=====================\n");
  printf("Testing lremove:\n");
  printf("Removing [queen | brighton rock]:\n");
  lremove(Q, "brighton rock", "queen");
  print_list(Q);
  printf("Removing [nirvana | the man who sold the world]:\n");
  lremove(Q, "the man who sold the world", "nirvana");
  print_list(Q);
  printf("Removing [pink floyd | wish you were here]:\n");
  lremove(Q, "wish you were here", "pink floyd");
  print_list(Q);
  
  printf("=====================\n");
  printf("testing free_list\n");
  free_list(Q);
  printf("list after being free:\n");
  printf("%s", *Q);

  
  printf("=====================\n");
  printf("MUSIC LIBRARY TEST\n");
  printf("=====================\n");
}
=======
<<<<<<< HEAD
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"

int main(){
	srand(time(NULL));//seed rng
	int i;
	for(i = 0;i < 26;i++){list_lengths[i] = 0;}
	for(i = 0;i < 26;i++){table[i]=NULL;} //init table
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
>>>>>>> 7feb1feb0cbc2ff2a0bd4b4d11482886cf6b5d7b
>>>>>>> 131b9899942fc70545f01c0c52ec04782d5d4bce
