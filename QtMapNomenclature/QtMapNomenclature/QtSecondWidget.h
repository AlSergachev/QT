#pragma once

#include <QWidget>
#include "ui_QtSecondWidget.h"
#include "qmessagebox.h"


class QtSecondWidget : public QWidget
{
	Q_OBJECT

public:
	QtSecondWidget(double &x, double &y, QString scale, QWidget* parent = Q_NULLPTR);
	~QtSecondWidget();
	Ui::QtSecondWidget ui;

private:
	QString X, Y, QN1, QN2, QN_One_million, QN3, QN_One_hundred_thousand;
};

class One_million
{

protected:
	double sx;						//��� �� �
	double sy;						//��� �� Y
	int columnNumber;				//����� ������� � �����������
	int stringNumber;				//����� ������ � �����������
	int z;							//���������� ���������
	int m;							//���������� �����
	int n;							//���������� ��������
	double north_result, south_result, west_result, east_result;

public:
	One_million(double m_sx, double m_sy);
	~One_million();

	void coordinateTransformation(double& value, QString side, QtSecondWidget* UU);		//��������� �������� ����� � ����, ���, ���(�������������) � ������� ��� ��������
	char StringNumber(double& x, double& y);											//O��������� ����� ������ �������� � 1:1 000 000
	int ColumnNumber(double& x, double& y);												//O��������� ����� ������� �������� � 1:1 000 000
	double setBorder1m(double& x, double& y, QString side);								//O��������� ������� �������� � 1:1 000 000
	void getBorder1m(double& x, double& y, QtSecondWidget* th_s);							//������� �������� ����� ��������

};

class One_hundred_thousand: public One_million 
{
private:
	//double sx = 1. / 3;			//��� �� �
	//double sy = 0.5;			//��� �� Y
	int squareNumber = 0;		//����� �������� � �����������
	//int z = 0;					//���������� ���������
	//int m = 0;					//���������� �����
	//int n = 0;					//���������� ��������
	//double north_result, south_result, west_result, east_result;
public:
	One_hundred_thousand(double m_sx, double m_sy);
	~One_hundred_thousand();
	int SquareNumber(double x, double y, double N, double E);
	double setBorder(double x, double y, double N, double E, QString side);
	void getBorder(double x, double y, double N, double E, QtSecondWidget* th_s);
	
};
