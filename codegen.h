#ifndef _codegen_h_
#define _codegen_h_

#include "symboltable.h"
#include "hashtable.h"
#include "token.h"
#include "parserDef.h"
#include "mainsymboltable.h"
#include "idsymboltable.h"
#include "typeExtractor.h"

void endcode();
void initialize(/*FILE* fp, */mainsymboltable* globalTable);
void codegenexp(stacknode* curr);
int getlabel();
void codegeniterative(stacknode* temp);
void code_statement(stacknode* temp);
void traverseAST_forCodegen(stacknode* curr);
void generate_code(mainsymboltable* globalTable, stacknode* astroot);

#endif
