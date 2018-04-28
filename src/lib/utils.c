#include <xxhash.h>

unsigned long long michet_xxhash(const void* buffer, size_t length)
{
    unsigned long long const seed = 31337;
    unsigned long long const hash = XXH64(buffer, length, seed);

    return hash;
}
