#pragma once
#include "input.hpp"

namespace rollback {
  template<class T> 
  class State {
    T state;

    template<class R>
    void Update(const Input<R>& input);
  };
}
