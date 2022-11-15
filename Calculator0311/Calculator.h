#pragma once

#include <QObject>

class Calculator : public QObject
{
	Q_OBJECT

public:
	Calculator(QObject *parent = nullptr);
	~Calculator();
};
