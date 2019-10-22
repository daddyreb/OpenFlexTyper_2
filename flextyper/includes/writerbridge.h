////////////////////////////////////////////////////////////////////////
///
/// Copyright (c) 2019, Wasserman lab
///
/// FILE        writerbridge.h
///
/// DESCRIPTION This file contains the declaration of writerbridge.h, it contains
///             all utility functions needed to writes results to result file
///
/// Initial version @
///
////////////////////////////////////////////////////////////////////////

#ifndef __WRITER_BRIDGE_H__
#define __WRITER_BRIDGE_H__

#include "typedefs.h"
#include <experimental/filesystem>
#include "utils.h"
#include "iwriterbridge.h"

namespace fs = std::experimental::filesystem;

namespace ft {
class WriterBridge : public IWriterBridge {
public:
    ////////////////////////////////////////////////////////////////////////
    /// \brief WriterBridge constructor
    ////////////////////////////////////////////////////////////////////////
    WriterBridge();

    ////////////////////////////////////////////////////////////////////////
    /// \brief saveQueryOutput
    /// \param allCounts
    /// \param returnMatchesOnly
    ////////////////////////////////////////////////////////////////////////
    void saveQueryOutput(MapOfCounts allCounts, bool returnMatchesOnly, bool crossover, const fs::path& pathToQueryFile, const fs::path& queryOutputFile);

    ////////////////////////////////////////////////////////////////////////
    /// `brief destructor
    ////////////////////////////////////////////////////////////////////////
    virtual ~WriterBridge();

    ////////////////////////////////////////////////////////////////////////
    /// \brief overrideUtils
    /// \param utils
    ////////////////////////////////////////////////////////////////////////
    void overrideUtils(std::shared_ptr<IUtils> utils);


private:
    ////////////////////////////////////////////////////////////////////////
    /// \brief _utils
    ////////////////////////////////////////////////////////////////////////
    Utils _ownedUtils;

    ////////////////////////////////////////////////////////////////////////
    /// \brief _utils
    ////////////////////////////////////////////////////////////////////////
    IUtils* _utils;
};
}

#endif // end of __WRITER_BRIDGE_H__