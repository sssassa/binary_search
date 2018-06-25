#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int i, j, l;
    j = x;
    l = 0;
    for(i = 0; i < n && l <= k; i++){
        if(A[i] > x){
            l = k + 1;
        }
        else if(A[i] > j){
            j = x - A[i];
            l = l + 1;
        }
        else {
            j = j - A[i];
        }
    }
    l = l + 1;
    return l <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int m = (lb + ub) / 2;
    if(p(m)){
        ub = m;
    }
    else {
        lb = m;
    }
}
printf("%d\n", ub);
  return 0;
}
