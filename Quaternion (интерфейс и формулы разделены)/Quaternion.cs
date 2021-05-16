using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quaternion
{
	class Quaternion
	{
		public double s, x, y, z;          //s-скаляр(вещественное число);x,y,z-координаты трехмерного вектора
		public Quaternion() { s = 0; x = 0; y = 0; z = 0; }
		public Quaternion(double a, double b, double c, double d) { s = a; x = b; y = c; z = d; }
		
		
		public static Quaternion operator +(Quaternion q1, Quaternion q2) 
		{
			return new Quaternion(q1.s + q2.s, q1.x + q2.x, q1.y + q2.y, q1.z + q2.z);
		}


		public static  Quaternion operator -(Quaternion q1, Quaternion q2) 
		{ 
			return new Quaternion(q1.s - q2.s, q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
		}


		public static Quaternion operator *(Quaternion q1, Quaternion q2) 
		{ 
			return new Quaternion(
				q1.s * q2.s - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
				q1.s * q2.x + q2.s * q1.x + q1.y * q2.z - q2.y * q1.z,
				q1.s * q2.y + q2.s * q1.y + q1.z * q2.x - q2.z * q1.x,
				q1.s * q2.z + q2.s * q1.z + q1.x * q2.y - q2.x * q1.y); 
		}


		public Quaternion Conjugate(Quaternion q) 
		{
			Quaternion temp = new Quaternion();
			temp.s = s;
			temp.x = -1 * x;
			temp.y = -1 * y;
			temp.z = -1 * z;
			return temp;
//			return new Quaternion(q.s, -1 * q.x, -1 * q.y, -1 * q.z);
		}             //сопряженное число
		
		
		public double Module(Quaternion q) 
		{
			return Math.Sqrt(q.s * q.s + q.x * q.x + q.y * q.y + q.z * q.z); 
		}


		public Quaternion ReverseQuaternion(Quaternion q) 
		{
			Quaternion abstrct = new Quaternion();
			q=Conjugate(abstrct);
			return new Quaternion(
				(q.s) / (s * s + x * x + y * y + z * z),
				(q.x) / (s * s + x * x + y * y + z * z),
				(q.y) / (s * s + x * x + y * y + z * z),
				(q.z) / (s * s + x * x + y * y + z * z));
		}    
		
		
		public static Quaternion operator /(Quaternion q1, Quaternion q2) 
		{
			Quaternion abstrct = new Quaternion();
			abstrct=q2.ReverseQuaternion(abstrct);
			return new Quaternion(
				q1.s * abstrct.s - q1.x * abstrct.x - q1.y * abstrct.y - q1.z * abstrct.z,
				q1.s * abstrct.x + abstrct.s * q1.x + q1.y * abstrct.z - abstrct.y * q1.z,
				q1.s * abstrct.y + abstrct.s * q1.y + q1.z * abstrct.x - abstrct.z * q1.x,
				q1.s * abstrct.z + abstrct.s * q1.z + q1.x * abstrct.y - abstrct.x * q1.y); 
		} //деление заменяем на умножение на q^(-1)
		
		
		public double ScalarProduct(Quaternion q1, Quaternion q2)
		{
			return q1.s * q2.s + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z; 
		}
		
		
		public double Angle(Quaternion q1, Quaternion q2)
		{
			return Math.Acos(ScalarProduct(q1, q2) / (Module(q1) * Module(q2))) * 180 / Math.PI;
		}
	}
}
