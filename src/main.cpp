#include "stdafx.h"
#include "MedicalVisualization.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MedicalVisualization w;
	w.show();

	return a.exec();

}
