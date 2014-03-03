#include "snakegame.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QPalette>
#include <QColor>
#include <QTimer>
#include <QTime>
SnakeGame::SnakeGame():
	foodLen(30),
	food(getFood()),
	timer(new QTimer),
	dir(D_RIGHT)
{
	this->resize(800,600);
	qsrand(QTime::currentTime().msec());
	timer->setInterval(200);
	timer->start();
	datas.push_back(food);
	connect(timer,SIGNAL(timeout()),this,SLOT(snakeMove()));
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::keyPressEvent(QKeyEvent *e)
{
	switch(e->key()){
		case Qt::Key_Up:
			dir=D_UP;
			break;
		case Qt::Key_Down:
			dir=D_DOWN;
			break;
		case Qt::Key_Left:
			dir=D_LEFT;
			break;
		case Qt::Key_Right:
			dir=D_RIGHT;
			break;
		default:break;
	}
}

QLabel* SnakeGame::getFood()
{
	food = new QLabel(this);
	food->resize(foodLen,foodLen);
	food->setAutoFillBackground(true);
	food->setPalette(QPalette(QColor(
		qrand()%255,qrand()%255,qrand()%255)));
	food->setFrameShape(QFrame::Box);
	int w = this->width()-foodLen;
	int h = this->height()-foodLen;
	food->move((qrand()%w)/foodLen*foodLen,(qrand()%h)/foodLen*foodLen);
	food->show();
	return food;
}

void SnakeGame::snakeMove()
{
	int x = datas[0]->x();
	int y = datas[0]->y();
	if (x==food->x() && y==food->y()){
		datas.push_back(food);
		if (datas.size()>40){
			QMessageBox msg(this);
			msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
			msg.setText("Game Over!");
			msg.show();
			if (msg.exec()==QMessageBox::Yes)
				this->close();
		}
		food=getFood();
	}
	for (size_t i=datas.size()-1; i!=0; --i)
		datas[i]->move(datas[i-1]->x(),datas[i-1]->y());
	switch (dir){
		case D_UP:
			y-=foodLen;
			break;
		case D_DOWN:
			y+=foodLen;
			break;
		case D_LEFT:
			x-=foodLen;
			break;
		case D_RIGHT:
			x+=foodLen;
			break;
		default:break;
	}
	datas[0]->move(x,y);
}
