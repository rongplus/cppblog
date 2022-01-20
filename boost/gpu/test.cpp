#include <iostream>

#include <boost/compute/core.hpp>
#include <vector>

#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/container/vector.hpp>
namespace compute = boost::compute;
int tranData() {
  // get default device and setup context
  compute::device device = compute::system::default_device();
  compute::context context(device);
  compute::command_queue queue(context, device);

  // create data array on host
  int host_data[] = {1, 3, 5, 7, 9};

  // create vector on device
  compute::vector<int> device_vector(5, context);

  // copy from host to device
  compute::copy(host_data, host_data + 5, device_vector.begin(), queue);

  // create vector on host
  std::vector<int> host_vector(5);

  // copy data back to host
  compute::copy(device_vector.begin(), device_vector.end(), host_vector.begin(),
                queue);

  return 0;
}
int main() {
  // get the default device
  compute::device device = compute::system::default_device();

  // print the device's name and platform
  std::cout << "hello from " << device.name();
  std::cout << " (platform: " << device.platform().name() << ")" << std::endl;

  tranData();
  return 0;
}

// cl test.cpp -ID:\3rdLib\boost_1_77_0 -ID:\3rdLib\include\sycl /MD
// D:\3rdLib\boost_1_77_0\stage\lib\libboost_chrono-vc142-mt-x64-1_77.lib
// D:\3rdLib\OpenCL-SDK\build\external\OpenCL-ICD-Loader\Release\OpenCL.lib
// /EHsc