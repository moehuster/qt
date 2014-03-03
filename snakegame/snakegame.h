#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <QDialog>
#include <QList>
#include <QLabel>
enum DIRECTION{D_UP,D_DOWN,D_LEFT,D_RIGHT};
class SnakeGame : public QDialog
{
	Q_OBJECT
private:
	QList<QLabel*> datas;
	int foodLen;
	QLabel* food;
	QTimer* timer;
	DIRECTION dir;
public:
	SnakeGame();
	~SnakeGame();
public:
	void keyPressEvent(QKeyEvent *e);
	QLabel* getFood();
public slots:
	void snakeMove();
};
#endif
