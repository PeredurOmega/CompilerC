int squared(int value){
    return value*value;
}

int times2(int value){
    return value*2;
}

int main(){
    int i = 0, nb = 21;

    while(i<nb){
        if(times2(squared(i))!=(i*i*2)){
            return 0;
        }
    }

    return 1;
}