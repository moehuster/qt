#ifndef  yaojiang_INC
#define  yaojiang_INC
#include <QPainter>
#include <QDialog>
#include <QTimer>
#include <QTime>
namespace Ui{
	class YaoJiang;
}
class YaoJiang : public QDialog
{
	Q_OBJECT
public:
	explicit YaoJiang(QWidget* parent=0);
	~YaoJiang();
private:
	Ui::YaoJiang *ui;
	QImage img;
	QTimer *timer;
	QString names[14];
	bool flag;
public slots:
	void changeflag();
public:
	void paintEvent(QPaintEvent *e);
};
#endif   /* ----- #ifndef yaojiang_INC  ----- */
