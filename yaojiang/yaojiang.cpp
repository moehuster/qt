#include <cstdio>
#include "yaojiang.h"
#include "ui_yaojiang.h"

YaoJiang::YaoJiang(QWidget *parent):
	QDialog(parent),
	ui(new Ui::YaoJiang),
	timer(new QTimer),
	flag(false)
{
	ui->setupUi(this);
	timer->setInterval(200);
	timer->start();
    for (int i=0; i<14; i++)
    {
        char buf[16] = {0};
        sprintf(buf, "Test%d", i+1);
        names[i] = buf;
    }
	qsrand(QTime::currentTime().msec());
	connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
	connect(ui->start,SIGNAL(clicked()),this,SLOT(changeflag()));
	connect(ui->stop,SIGNAL(clicked()),this,SLOT(changeflag()));
}

YaoJiang::~YaoJiang()
{
	delete ui; ui = NULL;
}

void YaoJiang::paintEvent(QPaintEvent *e)
{
	QPainter qp(this);
	if (flag){
		int num = qrand()%14+1;
		QString imgpath = ":/images/"+QString::number(num)+".jpg";
		img.load(imgpath);
		ui->label->setText(names[num-1]);
	}
	qp.drawImage(40,50,img,0,0,320,480);
}

void YaoJiang::changeflag()
{
	if (((QPushButton*)sender())->text()=="Start")
		flag = true;
	else flag = false;
}
