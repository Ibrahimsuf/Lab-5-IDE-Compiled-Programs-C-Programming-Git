#include <stdio.h>


int main() {
  FILE *fptr;

  fptr = fopen("sales_file.txt", "w");
  
  float sales[12];
  
  for(int i = 0; i < 12; i++) {
    fscanf(fptr, "%f", &sales[i]);
  }

  fclose(fptr);


  // print out each line in the file
  for(int i = 0; i < 12; i++) {
    printf("%f\n", sales[i]);
  }

  fclose(fptr);
}