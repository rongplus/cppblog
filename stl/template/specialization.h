class Window {
private:
  /* data */
public:
  Window(/* args */);
  ~Window();
};

class Button

{
private:
  /* data */
public:
  Button(/* args */);
  ~Button();
};
// template <> struct CompileTimeError<true> {};
template <typename A = Window, typename B = Button> class ApplicationFactory {
public:
  ApplicationFactory() {}
};

template <typename A> class Example<A, 2> {
public:
  Example(A b1, A b2){

  };
};

template <> class streamA<char> {
public:
  void f() {}
};

template <> int compare1(const char *const &p1, const char *const &p2) {
  return 0;
}