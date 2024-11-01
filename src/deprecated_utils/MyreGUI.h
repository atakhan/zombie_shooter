#ifndef MYREGUI_H
#define MYREGUI_H

#include <vector>
#include <raylib-cpp.hpp>

class MyreGUI {
  public:
    MyreGUI() : layers_() {};
  
  private:
    std::vector<std::vector<int>> layers_;
    
};

#endif // MYREGUI_H