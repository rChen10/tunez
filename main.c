#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"

int main(){
<<<<<<< HEAD
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
	
=======
	srand(time(NULL));//seed rng
	int i;
	for(i = 0;i < 26;i++){list_lengths[i] = 0;}
  for(i = 0;i < 26;i++){table[i]=NULL;} //init table
	add("hats","1");
	add("cats","1");
	add("cookies","1");
	add("fish","2");
	add("fried fish","3");
	add("butter","3");
	add("butter","2");
	print_library();\
	printf("--------------------\n");
	shuffle(3);

	/*struct song_node *head = insert_front(0, "apples", "1");
	print_list(head);
	insert_order(head,"1","hats");
	print_list(head);
	insert_order(head,"1","cats");
	print_list(head);
	insert_order(head,"1","cookies");
	print_list(head);
	insert_order(head,"2","cookies");
	print_list(head);
	insert_order(head,"3","fried fish");
	print_list(head);
	insert_order(head,"3","butter");
	print_list(head);
	insert_order(head,"2","butter");
	print_list(head);
	lremove(head, "1", "cats");
	print_list(head);
>>>>>>> ac07d88e34c9068b40870db5ed9988c110f5b6a9
}
