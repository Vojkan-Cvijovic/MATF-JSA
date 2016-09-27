%{
#define YYDEBUG 1
#include <iostream>
#include <string>
#include <vector>
#include "ClassTable.hpp"
#include "SymbolTable.hpp"
#include "ClassDef.hpp"
#include "MethodTable.hpp"
#include "FieldType.hpp"
#include "Type.hpp"
//ukljuciti stablo

extern int yylex();
void yyerror(std::string s){
    std::cerr << s << std::endl;
    exit(EXIT_FAILURE);
}
%}

%union{
        std::string str;
        int int_num;
        double double_num;
}
%token return_token class_token public_token private_token int_token double_token void_token string_token
%token <double_num> num_double_token
%token <int_num> num_int_token
%token <str> id_token

%%
Program: Array_of_object                                                                            {}           
|                                                                                                                   {}                                   
;
Array_of_object: Array_of_object Object                                                      { /*tablicaKlasa.add($2);*/}                                          
|                                                                                                                   { /*tablicaKlasa = new ClassTable();*/ }               
;

Object: class_token id_token '{' Class_block '}'    
                                       { /*$$ = ClassDef($2,$4); SymbolTable.deinit(); */}
|                                                                                                                    {// ubaci proveru ako je prazna klasa da ne prolazi kroz niz neko da odmah kaze da nema definiciju // tablica simbola se mora inicijalizovati pre ulaska u class_block 
}
;
Class_block: Class_block Commands                                                              { /*$$ = $2*/}    
|
                                                                                                                     { }
;
/* vraca vector<FieldType*>  */
Commands: Commands private_token Attribute ';' { /* mi prolazimo kroz vektor tipova $2 i za svaki pravimo PrivateAtributeFieldType i dodajemo ga na $1 i saljemo na $$*/ }
|       Commands public_token Attribute ';' { /* mi prolazimo kroz vektor tipova $2 i za svaki pravimo PublicAtributeFieldType*/ }
|       Commands private_token Method       { /* method vraca Type* a mi pravimo PrivateMethodFieldType($3) i dodajemo ga u niz $1
                                                                        i saljemo na $$ isto i dole */ }
|       Commands public_token Method        { /* pravimo PublicMethodFieldType($3) */ }
|                                                                                                                      { /*$$ = new vector<FieldType*>();*/ }
;
/* Vraca vector<Type*> */
Attribute:  int_token Ids                                                        { /* prolazimo kroz niz ids i za svaki id pravimo IntType(id) stavljamo sve to u niz i   
                                                                                                vracamo, isto i dole, jos dodajemo svaki Type koji napravimo u tablicu simbola*/ }
|           double_token Ids                                                                                {}
|           string_token Ids                                                                                  {}
;
Ids: Ids id_token                                                                                              { /*$1.push_back($2);$$ = $1; */ }
|                                                                                                                       { /*$$ = new vector<string>()*/}
;
// Napomena da li nam treba MethodType??
/* Vraca Type*  */
Method: int_token id_token '(' ')' '{' Method_block '}'         { /*$$ = new IntType($2); */   }
|       double_token id_token '(' ')' '{' Method_block '}'      { /*$$ = new DoubleType($2);*/ }
|       string_token id_token '(' ')' '{' Method_block '}'      { /*$$ = new StringType($2);*/ }
|       void_token id_token '(' ')' '{' Method_block '}'        { /*$$ = new VoidType($2);*/   }
;
Method_block: Method_block return_token id_token '(' ')' ';'  {/* Nadjemo type u methodTable i vratimo   */}
|   return_token id_token ';'                   { /* Nadjemo u symbolTable i vratimo tip */   }
|   Inicijalizacija ';'    {/*$$ = nullptr;*/}
|   Dodela ';'            {/*$$ = nullptr;*/}
|   Expresion              {/*$$ = nullptr;*/}
|                               {/* $$ = nullptr;*/}

;
Inicijalizacija: int_token Array
| double_token Array   //isto kao Ids
| string_token Array
;
Array: id_token ',' Array
| id_token '=' Expresion
;
Dodela: id_token '=' Expresion                {/* pogledamo u tablici simbola za jedan i za drugi i pogledamo da li se slazu */}
;
Expresion: id_token '.' id_token '(' ')' { /* trazimo u tablici klasa id_token i dobijamo classDef i dalje trazimo tip drugog id_token-a i vracamo taj tip */}
| id_token '.' id_token         {/* trazimo opet u tablici klasa pa opet isto, vracamo tip*/}
| Expresion '+' Expresion       {/* prvi vraca tip kao i drugi , imamo kastovanje ako je moguce ili gresku */}
| id_token                      {/* trazimo iz tablice id_token*/}
| num_double_token              { /*$$ = new DoubleType(nullptr);*/}
| num_int_token                 { /*$$ = new IntType(nullptr);*/}
| id_token '(' ')'              { /* trazimo u tablici metoda i vracamo tip*/}
%%

int main(){
    yyparse();
    return 0;
}
