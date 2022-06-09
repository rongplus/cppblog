 -lboost_system -lboost_thread
  g++ -std=c++14 follytest.cpp -lfolly -lgflags -lglog -lfollybenchmark  -lboost_system -lboost_thread -o fl




   g++ -std=c++14 follytest.cpp -lfolly -lgflags -lglog -lfollybenchmark  -lboost_system -lboost_thread -lboost_regex -lboost_iostreams -levent -ldouble-conversion -lfmt -lboost_context -o fl