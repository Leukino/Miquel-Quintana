#include <iostream>
using namespace std;

template <typename T>
class vec3 {
private:

	T x, y, z;

public:
	vec3() = default;
	vec3(T value)
	{
		x = value; y = value; z = value;
	}
	vec3(T x_, T y_, T z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}
	vec3(bool isZero)
	{
		if (isZero)
			x = 0, y = 0, z = 0;
	}
	~vec3()
	{

	}
	vec3<T> operator+(vec3<T> &vector) 
	{
		vec3 ret(this->xret() + vector.xret(), this->yret() + vector.yret(), this->zret() + vector.zret());
		return ret;
	}
	vec3<T> operator-(vec3<T> &vector)
	{
		vec3 ret(this->xret() - vector.xret(), this->yret() - vector.yret(), this->zret() - vector.zret());
		return ret;
	}
	vec3<T> operator+=(vec3<T> &vector)
	{
		this->x = this->x + vector.xret();
		this->y = this->y + vector.yret();
		this->z = this->z + vector.zret();
		return this;
	}
	vec3<T> operator-=(vec3<T> &vector)
	{
		this->x = this->x - vector.xret();
		this->y = this->y - vector.yret();
		this->z = this->z - vector.zret();
		return this;
	}

	vec3<T> operator=(vec3<T> &vector)
	{
		this->x = vector.xret();
		this->y = vector.yret();
		this->z = vector.zret();
		return this;
	}

	bool operator==(vec3<T> &vector)
	{
		bool ret = false;
		if (x == vector.xret() && y == vector.yret() && z == vector.zret())
			ret = true;
		return ret;
	}
	T xret()
	{
		return x;
	}
	T yret()
	{
		return y;
	}
	T zret()
	{
		return z;
	}
	void display()
	{
		if (is_same<T, float>::value)
			cout << this->x << "  " << this->y << "  " << this->z << endl;
		else
			cout << this->x << this->y << this->z << endl;
	}
	T magnitude()
	{
		T ret;
		T temp;
		temp = this->x + this->y + this->z;
		ret = sqrt(temp);
		return ret;
	}
	vec3<T> normalize()
	{
		vec3<T> ret;
		T mag = this->magnitude();
		ret.x = this->x / mag;
		ret.y = this->y / mag;
		ret.z = this->z / mag;
		return ret;
	}
	void zero()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	bool isZero()
	{
		if (this->x == 0 && this->y == 0 && this->z == 0)
			return true;
		else
			return false;
	}
	T distance_to(vec3<T> vec)
	{
		vec3<T> ret(vec.x - this->x, vec.y - this->y, vec.z - this->z);	
		return ret.magnitude();
	}
};

//#define OPERAND1
//#define OPERAND2
//#define OPERAND3
//#define OPERAND4
//#define OPERAND5
//#define OPERAND6
//#define NORMALIZE
//#define ZERO
//#define ISZERO
#define DISTANCETO
int main() 
{
	vec3<float> vec(3, 4, 5);    // = new vec3(3, 4, 5);
	vec3<float> vec2(1, 2, 3);
	vec3<int> vec4(0, 0, 0);

	cout << "  Vec 1: ";
	vec.display();
	cout << "  Vec 2: ";
	vec2.display();

#ifdef OPERAND1 //+
	cout << "Operand + :  ";
	vec = vec + vec2;
	vec.display();
#endif // DEBUG

#ifdef OPERAND2 //-
	cout << "Operand - :  ";
	vec = vec - vec2;
	vec.display();
#endif // 

#ifdef OPERAND3 //+
	cout << "Operand += :  ";
	vec += vec2;
	vec.display();
#endif // DEBUG
	
#ifdef OPERAND4 //+
	cout << "Operand -= :  ";
	vec -= vec2;
	vec.display();
#endif // DEBUG
	
#ifdef OPERAND5 //+
	cout << "Operand = :  ";
	vec = vec2;
	vec.display();
#endif // DEBUG

#ifdef OPERAND6 //+
	cout << "Operand == :  " << endl;
	if (vec == vec2)
		cout << "Same vector" << endl;
	else
		cout << "Different vector" << endl;
#endif // DEBUG

#ifdef NORMALIZE //+
	cout << "Normalize :  " << endl;
	//vec.normalize();
	vec.normalize().display();
#endif // DEBUG

#ifdef ZERO //+
	cout << "Convert to zero (did rick ask that, didn't he?) :  " << endl;
	vec.zero();
	vec.display();
#endif // DEBUG

#ifdef ISZERO //+
	cout << "Is zero :  " << endl;
	if (vec4.isZero())
		cout << "Yea, it's zero" << endl;
	else
		vec4.display();
#endif // DEBUG

#ifdef DISTANCETO //+
	cout << "Distance vec <-> vec2 :  " << endl;
	cout << vec.distance_to(vec2) << endl;

#endif // DEBUG
	system("pause");
}