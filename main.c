#include<stdio.h>
#include"list.h"

int main(){
	char t[] = "a\0";
	char t2[] = "aa\0";
	struct song_node * head = insert_front(NULL,t,t2);
	print_list(head);
	printf("%p\n",free_list(head));
	//printf("%d,%p\n",head->data,head->next);
	print_list(head);
}
