#include <CL/opencl.h>
#include <boost/compute/algorithm/sort.hpp>
#include <boost/compute/algorithm/transform.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/core.hpp>
#include <boost/compute/device.hpp>
#include <cstring>
#include <iostream>

namespace compute = boost::compute;

#define BOOST_COMPUTE_DEBUG_KERNEL_COMPILATION
#define BOOST_COMPUTE_HAVE_THREAD_LOCAL
#define BOOST_COMPUTE_THREAD_SAFE
#define BOOST_COMPUTE_USE_OFFLINE_CACHE

void listDevice() {
  auto devices = boost::compute::system::devices();
  for (auto &d : devices) {
    std::cout << d.name() << " " << d.clock_frequency() << " "
              << d.compute_units() << "\n";
  }
}

void testStd() {
  std::vector<float> host_vector(5000000);
  std::generate(host_vector.begin(), host_vector.end(), rand);
  auto begin = std::chrono::high_resolution_clock::now();
  std::sort(host_vector.begin(), host_vector.end());
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "test std Sort="
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "\n";
}

void testCompute() {
  // get default device and setup context
  compute::device device = compute::system::default_device();
  compute::context context(device);
  compute::command_queue queue(context, device);

  // generate random data on the host
  std::vector<float> host_vector(5000000);
  std::generate(host_vector.begin(), host_vector.end(), rand);
  auto begin = std::chrono::high_resolution_clock::now();
  compute::vector<float> device_vector(host_vector.size(), context);

  compute::copy(host_vector.begin(), host_vector.end(), device_vector.begin(),
                queue);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "copy cpu to gpu time="
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "\n";
  begin = std::chrono::high_resolution_clock::now();
  compute::sort(device_vector.begin(), device_vector.end(), queue);
  end = std::chrono::high_resolution_clock::now();
  std::cout << "gpu sort time="
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "\n";
  begin = std::chrono::high_resolution_clock::now();
  compute::copy(device_vector.begin(), device_vector.end(), host_vector.begin(),
                queue);
  end = std::chrono::high_resolution_clock::now();
  std::cout << "gpu to cpu time="
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "\n";
}

int f3() {
  cl_int err;
  cl_platform_id platform;
  err = clGetPlatformIDs(1, &platform, nullptr);
  if (err != CL_SUCCESS) {
    std::cout << "Cannot get platform" << std::endl;
    return -1;
  }

  cl_device_id device;
  err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 1, &device, nullptr);
  if (err != CL_SUCCESS) {
    std::cout << "Cannot get device" << std::endl;
    return -1;
  }
  const uint32_t cal_num = 10000;
  uint32_t *hA = new uint32_t[cal_num];
  uint32_t *hB = new uint32_t[cal_num];
  uint32_t *hC = new uint32_t[cal_num];

  // initialize data
  memset(hC, 0, sizeof(uint32_t) * cal_num);
  for (uint32_t i = 0; i < cal_num; i++) {
    hA[i] = hB[i] = i;
  }

  cl_mem mA = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                             sizeof(uint32_t) * cal_num, hA, nullptr);
  cl_mem mB = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                             sizeof(uint32_t) * cal_num, hB, nullptr);
  cl_mem mC = clCreateBuffer(context, CL_MEM_READ_WRITE,
                             sizeof(uint32_t) * cal_num, nullptr, nullptr);
  if (mA == nullptr || mB == nullptr || mC == nullptr) {
    std::cout << "Create buffer failed" << std::endl;
    return -1;
  }

  const char *program_source =
      "__kernel void test_main(__global const uint* A, __global const uint* B, "
      "__global uint* C) {\n"
      "  size_t idx = get_global_id(0);\n"
      "  C[idx] = A[idx] + B[idx];\n"
      "}";

  cl_program program =
      clCreateProgramWithSource(context, 1, &program_source, nullptr, nullptr);
  if (program == nullptr) {
    std::cout << "Create program failed" << std::endl;
    return -1;
  }

  err = clBuildProgram(program, 0, nullptr, nullptr, nullptr, nullptr);
  if (err != CL_SUCCESS) {
    std::cout << "Build program failed" << std::endl;
    return -1;
  }

  cl_kernel kernel = clCreateKernel(program, "test_main", nullptr);
  if (kernel == nullptr) {
    std::cout << "Create kernel failed" << std::endl;
    return -1;
  }

  err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &mA);
  err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &mB);
  err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &mC);
  if (err != CL_SUCCESS) {
    std::cout << "Set kernel arg failed" << std::endl;
    return -1;
  }

  size_t global_size[]{cal_num};
  size_t local_size[]{cal_num / 10};
  err = clEnqueueNDRangeKernel(queue, kernel, 1, nullptr, global_size,
                               local_size, 0, nullptr, nullptr);
  if (err != CL_SUCCESS) {
    std::cout << "Run kernel failed" << std::endl;
    return -1;
  }

  err = clEnqueueReadBuffer(queue, mC, CL_TRUE, 0, sizeof(uint32_t) * cal_num,
                            hC, 0, nullptr, nullptr);
  if (err != CL_SUCCESS) {
    std::cout << "Read data failed" << std::endl;
    return -1;
  }

  // check one output data
  if (hC[1024] != hA[1024] + hB[1024]) {
    std::cout << "Data calculation failed" << std::endl;
    return -1;
  }

  return 0;
}

int main() {
  listDevice();
  testCompute();
  testStd();
}