#include <stdio.h>
#include <ctype.h>

int word_count(const char s[]) {
    int count = 0, inside = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            if (inside == 0) {
                count++;
                inside = 1;
            }
        } else {
            inside = 0;
        }
    }

    return count;
}

int is_palindrome(const char s[]) {
    int left = 0, right = 0;

    while (s[right] != '\0')
        right++;

    right--;

    while (left < right) {
        while (left < right && !isalpha((unsigned char)s[left]))
            left++;

        while (left < right && !isalpha((unsigned char)s[right]))
            right--;

        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right]))
            return 0;

        left++;
        right--;
    }

    return 1;
}

int main(void) {
    printf("Words: %d\n",
           word_count("Meet at the library at 5PM"));

    printf("%d\n", is_palindrome("Madam,I'mAdam"));
    printf("%d\n", is_palindrome("Hello"));

    return 0;
}