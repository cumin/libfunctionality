/** @file
    @brief Header

    @date 2014

    @author
    Ryan Pavlik
    <ryan@sensics.com>
    <http://sensics.com>

*/

// Copyright 2014 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_Exceptions_h_GUID_65776C52_6607_42B4_5DED_5305A9EB1FC4
#define INCLUDED_Exceptions_h_GUID_65776C52_6607_42B4_5DED_5305A9EB1FC4

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
#include <stdexcept>
#include <string>

namespace libfunc {
/// @brief libfunctionality-specific exceptions
namespace exceptions {
    /// @brief Exception thrown upon an attempt to load a module with an invalid
    /// name (null, empty)
    class BadPluginName : public std::runtime_error {
      public:
        /// @brief Constructor
        BadPluginName()
            : std::runtime_error(
                  "Given module name is not valid (null, etc.)") {}
    };

    /// @brief Exception thrown when loading a dynamic module fails (before
    /// symbol
    /// lookup or entry point calling)
    class CannotLoadPlugin : public std::runtime_error {
      public:
        /// @brief Constructor
        explicit CannotLoadPlugin(std::string const &n)
            : std::runtime_error("Failed to load the module " + n) {}
        /// @brief Constructor
        CannotLoadPlugin(std::string const &n, const char *info)
            : std::runtime_error("Failed to load the module " + n +
                                 " with error: " + info) {}
    };

    /// @brief Exception thrown when loading the symbol for the entry point
    /// fails
    class CannotLoadEntryPoint : public std::runtime_error {
      public:
        /// @brief Constructor
        explicit CannotLoadEntryPoint(std::string const &n)
            : std::runtime_error("Could not access the libfunctionality entry "
                                 "point of the module " +
                                 n) {}
    };

    /// @brief Exception thrown when the entry point function returns failure.
    class PluginEntryPointFailed : public std::runtime_error {
      public:
        /// @brief Constructor
        explicit PluginEntryPointFailed(std::string const &n)
            : std::runtime_error("Loaded the module " + n +
                                 " and its entry point, but executing its "
                                 "entry point failed.") {}
    };
} // end of namespace exceptions
} // end of namespace libfunc

#endif // INCLUDED_Exceptions_h_GUID_65776C52_6607_42B4_5DED_5305A9EB1FC4
