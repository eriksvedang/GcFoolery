#ifndef REPL_H
#define REPL_H

#include "GC.h"
#include "Obj.h"
#include "Parser.h"
#include "Runtime.h"

void repl() {
  const int BUFFER_SIZE = 256;
  char str[BUFFER_SIZE];
  
  Runtime *r = runtime_new();

  while(r->mode != RUNTIME_MODE_FINISHED) {
    printf("> ");
    fgets(str, BUFFER_SIZE, stdin);
    //if(strcmp(str, "quit\n") == 0) break;
    runtime_eval(r, str);
  }
  
  //runtime_inspect_env(r);
  gc_collect(r->gc);
  runtime_delete(r);
}

#endif

