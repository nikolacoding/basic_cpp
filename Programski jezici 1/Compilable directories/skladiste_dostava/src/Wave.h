#ifndef WAVE_H
#define WAVE_H

#include "Import.h"
#include "Export.h"
#include "Stats.h"

namespace Wave{
    void Start(Storage& storage, Import& import, std::vector<Export&>& exports, Stats& stats);
};

#endif