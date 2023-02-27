#pragma once

namespace rollback {
  class Player {
  public:
    enum Location {
      Local,
      Remote
    };

  Location GetLocation();

  private:
    Location location;
  };
}
