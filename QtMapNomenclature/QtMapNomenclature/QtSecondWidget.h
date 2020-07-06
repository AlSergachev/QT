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
	QString X, Y, QN1, QN2, QN_One_million, 
		QN3, QN_One_hundred_thousand, 
		QN4, QN_Fifty_thousand, 
		QN5, QN_Twenty_five_thousand,
		QN6, QN_Ten_thousand,
		Qn4, QN_Five_thousand,
		Qn5, QN_Two_thousand;
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
	size_t sheet_size;
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
			//����� �������� � �����������
	//int z = 0;					//���������� ���������
	//int m = 0;					//���������� �����
	//int n = 0;					//���������� ��������
	//double north_result, south_result, west_result, east_result;
public:
	int squareNumber = 0;
	One_hundred_thousand(double m_sx, double m_sy);
	~One_hundred_thousand();
	int SquareNumber(double x, double y, double N, double E, size_t sheet_size);
	double setBorder(double x, double y, double N, double E, size_t sheet_size, QString side);
	void getBorder(double x, double y, double N, double E, size_t sheet_size, QtSecondWidget* th_s);
	
};

class Fifty_thousand: public One_hundred_thousand
{
private:
	//double sx = 1. / 6;			//��� �� �
	//double sy = 0.25;			//��� �� Y
	//int squareNumber = 0;		//����� �������� � �����������
	//int z = 0;					//���������� ���������
	//int m = 0;					//���������� �����
	//int n = 0;					//���������� ��������
	//double north_result, south_result, west_result, east_result;
public:
	Fifty_thousand(double m_sx, double m_sy);
	~Fifty_thousand();
	const char SquareNumber50th(double x, double y, double N, double E);		//���������� ����� �������� � 1:50 000
	

	//double setBorder(double x, double y, double N, double E, string side)			//����������  ������� �������� � 1:50 000
	//{
	//	for (; m < 2;) {			//���� �� �������
	//		for (; n < 2;) {		//���� �� ��������
	//			double north = (N - sx * m);
	//			double south = (N - sx - sx * m);
	//			double west = (E + sy + n * sy);
	//			double east = (E + n * sy);
	//			if (y >= east && y <= west && x >= south && x <= north) {
	//				n++;
	//				north_result = north;
	//				south_result = south;
	//				west_result = west;
	//				east_result = east;
	//			}
	//			else {
	//				n++;
	//			}
	//		}
	//		z += n;
	//		n = 0;
	//		m++;
	//	}
	//	m = 0;
	//	n = 0;
	//	if (side == "north")
	//		return north_result;
	//	else if (side == "east")
	//		return east_result;
	//	else if (side == "west")
	//		return west_result;
	//	else if (side == "south")
	//		return south_result;
	//	else
	//		cout << "ERROR\n";
	//}
	//void getBorder(double x, double y, double N, double E)			//������� �������� ����� �������� 
	//{
	//	double north_border = setBorder(x, y, N, E, "north");
	//	double south_border = setBorder(x, y, N, E, "south");
	//	double west_border = setBorder(x, y, N, E, "west");
	//	double east_border = setBorder(x, y, N, E, "east");
	//	coordinateTransformation(north_border, "north");
	//	coordinateTransformation(south_border, "south");
	//	coordinateTransformation(west_border, "west");
	//	coordinateTransformation(east_border, "east");
	//}
};

class Twenty_five_thousand: public Fifty_thousand
{
//private:
//	double sx = 1. / 12;		//��� �� �
//	double sy = 1. / 8;			//��� �� Y
//	int squareNumber = 0;		//����� �������� � �����������
//	int z = 0;					//���������� ���������
//	int m = 0;					//���������� �����
//	int n = 0;					//���������� ��������
//	double north_result, south_result, west_result, east_result;
public:
	Twenty_five_thousand(double m_sx, double m_sy);
	~Twenty_five_thousand();
	const char SquareNumber25th(double x, double y, double N, double E);
};

class Ten_thousand: public Twenty_five_thousand 
{
//private:
//	double sx = 1. / 24;		//��� �� �
//	double sy = 1. / 16;		//��� �� Y
//	int squareNumber = 0;		//����� �������� � �����������
//	int z = 0;					//���������� ���������
//	int m = 0;					//���������� �����
//	int n = 0;					//���������� ��������
//	double north_result, south_result, west_result, east_result;
public:
	Ten_thousand(double m_sx, double m_sy);
	~Ten_thousand();
	//int SquareNumber(double x, double y, double N, double E)			//���������� ����� �������� � 1:10 000
	//{
	//	for (; m < 2;) {			//���� �� �������
	//		for (; n < 2;) {		//���� �� ��������
	//			double north = (N - sx * m);
	//			double south = (N - sx - sx * m);
	//			double west = (E + sy + n * sy);
	//			double east = (E + n * sy);
	//			if (y >= east && y <= west && x >= south && x <= north) {
	//				n++;
	//				squareNumber = z + n;
	//			}
	//			else {
	//				n++;
	//			}
	//		}
	//		z += n;
	//		n = 0;
	//		m++;
	//	}
	//	m = 0;
	//	n = 0;
	//	return squareNumber;
	//}
};

class Five_thousand :public One_hundred_thousand 
{
//private:
//	double sx = 1. / 48;		//��� �� �
//	double sy = 1. / 32;		//��� �� Y
//	int squareNumber = 0;		//����� �������� � �����������
//	int z = 0;					//���������� ���������
//	int m = 0;					//���������� �����
//	int n = 0;					//���������� ��������
//	double north_result, south_result, west_result, east_result;
public:
	Five_thousand(double m_sx, double m_sy);
	~Five_thousand();
	//int SquareNumber(double x, double y, double N, double E)			//���������� ����� �������� � 1:5 000
	//{
	//	for (; m < 16;) {			//���� �� �������
	//		for (; n < 16;) {		//���� �� ��������
	//			double north = (N - sx * m);
	//			double south = (N - sx - sx * m);
	//			double west = (E + sy + n * sy);
	//			double east = (E + n * sy);
	//			if (y >= east && y <= west && x >= south && x <= north) {
	//				n++;
	//				squareNumber = z + n;
	//			}
	//			else {
	//				n++;
	//			}
	//		}
	//		z += n;
	//		n = 0;
	//		m++;
	//	}
	//	m = 0;
	//	n = 0;
	//	return squareNumber;
	//}
	//double setBorder(double x, double y, double N, double E, string side)			//���������� ������� �������� � 1:5 000
	//{
	//	for (; m < 16;) {			//���� �� �������
	//		for (; n < 16;) {		//���� �� ��������
	//			double north = (N - sx * m);
	//			double south = (N - sx - sx * m);
	//			double west = (E + sy + n * sy);
	//			double east = (E + n * sy);
	//			if (y >= east && y <= west && x >= south && x <= north) {
	//				n++;
	//				north_result = north;
	//				south_result = south;
	//				west_result = west;
	//				east_result = east;
	//			}
	//			else {
	//				n++;
	//			}
	//		}
	//		z += n;
	//		n = 0;
	//		m++;
	//	}
	//	m = 0;
	//	n = 0;
	//	if (side == "north")
	//		return north_result;
	//	else if (side == "east")
	//		return east_result;
	//	else if (side == "west")
	//		return west_result;
	//	else if (side == "south")
	//		return south_result;
	//	else
	//		cout << "ERROR\n";
	//}
	//void getBorder(double x, double y, double N, double E)			//������� �������� ����� ��������
	//{
	//	double north_border = setBorder(x, y, N, E, "north");
	//	double south_border = setBorder(x, y, N, E, "south");
	//	double west_border = setBorder(x, y, N, E, "west");
	//	double east_border = setBorder(x, y, N, E, "east");
	//	coordinateTransformationDoudle(north_border, "north");
	//	coordinateTransformationDoudle(south_border, "south");
	//	coordinateTransformationDoudle(west_border, "west");
	//	coordinateTransformationDoudle(east_border, "east");
	//}
};

class Two_thousand : public Five_thousand
{
//private:
//	double sx = 1. / 144;		//��� �� �
//	double sy = 1. / 96;		//��� �� Y
//	int squareNumber = 0;		//����� �������� � �����������
//	int z = 0;					//���������� ���������
//	int m = 0;					//���������� �����
//	int n = 0;					//���������� ��������
//	double north_result, south_result, west_result, east_result;
public:
	Two_thousand(double m_sx, double m_sy);
	~Two_thousand();
	const char SquareNumber2th(double x, double y, double N, double E);
	//double setBorder(double x, double y, double N, double E, string side)			//���������� ������� �������� � 1:2 000
	//{
	//	for (; m < 3;) {			//���� �� �������
	//		for (; n < 3;) {		//���� �� ��������
	//			double north = (N - sx * m);
	//			double south = (N - sx - sx * m);
	//			double west = (E + sy + n * sy);
	//			double east = (E + n * sy);
	//			if (y >= east && y <= west && x >= south && x <= north) {
	//				n++;
	//				north_result = north;
	//				south_result = south;
	//				west_result = west;
	//				east_result = east;
	//			}
	//			else {
	//				n++;
	//			}
	//		}
	//		z += n;
	//		n = 0;
	//		m++;
	//	}
	//	m = 0;
	//	n = 0;
	//	if (side == "north")
	//		return north_result;
	//	else if (side == "east")
	//		return east_result;
	//	else if (side == "west")
	//		return west_result;
	//	else if (side == "south")
	//		return south_result;
	//	else
	//		cout << "ERROR\n";
	//}
	//void getBorder(double x, double y, double N, double E)			//������� �������� ����� ��������
	//{
	//	double north_border = setBorder(x, y, N, E, "north");
	//	double south_border = setBorder(x, y, N, E, "south");
	//	double west_border = setBorder(x, y, N, E, "west");
	//	double east_border = setBorder(x, y, N, E, "east");
	//	coordinateTransformationDoudle(north_border, "north");
	//	coordinateTransformationDoudle(south_border, "south");
	//	coordinateTransformationDoudle(west_border, "west");
	//	coordinateTransformationDoudle(east_border, "east");
	//}
};
