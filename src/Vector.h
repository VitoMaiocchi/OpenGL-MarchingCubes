#ifndef VECTOR_VITO
#define VECTOR_VITO

#include <string>

class Vector3f {
    public:
        Vector3f(float x, float y, float z);
        Vector3f();
        void set(float x, float y, float z);
        std::string print();

        float x, y, z;
};

class Vector3i {
    public:
        Vector3i(int x, int y, int z);
        std::string print();

        int x, y, z;
};

Vector3f addVector(Vector3f v1, Vector3f v2);
Vector3i addVector(Vector3i v1, Vector3i v2);
Vector3f subtractVector(Vector3f v1, Vector3f v2);
Vector3f subtractVector(Vector3f v1, Vector3i v2);
float dotProduct(Vector3f v1, Vector3f v2); 
Vector3i floor(Vector3f vector);

#endif