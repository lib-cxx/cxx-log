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

#ifndef LOGGER_HXX
#define LOGGER_HXX

#include <memory>

#include "Formatter.hxx"
#include "LoggerDelegate.hxx"

namespace cxxlog {

    /// \brief Define a logger
    class Logger {

      private:
        /// \brief Internal delegate
        static std::shared_ptr<LoggerDelegate> delegate_;

    public:
        
        /// \brief Retrieve delegate
        static std::shared_ptr<LoggerDelegate> delegate();
        
        /// \brief Set delegate to define backend
        /// \param delegate New delegate
        static void setDelegate(std::shared_ptr<LoggerDelegate> delegate);

      private:
        /// \brief Logger name
        std::string name_;
        
        /// \brief Current log level
        Level level_;
        
        /// \brief Constructor with logger name
        Logger(const std::string &name) : name_(name), level_(Logger::delegate_->level(name_)) {

        }

      public:
          
        /// \brief Get current log level
        /// \return current log level
        Level level() const { return level_; }

        /// \brief Log a parametrized message
        /// \tparam Objects Variadic template
        /// \param level Log level
        /// \param msg Message
        /// \param objects parameters
        template <typename... Objects> void log(Level level, const std::string &msg, Objects... objects) const {
            if (level <= level_) {
                delegate_->log(level, name_, format(msg, objects...));
            }
        }

        /// \brief Get or create constructor by name
        static const Logger get(std::string name) { return Logger{name}; }
    };
}

#define LOGGER(X) cxxlog::Logger::get(#X)

#endif // LOGGER_HXX
