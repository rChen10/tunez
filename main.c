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
