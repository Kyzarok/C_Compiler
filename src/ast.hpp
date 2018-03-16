#ifndef ast_hpp
#define ast_hpp

#include "AST/ast_node.hpp"
#include "AST/ast_expressions.hpp"
#include "AST/ast_statements.hpp"
#include "AST/ast_declarations.hpp"
#include "AST/ast_primitives.hpp"
#include "AST/ast_varb_declarations.hpp"
#include "AST/ast_program.hpp"



/*  I regret so many choices found in the entire AST. 
In fact I regret them enough to write them down. Expressions and Node should have been written
to only reference Node - ie move compound statement. By moving compound statement to another file,
Statement doesn't need to reference varb_declarations. This means that varb_declarations can be merged with declarations without running into circular issues with stuff referenceing undefined stuff. More things should be of type Node, maybe? */

extern const Node *parseAST(const char* location);

#endif
