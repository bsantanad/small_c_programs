/** program that counts the characters in file **/
#include<stdio.h>
#include<stdlib.h>

int 
main(int argc, char *argv[])
{
        char *prog = argv[0];  /** program name for errors **/

        int c;
        FILE *fp;
        unsigned long count = 0;
        if (argc != 2) {
                printf("usage: %s filename\n", prog);
                exit(-1);
        }
        if ((fp = fopen(argv[1], "r")) == NULL){
                printf("can not open: %s \n", argv[1]);
                exit(-1);
        }
        while((c = getc(fp)) != EOF)
        {
                putc(c, stdout);
                count++;
        }

        fclose(fp);
        printf("file %s has %lu chars\n", argv[1], count);

        return 0;
}
