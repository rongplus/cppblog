
# Learn C++( updated to C++17)

This repo contains samples that demonstrate
how to use stand C++ and boost.

Some samples are for Windows, the others are fir Linux. Some can run both of Windows and Linux.

**Note**. You can use Microsoft Visual Studio to search the entire set of source code here to see whether the usage of a particular Windows API is being demonstrated. Clone this repo (or download the ZIP) to your local file system. Then **Find in Files** in Visual Studio, set **Look in** to the folder you cloned or downloaded into, and search for an API name. You can install [Visual Studio](https://visualstudio.microsoft.com/downloads/) without expense. A Community edition is available&mdash;it's free for students, open-source contributors, and individuals.

These samples demonstrate the functionality and programming model
for Windows and Linux.
For boost samples, you need to download and compile boost first.
needed to compile and run the sample.
For more info about the programming models, platforms, languages,
and APIs demonstrated in these samples,
check out the documentation on the
[Windows Dev Center](http://go.microsoft.com/fwlink/?LinkID=532421).
[boost](https://www.boost.org)
[STL](https://www.cplusplus.com/reference/stl/)
[C++11](https://en.cppreference.com/w/cpp/11)
[C++14](https://en.cppreference.com/w/cpp/14)
[C++17](https://en.cppreference.com/w/cpp/17)

To get a copy of Visual Studio, go to
[Visual Studio Downloads](http://go.microsoft.com/fwlink/p/?linkid=301697).

Other samples:

- [Windows Universal Samples (UWP)](https://github.com/Microsoft/Windows-universal-samples)
- [Desktop Bridge to Universal Windows Platform (UWP)](https://github.com/Microsoft/DesktopBridgeToUWP-Samples)
- [Code samples browser](https://docs.microsoft.com/samples/)

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/)
or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

-----
Readme for kafka
build kafka g++ -std=c++14 consumer2.cpp  -lrdkafka++



atomic_store_explicit

Buy the most expensive house and least expensive car you can afford. 

https://www.amazon.com/DevOps-Troubleshooting-Linux-Server-Practices-ebook-dp-B00A4G7M06/dp/B00A4G7M06/ref=mt_other?_encoding=UTF8&me=&qid=


Appendix
https://medium.com/model-monitoring-psi/population-stability-index-psi-ab133b0a5d42
Distribution Shift Detection Algorithms

KL Divergence
The KL divergence statistic is useful if one distribution has a high variance relative to another or small sample size.

Equation:
KLdiv = Ea[ln(Pa/Pb)] = ∑ (Pa)ln(Pa/Pb)

KL Divergence is a well-known metric that can be thought of as the relative entropy between a sample distribution and a reference (prior) distribution. Like PSI, KL Divergence is also useful in catching changes between distributions. Also similar to PSI, it has its basis in information theory. A drawback of KL Divergence is that it is asymmetric.

JS Divergence
Equation:
JS Div(P, Q) = ½ KL-DIV(P,M) + ½ KL-DIV(Q,M)
Reference = M (mixture distribution) = ½ (P + Q)

JS Divergence has some useful properties. Firstly, it’s always finite, so there are no divide-by-zero issues. Divide by zero issues come about when one distribution has values in regions the other does not. Secondly, unlike KLDivergence, it is symmetric.

Algorithm Choice
In v0, we may choose to implement the “PSI” metric/algorithm as an initial anomaly detection metric for model/feature distribution shifts. The main reasons are:

It is easier to calculate, interpret and has a well-defined detection threshold; 
It is widely used in third-party solutions like Arize for shift detection.

If clients have requirements for other anomaly detection metrics/algorithms, we can help implement them in future versions.


setrlimit --->system command.



pip install --upgrade protobuf
pip install --upgrade protobuf-compiler
protoc --python_out=. -I sysinfo.proto 
protoc --python_out="." -I="." sysinfo.proto 

-----google---
glog
gflag
gtest
protobuf

---facebook----
thrift
folly


