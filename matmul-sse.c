#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <emmintrin.h>

void get_walltime(double *wct)
{
    struct timeval tp;
    gettimeofday(&tp,NULL);
    *wct = (double) (tp.tv_sec+tp.tv_usec /1000000.0);
}

int main(int argc, char** argv)
{
    int i,j,k;
    double ts,te ,ct;
    float *a,*b,*c,*z;
    __m128 va, vb,*fa,*fb,*fc;
    float sum;
    
    i=0;
    i=posix_memalign((void**)&a,16,N*N*sizeof(float));
    if (i!=0){
        exit(1);
    }
    
    i=posix_memalign((void**)&b,16,N*N*sizeof(float));
    if (i!=0){
        free(a);
        exit(2);
    }
    
    i=posix_memalign((void**)&c,16,N*N*sizeof(float));
    if (i!=0){
        free(a);
        free(b);
        exit(3);
    }
    
    for (int i=0; i<N*N; i++){
        a[i] = 2.0;
        b[i] = 3.0;
        c[i] = 20.0;
    }
  
    for (i=0; i<4; i++) {
        z[i] = 0.0;
    }
    __m128 *sum = (__m128*) z;
    __m128 tmp;

    get_walltime(&ts);

    fc=c;
    for (k=0;k<N;k++){
        fb=b;
        vb=(__m128*) fb;
        for (j=0;j<N;j++) {
            fa = arra + k*N;
            va = (__m128*) fa;
            *sum = _mm_set_ps(0, 0, 0, 0);
            for (int i=0; i<N; i+=4){
                *sum = _mm_add_ps(*sum, _mm_mul_ps(*va, *vb));
                va++, vb++;
            }
            tmp=_mm_hadd_ps(*sum, *sum);
            *sum=_mm_hadd_ps(tmp, tmp);
            *fc = z[0];
            fc++;
        }
    }

    // Get end time
    get_walltime(&te);

    
    for (int i=0;i<N*N; i++){
        if (c[i] != 6.0 * N){
            printf("Error! \n");
            break;
        }
    }
    
    ct=(N* N) / ((te - ts) * 1e6);
    printf( %f\n", ct);
    
    free(a);
    free(b);
    free(c);
    return 0;
}
