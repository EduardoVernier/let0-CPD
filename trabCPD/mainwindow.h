#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int runSorts();
    void insertionSort (int *a, int aSize, long *nComp, long *nSwaps);
    void shellSort (int *a, int aSize, long *nComp, long *nSwaps);
    void bubbleSort (int *a, int aSize, long *nComp, long *nSwaps);
    void buildMaxHeap(int *array, int arraySize);
    void heapsort(int *array, int arraySize);
    void maxHeapify(int *array, int index, int arraySize);
    void randomArray (int *a, int aSize, int maxValue);
    void sortedArray (int *a, int aSize);
    void reversedArray (int *a, int aSize);
    int isSorted (int*a, int aSize, long *nComp);
    int bSearch (int*a, int aSize, int toBeFound);
    void printArray (int*a,int aSize);
    void definedArray(int*a,int nElem);
    void countingSort(int arr[], int sz);
    void mergeSort(int vec[], int vecSize);
    void merge(int vec[], int vecSize);


private slots:
    void on_compareButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
