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

#ifndef LOGGERDELEGATE_HXX
#define LOGGERDELEGATE_HXX
#include "Level.hxx"

namespace cxxlog {

    /// \brief Define delegate to implement logger backend
    /// May be overrided
    struct LoggerDelegate {

        /// \brief Methode used to log message on backend
        /// \param level Log level
        /// \param name Logger name
        /// \param message Message to log
        virtual void log(Level level, const std::string &name, const std::string &msg) const = 0;

        /// \brief virtual destructor to allow overriding
        virtual ~LoggerDelegate() {}
    };
}

#endif // LOGGERDELEGATE_HXX
