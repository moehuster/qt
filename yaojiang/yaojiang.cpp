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
	names[0] = "test1";
	names[1] = "test2";
	names[2] = "test3";
	names[3] = "test4";
	names[4] = "test5";
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
		int num = qrand()%5+1;
		QString imgpath = ":/images/"+QString::number(num)+".jpg";
		img.load(imgpath);
		ui->label->setText(names[num-1]);
	}
	qp.drawImage(40,60,img,0,0,320,480);
}

void YaoJiang::changeflag()
{
	if (((QPushButton*)sender())->text()=="Start")
		flag = true;
	else flag = false;
}
