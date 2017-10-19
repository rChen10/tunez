struct song_node * table[26];
struct song_node *add(char *new_name, char *new_artist);
struct song_node *search_sa(char *new_name, char *new_artist);
struct song_node *search_a(char *new_artist);
void print_letter(char letter);
void print_artist(char *new_artist);
void print_lib();
void shuffle();
void  remove_song(char *song_name);
void clear();





