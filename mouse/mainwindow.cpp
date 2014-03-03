#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent):
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui; ui=NULL;
}

void MainWindow::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type()){
		case QEvent::LanguageChange:
			ui->retranslateUi(this);
			break;
		default :break;
	}
}

#include <QMouseEvent>
void MainWindow::mousePressEvent(QMouseEvent *e)
{
	qDebug("mouse pressed: (%d,%d)",e->x(),e->y());
	if (e->button()==Qt::RightButton)
		qDebug("mouse right pressed");
	else if (e->button()==Qt::LeftButton)
		qDebug("mouse left pressed");
}

#include <QCursor>
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
	qDebug("mouse move: (%d,%d)",QCursor::pos().x(),QCursor::pos().y());
}
#include <QKeyEvent>
void MainWindow::keyPressEvent(QKeyEvent *e)
{
	switch(e->key()){
		case Qt::Key_Left:
				qDebug("left direction");
				break;
		case Qt::Key_Up:
				qDebug("up direction");
				break;
		default: break;
	}
}
