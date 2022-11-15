#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.button_0, &QPushButton::clicked, this, [=] { onSetDigit(0); });
	connect(ui.button_1, &QPushButton::clicked, this, [=] { onSetDigit(1); });
	connect(ui.button_2, &QPushButton::clicked, this, [=] { onSetDigit(2); });
	connect(ui.button_3, &QPushButton::clicked, this, [=] { onSetDigit(3); });
	connect(ui.button_4, &QPushButton::clicked, this, [=] { onSetDigit(4); });
	connect(ui.button_5, &QPushButton::clicked, this, [=] { onSetDigit(5); });
	connect(ui.button_6, &QPushButton::clicked, this, [=] { onSetDigit(6); });
	connect(ui.button_7, &QPushButton::clicked, this, [=] { onSetDigit(7); });
	connect(ui.button_8, &QPushButton::clicked, this, [=] { onSetDigit(8); });
	connect(ui.button_9, &QPushButton::clicked, this, [=] { onSetDigit(9); });

	connect(ui.button_add, &QPushButton::clicked, this, [=] { onSetOperation(Operation::Add); });
	connect(ui.button_sub, &QPushButton::clicked, this, [=] { onSetOperation(Operation::Sub); });
	connect(ui.button_mul, &QPushButton::clicked, this, [=] { onSetOperation(Operation::Mul); });
	connect(ui.button_div, &QPushButton::clicked, this, [=] { onSetOperation(Operation::Div); });

	connect(ui.button_plusminus, &QPushButton::clicked, this, &MainWindow::onSetPlusMinus);
	connect(ui.button_equal, &QPushButton::clicked, this, &MainWindow::onEqual);

	connect(&calc, &Calc::inputChanged, this, &MainWindow::onInputChanged);
}

void MainWindow::onSetDigit(int digit)
{
	calc.SetDigit(digit);
}
void MainWindow::onSetOperation(Operation op)
{
	calc.SetOperation(op);
}
void MainWindow::onSetPlusMinus()
{
	calc.SetPlusMinus();
}
void MainWindow::onEqual()
{
	calc.Equal();
}
void MainWindow::onInputChanged(QString str)
{
	ui.edit_input->setText(str);
}
