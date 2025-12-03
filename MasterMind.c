#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//global constants

const int NUM_PAWNS    = 5; 
const int NUM_COLORS   = 8; 
      int NUM_ATTEMPTS;
      int hiddenboard[5];
enum color_t{RED=1, GREEN, BLUE, YELLOW, BLACK, WHITE, GRAY, PURPLE};

int difficulty_selection(){
   int difficulty;
   printf("\nPlease select your difficulty:\n 1: Easy (10 Attempts)\n 2: Medium (7 Attempts)\n 3: Hard (5 Attempts)\n");
   scanf("%d", &difficulty);
   while ( 1 <= difficulty <= 3 )
   {
   if (difficulty == 1){
      return 10;}
   else if (difficulty == 2){
      return 7;}
   else if (difficulty == 3){
      return 5;} 
      else{
         printf("Difficulty is invalid, Please type either 1, 2 or 3\n");
         scanf("%d", &difficulty);
      }
   }
}
void generate_random_board(int hiddenboard[5]){
   for (int i=0; i<5; i++){
      int dupe;
      int color;
       do {
         dupe = 0;
         color=rand() %8 + 1;
         for (int j=0; j<i; j++){
            if (hiddenboard[j] == color){
               dupe = 1;
               break;
            }
         }

   } while (dupe == 1);

     hiddenboard[i] = color;

   }
}

// part for reading the proposed code

void read_proposed_code(int board[5]){
    printf("please enter the combination of colors:\n Red=1 | Green=2 | Blue=3 | Yellow=4 | Black=5 | White=6 | Gray=7 | Purple =8\n");
    for (int k=0; k<5;k++){
           scanf("%d", &board[k]);
    }
}

// part for comparing the proposed code to the actual code

void compare_codes(int board[],int *wellplacedpawns,int *missplacedpawns){
    *wellplacedpawns=0;
    *missplacedpawns=0;
      for(int i=0; i<5; i++){
         if  (board[i] == hiddenboard[i]){
       (*wellplacedpawns)++;
      }
   }
      for (int i=0; i<5; i++){
         if  (board[i] == hiddenboard[i]) continue;
          for(int j=0; j<5; j++){
            if (i == j) continue;
            if (board[i] == hiddenboard[j]){
               (*missplacedpawns)++;
            }
         }
      }
}
  
     // function for the game logic

      void game(){
      
     int NUM_ATTEMPTS = difficulty_selection();
     
     generate_random_board(hiddenboard);

      printf("Welcome Codebreaker\n");
      int hiddenboard[5];
      int board[5];
      int wellplacedpawns;
      int missplacedpawns;
      for(int tries=0; tries<NUM_ATTEMPTS; tries++){
         printf("attempt %d of %d\n", tries+1, NUM_ATTEMPTS);

         // we execute our main functions

                  read_proposed_code(board);
                  compare_codes(board, &wellplacedpawns, &missplacedpawns);

        if (wellplacedpawns ==0 && missplacedpawns ==0)
     {
      printf("you have no well placed pawns, and no missplaced pawns\n");
     }
           else{
               printf("you have %d well placed pawns, and %d missplaced pawns\n",wellplacedpawns, missplacedpawns );
          }
     if (wellplacedpawns==5){
      printf("you beat the system, you are awesome!\n");
      break;
     }
   }
 }
           int main(){
     srand(time(NULL));
   game();
   return 0;
}