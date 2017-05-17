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

#include "Logger.hxx"

#include "DefaultLoggerDelegate.hxx"

namespace cxxlog {

    // Internal delegate
    std::shared_ptr<LoggerDelegate> Logger::delegate_ = std::make_shared<DefaultLoggerDelegate>();

    // Default log level
    Level Logger::defaultLevel_ = Level::INFO;

    // Specific log levels
    std::map<std::string, Level> Logger::loggerLevels_{};

    // Get default log level
    Level Logger::defaultLevel() { return defaultLevel_; }

    // Set default log level
    void Logger::defaultLevel(Level level) { Logger::defaultLevel_ = level; }
    
    // Register level for a specified class
    void Logger::registerLevel(const std::string & name, Level level) {
        loggerLevels_[name] = level;
    }
}
