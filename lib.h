/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_LIB
#define SMT__LOCAL_LIB

/* biblioteki: */
	#include <stdio.h>
	#include <stdlib.h>	/* dla srand() */
	#include <time.h>	/* dla time() do srand() */
	#include <string.h> 

/* funkcje obslugujace argumenty */
	void usage(char *);
	void type_to_name(char *);

/* funkcje generujace */
	void generate(long, long, char *, char *, char);
	void generate_char(long, long, FILE **, char);
	void generate_long(long, long, FILE **, char);

/* funkcje obslugujace plik */
	void file_open(char *, FILE **);
	void file_close(FILE *);

#endif
