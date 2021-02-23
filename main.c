#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#define MAX_LEVEL 3
struct Level
{
    FILE *question;
    FILE *answer;
} LEVEL[MAX_LEVEL];

int showLevel(FILE*,FILE*);

int main(){
    system("COLOR 3E");
    LEVEL[0].question = fopen("levels/level_1_que.txt", "r");
    LEVEL[0].answer = fopen("levels/level_1_ans.txt", "r");

    LEVEL[1].question = fopen("levels/level_2_que.txt", "r");
    LEVEL[1].answer = fopen("levels/level_2_ans.txt", "r");

    LEVEL[2].question = fopen("levels/level_3_que.txt", "r");
    LEVEL[2].answer = fopen("levels/level_3_ans.txt", "r");

    int i;
    for(i=0;i<MAX_LEVEL;i++){
        printf("----------------LEVEL %d----------------\n",(i+1));
        int result = showLevel(LEVEL[i].question, LEVEL[i].answer);
        if(result == 1){
            printf("\nWow! You have won Level %d\n", (i+1));
            printf("\n");
            fclose(LEVEL[i].question);
            fclose(LEVEL[i].answer);
        } else{
            printf("\nSorry! you can't get Level %d right!\n",(i+1));
            break;
        }
    }

    if(i == MAX_LEVEL){
        printf("Congrats! you have played all the levels correctly\n");
    }

    printf("\nThanks for playing this Game");

    fflush(stdin);
    char c;
    scanf("%c",&c);
    return 0;
}

int showLevel(FILE *question, FILE *answer){

    //Getting question from File
    int questionGrid[9][9];

    char ch;
    int i=0;
    int j=0;
    while((ch = getc(question)) != EOF){
        if(isdigit(ch)){
            questionGrid[i][j++] = ch - '0';
            if(j == 9){
                i++;
                j=0;
            }
        }
    }

    //Getting answer from file
    int answerGrid[9][9];

    i=0;
    j=0;
    while((ch = getc(answer)) != EOF){
        if(isdigit(ch)){
            answerGrid[i][j++] = ch - '0';
            if(j == 9){
                i++;
                j=0;
            }
        }
    }

    //Showing question to user
    printf("\nPuzzel is:\n");
    printf("\t_________________________\n");
    for(i=0;i<9;i++){
    printf("\t");
    for(j=0;j<9;j++){
       if(j==0)
    printf("| ");
       if(questionGrid[i][j]==0)
    printf("_ ");
       else
    printf("%d ",questionGrid[i][j]);
       if((j+1)%3==0 )
    printf("| ");
   }
   if((i+1)%3==0 )
    printf("\n\t_________________________");
    printf("\n");
 }
 printf("\n");



int userAnswerGrid[9][9];


//Getting answer from user
    printf("\nEnter the fully solved grid:\n");
 for(i=0;i<9;i++)
 {
     for(j=0;j<9;j++)
     {
        scanf("%d",&userAnswerGrid[i][j]);
     }
 }
    for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        if(userAnswerGrid[i][j] != answerGrid[i][j]){
            return 0;
        }
    }
}
return 1;

}
