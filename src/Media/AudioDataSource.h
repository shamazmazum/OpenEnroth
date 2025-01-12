#pragma once

#include <memory>

#include "Utility/Memory/Blob.h"

class IAudioDataSource {
 public:
    IAudioDataSource() {}
    virtual ~IAudioDataSource() {}

    virtual bool Open() = 0;
    virtual void Close() = 0;

    virtual size_t GetSampleRate() = 0;
    virtual size_t GetChannelCount() = 0;
    virtual std::shared_ptr<Blob> GetNextBuffer() = 0;
};
typedef std::shared_ptr<IAudioDataSource> PAudioDataSource;
