#include<stdio.h>
#include<stdlib.h>
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

struct song_node * insert_front(struct song_node * list,char new_name[],char new_artist[]){
	struct song_node * new_node = (struct song_node  *)malloc(sizeof(struct song_node));
	char * zname = (char *)malloc(sizeof(new_name));
	zname = new_name;
	char * zartist = (char *)malloc(sizeof(new_artist));
	zartist = new_artist;
	new_node->name = zname;
	new_node->artist = zartist;
	new_node->next = list;
	return new_node;
}
struct song_node * free_list(struct song_node * list){
	struct song_node * temp;
	while(list->next){
		temp = list->next;
		free(list);
		list = temp;
	}
	free(list->next);
	free(list);
	return list;
}
