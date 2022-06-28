// Not Implemented
int main(){
    int taille = 5;
    int tab[taille];
    int cpt, i = 0;
    tab[0] = 0;
    tab[1] = 1;
    tab[2] = 2;
    tab[3] = 3;
    tab[4] = 4;
    while (i != taille){
        cpt = cpt + tab[i];
        i = i + 1;
    }
    return cpt;
}