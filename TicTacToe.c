#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main(){
    int b,c[]={'1','2','3','4','5','6','7','8','9'},d,e,f,g,h=0,i,j,k,l,m,n,o,p,q[7]={0};
    char a[10];
    memset(a,'0',9);
    for(b=0;b<10;b++){
        printf("\n        |        |        \n    %c   |    %c   |    %c    \n________|________|________\n        |        |        \n    %c   |    %c   |    %c    \n________|________|________\n        |        |        \n    %c   |    %c   |    %c    \n        |        |        \n\n",*c,c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8]);
        if(b<9&&q[0]==q[1]&&q[0]==q[2]&&q[0]==q[3]&&q[0]==q[4]&&q[0]==q[5]&&q[0]==q[6]){
            do{
                p=0;
                (b%2==1)? printf("\nsecond player turn (o): "): printf("\nfirst player turn (x): ");
                a[b]=getche();
                (a[b]<'1'||a[b]>'9')&&printf("\n\nenter only the numbers from 1 to 9\n")&&p++;
                if(p==0){
                    for(i=0;i<8;i++){
                        for(j=i+1;j<9;j++)
                        (a[j]==a[i]&&a[i]!='0')&&printf("\n\nYou have alrady used slot number %c\n",a[i])&&p++;        
                    }
                }
            }while(p);
        }
        for(e=0;e<9;e++){
            (c[e]==a[b]&&b%2==1)? c[e]='O': 0;
            (c[e]==a[b]&&b%2==0)? c[e]='X': 0;
        }
        for(k=0;k<9;k++)
        (c[k]=='X'||c[k]=='O')&&h++;
        if(h>=5){
            for(l=0;l<9;l+=3){
                if(c[l]==c[l+1]&&c[l]==c[l+2]&&c[l]=='O'){
                    q[0]++;
                    if(q[0]>1){
                        printf("\n{ the second player has won (o) }\n\n");
                        getche();
                        return 0;
                    }
                }
                if(c[l]==c[l+1]&&c[l]==c[l+2]&&c[l]=='X'){
                    q[1]++;
                    if(q[1]>1){
                        printf("\n{ the firsst player has won (x) }\n\n");
                        getche();
                        return 0;
                    }
                }
            }
            for(m=0;m<3;m++){
                if(c[m]==c[m+3]&&c[m]==c[m+6]&&c[m]=='O'){
                    q[2]++;
                    if(q[2]>1){
                        printf("\n{ the second player has won (o) }\n\n");
                        getche();
                        return 0;
                    }
                }
                if(c[m]==c[m+3]&&c[m]==c[m+6]&&c[m]=='X'){
                    q[3]++;
                    if(q[3]>1){
                        printf("\n{ the first player has won (x) }\n\n");
                        getche();
                        return 0;
                    }
                }
            }
            if(c[0]==c[4]&&c[0]==c[8]&&c[0]=='O'||c[2]==c[4]&&c[2]==c[6]&&c[2]=='O'){
                q[4]++;
                if(q[4]>1){
                    printf("\n{ the second player has won (0) }\n\n");
                    getche();
                    return 0;
                }
            }
            if(c[0]==c[4]&&c[0]==c[8]&&c[0]=='X'||c[2]==c[4]&&c[2]==c[6]&&c[2]=='X'){
                q[5]++;
                if(q[5]>1){
                    printf("\n{ the first player has won (x) }\n\n");
                    getche();
                    return 0;
                }
            }
        }
        if(h==9){
            q[6]++;
            if(q[6]>1){
                printf("\n\t { draw }\n\n");
                getche();
                return 0;
            }
        }
        system("cls");
        h=0;
    }
}