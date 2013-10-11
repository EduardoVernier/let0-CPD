#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define maxVal 100000

FILE *fp;
FILE *arrayDef;
int sortSwitch[2], arraySwitch;
long nComp, nSwaps;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fp = fopen("arq.txt", "w");

}

MainWindow::~MainWindow()
{
    fclose(fp);
    delete ui;
}

void MainWindow::on_compareButton_clicked()
{
    arraySwitch = ui->arrayConfig->currentIndex()+1;
    sortSwitch[0] = ui->sortA->currentIndex()+1;
    sortSwitch[1] = ui->sortB->currentIndex()+1;
    fprintf(fp,"%d\n", arraySwitch);

    runSorts();

    exit(0);
}

int MainWindow::runSorts ()
{
    int k, nElem;
    struct timespec tps, tpe;

    for (k=0; k<2; k++)
    {
        fprintf (fp, "%d\n", sortSwitch[k]);
        for (nElem=100; nElem<100001; nElem=nElem*10)
        {
            nSwaps=0;
            nComp=0;
            printf ("%d - ", nElem);
            int *a = (int*) malloc (nElem*sizeof(int));

            if (a==NULL)
                return 0;

            switch (arraySwitch)
            {
            case 1:
                randomArray(a, nElem,maxVal);
                break;
            case 2:
                sortedArray(a,nElem);
                break;
            case 3:
                reversedArray(a,nElem);
                break;
            case 4:
                definedArray(a,nElem);
                break;
            default:
                return 0;
            }

            switch(sortSwitch[k])
            {
            case 1:
                clock_gettime(CLOCK_REALTIME, &tps);
                insertionSort(a,nElem);
                clock_gettime(CLOCK_REALTIME, &tpe);
                printf("insertionSort\n");
                break;

            case 2:
                clock_gettime(CLOCK_REALTIME, &tps);
                shellSort(a,nElem);
                clock_gettime(CLOCK_REALTIME, &tpe);
                printf("shellSort\n");
                break;
            case 3:
                clock_gettime(CLOCK_REALTIME, &tps);
                bubbleSort(a,nElem);
                clock_gettime(CLOCK_REALTIME, &tpe);
                printf("bubbleSort\n");
                break;
            case 4:
                clock_gettime(CLOCK_REALTIME, &tps);
                heapsort(a,nElem);
                clock_gettime(CLOCK_REALTIME, &tpe);
                printf("heapSort\n");
                break;

            case 5:
                clock_gettime(CLOCK_REALTIME, &tps);
                countingSort(a,nElem);
                clock_gettime(CLOCK_REALTIME, &tpe);
                printf("countingSortSort\n");
                break;
            case 6:
                clock_gettime(CLOCK_REALTIME, &tps);
                mergeSort(a,nElem);
                clock_gettime(CLOCK_REALTIME, &tpe);
                printf("mergeSort\n");
                break;
            case 7:
                clock_gettime(CLOCK_REALTIME, &tps);
                quickSort(a,0,nElem);
                clock_gettime(CLOCK_REALTIME, &tpe);
                printf("quickSort\n");
                break;
            }

            printf("%d %lu %lu %lu %lu\n", nElem, tpe.tv_sec-tps.tv_sec, tpe.tv_nsec-tps.tv_nsec, nComp,nSwaps);
            fprintf(fp, "%d %lu %lu %lu %lu\n",  nElem, tpe.tv_sec-tps.tv_sec, tpe.tv_nsec-tps.tv_nsec, nComp,nSwaps);

            free (a);
        }
    }
return 1;
}




/*-------------------------INSERTION-------------------------------*/
void MainWindow::insertionSort (int *a, int aSize)
{
    int temp;
    int i,j;

    for (i=1; i<aSize; i++)
    {
        temp = a[i];
        for (j=i-1; temp<a[j]&&j>=0; --j)
        {
            a[j+1]=a[j];
            nSwaps++;
            nComp++;
        }
        a[j+1]=temp;
    }
}


/*---------------------------SHELL-------------------------------*/
void MainWindow::shellSort (int *a, int aSize)
{
    int h = 1;
    int offset=0;
    int si,sj;
    int temp;

    while (h<aSize)
        h =3*h +1;
    h = h/3;

    for (; h>0; h=h/3)
    {
        for (offset=0; offset<h; offset++)
        {
            for (si=offset+h; si<aSize; si=si+h)
            {
                temp = a[si];
                for (sj=si-h; sj>=0 && temp<a[sj]; sj=sj-h)
                {
                    a[sj+h] = a[sj];
                    nComp++;
                    nSwaps++;
                }
                a[sj+h]=temp;
            }
        }
    }
}


/*-------------------------BUBBLE-----------------------------*/
void MainWindow::bubbleSort (int *a, int aSize)
{
    int i=0, j=0, temp;

    for (j=0;j<aSize-1;j++)
    {
        for (i=0; i<aSize; i++)
        {
            if (a[i]>a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                nSwaps++;
            }
            nComp++;
        }
    }
}



/*-------------------------HEAP-------------------------------*/
void MainWindow::maxHeapify(int *array, int index, int arraySize)
{
    const int heapRoot = array[index];
    const int leftChildIndex = index*2 + 1,
        rightChildIndex = index*2 + 2;
    int leftChild, rightChild;
    if (leftChildIndex >= arraySize) return;
    else if (rightChildIndex >= arraySize)
    {
        nComp++;
        nSwaps++;
        rightChild = INT_MIN;
    }
    else rightChild = array[rightChildIndex];
    leftChild = array[leftChildIndex];

    int biggestChildIndex = (rightChild > leftChild) ? rightChildIndex : leftChildIndex;

    if (heapRoot < array[biggestChildIndex])
    {

        int temp = heapRoot;
        array[index] = array[biggestChildIndex];
        array[biggestChildIndex] = temp;
        maxHeapify(array, biggestChildIndex, arraySize);
    }
}

void MainWindow::buildMaxHeap(int *array, int arraySize)
{
    int i;
    for (i = arraySize / 2 - 1; i >= 0; i--)
    {
        maxHeapify(array, i, arraySize);
    }
}

void MainWindow::heapsort(int *array, int arraySize)
{
    buildMaxHeap(array, arraySize);
    while (arraySize > 0)
    {
        int temp = array[0];
        array[0] = array[arraySize - 1];
        array[arraySize-1] = temp;
        maxHeapify(array,0,--arraySize);
    }
}

/*---------------------COUNTING---------------*/
void MainWindow::countingSort(int arr[], int sz) {
    int i, j, k;
    int idx = 0;
    int min, max;

    min = max = arr[0];
    for(i = 1; i < sz; i++) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }

    k = max - min + 1;
    /* creates k buckets */
    int *B = new int [k];
    for(i = 0; i < k; i++) B[i] = 0;

    for(i = 0; i < sz; i++) B[arr[i] - min]++;
    for(i = min; i <= max; i++)
        for(j = 0; j < B[i - min]; j++) arr[idx++] = i;

    delete [] B;
}



/*---------------------MERGE-------------------*/
void MainWindow::merge(int vec[], int vecSize) {
    int mid;
    int i, j, k;
    int* tmp;

    tmp = (int*) malloc(vecSize * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    }

    mid = vecSize / 2;

    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < vecSize) {
        if (vec[i] < vec[j]) {
            tmp[k] = vec[i++];
        }
        else {
            tmp[k] = vec[j++];
        }
        ++k;
    }

    if (i == mid) {
        while (j < vecSize) {
            tmp[k++] = vec[j++];
        }
    }
    else {
        while (i < mid) {
            tmp[k++] = vec[i++];

        }
    }

    for (i = 0; i < vecSize; ++i) {
        vec[i] = tmp[i];
    }

    free(tmp);
}

void MainWindow::mergeSort(int vec[], int vecSize) {
    int mid;

    if (vecSize > 1) {
        mid = vecSize / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, vecSize - mid);
        merge(vec, vecSize);
    }
}



/*----------------QUICK---------------*/
void MainWindow::quickSort(int *vetor, int inicio, int fim)
{
   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) quickSort(vetor, inicio, j);
   if(i < fim) quickSort(vetor, i, fim);

}










/*---------------------ARRAY OPERATIONS---------------*/
void MainWindow::randomArray (int *a, int aSize, int maxValue)
{
    int newValue;
    int i;

    srand(time(NULL));

    for (i=0; i<aSize; i++)
    {
        newValue = rand() % (maxValue);
        a [i] = newValue;
    }
}

void MainWindow::sortedArray (int *a, int aSize)
{
    int i;
    for (i=0;i<aSize;i++)
        a[i]= i;
}

void MainWindow::reversedArray (int *a, int aSize)
{
    int i;
    for (i=aSize;i>=0;i--)
        a[i]= aSize - i;
}

void MainWindow::printArray (int*a,int aSize)
{
    int i;
    for (i=0;i<aSize;i++)
        printf (" %i ", a[i]);
    printf("\n");
}

int MainWindow::isSorted (int*a, int aSize, long *nComp)
{
    int i;

    for (i=0; i<aSize-1;i++)
    {
        if (!(a[i]<=a[i+1]))
            return 0;
        (*nComp)++;
    }
    return 1;
}

int MainWindow::bSearch (int*a, int aSize, int toBeFound)
{
    int* lB = a;
    int* uB = a + aSize-1; //upper boundarie
    int middle = aSize/2;
    int* current = a + middle;
    //printf ("%d  %d  %d \n\n", *lB, *current,*uB);

    while (*current!=toBeFound)
    {
        //printf(" %d ", *current);
        if (lB==uB)
            return 0;
        else
            if (*current>toBeFound)
                uB = current;
            else
                lB = current;

        middle = middle/2;
        current = lB + middle;
    }
    if (*current==toBeFound)
        return 1;
    return 0;
}

void MainWindow::definedArray(int*a,int nElem)
{
    arrayDef = fopen ( "randomnumbers.bin", "rb" );

    rewind( arrayDef );

    if( 1!=fread( a , nElem*(sizeof(int)), 1 , arrayDef) )
      fclose(arrayDef),free(a),fputs("entire read fails",stderr),exit(1);

    rewind( arrayDef );

}
