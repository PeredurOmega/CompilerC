//$not_implemented
// Test fails because we don't implement int a = b = 128; in the expression visitor
#include <inttypes.h>
int main()
{
    int b;
    int a = b = 128;
    return a;
}