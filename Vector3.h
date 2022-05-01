#include <iostream>
#include <cmath>

class Vector3 {
	private:
		double x, y, z;

		friend Vector3 operator +=(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator +=(const Vector3 &v_lhs, double d_rhs);
		friend Vector3 operator +(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator +(const Vector3 &v_lhs, double d_rhs);

		friend Vector3 operator -=(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator -=(const Vector3 &v_lhs, double d_rhs);
		friend Vector3 operator -(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator -(const Vector3 &v_lhs, double d_rhs);

		friend Vector3 operator *=(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator *=(const Vector3 &v_lhs, double d_rhs);
		friend Vector3 operator *(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator *(const Vector3 &v_lhs, double d_rhs);

		friend Vector3 operator /=(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator /=(const Vector3 &v_lhs, double d_rhs);
		friend Vector3 operator /(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend Vector3 operator /(const Vector3 &v_lhs, double d_rhs);

		friend bool operator ==(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend bool operator ==(const Vector3 &v_lhs, double d_rhs);
		friend bool operator !=(const Vector3 &v_lhs, const Vector3 &v_rhs);
		friend bool operator !=(const Vector3 &v_lhs, double d_rhs);

		friend void print(const Vector3 &);

	public:
		Vector3(): x(0.0), y(0.0), z(0.0) {};
		Vector3(double xyz): x(xyz), y(xyz), z(xyz) {};
		Vector3(double x, double y, double z): x(x), y(y), z(z) {};
		Vector3(const Vector3 &v): x(v.x), y(v.y), z(v.z) {};

		double sqMag();
		Vector3 abval();
		double dist(const Vector3 &);
		double dot(const Vector3 &);
		Vector3 cross(const Vector3 &);
		Vector3 rotX(double);
		Vector3 rotY(double);
		Vector3 rotZ(double);
		Vector3 rotXYZ(double, double, double);
		Vector3 norm();

		int closestVector(Vector3[], int len);

		Vector3 operator +=(Vector3 &v_rhs) {
			this->x += v_rhs.x;
			this->y += v_rhs.y;
			this->z += v_rhs.z;
			return *this;
		}

		Vector3 operator +=(double d_rhs) {
			this->x += d_rhs;
			this->y += d_rhs;
			this->z += d_rhs;
			return *this;
		}

		Vector3 operator -=(Vector3 &v_rhs) {
			this->x -= v_rhs.x;
			this->y -= v_rhs.y;
			this->z -= v_rhs.z;
			return *this;
		}

		Vector3 operator -=(double d_rhs) {
			this->x -= d_rhs;
			this->y -= d_rhs;
			this->z -= d_rhs;
			return *this;
		}

		Vector3 operator *=(Vector3 &v_rhs) {
			this->x *= v_rhs.x;
			this->y *= v_rhs.y;
			this->z *= v_rhs.z;
			return *this;
		}

		Vector3 operator *=(double d_rhs) {
			this->x *= d_rhs;
			this->y *= d_rhs;
			this->z *= d_rhs;
			return *this;
		}

		Vector3 operator /=(Vector3 &v_rhs) {
			this->x /= v_rhs.x;
			this->y /= v_rhs.y;
			this->z /= v_rhs.z;
			return *this;
		}

		Vector3 operator /=(double d_rhs) {
			this->x /= d_rhs;
			this->y /= d_rhs;
			this->z /= d_rhs;
			return *this;
		}
};

Vector3 operator +(const Vector3 &v_lhs, const Vector3 &v_rhs) {
	return {v_lhs.x + v_rhs.x, v_lhs.y + v_rhs.y, v_lhs.z + v_rhs.z};
}

Vector3 operator +(const Vector3 &v_lhs, double d_rhs) {
	return {v_lhs.x + d_rhs, v_lhs.y + d_rhs, v_lhs.z + d_rhs};
}

Vector3 operator -(const Vector3 &v_lhs, const Vector3 &v_rhs) {
	return {v_lhs.x - v_rhs.x, v_lhs.y - v_rhs.y, v_lhs.z - v_rhs.z};
}

Vector3 operator -(const Vector3 &v_lhs, double d_rhs) {
	return {v_lhs.x - d_rhs, v_lhs.y - d_rhs, v_lhs.z - d_rhs};
}

Vector3 operator *(const Vector3 &v_lhs, const Vector3 &v_rhs) {
	return {v_lhs.x * v_rhs.x, v_lhs.y * v_rhs.y, v_lhs.z * v_rhs.z};
}

Vector3 operator *(const Vector3 &v_lhs, double d_rhs) {
	return {v_lhs.x * d_rhs, v_lhs.y * d_rhs, v_lhs.z * d_rhs};
}

Vector3 operator /(const Vector3 &v_lhs, const Vector3 &v_rhs) {
	return {v_lhs.x / v_rhs.x, v_lhs.y / v_rhs.y, v_lhs.z / v_rhs.z};
}

Vector3 operator /(const Vector3 &v_lhs, double d_rhs) {
	return {v_lhs.x / d_rhs, v_lhs.y / d_rhs, v_lhs.z / d_rhs};
}

bool operator ==(const Vector3 &v_lhs, const Vector3 &v_rhs) {
	return (v_lhs.x == v_rhs.x) && (v_lhs.y == v_rhs.y) && (v_lhs.z == v_rhs.z);
}

bool operator ==(const Vector3 &v_lhs, double d_rhs) {
	return (v_lhs.x == d_rhs) && (v_lhs.y == d_rhs) && (v_lhs.z == d_rhs);
}

bool operator !=(const Vector3 &v_lhs, const Vector3 &v_rhs) {
	return (v_lhs.x != v_rhs.x) && (v_lhs.y != v_rhs.y) && (v_lhs.z != v_rhs.z);
}

bool operator !=(const Vector3 &v_lhs, double d_rhs) {
	return (v_lhs.x != d_rhs) && (v_lhs.y != d_rhs) && (v_lhs.z != d_rhs);
}

double Vector3::sqMag() {
	double xx = this->x * this->x;
	double yy = this->y * this->y;
	double zz = this->z * this->z;
	return std::sqrt(xx + yy + zz);
}

Vector3 Vector3::abval() {
	if(this->x < 0) this->x * -1;
	if(this->y < 0) this->y * -1;
	if(this->z < 0) this->z * -1;
	return *this;
}

double Vector3::dist(const Vector3 &v) {
	return (v - *this).sqMag();
}

double Vector3::dot(const Vector3 &v) {
	double xdot = this->x * v.x;
	double ydot = this->y * v.y;
	double zdot = this->z * v.z;
	return xdot + ydot + zdot;
}

Vector3 Vector3::cross(const Vector3 &v1) {
	Vector3 v2;
	v2.x = this->y * v1.z - this->z * v1.y;
	v2.y = this->z * v1.x - this->x * v1.z;
	v2.z = this->x * v1.y - this->y * v1.x;
	return v2;
}

Vector3 Vector3::rotX(double rad) {
	double c = std::cos(rad);
	double s = std::sin(rad);
	Vector3 v1;
	v1.x = this->x;
	v1.y = (this->y * c) - (this->z * s);
	v1.z = (this->z * c) + (this->y * s);
	return v1;
}

Vector3 Vector3::rotY(double rad) {
	double c = std::cos(rad);
	double s = std::sin(rad);
	Vector3 v1;
	v1.x = (this->x * c) - (this->z * s);
	v1.y = this->y;
	v1.z = (this->z * c) + (this->x * s);
	return v1;
}

Vector3 Vector3::rotZ(double rad) {
	double c = std::cos(rad);
	double s = std::sin(rad);
	Vector3 v1;
	v1.x = (this->x * c) - (this->y * s);
	v1.y = (this->y * c) + (this->x * s);
	v1.z = this->z;
	return v1;
}

Vector3 Vector3::rotXYZ(double rX, double rY, double rZ) {
	return (*this).rotX(rX).rotY(rY).rotZ(rZ);
}

Vector3 Vector3::norm() {
	return *this / (*this).sqMag();
}

int Vector3::closestVector(Vector3 v_list[], int len) {
	if(len == 0) return -1;
	else if(len == 1) return 0;
	else {
		int index = 0;
		double dist = v_list[0].dist(*this);
		for(int j = 1; j < len; j++) {
			double dist_new = v_list[j].dist(*this);
			if(dist_new < dist) {
				index = j;
				dist = dist_new;
			}
		}
		return index;
	}
}

void print(const Vector3 &v) {
	std::cout << "X: " << v.x << " Y: " << v.y << " Z: " << v.z << std::endl;
}

int main() {

	Vector3 v1(5.0, 2.0, 3.0);
	Vector3 v2(2.0, 9.0, 6.0);
	Vector3 v3(1.0, 1.0, 1.0);
	Vector3 v4(5.0, 3.0, 1.0);
	Vector3 v5(2.0, 9.0, 5.0);

	Vector3 v;

	Vector3 v_list[5] = {v1, v2, v3, v4, v5};
    int len = sizeof(v_list) / sizeof(Vector3);
	std::cout << "Closest Vector to v: " << v.closestVector(v_list, len) << std::endl;
	return 0;
}