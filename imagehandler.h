#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPixmap>

class ImageHandler
{
public:
    ImageHandler();
    ~ImageHandler();
    QPixmap returnCurrentImageAsPixmap();
    void setImageFileName(QString fileName);
    bool checkLoadedImage();

private:
    bool bImageLoaded;
    QString fileName;
    QImage imageFile;
    void readCurrentImageFile();

};

#endif // IMAGEHANDLER_H
