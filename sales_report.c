#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* padString(const char *str, const int length) {
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

void sortSales(const float sales[12], const char* months[12], float** sorted_sales_ptr, char*** sorted_months_ptr) {
  // sort sales and months and assign them to sorted_sales and sorted_months pointers
  *sorted_sales_ptr = malloc(12 * sizeof(float));
  *sorted_months_ptr = malloc(12 * sizeof(char*));
  float temp_sales;
  char* temp_month;

  // copy sales into sorted_sales and months into sorted_months
  for (int i = 0; i < 12; i++) {
    (*sorted_sales_ptr)[i] = sales[i];
    (*sorted_months_ptr)[i] = malloc(10);
    strcpy((*sorted_months_ptr)[i], months[i]);
  }
  // sort sales into descending order, and sort months accordingly
  for (int i = 0; i < 12; i++) {
    for (int j = i + 1; j < 12; j++) {
      if ((*sorted_sales_ptr)[i] < (*sorted_sales_ptr)[j]) {
        temp_sales = (*sorted_sales_ptr)[i];
        temp_month = malloc(10);
        strcpy(temp_month, (*sorted_months_ptr)[i]);
        (*sorted_months_ptr)[i] = (*sorted_months_ptr)[j];
        (*sorted_sales_ptr)[i] = (*sorted_sales_ptr)[j];
        (*sorted_months_ptr)[j] = temp_month;
        (*sorted_sales_ptr)[j] = temp_sales;
      }
    }
  }
  free(temp_month);
}

void printSalesReportSorted(const float sales[12], const char *months[12]) {
  float* sorted_sales_ptr;
  char** sorted_months_ptr;
  sortSales(sales, months, &sorted_sales_ptr, &sorted_months_ptr);


  printf("Sales Report (Highest to Lowest):\n");
  printf("\n");
  printf("Month     Sales\n");
  for (int i = 0; i < 12; i++) {
    char* month = padString(sorted_months_ptr[i], 10);
    printf("%s $%.2f\n", month, sorted_sales_ptr[i]);
  }

  free(sorted_sales_ptr);
  for (int i = 0; i < 12; i++) {
      free(sorted_months_ptr[i]);
  }
  free(sorted_months_ptr);
}

void printMonthlySalesReport(const float sales[12], const char *months[12]) {
  printf("Monthly sales report for 2022:\n");
  printf("\n");
  printf("Month     Sales\n");
  for (int i = 0; i < 12; i++) {
    char* month = padString(months[i], 10);
    printf("%s $%.2f\n", month, sales[i]);
  }
}

void printSalesSummary(const float sales[12], const char *months[12]) {
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

float getSixMonthMovingAverage(const float sales[12], const int start)
{
  float average = 0;
  for (int i = start; i < start + 6; i++) {
    average += sales[i] / 6;
  }
  return average;
}

void printSixMonthMovingAverage(const float sales[12], const char *months[12]) {
  printf("Six-Month Moving Average Report:\n");
  for (int i = 0; i <= 6; i++) {
    printf("%s-\t%s $%.2f\n", padString(months[i], 10), padString(months[i + 5], 10), getSixMonthMovingAverage(sales, i));
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

  const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  printMonthlySalesReport(sales, months);
  printf("\n");
  printSalesSummary(sales, months);
  printf("\n");
  printSixMonthMovingAverage(sales, months);
  printf("\n");
  printSalesReportSorted(sales, months);
}


