
#include <iostream>

using namespace std;


static void mergeSort(int* pmainArr );
static void divide(int *pmainArr,int lo,int hi);
static void merge(int* pmainArr,int lo,int mid,int hi);
int main()
{
    int myArr[5] = {0,5,1,3,2};
    mergeSort(myArr);

    cout<<myArr[0]<<endl;
}

static void mergeSort(int* pmainArr )
{
    int lo = 0;
    int hi = sizeof(pmainArr);
    divide(pmainArr,lo,hi);
}

static void divide(int *pmainArr,int lo,int hi)
{
    int mid = lo+(hi-lo)/2;
    if(lo<hi)
    {
        divide(pmainArr,lo,mid);
        divide(pmainArr,mid+1,hi);
        merge(pmainArr, lo,mid,hi);
    }
}
static void merge(int* pmainArr,int lo,int mid,int hi)
{
    int aux[sizeof(pmainArr)+1]={0};
    for (int k = lo; k <= hi; k++) {
        aux[k] = pmainArr[k]; 
    }

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) 
    {
        if      (i > mid)         pmainArr[k] = aux[j++];
        else if (j > hi)          pmainArr[k] = aux[i++];
        else if ((aux[i]>aux[j])) pmainArr[k] = aux[j++];
        else if ((aux[i]<aux[j])) pmainArr[k] = aux[i++];
        else                      pmainArr[k] = aux[i++];
    }
}