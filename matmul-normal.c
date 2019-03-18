#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void get_walltime(double *wct) {
  struct timeval tp;
  gettimeofday(&tp,NULL);
  *wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);
}


int main(int argc, char** argv)
{
int i,j,k;
float *a,*b,*c;
float *fa,*fb,*fc;
float sum;
double ts,te,aps;


  a = (float *)malloc(N*N*sizeof(float)); 
  if (a==NULL) {
    printf("error!\n");
    exit(-1);
  }

  b = (float *)malloc(N*N*sizeof(float)); 
  if (b==NULL) {
    printf("error!\n");
    free(a);
    exit(-1);
  }
  c = (float *)malloc(N*N*sizeof(float)); 
  if (c==NULL) {
    printf("error!\n");
    free(a);
    free(b);
    exit(-1);
  }


  for (i=0;i<N*N;i++) {
     a[i] = 2.0;
     b[i] = 3.0;
     c[i] = 20.0;
  } 

  // get starting time (double, seconds) 
  get_walltime(&ts);
  
  fc=c;
  for (k=0;k<N;k++) {
    fb=b;
    for (j=0;j<N;j++) {
      fa=a+k*N;
      sum=0.0;
      for(i=0; i<N; i++){
        sum = sum + (*pa) * (*pb);
                pa++;
                pb++;
      }
      *fc = sum;
            fc++;
    }
  }

  // get ending time
  get_walltime(&te);

 
 for (int i=0; i<N*N; i++) {
        if (arrc[i] != 6 * N) {
            printf("Error!\n");
            break;
        }
    }

  
 
  aps = (N*N)/((te-ts)*1e6);
  
  printf("%f\n",aps);

  free(b);
  free(a);
  free(c);
 

  return 0;
}
