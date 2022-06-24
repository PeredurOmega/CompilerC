int dontcallme();

int callme(){
    return dontcallme();
}

int main(){
    callme();
}

int dontcallme(){
    return 0;
}