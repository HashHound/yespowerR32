#pragma once
#include <stddef.h>
#include "yespower.h"

namespace Crypto {

inline bool yespower_hash(const void* data, size_t length, Hash& hash) {
yespower_params_t yespower_params = {
  .N = 2048,  // Parameter for regular Yespower
  .r = 32,    // Parameter for regular Yespower
  .pers = nullptr, // No seed/personalization for regular Yespower
  .perslen = 0     // Length of personalization is 0
};

if (yespower_tls((unsigned char*)data, length, &yespower_params, (yespower_binary_t*)hash.data)) {
  return false;
}

return true;
}
}
