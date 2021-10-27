#include <stdio.h>
#include <string.h>

void uppercase(char *s);

int main() {
    char s[] = "Hello world, OnLy ChAnGe The lower CasE";
    uppercase(s);
    printf("%s\n",s);
    return 0;
}

void uppercase(char *s) {
    int c = 0;
    while(*(s+c) != '\0') { 
        if (*(s+c) >= 'a' && *(s+c)<='z') {
            *(s+c) = *(s+c) - 32;
        }
    ++c;
    }
}
