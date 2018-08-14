#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./defs.h"
void Qsort(struct EmployeeRecord employee[], int start, int finish);//quicksort prototype

void Qsort(struct EmployeeRecord employee[], int start, int finish)
{
    int left,
    right;
    char *pivot=employee[(start+finish)/2].lastName;
    EmployeeRecord temp;
    left=start;
    right=finish;
    while(left<=right)
    {
        while((strcmp(employee[left].lastName, pivot)< 0) &&(left<right)) ++left;
        //find left candidate
       while((strcmp(employee[right].lastName, pivot)> 0) &&(right>left)) --right;
        //find right candidate
        if(left<=right)
        {
            temp=employee[left];
            employee[left]=employee[right];
            employee[right]=temp;
            left++;
            right--;
        }
    }
        if(start<right) Qsort(employee, start, right);
        if(left<finish) Qsort(employee, left, finish);
}


