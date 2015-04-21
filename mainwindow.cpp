#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initFunctionality();
    drawCurrentImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initFunctionality()
{
    connect(ui->loadButton,SIGNAL(clicked()),this,SLOT(handleFileDialog()));
    connect(ui->compareButton,SIGNAL(clicked()),this,SLOT(handleImageCompare()));
    connect(this, SIGNAL(windowShown()), this, SLOT(handleWindowInitializationResize()));
}

void MainWindow::handleFileDialog()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("Open Image (.jpg, .png, .bmp"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
    imHandler.setImageFileName(fileName);
    drawCurrentImage();
}

void MainWindow::handleImageCompare()
{
    QMessageBox msgBox;
    msgBox.setText("Image comparison is not yet implemented.");
    msgBox.exec();
}

void MainWindow::handleWindowInitializationResize()
{
    drawCurrentImage();
}

void MainWindow::drawCurrentImage()
{
    QPixmap currentImage;
    currentImage = this->imHandler.returnCurrentImageAsPixmap();
    currentImage = currentImage.scaled(ui->graphicsView->width(),ui->graphicsView->height());
    QGraphicsScene* scene = new QGraphicsScene();
    scene->addPixmap(currentImage);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   if(imHandler.checkLoadedImage() == true)
   {
        drawCurrentImage();
   }
}

void MainWindow::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);
    emit windowShown();
}
