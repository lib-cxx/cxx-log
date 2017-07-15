/*
 * Copyright 2017 Dami <contact@damiengiron.me>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef CXXLOG_LEVEL_HXX
#define CXXLOG_LEVEL_HXX

#include <string>
#include <ostream>

namespace cxxlog {
    
    /// \brief Define all available levels
    enum Level : int {

        /// \brief Log severe for critical error
        SEVERE = 0,

        /// \brief Log warning for non bocking errors
        WARNING = 1,

        /// \brief Log info for runtime informations
        INFO = 2,

        /// \brief Log fine for verbose informations
        FINE = 3,

        /// \brief Log debug to debug an application
        DEBUG = 4
    };

    /// \brief Convert enum to string
    /// \param level Level to convert
    /// \return String containing level
    std::string label(const Level &level);

    /// \brief Write level to stream
    /// \param os Output stream
    /// \param level Log level
    std::ostream &operator<<(std::ostream &os, const Level &level);
}

#endif // CXXLOG_LEVEL_HXX
