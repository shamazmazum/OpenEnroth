#include "InputStream.h"

#include "Utility/Exception.h"

void InputStream::ReadOrFail(void *data, size_t size) {
    size_t read = Read(data, size);
    if (read != size)
        throw Exception("Failed to read the requested number of bytes from a stream, requested {}, got {}", size, read);
}
