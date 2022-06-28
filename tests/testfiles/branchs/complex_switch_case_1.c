// Not Implemented
int main(){
    int a = 42;
    int b = 42;
    int n = 0;
    int m = 0;
    switch (a) {
        case 1:
            switch (b) {
                case 1:
                    m = 1;
                    break;
                case 2:
                    m = 2;
                    break;
                case 42:
                    m = 3;
                    break;
            }
            n = 1;
            break;

        case 2:
            switch (b) {
                case 1:
                    m = 1;
                    break;
                case 2:
                    m = 2;
                    break;
                case 42:
                    m = 3;
                    break;
            }
            n = 2;
            break;

        case 42:
            switch (b) {

                case 1:
                    m = 1;
                    break;

                case 2:
                    m = 2;
                    break;

                case 42:
                    m = 3;
                    break;

            }
            n = 3;
            break;

    }

    return n*m;
}