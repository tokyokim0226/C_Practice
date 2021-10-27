#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main() {
    char s[] = "My name is";
    printf("%s\n",s);
    reverse(s);
    printf("%s\n",s); // 出力䛿"olleh"
    return 0;
}

void reverse(char *s){
    for (int i = 0; i < strlen(s)/2; i++){
        int temp = *(s+strlen(s)-1-i);
        *(s+strlen(s)-1-i) = *(s+i);
        *(s+i) = temp;
    }
}