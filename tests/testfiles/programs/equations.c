int delta_int(int a, int b, int c){
    return b*b - 4*a*c;
}


int main(){
    int a = 2, b = 12, c = 9;

    int delta = delta_int(a,b,c);

    if(delta>0){
        return 1;
    }
    else if(delta==0){
        return 0;
    }
    else{
        return -1;
    }
}