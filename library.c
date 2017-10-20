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
  if (!to_add // it's null
      || new_artist[0] > to_add->artist[0] //it's in front of first artist
      || (new_artist[0] == to_add->artist[0] && //it's in front of first song
	  new_name[0] > to_add->name[0])){
    struct song_node *new_front =  insert_front(to_add, new_name, new_artist);
    table[new_artist[0] - 97] = new_front;
    list_lengths[new_artist[0] - 97]++;
    return new_front;
  }

  else{
    list_lengths[new_artist[0] - 97]++;
    return insert_order(to_add, new_name, new_artist);
  }
}

void print_library(){
  int i;
  for(i = 0;i < 26;i++){
    if(table[i]){
      printf("%c\n", i + 65);
      print_list(table[i]);
    }
  }
}
void print_library_artist(char*artist){
	int i;
	for(i = 0; i <26;i++){if(table[i]){
	    print_list_artist(table[i],artist);}}
}
void print_column(char a){
	print_list(table[tolower(a)-'a']);
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
void free_all_nodes(){
	int i;
	for(i = 0; i<26;i++){
		if(table[i]){
			free_list(table[i]);
			table[i] = NULL;
		}
	}
}
