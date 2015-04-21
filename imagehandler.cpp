#include "imagehandler.h"
#include <QFileDialog>
#include <QtGui>

ImageHandler::ImageHandler()
{
    fileName = ":/images/bwb.jpg";
    bImageLoaded = false;
    readCurrentImageFile();
}

ImageHandler::~ImageHandler()
{

}

void ImageHandler::setImageFileName(QString newFileName){
    fileName = newFileName;
    readCurrentImageFile();
}

void ImageHandler::readCurrentImageFile(){
    imageFile = QImage(fileName);
    bImageLoaded = true;
}

QPixmap ImageHandler::returnCurrentImageAsPixmap(){
    return QPixmap::fromImage(imageFile);
}

bool ImageHandler::checkLoadedImage(){
    return bImageLoaded;
}
