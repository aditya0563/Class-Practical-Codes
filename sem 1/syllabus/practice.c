#include <stdio.h>
#include <stdlib.h>
int mian(){
    FILE *Source, *Dest;
    char source[100],dest[100],ch;
    printf("enter the source filename: ");
    scanf("%s",&source);
    Source = fopen(source,"r");
    if(Source == NULL){
        printf("cannot open the file %s",source);
        return 1;
    }
    printf("enter the destinantion filename: ");
    scanf("%s",dest);
    Dest = fopen(dest,"r");
    if(Dest = NULL){
        printf("cannot open the file %s",dest);
        return 1;
    }
    while((ch= fgetc(Source))!=EOF){
        fputc(ch,Dest);
    }
    fclose(Source);
    fclose(Dest);
    return 0;
}