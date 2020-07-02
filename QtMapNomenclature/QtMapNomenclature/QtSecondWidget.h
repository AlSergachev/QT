#pragma once

#include <QWidget>
#include "ui_QtSecondWidget.h"
#include "qmessagebox.h"


class QtSecondWidget : public QWidget
{
	Q_OBJECT

public:
	QtSecondWidget(double &x, double &y, QWidget* parent = Q_NULLPTR);
	~QtSecondWidget();
	Ui::QtSecondWidget ui;

private:
	QString X, Y, QN1, QN2, QN_re;
};

class One_million : public QtSecondWidget 
{
public:
	One_million(double m_sx, double m_sy, double& x, double& y, QtSecondWidget* UU);
	~One_million();

private:
	double sx;						//��� �� �
	double sy;						//��� �� Y
	int columnNumber;				//����� ������� � �����������
	int stringNumber;				//����� ������ � �����������
	int z;							//���������� ���������
	int m;							//���������� �����
	int n;							//���������� ��������
	double north_result, south_result, west_result, east_result;
public:
	void coordinateTransformation(double& value, QString side, QtSecondWidget* UU);		//��������� �������� ����� � ����, ���, ���(�������������) � ������� ��� ��������
	char StringNumber(double& x, double& y);											//O��������� ����� ������ �������� � 1:1 000 000
	int ColumnNumber(double& x, double& y);												//O��������� ����� ������� �������� � 1:1 000 000
	double setBorder(double& x, double& y, QString side);								//O��������� ������� �������� � 1:1 000 000
	void getBorder(double& x, double& y, QtSecondWidget* th_s);							//������� �������� ����� ��������

};