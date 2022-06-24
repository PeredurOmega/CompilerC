char chiffre_char(int chiffre){
    if(chiffre==1)
        return "1";
    else if(chiffre==2)
        return "2";
    else if(chiffre==3)
        return "3";
    else if(chiffre==4)
        return "4";
    else if(chiffre==5)
        return "5";
    else if(chiffre==6)
        return "6";
    else if(chiffre==7)
        return "7";
    else if(chiffre==8)
        return "8";
    else if(chiffre==9)
        return "9";
    else
        return "0";
}

int main(){
    return chiffre_char(5);
}