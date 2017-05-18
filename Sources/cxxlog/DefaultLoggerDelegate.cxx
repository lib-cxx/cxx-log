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
    
    // Default log level
    Level DefaultLoggerDelegate::defaultLevel_ = Level::INFO;
    
    // Specific log levels
    std::map<std::string, Level> DefaultLoggerDelegate::loggerLevels_{};
    
    DefaultLoggerDelegate::DefaultLoggerDelegate() {
       
    }
    
    // Get default log level
    Level DefaultLoggerDelegate::defaultLevel() const {
        return DefaultLoggerDelegate::defaultLevel_;
    }
    
    // Set default log level
    void DefaultLoggerDelegate::defaultLevel(Level level) { DefaultLoggerDelegate::defaultLevel_ = level; }
    
    // Register level for a specified class
    void DefaultLoggerDelegate::registerLevel(const std::string & name, Level level) {
        loggerLevels_[name] = level;
    }
    
    // Retrieve level for a logger
    Level DefaultLoggerDelegate::level(const std::string & name) const {
        
        // Find specific configuration
        auto level = DefaultLoggerDelegate::loggerLevels_.find(name);
        if (level != loggerLevels_.end()) {
            return level->second;
        } else {
            // Use default configuration
            return DefaultLoggerDelegate::defaultLevel_;
        }
    }
    
    // Raw output stream
    std::ostream &DefaultLoggerDelegate::out() const { return std::cout; }

    // Method used to format entry
    void DefaultLoggerDelegate::format(std::ostream &out, Level level, const std::string &name,
                                       const std::string &msg) const {
        out << level << '|' << name << '|' << msg << std::endl;
    }

    // Override method to format message in raw output stream
    void DefaultLoggerDelegate::log(Level level, const std::string &name, const std::string &msg) const {
        format(out(), level, name, msg);
    }
}
