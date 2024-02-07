
#include <iostream>

class IVec3 {
    public:
        IVec3() : x(0), y(0), z(0) {}
        IVec3(int x, int y, int z) : x(x), y(y), z(z) {}
        void Print();
        int Sum();
        int Magnitude();
    private:
        int x, y, z;
};

class DVec3 {
    public:
        DVec3() : x(0), y(0), z(0) {}
        DVec3(double x, double y, double z) : x(x), y(y), z(z) {}
        void Print();
        double Sum();
        double Magnitude();
    private:
        double x, y, z;
};

struct MixedData1 {
    char a;
    short b;
    int c; 
    char d;  
};

struct MixedData2 {
    char a;
    char d;  
    short b;
    int c;
};