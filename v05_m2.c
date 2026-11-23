#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 256
void remove_newline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}
void remove_spaces(char *s)
{
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (!isspace((unsigned char)s[i])) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}
int main(void)
{
    char str[MAX];
    printf("Satrni kiriting: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Satr o'qilmadi.\n");
        return 1;
    }
    remove_newline(str);
    printf("Oldin : \"%s\" (uzunligi %zu)\n", str, strlen(str));
    remove_spaces(str);
    printf("Keyin : \"%s\" (uzunligi %zu)\n", str, strlen(str));
    return 0;
}
