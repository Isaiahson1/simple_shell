#ifndef SHELL_H
#define SHELL_H

/**##### MACROS #####*/

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/**#### Libraries Used ####*/

typedef struct bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <signal.h>
#include <linux/limits.h>

/*## environ var ##*/

extern char **environ;

/*shell.c*/
int check_builtin(char **cmd);
void create_env(char **env);

/*Execute Prototypes*/
void signal_to_handle(int sig);
int check_command(char **cmd, char *input, int c, char **argv);
int handle_builtin_cmds(char **cmd, int er);
void read_file(char *filename, char **argv);
void treat_file(char *line, int counter, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/*Builtin prototypes*/
void exit_bul(char **cmd, char *input, char **argv, int c);
int change_dir(char **cmd, __attribute__((unused))int er);
int disp_env(__attribute__((unused)) char **cmd, __attribute((unused))int er);
/*Help.c*/
int display_help(char **cmd, __attribute__((unused))int er);
int echo_bul(char **cmd, int st);
/*_strtok*/
unsigned int check_delimeter(char c, const char *str);
char *_strtok(char *str, const char *delim);

/*Parse.c*/
char **parse_cmd(char *input);
/*char_func.c*/
int _putchar( char c);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _atoi(char *str);
void _puts(char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _isalpha(int c);
char *_itoa(unsigned int n);
void array_rev(char *arr, int len);
int intlen(int num);
int _strcmp(char *s1,char *s2);

/*Custom error*/
void _prerror(char **argv, int c, char **cmd);

/*Path.c*/
int path_cmd(char **cmd);
char *build(char *token, char *value);
char *_getenv(char *name);
/*_getline.c*/
char *_getline();
void hashtag_handler(char *buff);
/*other_bul*/
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int s);
int print_echo(char **cmd);
/*hist.c)*/
int history(char *input);
void free_env(char **env);
/*memory*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **cmd, char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);
void *_calloc(unsigned int size);
/*print_number*/
void print_number(unsigned int n);
void print_number_in(int n);
/*prompt.c*/
void prompt(void);
void print_error(char *input, int counter, char **argv);
/*user.input*/
void read_command(char *command, size_t size);


#endif /*SHELL_H*/

