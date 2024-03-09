#include <stdio.h>


int getPossibleScoreCombinations(int totalScore) {
  int num_tdw2 = 0;
  int num_tdw1 = 0;
  int num_tds = 0;
  int num_fieldgoals = 0;
  int num_safeties = 0;
  // loop through possible combinations of tds with 2 extra points
  if (totalScore <= 2) {
    return -1;
  }
  printf("possible combinations of scoring plays:\n");
  while (num_tdw2 * 8 <= totalScore) {
    num_tdw1 = 0;
    // loop through possible combinations of tds with extra points
    while (8 * num_tdw2 + 7 * num_tdw1 <= totalScore) {
      num_tds = 0;
      // loop through possible combinations of tds with no extra points
      while (8 * num_tdw2 + 7 * num_tdw1 + 6 * num_tds <= totalScore) {
        num_fieldgoals = 0;
        // loop through possible combinations of field goals
        while (8 * num_tdw2 + 7 * num_tdw1 + 6 * num_tds + 3 * num_fieldgoals <= totalScore) {
          num_safeties = 0;
          // loop through possible combinations of safeties
          while (8 * num_tdw2 + 7 * num_tdw1 + 6 * num_tds + 3 * num_fieldgoals + 2 * num_safeties <= totalScore) {
            if (8 * num_tdw2 + 7 * num_tdw1 + 6 * num_tds + 3 * num_fieldgoals + 2 * num_safeties == totalScore) {
              printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", num_tdw2, num_tdw1, num_tds, num_fieldgoals, num_safeties);
            }
            num_safeties++;
          }
          num_fieldgoals++;
        }
        num_tds++;
      }
      num_tdw1++;
    }
    num_tdw2++;
  }
  return 0;
}

int main() {
  int userinput;
  printf("Enter 0 or 1 to STOP\n");
  printf("Enter total score: ");
  scanf("%d", &userinput);


  while (userinput != 0 && userinput != 1) {
    getPossibleScoreCombinations(userinput);
    printf("\n");
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter total score: ");
    scanf("%d", &userinput);
  } 
}