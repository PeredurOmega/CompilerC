int main()
{
    int a = 3;
    int b = 5;
    if (a == 4)
    {
      a = 444;
    }
    else if (a == 3)
    {
        a = 555;
    }
    else if (a == 2)
    {
        a = 777;
    }
    else
    {
        if (1 == 0) 
        {
            a = 2;
        } else if (1 == 1) 
        {
            a = 667;
        }
    }
    
    if (b != 5)
    {
        b = 3;
    }
    else 
    {
        b = 4;
    }
    return a + b;
}
