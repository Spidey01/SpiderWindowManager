/**-
 * Copyright 2014-current Terry M. Poulin <BigBoss1964@gmail.com>
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
 */

#include "version.h"

#include <unistd.h>

#include <cstdlib>
#include <iostream>


int
main(int argc, char* argv[])
{
    static const char* options = "hv";
    int i;
    while ((i = getopt(argc, argv, options)) != -1) {
        switch(i) {
            case 'h': {
                std::cout << "usage: " << argv[0] << " [OPTION]..."
                          << std::endl
                          << "    -h     display this help and exit."
                          << "    -v     output version information and exit"
                          << std::endl;
                return EXIT_SUCCESS;
            }
            case 'v':
                 std::cout << "Spider WM version " << SPIDER_VERSION << std::endl;
                return EXIT_SUCCESS;
            default:
                return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

