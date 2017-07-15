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

#include "Level.hxx"

namespace cxxlog {

    // Retrieve label for an enum
    std::string label(const Level &level) {

        static const std::string LEVEL_LABELS[] = {"SEVERE", "WARNING", "INFO", "FINE", "DEBUG"};

        const int index{(int)(level)};
        if (index < 5) {
            return LEVEL_LABELS[index];
        } else {
            return "UNKNOWN";
        }
    }

    // Write level to stream
    std::ostream &operator<<(std::ostream &os, const Level &level) {
        os << label(level);
        return os;
    }
}
