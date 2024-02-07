#include "lab_types.h"
#include <iostream>
#include <string>

void type_sizes();
void private_variables();
void byte_arrays();
void arrays();

int main(int argc, char**argv) {
  std::cout << std::endl;
  if (argc < 2) {
    std::cout << "\n---------------------\nUsage: ./memory_app <option>\n--------------------- \nOptions include:" << std::endl;
    std::cout << "\t type_sizes" <<  std::endl;
    std::cout << "\t private_variables" << std::endl;
    std::cout << "\t byte_arrays" << std::endl;
    std::cout << "\t arrays" << std::endl << std::endl;
    return 1;
  }

  std::string option(argv[1]);
  if (option == "type_sizes") {
    type_sizes();
  }
  else if (option == "private_variables") {
    private_variables();
  }
  else if (option == "byte_arrays") {
    byte_arrays();
  }
  else if (option == "arrays") {
    arrays();
  }
  else {
    std::cout << "Option not found..." << std::endl;
    return 1;
  }

  return 0;

}

void type_sizes() {
  DVec3 dvec(1,2,3);
  DVec3 dvecArray[16];
  IVec3 ivecArray[16];

  std::cout << "Type Sizes:" << "\n-----------" << std::endl;
  std::cout << "char:\t\t" << sizeof(char) << std::endl;
  std::cout << "short:\t\t" << sizeof(short) << std::endl;
  std::cout << "int:\t\t" << sizeof(int) << std::endl;
  std::cout << "long:\t\t" << sizeof(long) << std::endl;
  std::cout << "double:\t\t" << sizeof(double) << std::endl;
  std::cout << "unsigned char:\t" << sizeof(unsigned char) << std::endl;
  std::cout << "unsigned short:\t" << sizeof(unsigned short) << std::endl;
  std::cout << "unsigned int:\t" << sizeof(unsigned int) << std::endl;
  std::cout << "void*:\t\t" << sizeof(void*) << std::endl;
  std::cout << "char*:\t\t" << sizeof(char*) << std::endl;
  std::cout << "int*:\t\t" << sizeof(int*) << std::endl;
  std::cout << "IVec3*:\t\t" << sizeof(IVec3*) << std::endl;
  std::cout << "DVec3*:\t\t" << sizeof(DVec3*) << std::endl;
  std::cout << "IVec3:\t\t" << sizeof(IVec3) << std::endl;
  std::cout << "DVec3:\t\t" << sizeof(DVec3) << std::endl;
  std::cout << "dvec:\t\t" << sizeof(dvec) << std::endl;
  std::cout << "ivecArray:\t" << sizeof(ivecArray) << std::endl;
  std::cout << "dvecArray:\t" << sizeof(dvecArray) << std::endl;
  std::cout << "MixedData1:\t" << sizeof(MixedData1) << std::endl;
  std::cout << "MixedData2:\t" << sizeof(MixedData2) << std::endl;
  std::cout << std::endl;
}

void private_variables() {
  std::cout << "Private Variables:" << "\n-----------" << std::endl;
  DVec3 vec(1,2,3);
  double* members = reinterpret_cast<double*>(&vec);
  std::cout << "[" << members[0] << ", " << members[1] << ", " << members[2] << "]" << std::endl;
  members[2] = 3.14159;
  vec.Print();
}

void byte_arrays() {
  std::cout << "Byte Arrays:" << "\n-----------" << std::endl;
  int intValue = 3081;
  unsigned char* bytes = reinterpret_cast<unsigned char*>(&intValue);
  std::cout << (int)bytes[0] << " " << (int)bytes[1] << " " << (int)bytes[2] << " " << (int)bytes[3] << std::endl;
  std::cout << std::endl;
}

void arrays() {
  std::cout << "=======Array========" << std::endl;
  float array[4] = {1.2, 3.4, 5.6, 7.8};
  float overflow[4] = {9.1, 12.13, 14.15, 16.17};
  array[6] = -3.14159;
  for (int i = 0; i < 4; i++) {
    std::cout << array[i] << std::endl;
  }
  std::cout << "===Overflow Array===" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << overflow[i] << std::endl;
  }
}
