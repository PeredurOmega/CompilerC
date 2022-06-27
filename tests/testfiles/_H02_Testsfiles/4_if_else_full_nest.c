int main()
{
    int a = 3;
    if (a == 3)
    {
        a = 444;
        if (a == 444)
        {
            a = 445;
            if (a == 445)
            {
                a = 900;
            }
            else
            {
                a = 901;
            }
        }
    }
    else
    {
        a = 555;
    }
    return a;
}
