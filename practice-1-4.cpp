#include <iostream>
#include <math.h>
using namespace std;

class Vector3 {

  public:
    Vector3() {}
    void setVector3(float x, float y, float z) {
      _x = x;
      _y = y;
      _z = z;
    }
    float getX() {
      return _x;
    }
    float getY() {
      return _y;
    }
    float getZ() {
      return _z;
    }
    void plus(Vector3 vec) {
      _x += vec.getX();
      _y += vec.getY();
      _z += vec.getZ();
    }
    void multi(float n) {
      _x *= n;
      _y *= n;
      _z *= n;
    }
    void div(float n) {
      _x /= n;
      _y /= n;
      _z /= n;
    }
    float dot(Vector3 vec) {
      return _x * vec.getX() +
             _y * vec.getY() +
             _z * vec.getZ();
    }
    void cross(Vector3 vec) {

      float x = vec.getX();
      float y = vec.getY();
      float z = vec.getZ();

      _x = _y * z - _z * y;
      _y = _z * x - _x * z;
      _z = _x * y - _y * x;
    }

  private:
    float _x;
    float _y;
    float _z;

};

float abs(Vector3 vec) {
  return sqrt(pow(vec.getX(), 2) +
              pow(vec.getY(), 2) +
              pow(vec.getZ(), 2));
};

int main(int argc, char const* argv[])
{

  Vector3 vec1 = Vector3();
  Vector3 vec2 = Vector3();

  vec1.setVector3(0.0, 2.0, 0.0);
  vec2.setVector3(3.0, 2.0, 1.0);

  cout << "abs(vec1) :"
       << abs(vec1) << endl;

  vec1.cross(vec2);
  cout << "vec1 :"
       << "[" << vec1.getX() << ", "
              << vec1.getY() << ", "
              << vec1.getZ() << "]" << endl;

  return 0;
}
