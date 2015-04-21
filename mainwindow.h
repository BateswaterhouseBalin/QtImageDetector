#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <imagehandler.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ImageHandler imHandler;

    void initFunctionality();
    void drawCurrentImage();
    void resizeEvent(QResizeEvent* event);
    void showEvent(QShowEvent *ev);

signals:
      void windowShown();

private slots:
    void handleFileDialog();
    void handleImageCompare();
    void handleWindowInitializationResize();
};

#endif // MAINWINDOW_H
