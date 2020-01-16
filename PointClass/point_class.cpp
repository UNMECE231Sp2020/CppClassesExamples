#include <iostream>

class Point {
	private:
		double _x;
		double _y;
		double _z;

	public:
		//Empty constructor
		Point() {
			_x=0, _y=0, _z=0;
		}
		//Constructor with arguments
		Point(double x, double y, double z) {
			_x = x;
			_y = y;
			_z = z;
		}
	
		//Copy constructor
		Point(const Point &point) {
			_x = point._x;
			_y = point._y;
			_z = point._z;
		}
	
		~Point() {
			;
		}

		void set(double x, double y, double z) {
			if(x>=0) {
				_x = x;
			}
			if(y>=0) {
				_y = y;
			}
			if(z>=0) {
				_z = z;
			}
		}

		double x() {
			return _x;
		}
		double y() {
			return _y;
		}
		double z() {
			return _z;
		}

		void print() {
			std::cout << "x: " << _x << " y: " << _y;
			std::cout << " z: " << _z << std::endl;
		}

		Point operator+(Point point) {
			Point temp;
			temp._x = _x + point._x;
			temp._y = _y + point._y;
			temp._z = _z + point._z;

			return temp;
		}
		Point operator-(Point point) {
			Point temp;
			temp._x = _x - point._x;
			temp._y = _y - point._y;
			temp._z = _z - point._z;

			return temp;
		}
		Point operator*(Point point) {
			Point temp;
			temp._x = _x * point._x;
			temp._y = _y * point._y;
			temp._z = _z * point._z;

			return temp;
		}
		Point operator/(Point point) {
			Point temp;
			temp._x = _x / point._x;
			temp._y = _y / point._y;
			temp._z = _z / point._z;

			return temp;
		}

		Point operator=(Point point) {
			_x = point._x;
			_y = point._y;
			_z = point._z;

			return *this;
		}

		bool operator!=(Point point) {
			return ( (_x != point._x) && \
				(_y != point._y) && \
				(_z != point._z));
		}

		bool operator==(Point point) {
			return ( (_x == point._x) && \
				(_y == point._y) && \
				(_z == point._z));
		}

		//Pre ++
		Point operator++() {
			_x += 1;
			_y += 1;
			_z += 1;
			return *this;
		}

		//Post ++
		Point operator++(int p) {
			Point temp = *this;
			_x += 1;
			_y += 1;
			_z += 1;
			return temp;
		}

		//Pre --
		Point operator--() {
			_x -= 1;
			_y -= 1;
			_z -= 1;
			return *this;
		}

		//Post --
		Point operator--(int p) {
			Point temp = *this;
			_x -= 1;
			_y -= 1;
			_z -= 1;
			return temp;
		}


		friend std::ostream& operator<<(std::ostream &out, const Point &p) {
			out << p._x << " " << p._y << " " << p._z;
		
			return out;
		}
		friend std::istream& operator>>(std::istream &in, Point &p) {
			in >> p._x >> p._y >> p._z;
		
			return in;
		}
};

int main() {
	Point point(1, 0, 1);
	point.print();

	Point second_point(point);
	second_point.set(0, 1, 0);
	second_point.print();

	Point p3(point+second_point);
	p3.print();

	Point p4;
	p4 = p3 + point;
	p4.print();

	Point p5;
	std::cout << "Enter three numbers: ";
	std::cin >> p5;

	std::cout << p5 << std::endl;
	point = p3 / p5;
	p4 = second_point - point;

	if(p5==p4) {
		std::cout << "Yay" << std::endl;
	}
	else {
		std::cout << "oh no" << std::endl;
	}
	std::cout << point << " " << p4 << std::endl;

	Point p(1, 1, 1);

	std::cout << p << std::endl;
	p++;
	++p;
	std::cout << p << std::endl;

	p--;
	--p;
	std::cout << p << std::endl;

	return 0;
}
