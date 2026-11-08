#include <stdio.h>

int main(){
    char map[13][30]={
        "##############################",
        "#                            #",
        "#  ########################  #",
        "#                         #  #",
        "#  #  ##################  #  #",
        "#  #  #                #  #  #",
        "#  #  #     F             #  #",
        "#  #  #                #  #  #",
        "#  #  ##################  #  #",
        "#  #                      #  #",
        "#  ########################  #",
        "#                            #",
        "##############################"
    };
    int c[13][30];
    char m;
    int a_toggle=0,d_toggle=0;
    for(int i=0;i<13;i++){
            for(int j=0;j<30;j++){
                    if(map[i][j]=='#') c[i][j]=1;
                    else if(map[i][j]=='F') c[i][j]=2;
            }
    }
    struct car{
        int x;
        int y;
    };
    struct car cm;
    cm.x=6;
    cm.y=5;
    map[cm.x][cm.y]='^';
        
    do{
        printf("\e[1;1H\e[2J");
        printf("Controls: [W] Accel | [S] Brake | [A/D] Steer | [Q] Quit\n\n");
        
        printf("\n");
        for(int i=0;i<13;i++){
            for(int j=0;j<30;j++){
                printf("%c",map[i][j]);
                }
                printf("\n");
        }
        printf("\nEnter move:");
        scanf("%c",&m);
        if(m=='w' && map[cm.x][cm.y]=='^'){
            map[cm.x][cm.y]=' ';
            cm.x=cm.x-1;
            map[cm.x][cm.y]='^';
        }
        else if(m=='w' && map[cm.x][cm.y]=='>'){
            map[cm.x][cm.y]=' ';
            cm.y=cm.y+1;
            map[cm.x][cm.y]='>';
        }
        else if(m=='w' && map[cm.x][cm.y]=='v'){
            map[cm.x][cm.y]=' ';
            cm.x=cm.x+1;
            map[cm.x][cm.y]='v';
        }
        else if(m=='w' && map[cm.x][cm.y]=='<'){
            map[cm.x][cm.y]=' ';
            cm.y=cm.y-1;
            map[cm.x][cm.y]='<';
        }
        else if(c[cm.x][cm.y]==1){
            printf("\nStrike with wall!!");
            break;
        }
        
        else if(m=='q'){
            printf("\nGame closing...");
            break;
        }
        else if(m=='a'){
            if(a_toggle==0){
                map[cm.x][cm.y]='^';
                a_toggle=1;
            }
            else if(a_toggle==1){
                map[cm.x][cm.y]='v';
                a_toggle=0;
            }
        }
        else if(m=='d'){
            if(d_toggle==0){
                map[cm.x][cm.y]='<';
                d_toggle=1;
            }
            else if(d_toggle==1){
                map[cm.x][cm.y]='>';
                d_toggle=0;
            }
        }
    }while(c[cm.x][cm.y]!=2);
    if(c[cm.x][cm.y]==2){
        printf("Race completed\nYou won!!");
    }
}