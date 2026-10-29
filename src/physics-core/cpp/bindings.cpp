#include "add.h"
#include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(physics_core) {
  emscripten::function("add", &add);
}
