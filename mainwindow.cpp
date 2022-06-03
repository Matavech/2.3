#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (count){
        for(int i=0;i<count;i++){
            Point *point=crossPoint[i];
            point->draw(&painter);
    }
  }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    Point *point = new Point(event->x(),event->y(),3);
    qDebug("x=%d y=%d",event->x(),event->y());
    if(point->valid()){
        if(count<10){
            if(count>=1){
                point->setSize(crossPoint[count-1]->getSize()+1);
                if(count>=5){
                    point->setWidth(2);
             }
                crossPoint[count]=point;
                count++;

            }
            else{
                crossPoint[count]=point;
                count++;
            }

        }
    }
    else delete point;
    repaint();
}


