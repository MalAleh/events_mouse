#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMouseTracking(true);
    //this->setMouseTracking(true);
    if (hasMouseTracking()) {ui->lbl_btn_mouse->setText("Tracking mouse ON");}
    else {ui->lbl_btn_mouse->setText("Tracking mouse OFF");}
    ui->statusbar->addWidget(ui->label_inf_x);
    ui->statusbar->addWidget(ui->label_inf_y);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        ui->lbl_btn_mouse->setText("Press left button mouse");
    }

    if (event->button() == Qt::RightButton)
    {
        ui->lbl_btn_mouse->setText("Press right button mouse");
    }

    if (event->button() == Qt::MidButton)
    {
        ui->lbl_btn_mouse->setText("Press mid button mouse");
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    ui->label_inf_x->setText("X = " + QString().setNum(event->x()));
    ui->label_inf_y->setText("Y = " + QString().setNum(event->y()));

    ui->coord_global->setText("Xg  =" + QString().setNum(event->globalX()) +
                              ", Yg  =" + QString().setNum(event->globalY()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

