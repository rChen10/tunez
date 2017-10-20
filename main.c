#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"
int main(){
  //int i;
  //for(i = 0;i < 26;i++){table[i]=NULL;} //init table
	/*add("hats","1");
	add("cats","1");
	add("cookies","1");
	add("fish","2");
	add("fried fish","3");
	add("butter","3");
	add("butter","2");*/
	//print_library();

	struct song_node *head = insert_front(0, "1", "apples");
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
	print_list(head);
	
}
