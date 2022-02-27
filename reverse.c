#include<stdio.h>
#include<stdlib.h>

int
main(int argc, char *argv[])
{
        char *prog = argv[0]; /** program name for error **/

        char c;
        FILE *fp;
        long count, last;

        if (argc < 2){
                printf("%s: you need to pass at least one file to cat \n",
                       prog);
                exit(-1);
        }
        if ((fp = fopen(argv[1], "r")) == NULL) {
                printf("%s: can not open file\n", prog);
                exit(-1);
        }
        fseek(fp, 0L, SEEK_END); /** go to end of file **/
        last = ftell(fp);

        for (count = 1L; count <= last; count++) {
                fseek(fp, -count, SEEK_END); /** go backwards **/
                c = getc(fp);
                if (c != EOF)
                        putchar(c);
        }
        putchar('\n');
        fclose(fp);
        return 0;
}
