#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */

int space_char(char c){
  if (c == '\t' || c == ' ')
    return 1;
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  if (c == '\t' || c == ' '|| c == '\0')
    return 0;
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */

char *word_start(char *str){
  for (; space_char(*str); str++){ //increment pointer to point to first printable char
  }
  if(*str == '\0')
    return NULL;
  
    return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  while (non_space_char(*word)){
    word++;
  }
  return word;
}

int count_words(char *str){
  int count = 0;
  while (*str!= '\0'){
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *ptr = (char *)malloc((len+1)*sizeof(char));
  int i;
  for (i = 0; i <= len; i++) {
    *(ptr+i) = *inStr;
    inStr++;
  }
  i++;
  *(ptr+i) = 0;
  return ptr;
}

char **tokenize(char *str){
  int count = count_words(str); //the number of words tells us how many pointers to allocate
  char **tokens = (char **)malloc((count+1)*sizeof(char *));  //allocate an array of pointers the size of count
  for (int i = 0; i < count; i++){  //add a pointer to the beginning of each word to the pointer array
    str = word_start(str);
    char *end = word_terminator(str);
    int size = (end - str); //get the number of characters we need to allocate
    *(tokens+i) = copy_str(str, size);
    str = word_terminator(str); //move the pointer so the next word_start call will point to the next word
  }
  tokens[count] = NULL;
  return tokens;
}
void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != NULL; i++){
    printf("tokens[%d] = %s\n", i, tokens[i]);
  }
  printf("\n------------");
}
void free_tokens(char **tokens){

  char *start, *end;

  int count = count_words(*tokens);
  for (int i = 0; i < count; i++){
    free(*(tokens+i));
    end = word_terminator(*(tokens+i));
    int size = (end - start);


    printf("\n");

  }
}
