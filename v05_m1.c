#include <stdio.h>
#include <string.h>
#define MAX 256
void remove_newline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}
int count_char(const char *s, char c)
{
    int count = 0;
    const char *p = strchr(s, c);
    while (p != NULL) {
        count++;
        p = strchr(p + 1, c);
    }
    return count;
}
int first_position(const char *s, char c)
{
    const char *p = strchr(s, c);
    if (p == NULL) {
        return -1;
    }
    return (int)(p - s);
}
int main(void)
{
    char str[MAX];
    char buf[MAX];
    char c;
    printf("Satrni kiriting: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Satr o'qilmadi.\n");
        return 1;
    }
    remove_newline(str);
    printf("Belgini kiriting: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '\n' || buf[0] == '\0') {
        printf("Belgi kiritilmadi.\n");
        return 1;
    }
    c = buf[0];
    int count = count_char(str, c);
    int pos = first_position(str, c);
    printf("\nSatr: \"%s\"\n", str);
    printf("Belgi: '%c'\n", c);
    if (pos == -1) {
        printf("'%c' belgisi satrda uchramadi.\n", c);
    } else {
        printf("Uchrashlar soni: %d\n", count);
        printf("Birinchi pozitsiya: %d (indeks 0 dan), ya'ni %d-belgi\n", pos, pos + 1);
    }
    return 0;
}
