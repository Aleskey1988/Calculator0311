#include "Calc.h"

Calc::Calc()
{
}

void Calc::SetDigit(int digit)
{
	if (!isOperationSet)
	{
		if (firstNumber == "0")
			firstNumber = QString::number(digit);
		else
			firstNumber += QString::number(digit);
		emit inputChanged(firstNumber);
	}
	else
	{
		if (secondNumber == "0")
			secondNumber = QString::number(digit);
		else
			secondNumber += QString::number(digit);
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
	if (!isOperationSet)
	{
		if (firstNumber.indexOf(",") == -1)
			firstNumber += ",";
		emit inputChanged(firstNumber);
	}
	else
	{
		if (secondNumber.indexOf(",") == -1)
			secondNumber += ",";
		emit inputChanged(secondNumber);
	}
}
void Calc::Clear()
{
	// TODO: implement
}
void Calc::RemoveSymbol()
{
	// TODO: implement
}
void Calc::DivideOneByX()
{
	// TODO: implement
}
void Calc::Square()
{
	double num = firstNumber.toDouble();
	double result = num * num;
	SimplifyResultAndEmit(result);
}
void Calc::SquareRoot()
{
	// TODO: implement
}
void Calc::Equal()
{
	QString modifiedFirstNumber = firstNumber.replace(",", ".");
	QString modifiedSecondNumber = secondNumber.replace(",", ".");
	double num1 = modifiedFirstNumber.toDouble();
	double num2 = modifiedSecondNumber.toDouble();
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
	SimplifyResultAndEmit(res);
}

QString Calc::simplifyResult(QString str)
{
	if (str.contains("."))
	{
		while (str[str.length() - 1] == '0')
			str.chop(1);
		if (str[str.length() - 1] == '.')
			str.chop(1);
	}
	return str;
}
void Calc::SimplifyResultAndEmit(double result)
{
	QString resStr = QString::number(result, 'f', 3);
	QString simplifiedResStr = simplifyResult(resStr);
	emit inputChanged(simplifyResult(resStr));
}
