#pragma once

#include <QObject>
#include <QString>
#include "CommonData.h"

class Calc : public QObject
{
	Q_OBJECT

public:
	Calc();

	void SetDigit(int digit);
	void SetOperation(Operation op);
	void SetPlusMinus();
	void SetComma();
	void Clear();
	void RemoveSymbol();
	void DivideOneByX();
	void Square();
	void SquareRoot();
	void Equal();

signals:
	void inputChanged(QString value);

private:
	QString simplifyResult(QString str);
	void SimplifyResultAndEmit(double result);

	QString firstNumber = "0";
	QString secondNumber = "0";
	Operation op;
	bool isOperationSet = false;
};
