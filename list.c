#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void print_list(struct song_node * list){
  printf("\t%s | %s\n",list->artist,list->name);
  if(list->next){
    print_list(list->next);
  }
  else{
    printf("\n");
  }
}

void print_node(struct song_node * list){
  printf("\t%s | %s\n",list->artist,list->name);
}

struct song_node *insert_front(struct song_node * list,char new_name[],char new_artist[]){
  struct song_node * new_node = (struct song_node  *)malloc(sizeof(struct song_node));
  strcpy(new_node->name, new_name);
  strcpy(new_node->artist, new_artist);
  new_node->next = list;
  return new_node;
}

struct song_node *insert_order(struct song_node * list,char new_name[],char new_artist[]){
  if (list->next){
    if (strcmp(list->next->artist, new_artist) >= 0)
      {if  (strcmp(list->next->artist, new_artist) == 0 &&
	      strcmp(list->next->name, new_name) <= 0) {
	  return insert_order(list->next, new_name, new_artist);
	}
	else{
	  struct song_node * new_node = (struct song_node  *)malloc(sizeof(struct song_node));
	  strcpy(new_node->name, new_name);
	  strcpy(new_node->artist, new_artist);
	  new_node->next = list->next;
	  list->next = new_node;
	  return new_node;
	}
      }
    
    else{
      return insert_order(list->next, new_name, new_artist);
    }
  }
  else{
    struct song_node * new_node = (struct song_node  *)malloc(sizeof(struct song_node));
    strcpy(new_node->name, new_name);
    strcpy(new_node->artist, new_artist);
    new_node->next = 0;
    list->next = new_node;
    return new_node;
  }
}

struct song_node *lfind_sa(struct song_node *list, char *ssong, char *sartist){
  if (! (strcmp(list->artist, sartist)) &&
      ! (strcmp(list->name, ssong))){
    return list;
  }
  else if (! list->next){
    return 0;
  }
  else{
    lfind_sa(list->next, ssong, sartist);
  }
}

struct song_node *lfind_a(struct song_node *list, char *sartist){
  if (! (strcmp(list->artist, sartist))){
    return list;
  }
  else if (! list->next){
    return 0;
  }
  else{
    lfind_a(list->next, sartist);
  }
}
struct song_node *lfind_s(struct song_node *list,char *ssong){
 if(! (strcmp(list->name,ssong))){
   return list;
 }
 else if (! list->name){
   return 0;
 }
 else{
   lfind_s(list->next, ssong);
 }
}

void *lremove(struct song_node *list, char *rsong, char *rartist){
  struct song_node *dummy;
  while (list){
    if (! (strcmp(list->artist, rartist)) &&
	! (strcmp(list->name, rsong))){
      break;
    }
    dummy = list;
    list = list->next;
  }
  if (list){
    dummy->next = list->next;
    free(list);
  }
}

struct song_node *lfind_random(struct song_node *list){
  srand(time(NULL));
  int max = 0;
  int i;
  struct song_node *dummy = list;
  
  while (dummy){
    max++;
    dummy = dummy->next;
      }

  int stop = rand() % max;
  dummy = list;
  for (i = 0; i < stop; i++){
    dummy = dummy->next;
  }
  return dummy;
}

struct song_node * free_list(struct song_node * list){
  if (list->next){
    free_list(list->next);
    free(list);
  }

  return 0;
}
