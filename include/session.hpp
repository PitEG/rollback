#pragma once
#include "player.hpp"
#include <vector>

namespace rollback {
  class Session {
    Session(const std::vector<Player> players = {});
  };
}
