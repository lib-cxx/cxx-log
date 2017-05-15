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

#ifndef DEFAULTLOGGERDELEGATE_HXX
#define DEFAULTLOGGERDELEGATE_HXX

#include "LoggerDelegate.hxx"
#include <ostream>

namespace cxxlog {

    /// \brief Default backend implementation.
    /// May be overrided
    struct DefaultLoggerDelegate : public LoggerDelegate {

        /// \brief Raw output stream
        /// \return Internal output stream used to log messages
        virtual std::ostream &out() const;

        /// \brief Method used to format entry
        /// \param out Raw ouput stream
        /// \param level Log level
        /// \param msg Message to log
        virtual void format(std::ostream &out, Level level, const std::string &name,
                            const std::string &msg) const;

        // Override method to format message in raw output stream
        virtual void log(Level level, const std::string &name, const std::string &msg) const override;
    };
}

#endif // DEFAULTLOGGERDELEGATE_HXX
