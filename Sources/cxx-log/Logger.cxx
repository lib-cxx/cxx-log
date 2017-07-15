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
#include <sstream>

namespace cxxlog {

    // Instanciate delegate
    std::shared_ptr<LoggerDelegate> Logger::delegate_ = std::make_shared<DefaultLoggerDelegate>();

    // Retrieve delegate
    std::shared_ptr<LoggerDelegate> Logger::delegate() { return delegate_; }

    // Set delegate to define backend
    void Logger::setDelegate(std::shared_ptr<LoggerDelegate> delegate) {
        if (delegate) {
            delegate_ = delegate;
        }
    }
    
    // Log with lambda
    void Logger::log(Level logLevel, std::function<void(std::ostream &)> fct) const {
        if (logLevel <= level()) {
            auto loggerDelegate = delegate();
            if (loggerDelegate) {
                std::stringstream os;
                fct(os);
                loggerDelegate->log(logLevel, name_, os.str());
            }
        }
    }
}
