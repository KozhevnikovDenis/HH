#include <Windows.h> 
class CBallSettingsMonitor
{
	//текущий угол направления движения 
	double angle;
	//текущая скорость 
	double speed;
	double R;
	int T;
public:
	CBallSettingsMonitor();
	~CBallSettingsMonitor();
	//метод для отрисовки управляющего элемента 
	void Draw(HDC dc);
	//Повышение и понижение скорости 
	void SpeedUp();
	void SpeedDown();
	//увеличение и уменьшение угла 
	void AngleUp();
	void AngleDown();
	//возвращает параметры v_x, v_y в терминах шара в завис от текущих angle и speed 
	void GetVXVY(double& v_x, double& v_y);
};