/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main(int argc, char *argv[]) {
	long N = 10000, L = 8;
	char OUT[128] = "date.in";
	char TYPE[16] = "LONG";
	char SEPARATOR = '\n';

	if(argc==1) {
		usage(argv[0]);
	} else {
		while((argc > 1) && (argv[1][0] == '-')) {
			/* while there are any args */
		switch(argv[1][1]) {
			case 'c': 
				N = atoi(&argv[1][2]);
				break;
			case 'o':
				strcpy(OUT, &argv[1][2]);
				break;
			case 't':
				strcpy(TYPE, &argv[1][2]);
				type_to_name(TYPE);
				break;
			case 'l':
				L = atoi(&argv[1][2]);
				break;
			case 's':
				SEPARATOR = argv[1][2];
				break;
			default:
				fprintf(stderr, "Zly parametr: %s\n", argv[1]);
				usage(argv[0]);
			}
			++argv; /* list up */
			--argc; /* count down */
		}

		fprintf(stderr, "DANE WEJSCIOWE:\n");
		fprintf(stderr, "ILOSC SLOW:\t%ld\n", N);
		fprintf(stderr, "DLUGOSC SLOWA:\t%ld\n", L);
		fprintf(stderr, "TYP SLOWA:\t%s\n", TYPE);
		fprintf(stderr, "PLIK WYJSCIOWY:\t%s\n", OUT);
		fprintf(stderr, "SEPARATOR:\t%c\n", SEPARATOR);

		generate(N, L, OUT, TYPE, SEPARATOR);
	}
	return 0;
}
