#pragma once

#include <vcpkg/base/fwd/files.h>

#include <vcpkg/fwd/installedpaths.h>

#include <vcpkg/base/sortedvector.h>

#include <vcpkg/statusparagraphs.h>

namespace vcpkg
{
    StatusParagraphs database_load_check(Filesystem& fs, const InstalledPaths& installed);

    void write_update(Filesystem& fs, const InstalledPaths& installed, const StatusParagraph& p);

    struct StatusParagraphAndAssociatedFiles
    {
        StatusParagraph pgh;
        SortedVector<std::string> files;
    };

    std::vector<InstalledPackageView> get_installed_ports(const StatusParagraphs& status_db);
    std::vector<StatusParagraphAndAssociatedFiles> get_installed_files(Filesystem& fs,
                                                                       const InstalledPaths& installed,
                                                                       const StatusParagraphs& status_db);

    std::string shorten_text(const std::string& desc, const size_t length);
} // namespace vcpkg
