#pragma once

namespace rollback {
  template<class T>
  class Input {
    T input;
    unsigned int serial = 0; // this input's place in the order
  };
}
