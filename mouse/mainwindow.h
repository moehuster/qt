#ifndef  mainwindow_INC
#define  mainwindow_INC
#include <QMainWindow>
namespace Ui{class MainWindow;}
class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent=0);
	~MainWindow();
protected:
	void changeEvent(QEvent *e);
private:
	Ui::MainWindow *ui;
public:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void keyPressEvent(QKeyEvent *e);
};
#endif   /* ----- #ifndef mainwindow_INC  ----- */
