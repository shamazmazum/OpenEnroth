#pragma once

#include <unordered_map>

#include "Utility/Memory/Blob.h"

#include "SoundInfo.h"

class SoundList {
 public:
    void FromFile(const Blob &data_mm6, const Blob &data_mm7, const Blob &data_mm8);

    // TODO(captainurist): should be const
    SoundInfo *soundInfo(int soundId);

 private:
    std::unordered_map<int, SoundInfo> _mapSounds;
};

extern SoundList *pSoundList;
