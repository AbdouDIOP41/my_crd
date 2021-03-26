#ifndef __MY_ARG__
#define __MY_ARG__


int count_word(const char *str);
char *alloc_word(int *start, int *end, const char *str);
char **my_str_to_word_array(const char *str);
char *my_readline(void);

#endif
