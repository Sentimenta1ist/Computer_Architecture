#include  "stdio.h"

void print_mat(int a[3][4], int m, int n) 
{ 
    for (int i = 0; i < m; i++) { 
        for (int j = 1; j < n + 1; j++) { 
            printf("%3d ", a[i][j]); 
        } 
        printf("\n"); 
    } 
} 

void sort_mat(int a[3][4], int m, int n) { 
    int l;
    for(int k = 0; k < m; k++){
        for (int i = 2; i < n+1; i++){
            a[k][0] = a[k][i];
            l = i;
            while (a[k][0] < a[k][l-1]){
                a[k][l] = a[k][l - 1];
                l--;
            }
            a[k][l] = a[k][0];
        }
    }
} 

int main(){
    int arr[3][4] = { {0, 1, 2, 3},
                      {0, 0, -2, 4},
                      {0, 3, 1, 0},};

    printf("Some matrix:\n");
    print_mat(arr, 3, 3);
    
    sort_mat(arr, 3, 3);
    
    printf("Sorted matrix:\n");
    print_mat(arr, 3, 3);
    return 0;
}

