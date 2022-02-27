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
        if ((fp = fopen(argv[1], "r")) == NULL) {
                printf("%s: can not open file\n", prog);
                exit(-1);
        }
        int counter = 0;
        while ((c = getc(fp)) != EOF) {
                if (c == ' ') {
                        fseek(fp, -counter, SEEK_CUR);
                        while(counter > 0) {
                                c = getc(fp);
                                putc(c, stdout);
                        }
                        //putc('\n', stdout);
                        continue;
                }
                counter++;
        }
}
