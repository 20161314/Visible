#include "mainwindow.h"

#include <QApplication>

#include "InsertSort.h"
#include "BinarySort.h"
#include "ShellSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "RadixSort.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
  //将各种排序算法与主窗口的实例相关联
    InsertSort    *insertSort =    new InsertSort(&w);
    BinarySort    *binarySort =    new BinarySort(&w);
    ShellSort     *shellSort =     new ShellSort(&w);
    BubbleSort    *bubbleSort =    new BubbleSort(&w);
    QuickSort     *quickSort =     new QuickSort(&w);
    SelectionSort *selectionSort = new SelectionSort(&w);
    HeapSort      *heapSort =      new HeapSort(&w);
    MergeSort     *mergeSort =     new MergeSort(&w);
    RadixSort     *radixSort =     new RadixSort(&w);
    // 连接MainWindow的信号到各个排序算法的startSort槽函数
    // 当MainWindow发出特定信号时，相应的排序算法将开始执行

    QObject::connect(&w, &MainWindow::DoInsertSort, insertSort, &InsertSort::startSort);
    QObject::connect(&w, &MainWindow::DoBinarySort, binarySort, &BinarySort::startSort);
    QObject::connect(&w, &MainWindow::DoShellSort, shellSort, &ShellSort::startSort);
    QObject::connect(&w, &MainWindow::DoBubbleSort, bubbleSort, &BubbleSort::startSort);
    QObject::connect(&w, &MainWindow::DoQuickSort, quickSort, &QuickSort::startSort);
    QObject::connect(&w, &MainWindow::DoSelectionSort, selectionSort, &SelectionSort::startSort);
    QObject::connect(&w, &MainWindow::DoHeapSort, heapSort, &HeapSort::startSort);
    QObject::connect(&w, &MainWindow::DoMergeSort, mergeSort, &MergeSort::startSort);
    QObject::connect(&w, &MainWindow::DoRadixSort, radixSort, &RadixSort::startSort);



    return a.exec();//进入事件循环
}
