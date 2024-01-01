#pragma once
#include <iostream>
#include <filesystem>

#ifdef _WIN32
#include <Windows.h>
#else
#include <mach-o/dyld.h>
#include <unistd.h>
#endif

namespace Heatforge
{
    std::filesystem::path GetPath() 
    {
        #ifdef _WIN32
            wchar_t buffer[MAX_PATH];
            GetModuleFileName(NULL, buffer, sizeof(buffer));
            return std::filesystem::path(buffer).parent_path();
        #else
            char buffer[PATH_MAX];
            uint32_t bufsize = sizeof(buffer);

            if (_NSGetExecutablePath(buffer, &bufsize) == 0) 
            {
                char resolved[PATH_MAX];
                if (realpath(buffer, resolved) != nullptr) 
                {
                    return std::filesystem::path(resolved).parent_path();
                }
            }

            std::cerr << "Error getting process directory\n";
            return {};
        #endif
    }
}