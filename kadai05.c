#include <stdio.h>

/*

ほとんどのコーナーケースは全部考察をしてincludeしました。

- 入力されたローマ数字が形式に合わないとき
- I, X, Cが４個以上連続するとき ex) VIIII
- V, L, Dが２個以上連続するとき ex) XVV
- I, X, Cなどが２、３個出た後もっと大きい単位のローマ数字が表れるとき ex) IIV
- V, L, Dがもっと大きい単位のローマ数字に前に出るとき　ex) 95 --> VC (x)  XCV (o)

それぞれ該当するエラーメッセージが表示されるようにプログラミングされています。

一応mainのなかにはprintfがあるのでエラーメッセージが表示された後の数字はいったん出ますが、エラーメッセージが表示されていることでローマ表示が間違っていることがわかります。

ローマ表示があっている例を５個と、間違っている例を６個テストしてみました。結果は全部OKでした

*/
int roman2num(char*);

int main() {
    // Examples
    printf("XIV = %d\n", roman2num("XIV")); //14
    printf("CDXCV = %d\n", roman2num("CDXCV")); //495
    printf("MCMXLV = %d\n", roman2num("MCMXLV")); //1945
    printf("XCV = %d\n", roman2num("XCV")); //95
    printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX")); //3999
    //Wrong Examples
    printf("XXXX = %d\n", roman2num("XXXX")); //40
    printf("XVV = %d\n", roman2num("XVV")); //20
    printf("VC = %d\n", roman2num("VC")); //95
    printf("ZII = %d \n", roman2num("ZII")); //A is not a roman numeral
    printf("IIX = %d \n", roman2num("IIX")); //Roman numeral not written in the correct format
    printf("IIXXXXVIVA = %d \n", roman2num("IIXXXXVIVA")); //複数のエラーがあれば複数のエラーメッセージを示す
    return 0;
}

int roman2num(char *s) { 
    int c = 0; //for pointer
    int value = 0; // computes the value of the roman number

    
    while (*(s+c) != '\0') {
        //check to see if alphabet used are all letters used for roman numerals. If not, then will return a statement saying it is not a roman numeral.
        if (*(s+c) != 'I' && *(s+c) != 'V' && *(s+c) != 'X' && *(s+c) != 'L' && *(s+c) != 'C' && *(s+c) != 'D' && *(s+c) != 'M'){
            printf("\x1b[41m");
            printf("your input %c is not a roman numeral. Make sure that all your alphabets are all roman numerals and capitalized. \n", *(s+c));
            printf("\x1b[40m");
            ++c;
        }

        else if (*(s+c) == 'I') {
            if (*(s+c+1) == 'X' ||*(s+c+1) == 'V' ||*(s+c+1) == 'L'|| *(s+c+1) == 'C' || *(s+c+1) == 'D' ||*(s+c+1) == 'M') {
                value -= 1;
            }
            else if (*(s+c) == *(s+c+1) &&  *(s+c) == *(s+c+2) && *(s+c) == *(s+c+3)){
                printf("\x1b[41m");
                printf("There are more than 4 %c in a row in your roman numeral. Please fix your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 1;
            }
            else if (*(s+c) == *(s+c+1) && *(s+c) != *(s+c+2) && *(s+c+2) != '\0') {
                printf("\x1b[41m");
                printf("The roman numeral is not written in the correct format. Please check the [%c] in your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 1;
            }
            else {
                value += 1;
            }
            ++c; 
        }
        else if (*(s+c) == 'X') {
            if (*(s+c+1) == 'L'||*(s+c+1) == 'C' ||*(s+c+1) == 'D' || *(s+c+1) == 'M') {
                value -= 10;
            }
            else if (*(s+c) == *(s+c+1) &&  *(s+c) == *(s+c+2) && *(s+c) == *(s+c+3)){
                printf("\x1b[41m");
                printf("There are more than 4 %c in a row in your roman numeral. Please fix your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 10;
            }
            else if (*(s+c) == *(s+c+1) && *(s+c) != *(s+c+2) && *(s+c+2) != '\0') {
                printf("\x1b[41m");
                printf("The roman numeral is not written in the correct format. Please check the [%c] in your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 10;
            }
            else {
                value += 10;
            }
            ++c; 
        }
        else if (*(s+c) == 'C') {
            if (*(s+c+1) == 'D' ||*(s+c+1) == 'M') {
                value -= 100;
            }
            else if (*(s+c) == *(s+c+1) &&  *(s+c) == *(s+c+2) && *(s+c) == *(s+c+3)){
                printf("\x1b[41m");
                printf("There are more than 4 %c in a row in your roman numeral. Please fix your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 100;
            }
            else if (*(s+c) == *(s+c+1) && *(s+c) != *(s+c+2) && *(s+c+2) != '\0') {
                printf("\x1b[41m");
                printf("The roman numeral is not written in the correct format. Please check the [%c] in your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 100;
            }
            else {
                value += 100;
            }
            ++c; 
        }
        else if (*(s+c) == 'V') {
            if (*(s+c) == *(s+c+1)) {
                printf("\x1b[41m");
                printf("There are more than 2 %c in a row in your roman numeral. Please fix your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 5;
            }
            else if (*(s+c+1) == 'X'||*(s+c+1) == 'L'||*(s+c+1) == 'C'||*(s+c+1) == 'D'||*(s+c+1) == 'M') {
                printf("\x1b[41m");
                printf("%c should not come in front of %c. Please check your roman numeral \n", *(s+c), *(s+c+1));
                printf("\x1b[40m");
                value +=5;
            }
            else {
                value += 5;
            }
            ++c;
        }
        else if (*(s+c) == 'L') {
            if (*(s+c) == *(s+c+1)) {
                printf("\x1b[41m");
                printf("There are more than 2 %c in a row in your roman numeral. Please fix your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 50;
            }
            else if (*(s+c+1) == 'C'||*(s+c+1) == 'D'||*(s+c+1) == 'M') {
                printf("\x1b[41m");
                printf("%c should not come in front of %c. Please check your roman numeral \n", *(s+c), *(s+c+1));
                printf("\x1b[40m");
                value +=50;
            }
            else {
                value += 50;
            }
            ++c;
        }
        else if (*(s+c) == 'D') {
            if (*(s+c) == *(s+c+1)) {
                printf("\x1b[41m");
                printf("There are more than 2 %c in a row in your roman numeral. Please fix your roman numeral \n", *(s+c));
                printf("\x1b[40m");
                value += 500;
            }
            else if (*(s+c+1) == 'M') {
                printf("\x1b[41m");
                printf("%c should not come in front of %c. Please check your roman numeral \n", *(s+c), *(s+c+1));
                printf("\x1b[40m");
                value +=500;
            }
            else {
                value += 500;
            }
            ++c;
        }
        else if (*(s+c) == 'M') {
            value += 1000;
            ++c;
        }
    }
    return value;
}