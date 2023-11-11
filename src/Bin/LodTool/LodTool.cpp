#include "LodToolOptions.h"

#include "Library/Lod/LodReader.h"
#include "Library/LodFormats/LodFormats.h"
#include "Library/Serialization/Serialization.h"

#include "Utility/Format.h"
#include "Utility/String.h"
#include "Utility/UnicodeCrt.h"

int runDump(const LodToolOptions &options) {
    LodReader reader(options.lodPath, LOD_ALLOW_DUPLICATES);

    fmt::print("Lod file: {}\n", options.lodPath);
    fmt::print("Version: {}\n", toString(reader.info().version));
    fmt::print("Description: {}\n", reader.info().description);
    fmt::print("Root folder: {}\n", reader.info().rootName);

    for (const std::string &name : reader.ls()) {
        Blob data = reader.read(name);
        LodFileFormat format = lod::magic(data, name);
        bool isCompressed = format == LOD_FILE_COMPRESSED || format == LOD_FILE_PSEUDO_IMAGE;
        if (isCompressed)
            data = lod::decodeCompressed(data);

        fmt::print("\n");
        fmt::print("Entry: {}\n", name);
        fmt::print("Format: {}\n", toString(lod::magic(data, name)));
        fmt::print("Size{}: {}\n", isCompressed ? " (uncompressed)" : "", data.size());
        fmt::print("Data{}\n:", isCompressed ? " (uncompressed)" : "");

        std::string line;
        for (size_t offset = 0; offset < data.size(); offset += 16) {
            std::string_view chunk = data.string_view().substr(offset, 16);

            fmt::print("    {:08X}: {: <40}  {}\n", offset, toHexDump(chunk), toPrintable(chunk, '.'));
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    try {
        UnicodeCrt _(argc, argv);
        LodToolOptions options = LodToolOptions::parse(argc, argv);
        if (options.helpPrinted)
            return 1;

        switch (options.subcommand) {
        case LodToolOptions::SUBCOMMAND_DUMP: return runDump(std::move(options));
        default:
            assert(false);
            return 1;
        }
    } catch (const std::exception &e) {
        fmt::print(stderr, "{}\n", e.what());
        return 1;
    }
}
