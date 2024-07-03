#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QRegularExpressionValidator"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1200, 580);
    this->setWindowTitle("排序算法性能分析");
    ui->SizeEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+$")));
    ui->DelayEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+$")));//此两端确定输入的值只能是正整数


    array.InitArray();
    array.ShuffleArray();//数组的初始化和打乱

    Paint();//调用paint更新窗口
}

MainWindow::~MainWindow()
{
    delete ui;
}

ArrayToSort& MainWindow::getArray()
{
    //提供对其他数组的引用，以便其他类可以使用和访问数组
    return array;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // 绘制白色背景
    painter.setBrush(Qt::white);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, this->width(), this->height());

    // 计算画布的有效显示区域
    int effectiveHeight = this->height() - 40; // 上下各留20像素边距
    int effectiveWidth = this->width() - 40;   // 两侧各留20像素边距

    // 获取数组的长度
    int n = getArray().n; // 使用getArray()来获取数组长度

    // 计算每个矩形的宽度和高度比例
    int maxElementValue = n;// 找到数组中的最大值
    int maxHeight = maxElementValue * 4; // 原始最大高度，基于数组最大值乘以4
    int scaleFactor = std::min(
        (effectiveHeight - 20) / maxHeight, // 垂直方向的缩放，保持底部对齐
        (effectiveWidth - 100) / (n * 10) // 水平方向的缩放，基于矩形数量和每两个矩形之间的间隔
        );

    // 计算矩形框的左半边位置，使它们居中
    int left_border = 20+(effectiveWidth - (n * 10 + (n - 1) * 1)) / 2; // 居中计算，假设间隔为1像素

    // 绘制黑色的矩形框
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);
    for (int i = 0; i < n; i++)
    {
        // 根据数组元素值和缩放因子计算矩形的高度
        int originalHeight = getArray().get(i) * 4;
        int scaledHeight = std::min(originalHeight * scaleFactor, effectiveHeight - 20);

        // 计算每个矩形的位置并绘制
        painter.drawRect(
            i * (10 + 1) + left_border, // 宽度为10，间隔为1
            effectiveHeight - scaledHeight-85, // 保持底部在同一水平线
            10,
            scaledHeight
            );
    }
}


void MainWindow::Paint()
{
    // 更新窗口，从而触发 paintEvent
    update();
}



void MainWindow::on_SetSizeButton_clicked()
{
    QString str = ui->SizeEdit->text();
    int newSize = str.toInt();
    array.SetSize(newSize);
    array.InitArray();
    Paint();
}


void MainWindow::on_ButtonShuffle_clicked()
{
    array.ShuffleArray();
    Paint();
}


void MainWindow::on_SetDelayButton_clicked()
{
    QString str = ui->DelayEdit->text();
    this->delay = str.toInt();
}


void MainWindow::on_Button1_Insert_clicked()
{
    emit DoInsertSort();
}


void MainWindow::on_Button2_Binary_clicked()
{
    emit DoBinarySort();
}


void MainWindow::on_Button3_Shell_clicked()
{
    emit DoShellSort();
}


void MainWindow::on_Button4_Bubble_clicked()
{
    emit DoBubbleSort();
}


void MainWindow::on_Button5_Quick_clicked()
{
    emit DoQuickSort();
}


void MainWindow::on_Button6_Selection_clicked()
{
    emit DoSelectionSort();
}


void MainWindow::on_Button7_Heap_clicked()
{
    emit DoHeapSort();
}


void MainWindow::on_Button8_Merge_clicked()
{
    emit DoMergeSort();
}


void MainWindow::on_Button9_Radix_clicked()
{
    emit DoRadixSort(4);
}

