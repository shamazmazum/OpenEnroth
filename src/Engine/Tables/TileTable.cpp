#include "TileTable.h"

#include "Engine/AssetsManager.h"

#include "Library/Random/Random.h"
#include "Library/Logger/Logger.h"

#include "Utility/String.h"

#include "FrameTableInc.h"

struct TileTable *pTileTable;

GraphicsImage *TileDesc::GetTexture() {
    if (!this->texture) {
        this->texture = assets->getBitmap(this->name);
    }
    return this->texture;
}


//----- (00487E3B) --------------------------------------------------------
TileDesc *TileTable::GetTileById(unsigned int uTileID) {
    return &tiles[uTileID];
}

//----- (00487E58) --------------------------------------------------------
void TileTable::InitializeTileset(Tileset tileset) {
    //for (int i = 0; i < sNumTiles; ++i) {
        //if (pTiles[i].tileset == tileset && !pTiles[i].name.empty()) {
            // pTiles[i].uBitmapID =
            // pBitmaps_LOD->LoadTexture(pTiles[i].pTileName); if
            // (pTiles[i].uBitmapID != -1)
            //    pBitmaps_LOD->pTextures[pTiles[i].uBitmapID].palette_id2 =
            //    pPaletteManager->LoadPalette(pBitmaps_LOD->pTextures[pTiles[i].uBitmapID].palette_id1);
        //}
    //}
}

//----- (00487ED6) --------------------------------------------------------
int TileTable::GetTileForTerrainType(Tileset terrain_type, bool not_random) {
    int v5;  // edx@3
    int v6;  // edx@11

    if (not_random || terrain_type > Tileset_Tropical) {
        return GetTileId(terrain_type, TILE_SECT_Base1);
    }
    v5 = vrng->random(50);
    if (v5 < 20) {
        return GetTileId(terrain_type, TILE_SECT_Base1);
    } else if (v5 < 30) {
        return GetTileId(terrain_type, TILE_SECT_Base2_NS);
    } else if (v5 < 40) {
        return GetTileId(terrain_type, TILE_SECT_Base3_EW);
    } else if (v5 < 48) {
        return GetTileId(terrain_type, TILE_SECT_Base4_N_E);
    }
    return GetTileId(terrain_type, vrng->randomSample(allSpecialTileSects()));
}

//----- (00487F84) --------------------------------------------------------
unsigned int TileTable::GetTileId(Tileset uTerrainType, TILE_SECT uSection) {
    for (size_t i = 0; i < tiles.size(); ++i) {
        if ((tiles[i].tileset == uTerrainType) &&
            (tiles[i].uSection == uSection))
            return i;
    }
    return 0;
}
