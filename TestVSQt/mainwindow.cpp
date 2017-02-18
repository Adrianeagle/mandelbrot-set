#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Complex.h"

#include <QMessageBox>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	leftCornerUp.setX(30);
	leftCornerUp.setY(30);
	rightCornerDown.setX(this->width() - 30);
	rightCornerDown.setY(450);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter( this);
    if(startDrawing)
    {
		drawAxis(painter);
		drawMandelbrot(painter);
    }
}

void MainWindow::on_drawButton_clicked()
{
    this->startDrawing = true;
    update();
}

void MainWindow::drawAxis(QPainter &painter)
{
	painter.setPen(Qt::black);	
	QPoint *axisPoints = new QPoint[20];

	double length = (this->width() - 80) / 3;

	//X Axis
	axisPoints[0].setX(30);
	axisPoints[0].setY(this->height() / 2 - 30);
	axisPoints[1].setX(40);
	axisPoints[1].setY(this->height() / 2 - 30);
	axisPoints[2].setX(40);
	axisPoints[2].setY(this->height() / 2 - 35);
	axisPoints[3].setX(40);
	axisPoints[3].setY(this->height() / 2 - 25);
	axisPoints[4].setX(40);
	axisPoints[4].setY(this->height() / 2 - 30);
	axisPoints[5].setX(this->width() - 30);
	axisPoints[5].setY(this->height() / 2 - 30);
	axisPoints[6].setX(this->width() - 40);
	axisPoints[6].setY(this->height() / 2 - 30);
	axisPoints[7].setX(this->width() - 40);
	axisPoints[7].setY(this->height() / 2 - 35);
	axisPoints[8].setX(this->width() - 40);
	axisPoints[8].setY(this->height() / 2 - 25);
	axisPoints[9].setX(this->width() - 40);
	axisPoints[9].setY(this->height() / 2 - 30);
	axisPoints[10].setX(this->width() - 40 - length);
	axisPoints[10].setY(this->height() / 2 - 30);

	//Y Axis
	axisPoints[11].setX(this->width() - 40 - length);
	axisPoints[11].setY(this->height() / 2 - 40 - length);
	axisPoints[12].setX(this->width() - 40 - length);
	axisPoints[12].setY(this->height() / 2 - 30 - length);
	axisPoints[13].setX(this->width() - 45 - length);
	axisPoints[13].setY(this->height() / 2 - 30 - length);
	axisPoints[14].setX(this->width() - 35 - length);
	axisPoints[14].setY(this->height() / 2 - 30 - length);
	axisPoints[15].setX(this->width() - 40 - length);
	axisPoints[15].setY(this->height() / 2 - 30 - length);
	axisPoints[16].setX(this->width() - 40 - length);
	axisPoints[16].setY(this->height() / 2 - 20 + length);
	axisPoints[17].setX(this->width() - 40 - length);
	axisPoints[17].setY(this->height() / 2 - 30 + length);
	axisPoints[18].setX(this->width() - 45 - length);
	axisPoints[18].setY(this->height() / 2 - 30 + length);
	axisPoints[19].setX(this->width() - 35 - length);
	axisPoints[19].setY(this->height() / 2 - 30 + length);

	painter.drawPolyline(axisPoints, 20);

	delete[]axisPoints;
	return;
}

void MainWindow::drawMandelbrot(QPainter &painter) {
	double length = (this->width() - 80) / 3;
	int maxIteration = 50;
	int maxMagnitude = 2;

	for (double y = this->height() / 2 - 30 - length; y <= this->height() - 30 + length; ++y) {
		for (double x = 40; x <= this->width() - 40; ++x) {
			double realPart = (x - 40) / (this->width() - 80) * 3 - 2;
			double imaginaryPart = (y - (this->height() / 2 - 30 - length)) / (2 * length) * -2 + 1;
			int iterator = 0;
			bool drawPoint = true;
			Complex<double> originalComplex(realPart, imaginaryPart);
			Complex<double> computedComplex(0, 0);

			while (iterator < maxIteration) {
				computedComplex = computedComplex.computeSquare() + originalComplex;
				if (computedComplex.returnMagnitude() > maxMagnitude) {
					drawPoint = false;
					break;
				}
				++iterator;
			}
			if (drawPoint) {
				painter.drawPoint(x, y);
			}
		}
	}
	return;
}

void MainWindow::clearWindow(QPainter &painter) {
	painter.eraseRect(0, 0, this->width(), this->height());
	return;
}
