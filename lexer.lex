%option noyywrap
%option nounput
%{
#include <iostream>
#include <string>
#include <vector>
#include "ClassTable.hpp"
#include "SymbolTable.hpp"
#include "ClassDef.hpp"
#include "MethodTable.hpp"
#include "FieldType.hpp"
#include "Type.hpp"
#include "parser.tab.hpp"

using namespace std;

%}

%%

class			                return class_token;
public 			        return public_token;
private			        return private_token;
int			                return int_token;
double			        return double_token;
void			                return void_token;
string			        return string_token;
return 			        return return_token;
\/\/.*                                {}
[A-Z]                               {yylval.s = new string(yytext); return class_id_token;}
[0-9]+\.[0-9]+     	       { yylval.d = atof(yytext); return num_double_token; }
[0-9]+			       { yylval.i = atoi(yytext); return num_int_token; }
[a-zA-Z_][_a-zA-Z0-9]*    { yylval.s = new string(yytext); return id_token; }
[,;{}()\.+-/*=]                 return *yytext;
[\t\n ]			       {}
.			               {
                                            cerr << "Leksicka greska: neprepoznat karakter '" << *yytext << "'" << endl;
                                            exit(EXIT_FAILURE);
                                        }

%%
