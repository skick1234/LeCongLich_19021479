#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isSumSub(char c) {
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int isMulDiv(char c) {
    if (c == '*' || c == '/')
        return 1;
    return 0;
}

int isMathChar(char c) {
    if (isMulDiv(c) || isSumSub(c))
        return 1;
    return 0;
}

int isValidChar(char c) {
    if (isalnum(c) || isMathChar(c) || c == '(' || c == ')')
        return 1;
    return 0;
}

int main() {
    char str[50];
    gets(str);
    fflush(stdin);
    int i = 0, pre = 0, post = 0, flag = 1;

    while (str[i] != '\0' && flag) {
        if (!isValidChar(str[i]))
            flag = 0;
        else if (str[i] == '(') {
            pre++;
            if (!str[i + 1] || isMulDiv(str[i + 1]) || str[i + 1] == ')') flag = 0;
        } else if (str[i] == ')') {
            post++;
            if (!i || (str[i+1] && !isMathChar(str[i + 1]))) flag = 0;
        } else if (isSumSub(str[i])) {
            if (!str[i + 1] || isMulDiv(str[i + 1]) || str[i + 1] == ')') flag = 0;
        } else if (isMulDiv(str[i])) {
            if (!i || !str[i + 1] || str[i + 1] == ')') flag = 0;
        } else {
            // 3*a = valid, 3a is not valid
            // delete this case a(b) , xy(z) is valid
            if (str[i + 1] && (isalnum(str[i + 1]) || str[i + 1] == '(')) flag = 0;
        }
        i++;
    }
    if (pre != post) flag = 0;
    printf("%d",flag);
    return 0;
}