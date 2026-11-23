#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 256
#define LOG_FILE "log.txt"
void remove_newline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}
int append_log(const char *filename, const char *message)
{
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("log.txt ni yozish uchun ochib bo'lmadi");
        return -1;
    }
    time_t now = time(NULL);
    char timestr[64];
    strncpy(timestr, ctime(&now), sizeof(timestr) - 1);
    timestr[sizeof(timestr) - 1] = '\0';
    remove_newline(timestr);
    fprintf(fp, "[%s] %s\n", timestr, message);
    fclose(fp);
    return 0;
}
int print_file(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("log.txt ni o'qish uchun ochib bo'lmadi");
        return -1;
    }
    char line[MAX];
    int n = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        n++;
    }
    printf("--- Jami %d ta qator ---\n", n);
    fclose(fp);
    return 0;
}
int main(void)
{
    char message[MAX];
    printf("Xabarni kiriting: ");
    if (fgets(message, sizeof(message), stdin) == NULL) {
        printf("Xabar o'qilmadi.\n");
        return 1;
    }
    remove_newline(message);
    if (append_log(LOG_FILE, message) != 0) {
        return 1;
    }
    printf("Xabar %s ga qo'shildi.\n\n", LOG_FILE);
    printf("===== %s mazmuni =====\n", LOG_FILE);
    if (print_file(LOG_FILE) != 0) {
        return 1;
    }
    return 0;
}
