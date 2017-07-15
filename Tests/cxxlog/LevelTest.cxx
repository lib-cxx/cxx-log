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

#include "cxx-log/Level.hxx"

using namespace cxxlog;

TEST_CASE("Level", "[stream]") {

    REQUIRE("SEVERE" == label(Level::SEVERE));
    REQUIRE("WARNING" == label(Level::WARNING));
    REQUIRE("INFO" == label(Level::INFO));
    REQUIRE("FINE" == label(Level::FINE));
    REQUIRE("DEBUG" == label(Level::DEBUG));
    REQUIRE("UNKNOWN" == label(static_cast<Level>(100)));

    REQUIRE(0 == static_cast<int>((Level::SEVERE)));
    REQUIRE(1 == static_cast<int>(Level::WARNING));
    REQUIRE(2 == static_cast<int>(Level::INFO));
    REQUIRE(3 == static_cast<int>(Level::FINE));
    REQUIRE(4 == static_cast<int>(Level::DEBUG));

    std::stringstream ss{};
    ss << Level::SEVERE;

    REQUIRE("SEVERE" == ss.str());
}
