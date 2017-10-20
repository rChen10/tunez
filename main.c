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
	add("cats","edmond");
	add("bats","ricky");
	add("cheese","tom");
	add("dogs","edmond");
	add("fried fish","steve");
	add("butter","bob");
	add("butter","ricky");
	print_library();\
	printf("--------------------\n");
	shuffle(3);
/*
	struct song_node *head = insert_front(0, "apples", "1");
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
	print_list(head);*/
}
