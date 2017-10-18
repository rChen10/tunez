#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_list(struct song_node * list){
	printf("\t%s | %s\n",list->name,list->artist);
	if(list->next){
		print_list(list->next);
	}
	else{
		printf("\n");
	}
}

struct song_node *insert_front(struct song_node * list,char new_name[],char new_artist[]){
	struct song_node * new_node = (struct song_node  *)malloc(sizeof(struct song_node));
	strcpy(new_node->name, new_name);
	strcpy(new_node->artist, new_artist);
	new_node->next = list;
	return new_node;
}

struct song_node * free_list(struct song_node * list){
  if (list->next){
    freelist(list->next);
    free(list);
  }
  
}
