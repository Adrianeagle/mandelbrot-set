#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_drawButton_clicked();

	void drawAxis(QPainter &painter);
	void clearWindow(QPainter &painter);
	void drawMandelbrot(QPainter &painter);

private:
    Ui::MainWindow *ui;
    bool startDrawing = false;

	QPoint leftCornerUp;
	QPoint rightCornerDown;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
