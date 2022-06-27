int main()
{
    int a = 0;
    if (a == 0)
    {
        while (a < 10)
        {
            if (a == 5)
            {
                a = a+10;
            }
            a = a + 1;
        }
    } else if(a == 1) {
        a = a + 10;
    } else {
        a = -2;
    }
    return a;
}