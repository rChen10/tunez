struct song_node{
	char name[256];
	char artist[256];
	struct song_node * next;
};

void print_list(struct song_node*);
void print_node(struct song_node * list);
struct song_node *insert_front(struct song_node *, char*, char*);
struct song_node *insert_order(struct song_node *, char*, char*);
struct song_node *lfind_sa(struct song_node*, char*, char*);
struct song_node *lfind_a(struct song_node *,char*);
struct song_node *lfind_random();
void *lremove(struct song_node *, char*, char*);
struct song_node *free_list(struct song_node *);
