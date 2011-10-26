/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void usage(char *app_name) {
	fprintf(stderr, "Use: %s [options]\n", app_name);
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "\t-c[N]\t\t# where [N] is the number of generating words\n");
	fprintf(stderr, "\t-o[FILE_NAME]\t# where [FILE] is name of output file\n");
	fprintf(stderr, "\t-l[N]\t\t# where [N] is the lenght of word\n");
	fprintf(stderr, "\t-s[C]\t\t# where [C] is the separator of the words\n");
	fprintf(stderr, "\t-t[C]\t\t# where [C] is type of words\n");
	fprintf(stderr, "\t\tc\t# for CHAR\n");
	fprintf(stderr, "\t\tl\t# for LONG\n");
	fprintf(stderr, "\nEXAMPLE:\n ./main -c100 -l10 -tl -ooutput.txt -s:\n");
	fprintf(stderr, "\nStandards output:\n");
	fprintf(stderr, "-c10000 -l8 -tl -odate.in -s{new line}\n");
	exit(8);
}

void type_to_name(char *type) {
	switch(type[0]) {
		case 'l':
			strcpy(type, "LONG");
			break;
		case 'c':
			strcpy(type, "CHAR");
			break;
	}
}

void generate(long n, long l, char *out, char *type, char sep) {
	FILE *f;

	file_open(out, &f);

	srand(time(NULL));

	fprintf(f, "%ld\n", n);
	fprintf(stderr, "Generowanie w toku\n");

	if(!strcmp(type, "LONG")) {
		generate_long(n, l, &f, sep);
	} else {
		if(!strcmp(type, "CHAR")) {
			generate_char(n, l, &f, sep);
		} else {
			fprintf(stderr, "Blad: bledny typ pliku\n");
			exit(8);
		}
	}

	file_close(f);
}

void generate_char(long n, long l, FILE **f, char sep) {
	char tmp;
	long i;

	while(n--) {
		for(i=0; i<rand()%l+1; i++) {
			tmp = (char)(rand() % 25 + 97);
			fprintf(*f, "%c", tmp);
		}
		fprintf(*f, "%c", sep);
		printf("\rPozostalo: %ld", n);
	}
}

void generate_long(long n, long l, FILE **f, char sep) {
	long tmp, i;

	while(n--) {
		fprintf(*f, "%d", rand() % 10+1);
		for(i=1; i<rand()%l; i++) {
			tmp = rand() % 10;
			fprintf(*f, "%ld", tmp);
		}
		fprintf(*f, "%c", sep);
		printf("\rPozostalo: %ld", n);
	}
}

void file_open(char *out, FILE **f) {
	if((*f = fopen(out, "wa")) == NULL) {
		fprintf(stderr, "Nie moge otworzyc / utworzyc pliku: %s", out);
		exit(8);
	}
}

void file_close(FILE *f) {
	fclose(f);
}
