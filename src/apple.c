#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int q,r;
    r = 0;
    for( q= 0;  q < n; q++){
      if(A[q] % x == 0){
        r = r + A[q] / x;
        }
      else {
        r = r + 1 + A[q] / x;
    }
    }
    return r <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    int max = A[0];
    int l;
    for(l = 1; l < n; l++){
        if(A[l] > max){
            max = A[l];
        }
    }

    
  lb = 0;
  ub = max;
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
