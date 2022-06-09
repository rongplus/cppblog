#include <iostream>
#include <memory.h>

template <class T> class Widget { void Fun(); };

// OK: specialization of a member function of Widget
template <> Widget<char>::Fun() {}
template <class T, class U> class Gadget {
  void Fun() {}
};

template <class T> struct OpNewCreator {
  static T *Create() { return new T; }
};
template <class T> struct MallocCreator {
  static T *Create() {
    void *buf = std::malloc(sizeof(T));
    if (!buf)
      return 0;
    return new (buf) T;
  }
};

// Library code
template <class CreationPolicy> class WidgetManager : public CreationPolicy {};