#include <Windows.h> 
class CBallSettingsMonitor
{
	//������� ���� ����������� �������� 
	double angle;
	//������� �������� 
	double speed;
	double R;
	int T;
public:
	CBallSettingsMonitor();
	~CBallSettingsMonitor();
	//����� ��� ��������� ������������ �������� 
	void Draw(HDC dc);
	//��������� � ��������� �������� 
	void SpeedUp();
	void SpeedDown();
	//���������� � ���������� ���� 
	void AngleUp();
	void AngleDown();
	//���������� ��������� v_x, v_y � �������� ���� � ����� �� ������� angle � speed 
	void GetVXVY(double& v_x, double& v_y);
};