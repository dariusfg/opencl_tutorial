#include "main.hpp"
#include <CL/cl.h>
#include <vector>
#include <iostream>

void print_version_of__opencl(cl_platform_id id_of__platform) {
    size_t size_of__version_string;
    clGetPlatformInfo(
            id_of__platform, 
            CL_PLATFORM_VERSION, 
            0, 
            0, 
            &size_of__version_string);

    std::vector<char> buffer(size_of__version_string);

    clGetPlatformInfo(
            id_of__platform, 
            CL_PLATFORM_VERSION, 
            size_of__version_string, 
            buffer.data(), 
            &size_of__version_string);

    std::cout << "Version: "
        << buffer.data()
        << std::endl
        ;
}

int main(void) {
    cl_uint quantity_of__devices;
    clGetPlatformIDs(
            0, 
            0, 
            &quantity_of__devices);

    std::cout << "Quantity of devices: "
        << quantity_of__devices
        << std::endl
        ;

    std::vector<cl_platform_id> platform_ids(quantity_of__devices);

    clGetPlatformIDs(
            quantity_of__devices, 
            platform_ids.data(),
            &quantity_of__devices);
    
    for (auto platform_id : platform_ids) {
        print_version_of__opencl(platform_id);
    }

    return 0;
}
