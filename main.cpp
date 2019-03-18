#include "bovwtrainer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BoVWTrainer w;
	w.show();
	return a.exec();
}
