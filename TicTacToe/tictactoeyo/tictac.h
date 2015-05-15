#ifdef FUNCS
#define FUNCS

void twoPlayers(bool &comp);

bool returnR(string i);

int game(char pla1, char pla2, bool com, string rows[], int &winning);

void start();

void des(int row, int colm, int &t, int &x);

void checker(char one, char two, string row[], bool &oneW, bool &twoW);

#endif
