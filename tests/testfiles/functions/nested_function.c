int timesto(int value){
    return value*2;
}

int main(){
    int a = 3, b = 4, c = 5;
    return timesto(a)* timesto(b)* timesto(c);
}