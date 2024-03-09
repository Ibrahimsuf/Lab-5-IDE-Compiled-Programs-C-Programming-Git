#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* padString(char *str, int length) {
  char *newStr = malloc(length + 1);
  for (int i = 0; i < strlen(str); i++) {
    newStr[i] = str[i];
  }
  for (int i = strlen(str); i < length; i++) {
    newStr[i] = ' ';
  }
  newStr[length] = '\0';
  return newStr;
}

void printMonthlySalesReport(float sales[12], char *months[12]) {
  printf("Monthly sales report for 2022:\n");
  printf("\n");
  printf("Month     Sales\n");
  for (int i = 0; i < 12; i++) {
    char* month = padString(months[i], 10);
    printf("%s $%.2f\n", month, sales[i]);
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
  printf("Minimum sales: $%.2f (%s)\n", min, months[min_month]);
  printf("Maximum sales: $%.2f (%s)\n", max, months[max_month]);
  printf("Average sales: $%.2f\n", average);
}

int getSixMonthMovingAverage(int sales[12], int start):
{
  int average = 0;
  for (int i = start; i < start + 6; i++) {
    average += sales[i] / 6;
  }
  return average;
}

void printSixMonthMovingAverage(float sales[12], char *months[12]) {
  printf("Six-Month Moving Average Report:\n");
  for (int i = 0; i < 6; i++) {
    printf("%s\t- $%.2f\n", months[i], getSixMonthMovingAverage(sales, i));
  }
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
  printSixMonthMovingAverage(sales, months);
  // printSalesReportSorted(sales);
}


