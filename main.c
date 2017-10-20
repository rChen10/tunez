#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"

int main(){
    srand(time(NULL));
  struct song_node *Q = insert_front(0, "the man who sold the world", "david bowie");
  insert_order(Q, "brighton rock", "queen");
  insert_order(Q, "good company", "queen");
  insert_order(Q, "wish you were here", "pink floyd");
  insert_order(Q, "the man who sold the world", "nirvana");
  insert_order(Q, "comfortably numb", "pink floyd");
  
  printf("LINKED LIST TESTS\n");
  printf("=====================\n");
  printf("Testing print_list:\n");
  print_list(Q);
  
  printf("=====================\n");
  printf("Testing print_node:\n");
  print_node(Q);
  
  printf("=====================\n");
  printf("Testing lfind_sa (list find song artist):\n");
  printf("Looking for [pink floyd | wish you were here]:\n");
  print_node(lfind_sa(Q, "wish you were here", "pink floyd"));
  
  printf("=====================\n");
  printf("Testing lfind_a (list find artist):\n");
  printf("Looking for [pink floyd]:\n");
  print_list(lfind_a(Q, "pink floyd"));
  
  printf("=====================\n");
  printf("Testing lfind_random:\n");
  print_node(lfind_random(Q));
  

  printf("=====================\n");
  printf("Testing lremove:\n");
  printf("Removing [queen | brighton rock]:\n");
  lremove(Q, "brighton rock", "queen");
  print_list(Q);
  printf("Removing [nirvana | the man who sold the world]:\n");
  lremove(Q, "the man who sold the world", "nirvana");
  print_list(Q);
  printf("Removing [pink floyd | wish you were here]:\n");
  lremove(Q, "wish you were here", "pink floyd");
  print_list(Q);
  
  printf("=====================\n");
  printf("testing free_list\n");
  free_list(Q);
  printf("list after being free:\n");
  printf("%s\n", *Q);

  
  printf("=====================\n");
  printf("MUSIC LIBRARY TEST\n");
  printf("=====================\n");

  int i;
  for(i = 0; i < 26;i++){
	list_lengths[i] = 0;
	table[i] = NULL;
  }
  add("the man who sold the world", "david bowie");
  add("brighton rock", "queen");
  add("good company", "queen");
  add("wish you were here", "pink floyd");
  add("the man who sold the world", "nirvana");
  add("comfortably numb", "pink floyd");
  printf("Printing library\n");
  print_library();
  printf("=====================\n");
  printf("Printing \"p\" section\n");
  print_column('p');
  printf("=====================\n");
  printf("Testing shuffle(3): should return 3 random songs\n");
  shuffle(3);
  printf("=====================\n");
  printf("Testing print all songs by queen\n");
  print_library_artist("queen");
  printf("Testing free all nodes\n");
  free_all_nodes();
  for(i = 0; i < 26;i++){
  	printf("%p ",table[i]);
  }
  
  printf("\n=====================\n");
}
