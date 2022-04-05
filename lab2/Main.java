public class Main {
  public static void main(String[] args) {
    int arr[][] = { {0, 1, 2, 3, -2}, {0, 0, -2, 4, -6}, {0, 3, 1, 0, 10},};
    System.out.println("Some matrix:");
    print_mat(arr, 3, 4);
    sort_mat(arr, 3, 4);
    System.out.println("Sorted matrix:");
    print_mat(arr, 3, 4);
    return;
  }
  
  private static void print_mat(int a[][], int m, int n) { 
    for (int i = 0; i < m; i++) { 
        for (int j = 1; j < n + 1; j++) { 
          System.out.printf("%3d ", a[i][j]); 
        } 
        System.out.printf("\n"); 
    } 
  } 

  private static void sort_mat(int a[][], int m, int n) { 
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
}
