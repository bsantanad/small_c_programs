/** simple cat implemetation **/
#include<stdio.h>
#include<stdlib.h>

int
main(int argc, char *argv[])
{
        char *prog = argv[0]; /** program name for error **/

        char c;
        FILE *fp;

        if (argc < 2){
                printf("%s: you need to pass at least one file to cat \n",
                       prog);
                exit(-1);
        }

        /** we need to move the argv array by one, since we dont want to print
         * the binary program, argv[0] = prog (the actual binary) **/
        *argv++;

        while(argc-- > 1){
            if ((fp = fopen(*argv++, "r")) == NULL) {
                    printf("%s: can not open file\n", prog);
                    exit(-1);
            }
            while((c = getc(fp)) != EOF) {
                    putc(c, stdout);
            }
            fclose(fp);
        }
        return 0;
}

