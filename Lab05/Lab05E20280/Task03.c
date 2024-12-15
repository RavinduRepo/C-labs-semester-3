#include<stdio.h>

int main(){

    char seqence[225], motif[225];
    int scount = 0, svalid = 1, mcount = 0, mvalid = 1;

    printf("Enter a DNA sequence: ");
    scanf(" %s", seqence);

    printf("Enter the motif: ");
    scanf(" %s", motif);
    
    for (int i = 0; seqence[i] != '\0'; i++){
        if (!(seqence[i] == 'A' || seqence[i] == 'T' || seqence[i] == 'C' || seqence[i] == 'G')){
            svalid = 0;
        }
        // scount++;
    }
    for (int i = 0; motif[i] != '\0'; i++){
        if (!(motif[i] == 'A' || motif[i] == 'T' || motif[i] == 'C' || motif[i] == 'G')){
            mvalid = 0;
        }
        mcount++;
    }

    if (!svalid && !mvalid){
        printf("Both DNA sequence and motif are not valid.\n");
    }
    else if (!svalid){
        printf("The DNA sequence is not valid.\n");
    }
    else if (!mvalid){
        printf("The motif is not valid.\n");
    }

    if (svalid && mvalid){
        
        for (int i = 0; seqence[i] != '\0'; i++){
            if (motif[0] == seqence[i]){
                int l = i;
                for (int k = 0; motif[k] != '\0'; k++){
                    if (motif[k] != seqence[l]){
                        break;
                    } else if (l == i + mcount - 1){
                        printf("Found at indexes %d-%d\n", i + 1,l +1);
                        i = l;
                    }
                    l++;
                }
            }
        }
    }
    
    return 0;
}