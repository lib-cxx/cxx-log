/* Copyright 2017 Dami<contact @damiengiron.me> **Licensed under the Apache License, Version 2.0(the "License");
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

#ifndef FORMATTER_HXX
#define FORMATTER_HXX

#include <boost/format.hpp>
#include <string>

namespace cxxlog {

    /// \brief Format a string using a boost format and parameters
    /// Use as meta break point
    /// \param formatter Current Boost format
    /// \param others Empty
    /// \return String containing formatted message
    template <typename... Others> std::string format(boost::format &formatter, Others... others) {
        return formatter.str();
    }

    /// \brief Format a string using a boost format parameter and other parameters
    /// \param formatter Current Boost formater
    /// \param param To format
    /// \param others Others params formatted in nexts calls
    /// \return String containing formatted message
    template <typename T, typename... Others> std::string format(boost::format &formatter, T object, Others... others) {
        formatter % object;
        return format(formatter, others...);
    }

    /// \brief Format a string using string definition and parameters
    /// \param msg String containing message template
    /// \param others All params to format using template
    /// \return String containing formatted message
    template <typename... Others> std::string format(const std::string &msg, Others... others) {
        boost::format formatter(msg);
        return format(formatter, others...);
    }
}

#endif // FORMATTER_HXX
