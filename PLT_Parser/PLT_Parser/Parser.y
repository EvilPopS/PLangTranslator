%{

%}



%%


%%


int parser_main(int argc, char* argv[]) {
	return 0;
}
int yyerror(const char *s) {
	fprintf(stderr, "SYNTAX ERROR %s\n", s);
	return 0;
}