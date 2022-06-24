int main(){
    int a  = 2;
    {
        int  a = 4;
        return a;
    }
    return a;
}