#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMonthlySalesReport(float sales[12], char *months[12]) {
  printf("Monthly sales report for 2022:\n");
  printf("\n");
  printf("Month     Sales\n");
  for (int i = 0; i < 12; i++) {
    fputs(months[i], stdout);
    for (int j = strlen(months[i]) - 1; j < 9; j++) {
      fputs(" ", stdout);
    }
    printf("$%.2f\n", sales[i]);
  }
}

void printSalesSummary(float sales[12], char *months[12]) {
  float average = sales[0] / 12;
  float max = sales[0];
  int max_month = 0;
  float min = sales[0];
  int min_month = 0;
  for (int i = 0; i < 12; i++) {
    average += sales[i] / 12;
    if (sales[i] > max) {
      max = sales[i];
      max_month = i;
    }
    if (sales[i] < min) {
      min = sales[i];
      min_month = i;
    }
  }
  
  printf("Sales summary:\n");
  printf("Minimum sales: $%.2f\t(%s)\n", min, months[min_month]);
  printf("Maximum sales: $%.2f\t(%s)\n", max, months[max_month]);
  printf("Average sales: $%.2f\n", average);
}

int main() {
  FILE *fptr;

  fptr = fopen("sales_file.txt", "r");
  
  float sales[12];
  
  for(int i = 0; i < 12; i++) {
    fscanf(fptr, "%f", &sales[i]);
  }

  fclose(fptr);

  char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  printMonthlySalesReport(sales, months);
  printf("\n");
  printSalesSummary(sales, months);
  // printSixMonthMovingAverage(sales);
  // printSalesReportSorted(sales);
}


