#include <stdlib.h>

#include <stdio.h>

#include "tokenizer.h"

#include "history.h"

int main(void) {



  char str[] = "   MY DOG HAS FLEAS";





  //printf("%c\n",*word_start(str));



  //printf("%c\n",*word_terminator(str));



  //printf("%d\n", count_words(str));



  //printf("%s\n", copy_str(str, 4));





  char ** tokens = tokenize(str);



  print_tokens(tokens);



  //free_tokens(tokens);

  
}
