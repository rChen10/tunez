#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "list.h"
#include <ctype.h>

void str_lower(char * p){
	for ( ; *p; p++){ *p = tolower(*p);}
}

struct song_node* add(char *new_name, char *new_artist){
	char artist[strlen(new_artist)];
	strcpy(artist,new_artist);
	struct song_node * list = table[artist[0]-97];
	if(!list){
		table[artist[0]-97] = insert_front(NULL,new_name,new_artist);
		list_lengths[artist[0]-97]++;
		return table[artist[0]-97];
	}
	struct song_node * prev = NULL;
	char * temp;
	str_lower(temp = strcpy((char *)malloc(strlen(list->artist)),list->artist));
	while(strcmp(artist,temp)>=0){
		prev = list;
		list = list->next;
		if(list == NULL){
			break;
		}
		free(temp);
		str_lower(temp = strcpy((char *)malloc(strlen(list->artist)),list->artist));
	}
	free(temp);
	struct song_node * new_node = insert_front(list,new_name,new_artist);
	prev->next = new_node;
	list_lengths[artist[0]-97]++;
	return new_node;
}

void print_library(){
	int i;
	for(i = 0;i < 26;i++){if(table[i]){print_list(table[i]);}}
}
void print_column(char a){
	print_list(table[tolower(a)-97]);
}
struct song_node * table_index(int selection){
	int i;
	int total = 0;
	for(i = 0; i < 26; i++){
		total += list_lengths[i];
		if(selection < total){
			break;
		}
	}
	selection -= (total - list_lengths[i]);
	struct song_node * list = table[i];
	while(selection--){
		list = list->next;
	}
	return list;
}
void shuffle(int number_of_songs){
	int total_length = 0;
	int i;
	for(i = 0; i < 26; i++){total_length += list_lengths[i];}
	int selection;
	struct song_node * head = NULL;
	struct song_node * selected;
	if(number_of_songs < 0){
		number_of_songs = total_length;
	}
	int table_indexes[number_of_songs];
	int i2;
	for(i = 0; i < number_of_songs; i++){table_indexes[i] = 0;}
	for(i = 0; i < number_of_songs; i++){
		selection = rand() % total_length;
		table_indexes[i] = selection;
		for(i2 = 0; i2 < i; i2++){
			if(selection == table_indexes[i2]){
				if(selection == total_length - 1){
					selection = 0;
				}
				else{
					selection++;
				}
				i2--;
			}
		}
		selected = table_index(selection);
		head = insert_front(head,selected->name,selected->artist);
	}
	print_list(head);
	free_list(head);
}
