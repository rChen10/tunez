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

struct song_node *insert_order(struct song_node * list,char new_name[],char new_artist[]){
  if (! list->next){
    struct song_node * new_node = (struct song_node  *)malloc(sizeof(struct song_node));
    strcpy(new_node->name, new_name);
    strcpy(new_node->artist, new_artist);
    new_node->next = list;
    return new_node;
  }
  else{
    return insert_order(list->next, new_name, new_artist);
  }
}

struct song_node *lfind_sa(struct song_node *list, char *ssong, char *sartist){
  if (! (strcmp(list->sartist, sartist)) &&
      ! (strcmp(list->ssong, ssong))){
    return list;
  }
  else if (! list->next){
    return 0;
  }
  else{
    lfind_sa(list->next, ssong, sartist);
  }
}

struct song_node *lfind_aa(struct song_node *list, char *sartist){
  if (! (strcmp(list->sartist, sartist))
    return list;
  }
  else if (! list->next){
    return 0;
  }
  else{
    lfind_sa(list->next, sartist);
  }
}

void *lremove(struct song_node *list, char *rsong, char *rartist){
  struct song_node *dummy;
  while (! list){
    if (! (strcmp(list->sartist, sartist)) &&
      ! (strcmp(list->ssong, ssong))){
      break;
    }
    dummy = list;
    list = list->next;
  }
  if (! list){
    dummy->next = list->next;
    free(list);
  }
}

struct song_node * free_list(struct song_node * list){
  if (list->next){
    free_list(list->next);
    free(list);
  }

  return 0;
}
