int main()
{
    int a = 3;
    {
        if (a != 3) {
            a = 5;
        }    
    }
    return a;
}