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

#include "DefaultLoggerDelegate.hxx"

#include <iostream>

namespace cxxlog {

    /// \brief Raw output stream
    /// \return Internal output stream used to log messages
    std::ostream &DefaultLoggerDelegate::out() const { return std::cout; }

    /// \brief Method used to format entry
    /// \param out Raw ouput stream
    /// \param level Log level
    /// \param msg Message to log
    void DefaultLoggerDelegate::format(std::ostream &out, Level level, const std::string &name,
                                       const std::string &msg) const {
        out << level << '|' << name << '|' << msg << std::endl;
    }

    // Override method to format message in raw output stream
    void DefaultLoggerDelegate::log(Level level, const std::string &name, const std::string &msg) const {
        format(out(), level, name, msg);
    }
}
