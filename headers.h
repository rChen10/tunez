struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * table[26];



