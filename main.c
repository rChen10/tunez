#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"
int main(){
	struct song_node * head = insert_front(NULL,"hats","1");
	head = insert_front(head,"cats","1");
	head = insert_front(head,"cookies","1");
	head = insert_front(head,"fish","2");
	head = insert_front(head,"fried fish","3");
	head = insert_front(head,"butter","3");
	head = insert_front(head,"butter","2");
	lremove(head,"fried fish","3");
	print_list(head);
}
