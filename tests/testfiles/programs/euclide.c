int euclide(int a, int b){
    if (b == 0){
        return a;
    }
    else {
        return euclide(b, a%b);
    }
}

int main(){
    int a = 21;
    int b = 15;
    return euclide(a, b);
}