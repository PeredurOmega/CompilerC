// Not Implemented

int main() {
    char s1[100] = {'B', 'o', 'n', 'j', 'o', 'u', 'r',',',' ','j','e',' ','s','u','i','s',' ','h','e','u','r','e','u','x',' ',':',')', '\0'};
    char s2[100], i;

    for (i = 0; s1[i] != '\0'; i = i + 1) {
        s2[i] = s1[i];
    }

    int ret = 0;
    for (i = 0; s2[i] != '\0'; i = i + 1) {
        ret = ret + s2[i];
    }

    s2[i] = '\0';
    return ret;
}
