#include "QtMapNomenclature.h"


QtMapNomenclature::QtMapNomenclature(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	
	connect(ui.M1000000, SIGNAL(clicked()), this, SLOT(one_million_clicked));
}

/*
void QtMapNomenclature::coordinateTransformation(double value, string side)			//��������� �������� ����� � ����, ���, ���(�������������) � ������� ��� ��������
{
	int Vgrad, Vmin, Vsec;
	Vgrad = static_cast<int>(value);
	Vmin = static_cast<int>((value - Vgrad) * 60);
	Vsec = round((((value - Vgrad) * 60) - Vmin) * 60);
	//if (side == "north")
	//	cout << "\tNorth border: ";
	//else if (side == "south")
	//	cout << "\tSouth border: ";
	//else if (side == "west")
	//	cout << "\tEast border: ";
	//else if (side == "east")
	//	cout << "\tWest border: ";
	//else cout << "ERROR";

	//cout << Vgrad << "�" << Vmin << "'" << Vsec << "''\n";
}

void QtMapNomenclature::coordinateTransformationDoudle(double value, string side)			//��������� �������� ����� � ����, ���, ���(����������) � ������� ��� ��������
{
	//cout << setprecision(1) << fixed;
	int Vgrad, Vmin;
	double Vsec;
	Vgrad = static_cast<int>(value);
	Vmin = static_cast<int>((value - Vgrad) * 60);
	Vsec = (((value - Vgrad) * 60) - Vmin) * 60;
	if (side == "north")
		cout << "\tNorth border: ";
	else if (side == "south")
		cout << "\tSouth border: ";
	else if (side == "west")
		cout << "\tEast border: ";
	else if (side == "east")
		cout << "\tWest border: ";
	else cout << "ERROR";

	cout << Vgrad << "�" << Vmin << "'" << Vsec << "''\n";
}

class QtMapNomenclature::One_million {
private:
	double sx = 4;				//��� �� �
	double sy = 6;				//��� �� Y
	int columnNumber = 0;		//����� ������� � �����������
	int stringNumber = 0;		//����� ������ � �����������
	int z = 0;					//���������� ���������
	int m = 0;					//���������� �����
	int n = 0;					//���������� ��������
	double north_result, south_result, west_result, east_result;
public:
	char StringNumber(double x, double y)			 //���������� ����� ������ �������� � 1:1 000 000
	{
		for (; m < 12;) {			//���� �� �������
			double north = (80 - sx * m);
			double south = (80 - sx - sx * m);
			if (x >= south && x <= north) {
				m++;
				north_result = north;
				stringNumber = m;
			}
			else {
				m++;
			}
		}
		m = 0;
		string a("TSRQPONMLKJI");
		return a[stringNumber - 1];
	}
	int ColumnNumber(double x, double y)			//���������� ����� ������� �������� � 1:1 000 000
	{
		for (; n < 60;) {		//���� �� ��������
			double west = (0 + sy + n * sy);
			double east = (0 + n * sy);
			if (y >= east && y <= west) {
				n++;
				east_result = east;
				columnNumber = 30 + n;
			}
			else {
				n++;
			}
		}
		n = 0;
		return columnNumber;
	}
	/*double setBorder(double x, double y, string side)			//���������� ������� �������� � 1:1 000 000
	{
		for (; n < 60;) {						//���� �� ��������
			double west = (0 + sy + n * sy);
			double east = (0 + n * sy);
			if (y >= east && y <= west) {
				n++;
				west_result = west;
				east_result = east;
			}
			else {
				n++;
			}
		}
		for (; m < 12;) {						//���� �� �������
			double north = (80 - sx * m);
			double south = (80 - sx - sx * m);
			if (x >= south && x <= north) {
				m++;
				north_result = north;
				south_result = south;
			}
			else {
				m++;
			}
		}
		m = 0;
		n = 0;
		if (side == "north")
			return north_result;
		else if (side == "east")
			return east_result;
		else if (side == "west")
			return west_result;
		else if (side == "south")
			return south_result;
		else
			cout << "ERROR\n";
	}
	void getBorder(double x, double y)			//������� �������� ����� ��������
	{
		double north_border = setBorder(x, y, "north");
		double south_border = setBorder(x, y, "south");
		double west_border = setBorder(x, y, "west");
		double east_border = setBorder(x, y, "east");
		coordinateTransformation(north_border, "north");
		coordinateTransformation(south_border, "south");
		coordinateTransformation(west_border, "west");
		coordinateTransformation(east_border, "east");
	}
};
*/
void QtMapNomenclature::one_million_clicked()
{
	//����������� ���������� � ���������� ��������
	Xgrad = ui.spinBox_lng_gr->value();
	Xmin = ui.spinBox_lng_min->value();
	Xsec = ui.spinBox_lng_sec->value();
	Ygrad = ui.spinBox_lt_gr->value();
	Ymin = ui.spinBox_lt_min->value();
	Ysec = ui.spinBox_lt_sec->value();
	x = Xgrad + (Xmin / 60.) + (Xsec / 3600.);
	y = Ygrad + (Ymin / 60.) + (Ysec / 3600.);

	//sWidget = new QtSecondWidget(X.setNum(x), Y.setNum(y));				//������ ����� ����, � ������� ����� ������� ���� ���������� � ���� ������(�����)
	sWidget = new QtSecondWidget(x, y);
	sWidget->show();													//���������� ��� ���� 

}