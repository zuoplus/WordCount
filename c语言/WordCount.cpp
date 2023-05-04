#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_BUF_SIZE 1024

void print_usage()
{
    printf("Usage: WordCount [-c | -w] [input_file_name]\n");
}

int count_chars(FILE* fp)
{
    int count = 0;
    int c;

    while ((c = fgetc(fp)) != EOF)
    {
        count++;
    }

    return count;
}

int count_words(FILE* fp)
{
    int count = 0;
    int c;
    int is_word = 0;

    while ((c = fgetc(fp)) != EOF)
    {
        if (isalnum(c))
        {
            if (!is_word)
            {
                is_word = 1;
                count++;
            }
        }
        else
        {
            is_word = 0;
        }
    }

    return count;
}

int main(int argc, char* argv[])
{
    int count = 0;
    char* param = NULL;
    char file_name[MAX_FILE_NAME_LEN];
    FILE* fp = NULL;
    if (argc < 2 || argc > 3)
    {
        print_usage();
        return 1;
    }

    param = argv[1];

    if (strcmp(param, "-c") != 0 && strcmp(param, "-w") != 0)
    {
        print_usage();
        return 1;
    }

    if (argc == 3)
    {
        strncpy(file_name, argv[2], MAX_FILE_NAME_LEN);
    }
    else
    {
        strcpy(file_name, "input.txt");
    }
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open file %s\n", file_name);
        return 1;
    }
    if (strcmp(param, "-c") == 0)
    {
        count = count_chars(fp);
        printf("×Ö·ûÊý: %d\n", count);
    }
    else
    {
        count = count_words(fp);
        printf("µ¥´ÊÊý: %d\n", count);
    }
    fclose(fp);
    return 0;
}
