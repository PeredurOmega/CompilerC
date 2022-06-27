int main(){
    int taille = 5;
    int tab[taille];
    int cpt, i = 0;
    while (i != taille){
        tab[i] = 0;
        i = i + 1;
    }
    i = 0;
    while (i != taille){
        cpt = cpt + tab[i];
        i = i + 1;
    }
    return cpt;
}