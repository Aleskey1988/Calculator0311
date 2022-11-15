#include "Calc.h"

Calc::Calc()
{
}
Calc::~Calc()
{
}

void Calc::SetDigit(int digit)
{
	if (!isOperationSet)
	{
		if (firstNumber == "0")
		{
			firstNumber = QString::number(digit);
		}
		else
		{
			firstNumber += QString::number(digit);
		}
		emit inputChanged(firstNumber);
	}
	else
	{
		if (secondNumber == "0")
		{
			secondNumber = QString::number(digit);
		}
		else
		{
			secondNumber += QString::number(digit);
		}
		emit inputChanged(secondNumber);
	}
}
void Calc::SetOperation(Operation op)
{
	isOperationSet = true;
	this->op = op;
}
void Calc::SetPlusMinus()
{
	if (!isOperationSet)
	{
		if (firstNumber != "0")
		{
			if (firstNumber[0] != "-")
				firstNumber = "-" + firstNumber;
			else
				firstNumber.remove(0, 1);
		}
		emit inputChanged(firstNumber);
	}
	else
	{
		if (secondNumber != "0")
		{
			if (secondNumber[0] != "-")
				secondNumber = "-" + secondNumber;
			else
				secondNumber.remove(0, 1);
		}
		emit inputChanged(secondNumber);
	}
}
void Calc::SetComma()
{
}
void Calc::Clear()
{
}
void Calc::RemoveSymbol()
{
}
void Calc::DivideOneByX()
{
}
void Calc::Square()
{
}
void Calc::SquareRoot()
{
}
void Calc::Equal()
{
	double num1 = firstNumber.toDouble();
	double num2 = secondNumber.toDouble();
	double res = 0.0;
	if (op == Operation::Add)
		res = num1 + num2;
	else if (op == Operation::Sub)
		res = num1 - num2;
	else if (op == Operation::Mul)
		res = num1 * num2;
	else if (op == Operation::Div)
	{
		if (num2 == 0)
		{
			emit inputChanged("Division by zero");
			return;
		}
		else
			res = num1 / num2;
	}
	QString resStr = QString::number(res, 'f', 3);
	QString simplifiedResStr = simplifyResult(resStr);
	emit inputChanged(simplifiedResStr);
}

QString Calc::simplifyResult(QString str)
{
	while (str[str.length() - 1] == '0')
		str.chop(1);
	if (str[str.length() - 1] == '.')
		str.chop(1);
	return str;
}
