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

	struct song_node *head = insert_front(0, "apples", "1");
	insert_order(head,"hats","1");
	insert_order(head,"cats","1");
	insert_order(head,"cookies","1");
	insert_order(head,"fish","2");
	insert_order(head,"fried fish","3");
	insert_order(head,"butter","3");
	insert_order(head,"butter","2");
	print_list(head);
	
}
