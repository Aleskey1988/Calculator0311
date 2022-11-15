#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"
#include "Calc.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	void onSetDigit(int digit);
	void onSetOperation(Operation op);
	void onSetPlusMinus();
	void onEqual();
	
	void onInputChanged(QString str);

	Ui::MainWindowClass ui;
	Calc calc;
};
