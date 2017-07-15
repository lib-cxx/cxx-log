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

#include <catch/catch.hxx>

#include "cxx-log/Logger.hxx"
#include "cxx-log/DefaultLoggerDelegate.hxx"

using namespace cxxlog;

struct LambdaDelegate : public DefaultLoggerDelegate {

    static bool hasLog_;

    virtual void log(Level level, const std::string &name, const std::string &msg) const override {
        LambdaDelegate::hasLog_ = true;
    }

    void reset() { hasLog_ = false; }
};

bool LambdaDelegate::hasLog_ = false;

TEST_CASE("Logger", "[stream]") {
    
    
    // Test default logger
    LOGGER(default).log(Level::INFO, "msg level1");
    
    REQUIRE(Level::INFO == Logger::delegate()->defaultLevel());
    
    // Set custom delegate to test results
    auto delegate = std::make_shared<LambdaDelegate>();
    
    // Set default log level
    delegate->defaultLevel(Level::WARNING);

    Logger::setDelegate(delegate);

    // Create logger
    auto logger1 = Logger::get("logger1");
    REQUIRE(Level::WARNING == logger1.level());

    logger1.log(Level::INFO, "msg level1");
    REQUIRE_FALSE(LambdaDelegate::hasLog_);
    delegate->reset();

    logger1.log(Level::WARNING, "msg level1");
    REQUIRE(LambdaDelegate::hasLog_);
    delegate->reset();
    
    // Test specif level
    delegate->registerLevel("severLogger", Level::SEVERE);
    REQUIRE(Level::SEVERE == LOGGER(severLogger).level());
}
