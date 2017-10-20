#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "list.h"
#include <ctype.h>

char * str_lower(char * p){
	for ( ; *p; ++p) *p = tolower(*p);
	return p;
}

struct song_node* add(char *new_name, char *new_artist){
	char name[strlen(new_name)];
	strcpy(name,new_name);
	struct song_node * list = table[name[0]-97];
	if(list == NULL){
		table[name[0]-97] = insert_front(NULL,new_name,new_artist);
		return table[name[0]-97];
	}
	struct song_node * prev = NULL;
	char * temp;
	while(strcmp(name,temp = str_lower(strcpy((char *)malloc(strlen(list->name)),list->name)))>0){
		prev = list;
		list = list->next;
		if(list == NULL){
			break;
		}
		free(temp);
	}
	free(temp);
	struct song_node * new_node = insert_front(list,new_name,new_artist);
	prev->next = new_node;
	return new_node;
}
