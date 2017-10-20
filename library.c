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
  struct song_node *to_add = table[new_artist[0] - 97];
  if (new_artist[0] > to_add->artist[0]){
    table[new_artist[0] - 97] = insert_order(to_add, new_name, new_artist);
  }
  else if (new_artist[0] == to_add->artist[0] &&
      new_name[0] > to_add->name[0]){
    table[new_artist[0] - 97] = insert_order(to_add, new_name, new_artist);
  }
  else{
    insert_order(to_add, new_name, new_artist);
  }
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
	for(i = 0; i < number_of_songs; i++){
		selection = rand() % total_length;
		selected = table_index(selection);
		head = insert_front(NULL,selected->name,selected->artist);
	}
	print_list(head);
	free_list(head);
}
