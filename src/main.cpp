#include "stdafx.h"
#include "MedicalVisualization.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MedicalVisualization w;
	w.show();

	return a.exec();

}
