#include <stdio.h>
#include <string.h>

int palindrome(char word[]) {
    int i = 0;
    int j = strlen(word) - 1;
    while (i < j) {
        if (word[i] != word[j]) {
            return -1;
        }
        i++;
        j--;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Need a palindrome to test\n");
        return 0;
    }
    int len = strlen(argv[1]);
    printf("The word is %d characters long and is ", len);
    if (palindrome(argv[1])) {
        printf("a palindrome.\n");
    } else {
        printf("not a palindrome.\n");
    }
    return 0;
}
