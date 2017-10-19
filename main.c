#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "library.h"
int main(){
	//table = (struct song_node *)malloc(sizeof(struct song_node)*26);
	add("aa","1");
	add("ab","1");
	add("ac","1");
	print_list(table[0]);
}
