/** simple cat implemetation for two files **/
#include<stdio.h>
#include<stdlib.h>

int
main(int argc, char *argv[])
{
        char *prog = argv[0];

        char c;
        FILE *first, *second; 

        if (argc != 3){
                printf("%s: usage %s <filename> <filename>\n", prog, prog);
                exit(-1);
        }

        if ((first = fopen(argv[1], "r")) == NULL) {
                printf("%s: can not open %s\n", prog, argv[1]);
                exit(-1);
        }
        if ((second = fopen(argv[2], "r")) == NULL) {
                printf("%s: can not open %s\n", prog, argv[2]);
                exit(-1);
        }

        while((c = getc(first)) != EOF) {
                putc(c, stdout);
        }
        while((c = getc(second)) != EOF) {
                putc(c, stdout);
        }

        return 0;
}

